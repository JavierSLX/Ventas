#include "stdafx.h"  //_____________________________________________ LibreriaAngelDll.cpp
#include "LibreriaAngelDll.h"

//
wstring LibreriaAngelDll::tipoArticuloCLS::sacarTipoArticuloSiExiste(wstring tipoArticulo) 
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	wstring existeTipoArticulo;

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
			FROM tipo_articulo\
			WHERE nombre = '%s'", tipoArticulo.c_str());
		coneccion.GetString(consulta, existeTipoArticulo, 50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	coneccion.CloseSession();
	return existeTipoArticulo;
}


//Metodo que inserta un nuevo tipo de artículo en la base de datos
void LibreriaAngelDll::tipoArticuloCLS::insertarTipoArticulo(wstring nombreArticulo,bool articuloActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO tipo_articulo(nombre,activo)VALUES('%s',%d)",nombreArticulo.c_str(),articuloActivo);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo para obtener el id del tipo de articulo seleccionado
int LibreriaAngelDll::tipoArticuloCLS::obtenerIdOculto(Win::ListView lvTiposArticulos)
{
	int indice = lvTiposArticulos.GetSelectedIndex();
	int id = lvTiposArticulos.Items[indice].Data;
	return id;
}

//Metodo para obtener el contenido del texto en un listview
wstring LibreriaAngelDll::tipoArticuloCLS::obtenerTextoListView(Win::ListView lvTiposArticulos,int columna)
{
	int indice = lvTiposArticulos.GetSelectedIndex();
	wstring textoListView = lvTiposArticulos.Items[indice].GetText(columna);
	return textoListView;
}

//Metodo que actualiza la información del tipo de articulo seleccionado
void LibreriaAngelDll::tipoArticuloCLS::actualizarTipoArticulo(int id, wstring nombreArticulo, bool articuloActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	int rows = 0;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE tipo_articulo \
		SET nombre='%s'\
		WHERE id=%d;", nombreArticulo.c_str(),id);
		rows = coneccion.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error al actualizar el tipo de artículo", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo que cambia de estado el tipo de articulo
void LibreriaAngelDll::tipoArticuloCLS::cambiarEstadoTipoArticulo(int id, wstring nombreArticulo, bool articuloActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE tipo_articulo \
		SET activo=%d\
		WHERE id=%d", articuloActivo,id);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo que muestra los tipos de articulos
void LibreriaAngelDll::tipoArticuloCLS::mostrarTiposArticulosExistentes(wstring encabezado,Win::ListView lvTipoArticulo, int longuitud,bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvTipoArticulo.DeleteAllItems();
	int rows = 0;
	lvTipoArticulo.SetRedraw(false);
	lvTipoArticulo.Cols.DeleteAll();
	lvTipoArticulo.Items.DeleteAll();
	lvTipoArticulo.SetRedraw(true);
	lvTipoArticulo.Cols.Add(0, LVCFMT_CENTER, 300,encabezado);
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en el list view (Solo muestra los tipos de articulos activos)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM tipo_articulo \
		WHERE activo =%d \
		ORDER BY nombre ASC;",activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvTipoArticulo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}
//Metodo para mostrar los departamentos de colocacion en un DropDownList
void LibreriaAngelDll::reportesCLS::llenarColocacion(Win::DropDownList ddColocacion, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddColocacion.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM colocacion \
		WHERE activo=true\
		ORDER BY tipo ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddColocacion);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}
//Metodo que obtiene el id oculto en los DropDownList
int LibreriaAngelDll::reportesCLS::obtenerIdOculto(Win::DropDownList ddInformacion)
{
	int indice = ddInformacion.GetSelectedIndex();
	int id = ddInformacion.Items[indice].Data;
	return id;
}

//Metodo que pone los puntos de venta activos en un DropDownList
void LibreriaAngelDll::reportesCLS::llenarPuntoVenta(int id,Win::DropDownList ddDepartamento, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddDepartamento.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		Sys::Format(consulta, L"SELECT pv.id, pv.tipo\
		FROM punto_venta pv,puntoventa_colocacion pvc\
		WHERE pv.id=pvc.puntoVenta_id \
		AND pvc.colocacion_id=%d \
		AND pv.activo=true\
		ORDER BY tipo ASC;",id);

		coneccion.ExecuteSelect(consulta, longuitud, ddDepartamento);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que pone los Tipos de Articulo en un DropDownList
void LibreriaAngelDll::reportesCLS::llenarTipoArticulo(Win::DropDownList ddTipoArticulo, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddTipoArticulo.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM tipo_articulo \
		WHERE activo=true\
		ORDER BY nombre ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddTipoArticulo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que muestra los tipo de movimientos en un dropdownlist
void LibreriaAngelDll::reportesCLS::llenarTipoMovimiento(Win::DropDownList ddTipoMovimiento, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddTipoMovimiento.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM tipo_movimiento \
		WHERE activo=true\
		ORDER BY nombre ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddTipoMovimiento);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}
//Metodo que pone las marcas activas en un DropDownList
void LibreriaAngelDll::reportesCLS::llenarMarca(Win::DropDownList ddMarca, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddMarca.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM marca \
		WHERE activo=true\
		ORDER BY nombre ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddMarca);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que pone los modelos activos en un DropDownList
void LibreriaAngelDll::reportesCLS::llenarArticulo(Win::DropDownList ddArticulo, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddArticulo.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM modelo \
		WHERE activo=true\
		ORDER BY nombre ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddArticulo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que genera el reporte de manera general segun el punto de venta seleccionado
void LibreriaAngelDll::reportesCLS::llenarReporteGeneral(Win::ListView lvReporte, int longuitud,int id_punto_venta,bool activo)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);

	lvReporte.Cols.Add(0, LVCFMT_CENTER, 200, L"Código");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 100, L"Àrea");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 100, L"Precio");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Color");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 100, L"Cantidad");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT a.id,a.codigo,pv.tipo,mo.nombre,ma.nombre,a.precio,co.nombre,can.valor \
			FROM articulo a,modelo mo,marca ma,color co,cantidad can,punto_venta pv\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND pv.id=%d\
			AND can.color_id=co.id\
			AND a.activo = %d\
			AND can.valor > 0\
			ORDER BY a.id DESC", id_punto_venta,activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que genera el reporte basado en el tipo de articulo segun el punto de venta seleccionado
void LibreriaAngelDll::reportesCLS::llenarReporteTipoArticulo(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_tipoArticulo, bool activo)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);

	lvReporte.Cols.Add(0, LVCFMT_CENTER, 200, L"Código");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 100, L"Àrea");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 100, L"Precio");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Color");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 100, L"Cantidad");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT a.id,a.codigo,pv.tipo,mo.nombre,ma.nombre,a.precio,co.nombre,can.valor \
			FROM articulo a,modelo mo,marca ma,color co,cantidad can,punto_venta pv,tipo_articulo ta\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND pv.id=%d\
			AND can.color_id=co.id\
			AND a.tipoArticulo_id=ta.id\
			AND ta.id=%d\
			AND a.activo = %d\
			AND can.valor > 0\
			ORDER BY a.id DESC", id_punto_venta, id_tipoArticulo,activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que genera basado en la marca segun el punto de venta seleccionado
