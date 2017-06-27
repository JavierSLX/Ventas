#include "stdafx.h"  //_____________________________________________ LibreriaJRDll.cpp
#include "LibreriaJRDll.h"


//__________________________________________ CLASE WINTEMPLACLS
//Método que llena todos los punto de venta existentes en la base de datos
void LibreriaJRDll::WintemplaCLS::llenarLVPuntoVenta(Win::ListView lvTabla, bool activo, int size)
{
	Sql::SqlConnection conn;

	wstring consulta;

	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Se define los nombres de las columnas
		lvTabla.Cols.Add(0, LVCFMT_LEFT, 200, L"Nombre");

		//Ejecuta la consulta en la listview (Solo muestra los disponibles)
		Sys::Format(consulta, L"SELECT id, tipo \
		FROM punto_venta \
		WHERE activo = %d\
		ORDER BY tipo ASC", activo);
		conn.ExecuteSelect(consulta, size, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Saca la id oculto en cualquier listview, lo regresa
int LibreriaJRDll::WintemplaCLS::sacarIDOcultoLV(Win::ListView lvTabla)
{
	int indice = lvTabla.GetSelectedIndex();
	int id = lvTabla.Items[indice].Data;

	return id;
}

//Saca el id oculto en cualquier drop down list, lo regresa
int LibreriaJRDll::WintemplaCLS::sacarIDOcultoDdl(Win::DropDownList ddLista)
{
	int indice = ddLista.GetSelectedIndex();
	int id = ddLista.Items[indice].Data;

	return id;
}

//Saca una cadena en una determinada celda de listview, lo regresa
wstring LibreriaJRDll::WintemplaCLS::sacarTextoLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring nombre = lvTabla.Items[s].GetText(columna);

	return nombre;
}

//Saca una lista de marcas de un determinado tipo de articulo
void LibreriaJRDll::WintemplaCLS::sacarListaMarcas(Win::DropDownList ddMarca, wstring punto_venta, wstring tipo_articulo, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddMarca.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		wstring agregado;
		
		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT a.id, ma.nombre\
		FROM cantidad c, articulo a, modelo m, marca ma, tipo_articulo ta, punto_venta pv\
		WHERE c.articulo_id = a.id\
		AND a.modelo_id = m.id\
		AND ma.id = m.marca_id\
		AND ta.id = a.tipoArticulo_id\
		AND pv.id = c.puntoVenta_id\
		AND c.valor > 0\
		AND a.activo = true\
		AND ta.nombre = '%s'", tipo_articulo.c_str());

		if (punto_venta.length() > 0)
		{
			Sys::Format(agregado, L"AND pv.tipo = '%s'\
			ORDER BY ma.nombre ASC;", punto_venta.c_str());
		}
		else
			agregado = L"ORDER BY ma.nombre ASC;";

		consulta += agregado;
		conn.ExecuteSelect(consulta, size, ddMarca);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddMarca.SetSelectedIndex(0);
	conn.CloseSession();
}

//Saca una lista de las cantidad de marcas de cierto tipo de articulo registrado en un determinado departamento
void LibreriaJRDll::WintemplaCLS::sacarListaCantidadMarcas(Win::DropDownList ddCantidad, wstring punto_venta, wstring tipo_articulo, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddCantidad.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		wstring agregado;
		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT a.id,\
		(SELECT SUM(can.valor)\
			FROM articulo art, cantidad can\
			WHERE can.articulo_id = art.id\
			AND art.id = a.id) \
		FROM cantidad c, articulo a, modelo m, marca ma, tipo_articulo ta, punto_venta pv\
		WHERE c.articulo_id = a.id\
		AND a.modelo_id = m.id\
		AND ma.id = m.marca_id\
		AND ta.id = a.tipoArticulo_id\
		AND pv.id = c.puntoVenta_id\
		AND c.valor > 0\
		AND a.activo = true\
		AND ta.nombre = '%s'", tipo_articulo.c_str());

		if (punto_venta.length() > 0)
		{
			Sys::Format(agregado, L"AND pv.tipo = '%s'\
			ORDER BY ma.nombre ASC;", punto_venta.c_str());
		}
		else
			agregado = L"ORDER BY ma.nombre ASC;";

		consulta += agregado;
		conn.ExecuteSelect(consulta, size, ddCantidad);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddCantidad.SetSelectedIndex(0);
	conn.CloseSession();
}

//Saca una lista de tipo de articulos que contiene al menos un artículo
void LibreriaJRDll::WintemplaCLS::sacarListaTipoArticulos(Win::DropDownList ddTipo, wstring punto_venta, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddTipo.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		wstring agregado;

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT ta.id, ta.nombre\
		FROM articulo a, tipo_articulo ta, cantidad c, punto_venta pv\
		WHERE a.tipoArticulo_id = ta.id\
		AND a.id = c.articulo_id\
		AND c.puntoVenta_id = pv.id\
		AND c.valor > 0\
		AND a.activo = true ");

		if (punto_venta.length() > 0)
		{
			Sys::Format(agregado, L"AND pv.tipo = '%s'\
				ORDER BY ta.nombre ASC;", punto_venta.c_str());
		}
		else
			agregado = L"ORDER BY ta.nombre ASC;";

		consulta += agregado;
		conn.ExecuteSelect(consulta, size, ddTipo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddTipo.SetSelectedIndex(0);
	conn.CloseSession();
}

//Saca una lista de las cantidades que contienen cada tipo de articulo en cierto punto_venta
void LibreriaJRDll::WintemplaCLS::sacarListaCantidadTipoArticulos(Win::DropDownList ddCantidad, wstring punto_venta, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;
	wstring agregado;

	//Borra todos los posibles elementos que puedan ya existir
	ddCantidad.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT ta.id, \
		(SELECT SUM(cant.valor) \
		FROM cantidad cant, punto_venta pvt, tipo_articulo tat, articulo art \
		WHERE cant.puntoVenta_id = pvt.id \
		AND tat.id = art.tipoArticulo_id \
		AND art.id = cant.articulo_id ");

		if (punto_venta.length() > 0)
		{
			Sys::Format(agregado, L"AND tat.id = ta.id\
			AND pvt.tipo = pv.tipo)\
			FROM articulo a, tipo_articulo ta, cantidad c, punto_venta pv \
			WHERE a.tipoArticulo_id = ta.id \
			AND a.id = c.articulo_id \
			AND c.puntoVenta_id = pv.id \
			AND c.valor > 0 \
			AND a.activo = true \
			AND pv.tipo = '%s' \
			ORDER BY ta.nombre ASC;", punto_venta.c_str());
		}
		else
		{
			Sys::Format(agregado, L"AND tat.id = ta.id)\
			FROM articulo a, tipo_articulo ta, cantidad c, punto_venta pv \
			WHERE a.tipoArticulo_id = ta.id \
			AND a.id = c.articulo_id \
			AND c.puntoVenta_id = pv.id \
			AND c.valor > 0 \
			AND a.activo = true \
			ORDER BY ta.nombre ASC;");
		}

		consulta += agregado;
		conn.ExecuteSelect(consulta, size, ddCantidad);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddCantidad.SetSelectedIndex(0);
	conn.CloseSession();
}

//Saca una lista de los movimientos que se hicieron de los articulos de ciertos puntos de venta
void LibreriaJRDll::WintemplaCLS::sacarListaMovimientos(Win::DropDownList ddTipo, wstring movimiento, wstring punto_venta, Sys::Time inicial, Sys::Time termino, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddTipo.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		wstring agregado;

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT ta.id, ta.nombre\
		FROM movimiento m, fecha_movimiento fm, tipo_movimiento tm, punto_venta pv, articulo a, tipo_articulo ta\
		WHERE fm.movimiento_id = m.id\
		AND tm.id = m.tipoMovimiento_id\
		AND m.puntoVenta_id = pv.id\
		AND m.articulo_id = a.id\
		AND ta.id = a.tipoArticulo_id\
		AND ta.activo = true\
		AND m.cantidad > 0\
		AND tm.nombre = '%s'\
		AND fm.fecha > '%d-%d-%d 00:00:00'\
		AND fm.fecha < '%d-%d-%d 23:59:59' ", movimiento.c_str(), inicial.wYear, inicial.wMonth, inicial.wDay,
			termino.wYear, termino.wMonth, termino.wDay);

		if (punto_venta.length() > 0)
		{
			Sys::Format(agregado, L"AND pv.tipo = '%s'\
				ORDER BY ta.nombre ASC;", punto_venta.c_str());
		}
		else
			agregado = L"ORDER BY ta.nombre ASC;";

		consulta += agregado;
		conn.ExecuteSelect(consulta, size, ddTipo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddTipo.SetSelectedIndex(0);
	conn.CloseSession();
}

//Saca una lista de la cantidad de los movimientos que se hicieron de los articulos de ciertos puntos de venta
void LibreriaJRDll::WintemplaCLS::sacarListaCantidadMovimientos(Win::DropDownList ddCantidad, wstring movimiento, wstring punto_venta, Sys::Time inicial, Sys::Time termino, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;
	wstring agregado;

	//Borra todos los posibles elementos que puedan ya existir
	ddCantidad.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT ta.id, \
		(SELECT SUM(mov.cantidad)\
		FROM movimiento mov, fecha_movimiento fmv, tipo_movimiento tmv, punto_venta pvt, articulo art, tipo_articulo tar\
		WHERE mov.id = fmv.movimiento_id\
		AND tmv.id = mov.tipoMovimiento_id\
		AND pvt.id = mov.puntoVenta_id\
		AND art.id = mov.articulo_id\
		AND tar.id = art.tipoArticulo_id\
		AND tar.activo = true\
		AND mov.cantidad > 0\
		AND tmv.nombre = tm.nombre\
		AND fmv.fecha > '%d-%d-%d 00:00:00'\
		AND fmv.fecha < '%d-%d-%d 23:59:59'", inicial.wYear, inicial.wMonth, inicial.wDay,
			termino.wYear, termino.wMonth, termino.wDay);

		if (punto_venta.length() > 0)
		{
			Sys::Format(agregado, L"AND pvt.tipo = pv.tipo\
			AND tar.nombre = ta.nombre)\
			FROM movimiento m, fecha_movimiento fm, tipo_movimiento tm, punto_venta pv, articulo a, tipo_articulo ta\
			WHERE fm.movimiento_id = m.id\
			AND tm.id = m.tipoMovimiento_id\
			AND m.puntoVenta_id = pv.id\
			AND m.articulo_id = a.id\
			AND ta.id = a.tipoArticulo_id\
			AND ta.activo = true\
			AND m.cantidad > 0\
			AND tm.nombre = '%s'\
			AND fm.fecha > '%d-%d-%d 00:00:00'\
			AND fm.fecha < '%d-%d-%d 23:59:59'\
			AND pv.tipo = '%s'\
			ORDER BY ta.nombre ASC;", movimiento.c_str(), inicial.wYear, inicial.wMonth, inicial.wDay,
				termino.wYear, termino.wMonth, termino.wDay, punto_venta.c_str());
		}
		else
		{
			Sys::Format(agregado, L"AND tar.nombre = ta.nombre)\
			FROM movimiento m, fecha_movimiento fm, tipo_movimiento tm, punto_venta pv, articulo a, tipo_articulo ta\
			WHERE fm.movimiento_id = m.id\
			AND tm.id = m.tipoMovimiento_id\
			AND m.puntoVenta_id = pv.id\
			AND m.articulo_id = a.id\
			AND ta.id = a.tipoArticulo_id\
			AND ta.activo = true\
			AND m.cantidad > 0\
			AND tm.nombre = '%s'\
			AND fm.fecha > '%d-%d-%d 00:00:00'\
			AND fm.fecha < '%d-%d-%d 23:59:59'\
			ORDER BY ta.nombre ASC;", movimiento.c_str(), inicial.wYear, inicial.wMonth, inicial.wDay,
				termino.wYear, termino.wMonth, termino.wDay);
		}

		consulta += agregado;
		conn.ExecuteSelect(consulta, size, ddCantidad);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddCantidad.SetSelectedIndex(0);
	conn.CloseSession();
}

//Saca la cantidad máxima de una lista
double LibreriaJRDll::WintemplaCLS::sacaValorMaximo(Win::DropDownList ddCantidad)
{
	double maximo = Sys::Convert::ToDouble(ddCantidad.Items[0].Text);

	for (int j = 1; j < ddCantidad.GetItemCount(); j++)
		if (Sys::Convert::ToDouble(ddCantidad.Items[j].Text) > maximo)
			maximo = Sys::Convert::ToDouble(ddCantidad.Items[j].Text);

	return maximo;
}

//Método que llena todas los punto de venta según una búsqueda
void LibreriaJRDll::WintemplaCLS::llenarLVPuntoVentaBusqueda(Win::ListView lvTabla, wstring texto, bool activo, int size)
{
	Sql::SqlConnection conn;

	wstring consulta;

	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Se define los nombres de las columnas
		lvTabla.Cols.Add(0, LVCFMT_LEFT, 200, L"Nombre");

		//Ejecuta la consulta en la listview (Solo muestra los disponibles)
		Sys::Format(consulta, L"SELECT id, tipo \
		FROM punto_venta \
		WHERE activo = %d\
		AND tipo LIKE '%s%%'\
		ORDER BY tipo ASC", activo, texto.c_str());
		conn.ExecuteSelect(consulta, size, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que llena la drop down list con los tipos de punto de venta registrados
void LibreriaJRDll::WintemplaCLS::llenarDdPuntoVenta(Win::DropDownList ddVenta, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddVenta.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM punto_venta \
		ORDER BY tipo ASC;");

		conn.ExecuteSelect(consulta, size, ddVenta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddVenta.SetSelectedIndex(0);
	conn.CloseSession();
}

//Método que llena la drop down list con los tipos generales de categorias en la empresa
void LibreriaJRDll::WintemplaCLS::llenarDdColocacion(Win::DropDownList ddColocacion, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddColocacion.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM colocacion \
		WHERE activo = true\
		ORDER BY tipo ASC;");

		conn.ExecuteSelect(consulta, size, ddColocacion);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddColocacion.SetSelectedIndex(0);
	conn.CloseSession();
}

//Método que llena la drop down list con los tipos de artículos registrados en la base de datos
void LibreriaJRDll::WintemplaCLS::llenarDdTipoArticulo(Win::DropDownList ddTipo, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddTipo.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM tipo_articulo \
		WHERE activo = true\
		ORDER BY nombre ASC;");

		conn.ExecuteSelect(consulta, size, ddTipo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddTipo.SetSelectedIndex(0);
	conn.CloseSession();
}

//Método que llena la drop down list con las ciudades registradas en la base de datos
void LibreriaJRDll::WintemplaCLS::llenarDdCiudad(Win::DropDownList ddCiudad, bool activo, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddCiudad.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM ciudad \
		WHERE activo = %d\
		ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, size, ddCiudad);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddCiudad.SetSelectedIndex(0);
	conn.CloseSession();
}

//Método que llena una gráfica de pastel con los datos correspondientes al inventario
void LibreriaJRDll::WintemplaCLS::llenarPastelInventario(wstring opcion)
{
	Win::DropDownList lista;
	
}

//__________________________________________ CLASE SQLCLS
//Saca el id de un registro de la tabla punto_venta, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDPuntoVenta(wstring nombre)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int categoria_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id \
			FROM punto_venta \
			WHERE tipo = '%s'", nombre.c_str());
		categoria_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		categoria_id = 0;
	}

	conn.CloseSession();

	return categoria_id;
}

//Saca el id de un registro de la tabla colocacion, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDColocacion(int puntoVenta_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int colocacion_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.id \
		FROM colocacion c, puntoVenta_colocacion pc \
		WHERE c.id = pc.colocacion_id\
		AND pc.puntoVenta_id = %d", puntoVenta_id);
		colocacion_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		colocacion_id = 0;
	}

	conn.CloseSession();

	return colocacion_id;
}

//Saca el id de un registro de la tabla colocacion, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDColocacion(wstring tipo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int colocacion_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
		FROM colocacion\
		WHERE tipo = '%s'", tipo.c_str());
		colocacion_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		colocacion_id = 0;
	}

	conn.CloseSession();

	return colocacion_id;
}