void LibreriaAngelDll::reportesCLS::llenarReporteMarca(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_Marca, bool activo)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);

	lvReporte.Cols.Add(0, LVCFMT_CENTER, 200, L"Código");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 100, L"Àrea");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 100, L"Precio");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Color");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 100, L"Cantidad");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT a.id,a.codigo,pv.tipo,mo.nombre,ma.nombre,a.precio,co.nombre,can.valor \
			FROM articulo a,modelo mo,marca ma,color co,cantidad can,punto_venta pv\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND mo.marca_id=%d\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND pv.id=%d\
			AND can.color_id=co.id\
			AND a.activo = %d\
			AND can.valor > 0\
			ORDER BY a.id DESC", id_Marca,id_punto_venta, activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo que genera el reporte basado en el modelo segun el punto de venta seleccionado
void LibreriaAngelDll::reportesCLS::llenarReporteModelo(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_Modelo, bool activo)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);

	lvReporte.Cols.Add(0, LVCFMT_CENTER, 200, L"Código");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 120, L"Àrea");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 80, L"Precio");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Color");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 100, L"Cantidad");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT a.id,a.codigo,pv.tipo,mo.nombre,ma.nombre,a.precio,co.nombre,can.valor \
			FROM articulo a,modelo mo,marca ma,color co,cantidad can,punto_venta pv\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND a.modelo_id=mo.id\
			AND mo.id=%d\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND pv.id=%d\
			AND can.color_id=co.id\
			AND a.activo = %d\
			AND can.valor > 0\
			ORDER BY a.id DESC", id_Modelo, id_punto_venta, activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Constructor del logo
LibreriaAngelDll::Logo::Logo(wstring ruta, int size)
{
	this->sizeVP = size;
	_metafile.Load(ruta.c_str());
}

//Metodo que permite imprimir el logo
void LibreriaAngelDll::Logo::Print(CG::Gdi &gdi, Win::PrintInfo pi)
{
	SIZE size = _metafile.GetSizeIn0_01mm();
	const double logoSize = sizeVP;
	double scale = min(logoSize / (size.cy + 0.5), logoSize / (size.cy + 0.5));
	RECT borde;
	borde.left = pi.pageWidth;
	borde.right = (int)(pi.pageWidth - size.cx*scale + 0.5);
	borde.top = 0;
	borde.bottom = (int)(size.cy*scale + 0.5);
	gdi.DrawMetafile(_metafile, borde);
	gdi.Select(_pen);
}

//Metodo que genera el reporte de movimientos dependiendo del punto de venta y el rango de fecha deseado por el usuario
void LibreriaAngelDll::reportesCLS::llenarReporteMovimientoConColor(Win::ListView lvReporte, int longuitud, int id_punto_venta,int id_tipo_movimiento, Sys::Time inicial, Sys::Time termino, bool activo)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	int rows = 0;

	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);

	lvReporte.Cols.Add(0, LVCFMT_CENTER, 150, L"Código");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 120, L"Àrea");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 80, L"Precio");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Color");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 110, L"Mov");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 100, L"Cantidad");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 140, L"Fecha");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT mov.id,art.codigo,pv.tipo,mdl.nombre,mar.nombre,art.precio,clr.nombre,tm.nombre,mov.cantidad,date_format(fec.fecha, '%%d/%%b/%%Y') \
			FROM movimiento mov,articulo art,modelo mdl,marca mar,punto_venta pv,color clr,tipo_movimiento tm,usuario usu,cantidad ctd,fecha_movimiento fec\
			WHERE mov.articulo_id=art.id\
			AND pv.id=mov.puntoVenta_id\
			AND mov.tipoMovimiento_id=tm.id\
			AND tm.id=%d\
			AND mov.usuario_id=usu.id\
			AND fec.movimiento_id=mov.id\
			AND DATE(fec.fecha) >= '%d-%d-%d'\
			AND DATE(fec.fecha) <= '%d-%d-%d'\
			AND art.modelo_id=mdl.id\
			AND mdl.marca_id=mar.id\
			AND clr.id=ctd.color_id\
			AND ctd.articulo_id=art.id\
			AND pv.id=%d\
			AND mov.cantidad>0\
			AND art.activo=%d\
			ORDER BY fec.fecha DESC", id_tipo_movimiento,inicial.wYear, inicial.wMonth, inicial.wDay,
			termino.wYear, termino.wMonth, termino.wDay, id_punto_venta, activo);
		coneccion.ExecuteSelect(consulta,longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo para obtener el nombre del usuario que genero el reporte
wstring LibreriaAngelDll::reportesCLS::obtenerNombreUsuario(int usuarioId)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	wstring nombreUsuario;

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
			FROM usuario\
			WHERE id = %d", usuarioId);
		coneccion.GetString(consulta,nombreUsuario, 50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	coneccion.CloseSession();
	return nombreUsuario;
}
//version sin color
void LibreriaAngelDll::reportesCLS::llenarReporteMovimiento(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_tipo_movimiento, Sys::Time inicial, Sys::Time termino, bool activo)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	int rows = 0;

	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);

	lvReporte.Cols.Add(0, LVCFMT_CENTER, 150, L"Código");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 120, L"Àrea");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 80, L"Precio");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 110, L"Mov");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 100, L"Cantidad");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 140, L"Fecha");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT mov.id,art.codigo,pv.tipo,mdl.nombre,mar.nombre,art.precio,tm.nombre,mov.cantidad,date_format(fec.fecha, '%%d/%%b/%%Y') \
			FROM movimiento mov,articulo art,modelo mdl,marca mar,punto_venta pv,color clr,tipo_movimiento tm,usuario usu,cantidad ctd,fecha_movimiento fec\
			WHERE mov.articulo_id=art.id\
			AND pv.id=mov.puntoVenta_id\
			AND mov.tipoMovimiento_id=tm.id\
			AND tm.id=%d\
			AND mov.usuario_id=usu.id\
			AND fec.movimiento_id=mov.id\
			AND DATE(fec.fecha) >= '%d-%d-%d'\
			AND DATE(fec.fecha) <= '%d-%d-%d'\
			AND art.modelo_id=mdl.id\
			AND mdl.marca_id=mar.id\
			AND ctd.articulo_id=art.id\
			AND pv.id=%d\
			AND mov.cantidad>0\
			AND art.activo=%d\
			ORDER BY fec.fecha DESC", id_tipo_movimiento, inicial.wYear, inicial.wMonth, inicial.wDay,
			termino.wYear, termino.wMonth, termino.wDay, id_punto_venta, activo);
		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Método para mostrar todos los servicios activos con los que cuenta la empresa en un listview