//Saca el id de un registro de la tabla puntoVenta_colocacion, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDPuntoVentaColocacion(int puntoVenta_id, int colocacion_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int estandar_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id \
		FROM puntoVenta_colocacion\
		WHERE puntoVenta_id = %d\
		AND colocacion_id = %d", puntoVenta_id, colocacion_id);
		estandar_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		estandar_id = 0;
	}

	conn.CloseSession();

	return estandar_id;
}

//Saca el tipo de un registro de la tabla colocacion
wstring LibreriaJRDll::SqlCLS::sacarTipoColocacion(wstring punto_venta)
{
	wstring colocacion;
	wstring consulta;
	Sql::SqlConnection conn;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.tipo \
		FROM punto_venta p, colocacion c, puntoVenta_colocacion pc \
		WHERE p.id = pc.puntoVenta_id \
		AND c.id = pc.colocacion_id\
		AND p.tipo = '%s'", punto_venta.c_str());
		conn.GetString(consulta, colocacion, 100);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return colocacion;
}

//Método que actualiza un registro de la tabla punto_venta dado por su id
void LibreriaJRDll::SqlCLS::actualizarPuntoVenta(int categoria_id, wstring nombre)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE punto_venta \
		SET tipo = '%s' \
		WHERE id = %d", nombre.c_str(), categoria_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que actualiza un estado de un registro de la tabla punto_venta dado por su id