void LibreriaAngelDll::servicioVentaCLS::mostrarServiciosExistentes(Win::ListView lvServicio, int longuitud, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvServicio.DeleteAllItems();
	int rows = 0;
	lvServicio.SetRedraw(false);
	lvServicio.Cols.DeleteAll();
	lvServicio.Items.DeleteAll();
	lvServicio.SetRedraw(true);
	lvServicio.Cols.Add(0, LVCFMT_CENTER, 50,L"$");
	lvServicio.Cols.Add(1, LVCFMT_CENTER, 200, L"Nombre");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en el list view (Solo muestra los tipos de articulos activos)
		Sys::Format(consulta, L"SELECT id, precio,nombre\
		FROM servicio_venta \
		WHERE activo =%d \
		ORDER BY nombre ASC;", activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvServicio);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo para verificar si un servicio ya existe en la base de datos
wstring LibreriaAngelDll::servicioVentaCLS::sacarServicioSiExiste(wstring servicioVenta)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	wstring existeServicioVenta;

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
			FROM servicio_venta\
			WHERE nombre = '%s'", servicioVenta.c_str());
		coneccion.GetString(consulta, existeServicioVenta, 50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	coneccion.CloseSession();
	return existeServicioVenta;
}

//Metodo que inserta un nuevo servicio
void LibreriaAngelDll::servicioVentaCLS::insertarServicio(wstring servicio, int precio,bool servicioActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO servicio_venta(nombre,precio,activo)VALUES('%s',%d,%d)", servicio.c_str(),precio, servicioActivo);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo que actualiza los datos de un servicio
void LibreriaAngelDll::servicioVentaCLS::actualizarServicio(int id, wstring servicio,int precio, bool servicioActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	int rows = 0;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE servicio_venta \
		SET nombre='%s',\
		precio=%d\
		WHERE id=%d;", servicio.c_str(),precio, id);
		rows = coneccion.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error al actualizar el tipo de artículo", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo que cambia el estado de un servicio segun la opcion del usuario
void LibreriaAngelDll::servicioVentaCLS::cambiarEstadoServicio(int idServicio, bool servicioActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE servicio_venta \
		SET activo=%d\
		WHERE id=%d", servicioActivo, idServicio);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo para mostrar en un listview los rangos activo
void LibreriaAngelDll::rangoCLS::mostrarRangoExistente(Win::ListView lvRango, int longuitud, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvRango.DeleteAllItems();
	int rows = 0;
	lvRango.SetRedraw(false);
	lvRango.Cols.DeleteAll();
	lvRango.Items.DeleteAll();
	lvRango.SetRedraw(true);
	lvRango.Cols.Add(0, LVCFMT_CENTER, 100, L"Mínimo");
	lvRango.Cols.Add(1, LVCFMT_CENTER,100 , L"Máximo");
	lvRango.Cols.Add(2, LVCFMT_CENTER, 100, L"Comisión");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
		Sys::Format(consulta, L"SELECT id, minimo,maximo,comision\
		FROM rango \
		WHERE activo =%d \
		ORDER BY id ASC;", activo);

		coneccion.ExecuteSelect(consulta, longuitud, lvRango);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//Metodo para verificar si un rango ya existe en la base de datos
wstring LibreriaAngelDll::rangoCLS::sacarRangoSiExiste(double minimo,double maximo,double comision)
{
	wstring consulta;
	Sql::SqlConnection coneccion;
	wstring existeRango;

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT minimo\
			FROM rango\
			WHERE minimo = '%f'\
			AND maximo='%f'\
			AND comision='%f'",minimo,maximo,comision);
		coneccion.GetString(consulta, existeRango,50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	coneccion.CloseSession();
	return existeRango;
}

//Metodo que inserta un nuevo rango
void LibreriaAngelDll::rangoCLS::insertaRango(double minimo,double maximo,double comision, bool rangoActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO rango(minimo,maximo,comision,activo)VALUES('%f','%f','%f',%d)", minimo,maximo,comision,rangoActivo);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo que actualiza los datos de un servicio
void LibreriaAngelDll::rangoCLS::actualizarRango(int id, double minimo, double maximo,double comision, bool servicioActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	int rows = 0;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE rango \
		SET minimo='%f',\
		maximo='%f',\
		comision='%f'\
		WHERE id=%d;",minimo,maximo,comision,id);
		rows = coneccion.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error al actualizar el tipo de artículo", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

//Metodo que cambia el estado de un rango segun la opcion del usuario
void LibreriaAngelDll::rangoCLS::cambiarEstadoRango(int idRango, bool rangoActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE rango \
		SET activo=%d\
		WHERE id=%d", rangoActivo, idRango);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}
//Metodo que consulta en un drop downlist los puntos de venta de la empresa
void LibreriaAngelDll::reporteVentasCLS::llenarDepartamento(Win::DropDownList ddColocacion, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddColocacion.DeleteAllItems();

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM punto_venta \
		WHERE activo=true\
		ORDER BY tipo ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddColocacion);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}
//
void LibreriaAngelDll::reporteVentasCLS::llenarRegion(Win::DropDownList ddRegion, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddRegion.DeleteAllItems();
	ddRegion.Items.Add(L"Todas las regiones");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM region \
		WHERE activo=true\
		ORDER BY nombre ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddRegion);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

void LibreriaAngelDll::reporteVentasCLS::llenarRequerimiento(Win::DropDownList ddRequerimiento, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddRequerimiento.DeleteAllItems();
	ddRequerimiento.Items.Add(L"Todo");

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM requerimiento \
		WHERE activo=true\
		ORDER BY tipo ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddRequerimiento);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}
//
void LibreriaAngelDll::reporteVentasCLS::llenarCiudad(Win::DropDownList ddCiudad, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddCiudad.DeleteAllItems();
	ddCiudad.Items.Add(L"Todas las ciudades");

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM ciudad \
		WHERE activo=true\
		ORDER BY nombre ASC;");

		coneccion.ExecuteSelect(consulta, longuitud, ddCiudad);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//
void LibreriaAngelDll::reporteVentasCLS::llenarCiudad(Win::DropDownList ddCiudad, int regionId, int longuitud)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddCiudad.DeleteAllItems();
	ddCiudad.Items.Add(L"Todas las ciudades");

	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT ciu.id, ciu.nombre\
		FROM ciudad ciu,lada la,region re \
		WHERE ciu.lada_id=la.id\
		AND la.region_id=re.id\
		AND re.id=%d\
		AND ciu.activo=true\
		ORDER BY ciu.nombre ASC;",regionId);

		coneccion.ExecuteSelect(consulta, longuitud, ddCiudad);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	coneccion.CloseSession();
}

//LLenar reporte general
void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasGeneral(Win::ListView lvReporte,int idRequerimiento,int longuitud,bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvReporte.DeleteAllItems();
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);
	lvReporte.Cols.Add(0, LVCFMT_CENTER, 100, L"Folio");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 100, L"Cliente");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 100, L"S/A");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Tipo");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 100, L"Cantidad");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 100, L"Precio Sugerido");
	lvReporte.Cols.Add(9, LVCFMT_CENTER, 100, L"Precio Final");
	lvReporte.Cols.Add(10, LVCFMT_CENTER, 100, L"Total");
	lvReporte.Cols.Add(11, LVCFMT_CENTER, 100, L"Fecha");
	//reporte general de todos los requerimientos
	if (idRequerimiento == 0)
	{
		try
		{
			coneccion.OpenSession(hWnd, CONNECTION_STRING);

			//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
			Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
				, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final, o.fecha\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				servicio_requerimiento sr, servicio_venta sv\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND sr.requerimiento_id = r.id\
				AND sr.servicioVenta_id = sv.id\
				AND sv.id = od.tipoVentaId\
				UNION\
				SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, mo.nombre, ma.nombre,\
				od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final, o.fecha\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND cr.requerimiento_id = r.id\
				AND cr.cantidad_id = can.id\
				AND can.articulo_id = a.id\
				AND a.modelo_id = mo.id\
				AND mo.marca_id = ma.id\
				AND a.tipoArticulo_id = ta.id\
				AND a.id = od.tipoVentaId;");
			coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
		}
		catch (Sql::SqlException e)
		{
			this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		}
	}
	else
	{
		try
		{
			coneccion.OpenSession(hWnd, CONNECTION_STRING);

			//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
			Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre,\
			od.cantidad,od.precio_sugerido,od.precio_final,od.cantidad*od.precio_final,o.fecha\
		FROM orden o,orden_descripcion od,cliente c,clave_cliente cc,punto_venta pv,requerimiento r,\
			servicio_requerimiento sr, servicio_venta sv \
		WHERE od.orden_id=o.id\
			AND o.cliente_id = c.id\
			AND cc.cliente_id = c.id\
			AND o.puntoVenta_id = pv.id\
			AND od.requerimiento_id = r.id\
			AND sr.requerimiento_id = r.id\
			AND r.id=%d\
			AND sr.servicioVenta_id = sv.id\
			AND sv.id = od.tipoVentaId\
		UNION\
		SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero),r.tipo,mo.nombre,\
			od.cantidad,od.precio_sugerido,od.precio_final,od.cantidad*od.precio_final,o.fecha\
		FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
			cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma\
		WHERE od.orden_id = o.id\
			AND o.cliente_id = c.id\
			AND cc.cliente_id = c.id\
			AND o.puntoVenta_id = pv.id\
			AND od.requerimiento_id = r.id\
			AND cr.requerimiento_id = r.id\
			AND r.id=%d\
			AND cr.cantidad_id = can.id\
			AND can.articulo_id = a.id\
			AND a.modelo_id = mo.id\
			AND a.id = od.tipoVentaId;",idRequerimiento,idRequerimiento);

			coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
		}
		catch (Sql::SqlException e)
		{
			this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		}
	}
	

	coneccion.CloseSession();
}

//LLenar reporte general con fecha
void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasGeneral(Win::ListView lvReporte, int idRequerimiento, int longuitud, Sys::Time inicial, Sys::Time termino, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvReporte.DeleteAllItems();
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);
	lvReporte.Cols.Add(0, LVCFMT_CENTER, 85, L"Folio");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 125, L"Cliente");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 60, L"S/A");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 125, L"Tipo");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 85, L"Marca");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 60, L"Cant");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 60, L"P/Sug");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 60, L"P/Final");
	lvReporte.Cols.Add(9, LVCFMT_CENTER, 60, L"Total");
	lvReporte.Cols.Add(10, LVCFMT_CENTER, 70, L"Fecha");
	//reporte general de todos los requerimientos
	if (idRequerimiento == 0)
	{
		try
		{
			coneccion.OpenSession(hWnd, CONNECTION_STRING);

			//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
			Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
				, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final, DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				servicio_requerimiento sr, servicio_venta sv\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND sr.requerimiento_id = r.id\
				AND sr.servicioVenta_id = sv.id\
				AND sv.id = od.tipoVentaId\
				AND DATE(o.fecha) >= '%d-%d-%d'\
				AND DATE(o.fecha) <= '%d-%d-%d'\
				UNION\
				SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
				od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND cr.requerimiento_id = r.id\
				AND cr.cantidad_id = can.id\
				AND can.articulo_id = a.id\
				AND a.modelo_id = mo.id\
				AND mo.marca_id = ma.id\
				AND a.tipoArticulo_id = ta.id\
				AND a.id = od.tipoVentaId\
				AND DATE(o.fecha) >= '%d-%d-%d'\
				AND DATE(o.fecha) <= '%d-%d-%d';",inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay,inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
			coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
		}
		catch (Sql::SqlException e)
		{
			this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		}
	}
	else
	{
		try
		{
			coneccion.OpenSession(hWnd, CONNECTION_STRING);

			//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
			Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
				, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				servicio_requerimiento sr, servicio_venta sv\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND sr.requerimiento_id = r.id\
				AND r.id=%d\
				AND sr.servicioVenta_id = sv.id\
				AND sv.id = od.tipoVentaId\
				AND DATE(o.fecha) >= '%d-%d-%d'\
				AND DATE(o.fecha) <= '%d-%d-%d'\
				UNION\
				SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
				od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND cr.requerimiento_id = r.id\
				AND r.id=%d\
				AND cr.cantidad_id = can.id\
				AND can.articulo_id = a.id\
				AND a.modelo_id = mo.id\
				AND mo.marca_id = ma.id\
				AND a.tipoArticulo_id = ta.id\
				AND a.id = od.tipoVentaId\
				AND DATE(o.fecha) >= '%d-%d-%d'\
				AND DATE(o.fecha) <= '%d-%d-%d';", idRequerimiento, inicial.wYear, inicial.wMonth, inicial.wDay,termino.wYear, termino.wMonth, termino.wDay, idRequerimiento, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);

			coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
		}
		catch (Sql::SqlException e)
		{
			this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		}
	}


	coneccion.CloseSession();
}

//Método que llena el reporte por departamento
void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasDepartamento(Win::ListView lvReporte, int idPuntoVenta, int idRegion, int idCiudad,int idRequerimiento, int longuitud, Sys::Time inicial, Sys::Time termino,bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvReporte.DeleteAllItems();
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);
	lvReporte.Cols.Add(0, LVCFMT_CENTER, 85, L"Folio");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 125, L"Cliente");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 60, L"S/A");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 125, L"Tipo");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 85, L"Marca");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 60, L"Cant");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 60, L"P/Sug");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 60, L"P/Final");
	lvReporte.Cols.Add(9, LVCFMT_CENTER, 60, L"Total");
	lvReporte.Cols.Add(10, LVCFMT_CENTER, 70, L"Fecha");
	//Todas las regiones
	if (idRegion == 0)
	{
		//Todas la ciudades de todas las regiones
		if (idCiudad == 0)
		{
			//Todos los requerimientos de todas las ciudades de todas las regiones
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
				, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				servicio_requerimiento sr, servicio_venta sv\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
				od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idPuntoVenta, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//Un requerimiento especifico de todas las ciudades de todas las regiones
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
					cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id=ta.id\
						AND a.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\;", idPuntoVenta,idRequerimiento, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay,idPuntoVenta,idRequerimiento, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}
		//Una ciudad específica
		else
		{
			//Todo los requerimientos de una ciudad de todas las regiones 
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,ciudad ciu\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						ciudad ciu\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta,idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay,idPuntoVenta,idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//Un requerimirno especifico de una ciudad especifica de todas las regiones
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,ciudad ciu\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						ciudad ciu\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta, idRequerimiento,idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay,idPuntoVenta,idRequerimiento,idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}
	}
	//Region especifica
	else
	{
		//Todas las ciudades de un region
		if (idCiudad == 0)
		{
			//Todos los requerimiento de todas las ciudades de una region
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta,idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idPuntoVenta, idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//un requerimiento especifico de todas las ciudades de una region
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta,idRequerimiento, idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay,idPuntoVenta,idRequerimiento, idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}
		//Ciudad especifica de una region
		else
		{
			//Todos los requerimiento de un ciudad especifica de una region
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta, idRegion,idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay,idPuntoVenta, idRegion,idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//Unrequerimiento especifoc de una ciudad especifica de una region
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND pv.id=%d\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idPuntoVenta,idRequerimiento, idRegion, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idPuntoVenta,idRequerimiento, idRegion, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}

	}


	coneccion.CloseSession();
}