void LibreriaJRDll::SqlCLS::actualizarPuntoVenta(int categoria_id, bool estado)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE punto_venta \
		SET activo = %d \
		WHERE id = %d", estado, categoria_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que actualiza un registro de la tabla puntoVenta_colocacion dado por su id
void LibreriaJRDll::SqlCLS::actualizarPuntoVentaColocacion(int puntoVentaColocacion_id, int puntoVenta_id, int colocacion_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE puntoVenta_colocacion \
		SET puntoVenta_id = %d, colocacion_id = %d \
		WHERE id = %d", puntoVenta_id, colocacion_id, puntoVentaColocacion_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que inserta un registro en la tabla punto_venta
void LibreriaJRDll::SqlCLS::insertarPuntoVenta(wstring nombre)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO punto_venta (tipo, activo) \
		VALUES('%s', true)", nombre.c_str());
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of inserted rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que inserta un registro en la tabla colocacion
void LibreriaJRDll::SqlCLS::insertarColocacion(wstring tipo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO colocacion (tipo, activo) \
		VALUES('%s', true)", tipo.c_str());
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of inserted rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que inserta un registro en la tabla puntoVenta_colocacion
void LibreriaJRDll::SqlCLS::insertarPuntoVentaColocacion(int puntoVenta_id, int colocacion_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO puntoVenta_colocacion (puntoVenta_id, colocacion_id) \
		VALUES(%d, %d)", puntoVenta_id, colocacion_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of inserted rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//__________________________________________ CLASE COLORCLS
//Método que regreso valores RGB distintos
void LibreriaJRDll::ColorCLS::obtenerColor(int index, int *R, int *G, int *B)
{
	switch (index)
	{
	case 0:
		*R = 255;
		*G = 0;
		*B = 0;
		break;
	case 1:
		*R = 255;
		*G = 255;
		*B = 0;
		break;
	case 2:
		*R = 50;
		*G = 205;
		*B = 50;
		break;
	case 3:
		*R = 255;
		*G = 192;
		*B = 203;
		break;
	case 4:
		*R = 0;
		*G = 255;
		*B = 255;
		break;
	case 5:
		*R = 188;
		*G = 143;
		*B = 143;
		break;
	case 6:
		*R = 47;
		*G = 79;
		*B = 79;
		break;
	case 7:
		*R = 102;
		*G = 205;
		*B = 170;
		break;
	case 8:
		*R = 255;
		*G = 218;
		*B = 185;
		break;
	case 9:
		*R = 176;
		*G = 196;
		*B = 222;
		break;
	case 10:
		*R = 139;
		*G = 69;
		*B = 19;
		break;
	case 11:
		*R = 221;
		*G = 160;
		*B = 221;
		break;
	case 12:
		*R = 255;
		*G = 69;
		*B = 0;
		break;
	case 13:
		*R = 0;
		*G = 128;
		*B = 128;
		break;
	case 14:
		*R = 205;
		*G = 92;
		*B = 92;
		break;
	case 15:
		*R = 0;
		*G = 206;
		*B = 209;
		break;
	case 16:
		*R = 128;
		*G = 0;
		*B = 0;
		break;
	case 17:
		*R = 255;
		*G = 0;
		*B = 255;
		break;
	case 18:
		*R = 154;
		*G = 205;
		*B = 50;
		break;
	case 19:
		*R = 219;
		*G = 165;
		*B = 32;
		break;
	case 20:
		*R = 255;
		*G = 20;
		*B = 147;
		break;
	case 21:
		*R = 255;
		*G = 215;
		*B = 0;
		break;
	case 22:
		*R = 64;
		*G = 224;
		*B = 208;
		break;
	case 23:
		*R = 255;
		*G = 222;
		*B = 173;
		break;
	case 24:
		*R = 169;
		*G = 183;
		*B = 107;
		break;
	case 25:
		*R = 139;
		*G = 0;
		*B = 0;
		break;
	case 26:
		*R = 173;
		*G = 255;
		*B = 47;
		break;
	case 27:
		*R = 0;
		*G = 0;
		*B = 255;
		break;
	case 28:
		*R = 123;
		*G = 104;
		*B = 238;
		break;
	case 29:
		*R = 255;
		*G = 127;
		*B = 80;
		break;
	case 30:
		*R = 105;
		*G = 105;
		*B = 105;
		break;
	case 31:
		*R = 0;
		*G = 191;
		*B = 255;
		break;
	case 32:
		*R = 128;
		*G = 128;
		*B = 0;
		break;
	case 33:
		*R = 238;
		*G = 232;
		*B = 170;
		break;
	case 34:
		*R = 0;
		*G = 250;
		*B = 154;
		break;
	case 35:
		*R = 255;
		*G = 165;
		*B = 0;
		break;
	case 36:
		*R = 210;
		*G = 105;
		*B = 30;
		break;
	case 37:
		*R = 0;
		*G = 100;
		*B = 0;
		break;
	case 38:
		*R = 240;
		*G = 128;
		*B = 128;
		break;
	case 39:
		*R = 218;
		*G = 112;
		*B = 214;
		break;
	case 40:
		*R = 70;
		*G = 130;
		*B = 180;
		break;
	case 41:
		*R = 143;
		*G = 188;
		*B = 143;
		break;
	case 42:
		*R = 255;
		*G = 105;
		*B = 180;
		break;
	case 43:
		*R = 244;
		*G = 164;
		*B = 96;
		break;
	case 44:
		*R = 240;
		*G = 230;
		*B = 140;
		break;
	case 45:
		*R = 220;
		*G = 20;
		*B = 60;
		break;
	case 46:
		*R = 46;
		*G = 139;
		*B = 89;
		break;
	case 47:
		*R = 135;
		*G = 206;
		*B = 235;
		break;
	case 48:
		*R = 255;
		*G = 228;
		*B = 225;
		break;
	case 49:
		*R = 255;
		*G = 99;
		*B = 71;
		break;
	case 50:
		*R = 107;
		*G = 142;
		*B = 35;
		break;
	default:
		*R = 119;
		*G = 136;
		*B = 153;
		break;
	}
}