//Método que llena el reporte por ciudad
void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasCiudad(Win::ListView lvReporte,int idRegion, int idCiudad, int idRequerimiento, int longuitud, Sys::Time inicial, Sys::Time termino,bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvReporte.DeleteAllItems();
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);
	lvReporte.Cols.Add(0, LVCFMT_CENTER, 85, L"Folio");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 125, L"Cliente");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 60, L"S/A");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 125, L"Tipo");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 85, L"Marca");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 60, L"Cant");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 60, L"P/Sug");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 60, L"P/Final");
	lvReporte.Cols.Add(9, LVCFMT_CENTER, 60, L"Total");
	lvReporte.Cols.Add(10, LVCFMT_CENTER, 70, L"Fecha");
	//Todas las regiones
	if (idRegion == 0)
	{
		//Todas la ciudades de todas las regiones
		if (idCiudad == 0)
		{
			//Todos los requerimientos de todas las ciudades de todas las regiones
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
				, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				servicio_requerimiento sr, servicio_venta sv\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
				od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//Un requerimiento especifico de todas las ciudades de todas las regiones
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
					cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id=ta.id\
						AND a.id = od.tipoVentaId\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\;",idRequerimiento, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idRequerimiento, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}
		//Una ciudad específica
		else
		{
			//Todo los requerimientos de una ciudad de todas las regiones 
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,ciudad ciu\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						ciudad ciu\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';",idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//Un requerimirno especifico de una ciudad especifica de todas las regiones
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,ciudad ciu\
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						ciudad ciu\
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idRequerimiento, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idRequerimiento, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}
	}
	//Region especifica
	else
	{
		//Todas las ciudades de un region
		if (idCiudad == 0)
		{
			//Todos los requerimiento de todas las ciudades de una region
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//un requerimiento especifico de todas las ciudades de una region
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idRequerimiento, idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idRequerimiento, idRegion, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}
		//Ciudad especifica de una region
		else
		{
			//Todos los requerimiento de un ciudad especifica de una region
			if (idRequerimiento == 0)
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idRegion, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idRegion, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
			//Unrequerimiento especifoc de una ciudad especifica de una region
			else
			{
				try
				{
					coneccion.OpenSession(hWnd, CONNECTION_STRING);

					//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
					Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
						, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						servicio_requerimiento sr, servicio_venta sv,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id=o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND sr.requerimiento_id = r.id\
						AND r.id=%d\
						AND sr.servicioVenta_id = sv.id\
						AND sv.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d'\
					UNION\
					SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
						od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,  DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
					FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
						cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col,\
						region re,lada la,ciudad ciu \
					WHERE od.orden_id = o.id\
						AND o.cliente_id = c.id\
						AND cc.cliente_id = c.id\
						AND o.puntoVenta_id = pv.id\
						AND od.requerimiento_id = r.id\
						AND cr.requerimiento_id = r.id\
						AND r.id=%d\
						AND cr.cantidad_id = can.id\
						AND can.articulo_id = a.id\
						AND a.modelo_id = mo.id\
						AND mo.marca_id = ma.id\
						AND a.tipoArticulo_id = ta.id\
						AND a.id = od.tipoVentaId\
						AND c.ciudad_id=ciu.id\
						AND ciu.lada_id=la.id\
						AND la.region_id=re.id\
						AND re.id = '%d'\
						AND ciu.id='%d'\
						AND DATE(o.fecha) >= '%d-%d-%d'\
						AND DATE(o.fecha) <= '%d-%d-%d';", idRequerimiento, idRegion, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay, idRequerimiento, idRegion, idCiudad, inicial.wYear, inicial.wMonth, inicial.wDay, termino.wYear, termino.wMonth, termino.wDay);
					coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
				}
				catch (Sql::SqlException e)
				{
					this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
				}
			}
		}

	}


	coneccion.CloseSession();
}

//LLenar reporte por orden de compra
void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasOrdenCompra(Win::ListView lvReporte, wstring folio, int longuitud, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	lvReporte.DeleteAllItems();
	int rows = 0;
	lvReporte.SetRedraw(false);
	lvReporte.Cols.DeleteAll();
	lvReporte.Items.DeleteAll();
	lvReporte.SetRedraw(true);
	lvReporte.Cols.Add(0, LVCFMT_CENTER, 85, L"Folio");
	lvReporte.Cols.Add(1, LVCFMT_CENTER, 125, L"Cliente");
	lvReporte.Cols.Add(2, LVCFMT_CENTER, 60, L"S/A");
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 125, L"Tipo");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 85, L"Marca");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 60, L"Cant");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 60, L"P/Sug");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 60, L"P/Final");
	lvReporte.Cols.Add(9, LVCFMT_CENTER, 60, L"Total");
	lvReporte.Cols.Add(10, LVCFMT_CENTER, 70, L"Fecha");
	//reporte general de todos los requerimientos
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
		Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
				, 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final, o.fecha\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				servicio_requerimiento sr, servicio_venta sv\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND sr.requerimiento_id = r.id\
				AND sr.servicioVenta_id = sv.id\
				AND sv.id = od.tipoVentaId\
				AND o.folio='%s'\
				UNION\
				SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, ma.nombre, mo.nombre,\
				od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final, o.fecha\
				FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
				cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
				WHERE od.orden_id = o.id\
				AND o.cliente_id = c.id\
				AND cc.cliente_id = c.id\
				AND o.puntoVenta_id = pv.id\
				AND od.requerimiento_id = r.id\
				AND cr.requerimiento_id = r.id\
				AND cr.cantidad_id = can.id\
				AND can.articulo_id = a.id\
				AND a.modelo_id = mo.id\
				AND mo.marca_id = ma.id\
				AND a.tipoArticulo_id = ta.id\
				AND a.id = od.tipoVentaId\
				AND o.folio='%s';",folio.c_str(),folio.c_str());

		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}