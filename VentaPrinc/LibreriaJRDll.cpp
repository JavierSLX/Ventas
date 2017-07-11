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

//Método que llena todos los clientes de un determinado punto de venta
void LibreriaJRDll::WintemplaCLS::llenarLVClientes(Win::ListView lvTabla, wstring punto_venta, bool activoCliente, bool activoClaveCliente, int size)
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
		lvTabla.Cols.Add(0, LVCFMT_LEFT, 70, L"Clave");
		lvTabla.Cols.Add(1, LVCFMT_LEFT, 200, L"Nombre");
		lvTabla.Cols.Add(2, LVCFMT_LEFT, 260, L"Dirección");
		lvTabla.Cols.Add(3, LVCFMT_LEFT, 100, L"Teléfono");
		lvTabla.Cols.Add(4, LVCFMT_LEFT, 150, L"Ciudad");

		//Ejecuta la consulta en la listview (Solo muestra los disponibles)
		Sys::Format(consulta, L"SELECT cc.id, CONCAT('%s-', cc.numero), c.nombre, c.direccion, c.telefono, cd.nombre\
		FROM clave_cliente cc, cliente c, punto_venta pv, ciudad cd\
		WHERE cc.cliente_id = c.id\
		AND  pv.id = cc.puntoVenta_id\
		AND c.ciudad_id = cd.id\
		AND cc.activo = %d\
		AND c.activo = %d\
		AND pv.tipo = '%s';", punto_venta.c_str(), activoClaveCliente, activoCliente, punto_venta.c_str());
		conn.ExecuteSelect(consulta, size, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que llena todas las claves de cliente de un determinado punto de venta
void LibreriaJRDll::WintemplaCLS::llevarLVClaveClientes(Win::ListView lvTabla, wstring punto_venta, bool activo, int size)
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
		lvTabla.Cols.Add(0, LVCFMT_LEFT, 200, L"Clave");

		//Ejecuta la consulta en la listview (Solo muestra los disponibles)
		Sys::Format(consulta, L"SELECT cc.id, cc.numero\
		FROM clave_cliente cc, punto_venta pv\
		WHERE cc.puntoVenta_id = pv.id\
		AND pv.tipo = '%s'\
		AND cc.activo = %d\
		ORDER BY cc.numero ASC;", punto_venta.c_str(), activo);
		conn.ExecuteSelect(consulta, size, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que llena todos los artículos faltantes de registrar un precio_cliente
void LibreriaJRDll::WintemplaCLS::llenarLVFaltantesPrecioCliente(Win::ListView lvTabla, wstring punto_venta, wstring numero, int size)
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
		lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"Artículo");
		lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Marca");
		lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");

		//Ejecuta la consulta en la listview (Solo muestra los disponibles)
		Sys::Format(consulta, L"SELECT a.id, ta.nombre, ma.nombre, mo.nombre\
		FROM articulo a, tipo_articulo ta, modelo mo, marca ma\
		WHERE a.id NOT IN\
		(SELECT ar.id\
			FROM precio_cliente pce, clave_cliente cce, articulo ar, punto_venta pvt, tipo_articulo tar, modelo md, marca mr\
			WHERE pce.articulo_id = ar.id\
			AND cce.id = pce.claveCliente_id\
			AND pvt.id = cce.puntoVenta_id\
			AND tar.id = ar.tipoArticulo_id\
			AND md.id = ar.modelo_id\
			AND md.marca_id = mr.id\
			AND pvt.tipo = '%s'\
			AND cce.numero = '%s')\
		AND a.tipoArticulo_id = ta.id\
		AND a.modelo_id = mo.id\
		AND mo.marca_id = ma.id\
		ORDER BY ta.nombre ASC;", punto_venta.c_str(), numero.c_str());
		conn.ExecuteSelect(consulta, size, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Método que llena los artículos registrados de precio_cliente
void LibreriaJRDll::WintemplaCLS::llenarLVPrecioCliente(Win::ListView lvTabla, wstring punto_venta, wstring numero, int size)
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
		lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"Artículo");
		lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Marca");
		lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");

		//Ejecuta la consulta en la listview (Solo muestra los disponibles)
		Sys::Format(consulta, L"SELECT a.id, ta.nombre, ma.nombre, m.nombre\
		FROM precio_cliente pc, clave_cliente cc, articulo a, punto_venta pv, tipo_articulo ta, modelo m, marca ma\
		WHERE pc.articulo_id = a.id\
		AND cc.id = pc.claveCliente_id\
		AND pv.id = cc.puntoVenta_id\
		AND ta.id = a.tipoArticulo_id\
		AND m.id = a.modelo_id\
		AND m.marca_id = ma.id\
		AND pv.tipo = '%s'\
		AND cc.numero = '%s'\
		ORDER BY ta.nombre ASC;", punto_venta.c_str(), numero.c_str());
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

//Método que llena las marcas de un determinado tipo de articulo
void LibreriaJRDll::WintemplaCLS::llenarDdMarca(Win::DropDownList ddMarca, wstring tipoArticulo, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddMarca.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT DISTINCT m.id, m.nombre\
		FROM tipo_articulo ta, articulo a, marca m, modelo mo\
		WHERE ta.id = a.tipoArticulo_id\
		AND a.modelo_id = mo.id\
		AND mo.marca_id = m.id\
		AND ta.nombre = '%s'\
		ORDER BY m.nombre ASC;", tipoArticulo.c_str());

		conn.ExecuteSelect(consulta, size, ddMarca);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddMarca.SetSelectedIndex(0);
	conn.CloseSession();
}

//Método que llena las marcas de un determinado tipo de articulo
void LibreriaJRDll::WintemplaCLS::llenarDdModelo(Win::DropDownList ddModelo, wstring marca, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddModelo.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT m.id, m.nombre\
		FROM modelo m, marca ma\
		WHERE m.marca_id = ma.id\
		AND ma.nombre = '%s'\
		ORDER BY ma.nombre ASC;", marca.c_str());

		conn.ExecuteSelect(consulta, size, ddModelo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddModelo.SetSelectedIndex(0);
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

//Método que llena la drop down list exclusivamente de rutas registradas en la base de datos
void LibreriaJRDll::WintemplaCLS::llenarDdRutasExclusiva(Win::DropDownList ddRutas, bool activo, int size)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddRutas.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM punto_venta\
		WHERE activo = true\
		AND tipo LIKE 'R%%'\
		AND CHARACTER_LENGTH(tipo) <= 3\
		ORDER BY tipo ASC;");

		conn.ExecuteSelect(consulta, size, ddRutas);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	ddRutas.SetSelectedIndex(0);
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

//Saca el id de un registro de la tabla ciudad, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDCiudad(wstring nombre)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int estandar_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id \
		FROM ciudad\
		WHERE nombre = '%s'", nombre.c_str());
		estandar_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		estandar_id = 0;
	}

	conn.CloseSession();

	return estandar_id;
}

//Saca el id de un registro de la tabla cliente, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDCliente(wstring nombre)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int estandar_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.id \
		FROM cliente c\
		WHERE c.nombre = '%s';", nombre.c_str());
		estandar_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		estandar_id = 0;
	}

	conn.CloseSession();

	return estandar_id;
}

//Saca el id de un registro de la tabla clave_cliente, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarIDClaveCliente(int cliente_id, int puntoVenta_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int estandar_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id \
		FROM clave_cliente\
		WHERE cliente_id = %d\
		AND puntoVenta_id = %d;", cliente_id, puntoVenta_id);
		estandar_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		estandar_id = 0;
	}

	conn.CloseSession();

	return estandar_id;
}

//Saca el id del último registro de la tabla clave_cliente, en caso de no existir regresa un 0
int LibreriaJRDll::SqlCLS::sacarUltimoIDClaveCliente(wstring punto_venta)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring clave = L"0";

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"select cc.numero\
		from clave_cliente cc, punto_venta pv\
		where cc.puntoVenta_id = pv.id\
		and pv.tipo = '%s'\
		order by cc.numero desc limit 1;", punto_venta.c_str());
		conn.GetString(consulta, clave, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		clave = L"0";
	}

	conn.CloseSession();
	return Sys::Convert::ToInt(clave);
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

//Saca el email de un cliente determinado dado por su clave_cliente
wstring LibreriaJRDll::SqlCLS::sacarEmailCliente(int claveCliente_id)
{
	wstring colocacion;
	wstring consulta;
	Sql::SqlConnection conn;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.email\
		FROM cliente c, clave_cliente cc\
		WHERE cc.cliente_id = c.id\
		AND cc.id = %d;", claveCliente_id);
		conn.GetString(consulta, colocacion, 100);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return colocacion;
}

//Saca el nombre de un cliente determinado por su clave_cliente
wstring LibreriaJRDll::SqlCLS::sacarNombreCliente(int claveCliente_id)
{
	wstring cadena;
	wstring consulta;
	Sql::SqlConnection conn;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.nombre\
		FROM cliente c, clave_cliente cc\
		WHERE cc.cliente_id = c.id\
		AND cc.id = %d;", claveCliente_id);
		conn.GetString(consulta, cadena, 200);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return cadena;
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

//Método que actualiza el estado de un registro de la tabla clave_cliente
void LibreriaJRDll::SqlCLS::actualizarEstadoClaveCliente(int claveCliente_id, bool estado)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE clave_cliente \
		SET activo = %d \
		WHERE id = %d", estado, claveCliente_id);
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

//Método que actualiza los datos de un registro de la tabla cliente
void LibreriaJRDll::SqlCLS::actualizarCliente(int cliente_id, wstring nombre, wstring direccion, wstring telefono, wstring email, int ciudad_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cliente \
		SET nombre = '%s', direccion = '%s', telefono = '%s', email = '%s', ciudad_id = %d \
		WHERE id = %d", nombre.c_str(), direccion.c_str(), telefono.c_str(), email.c_str(), ciudad_id, cliente_id);
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

//Método que inserta un registro en la tabla cliente
void LibreriaJRDll::SqlCLS::insertarCliente(wstring nombre, wstring direccion, wstring telefono, wstring email, int ciudad_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) \
		VALUES('%s', '%s', '%s', '%s', true, %d)", nombre.c_str(), direccion.c_str(), telefono.c_str(), email.c_str(),
			ciudad_id);
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

//Método que inserta un registro en la tabla ciudad
void LibreriaJRDll::SqlCLS::insertarCiudad(wstring nombre, int lada_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO ciudad (nombre, activo, lada_id) \
		VALUES('%s', true, %d)", nombre.c_str(), lada_id);
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

//Método que inserta un registro en la tabla clave_cliente
void LibreriaJRDll::SqlCLS::insertarClaveCliente(wstring numero, int cliente_id, int puntoVenta_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id) \
		VALUES('%s', true, %d, %d)", numero.c_str(), cliente_id, puntoVenta_id);
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

//__________________________________________ CLASE STRINGCLS
//Verifica que la posición que se le pasa al método es una letra, regresa TRUE si es así
bool LibreriaJRDll::StringCLS::verificaLetra(wstring cadena, int posicion)
{
	if (isalpha(cadena.at(posicion)))
		return true;

	return false;
}

//Verifica que la posición que se le pasa al método es un número, regresa TRUE si es así
bool LibreriaJRDll::StringCLS::verificaNumero(wstring cadena, int posicion)
{
	if (isdigit(cadena.at(posicion)))
		return true;

	return false;
}

//Verifica si el elemento que se busca existe en la posicion que se le pasa
bool LibreriaJRDll::StringCLS::comparaElemento(wstring cadena, int posicion, char elemento)
{
	if (cadena.at(posicion) == elemento)
		return true;
	else
		return false;
}

//Verifica si la cadena cumple con el estándar de una estructura de ruta (R1, R1-67, etc)
bool LibreriaJRDll::StringCLS::verificaRuta(wstring cadena)
{
	int cont = 0;

	//Verifica que el primer elemento de la cadena sea una R
	if (comparaElemento(cadena, 0, 'r') == false && comparaElemento(cadena, 0, 'R') == false)
		return false;

	//Verifica que el segundo elemento de la cadena sea un numero
	if (!verificaNumero(cadena, 1))
		return false;

	//Verifica que el resto de la cadena contenga solamente un signo de separacion '-' y numeros
	for (int unsigned i = 2; i < cadena.length(); i++)
	{
		if (cont == 0 && comparaElemento(cadena, i, '-'))
			cont++;
		else
		{
			if (!verificaNumero(cadena, i))
				return false;
		}
	}

	return true;
}

//Convierte una cadena a Mayúsculas y regresa el resultado
wstring LibreriaJRDll::StringCLS::convertirAMayusculas(wstring cadena)
{
	wstring resultado = cadena;

	for (unsigned int k = 0; k < cadena.length(); k++)
	{
		if (isalpha(resultado.at(k)))
			resultado.at(k) = toupper(cadena.at(k));
	}

	return resultado;
}

//Convierte una cadena a Mayúsculas y regresa el resultado
wstring LibreriaJRDll::StringCLS::convertirAMinusculas(wstring cadena)
{
	wstring resultado = cadena;

	for (unsigned int k = 0; k < cadena.length(); k++)
	{
		if (isalpha(resultado.at(k)))
			resultado.at(k) = tolower(cadena.at(k));
	}

	return resultado;
}

//Convierte una cadena en la primera letra en mayúscula y las demás en minúsculas
wstring LibreriaJRDll::StringCLS::convertirATextoEstandar(wstring cadena)
{
	wstring resultado = cadena;
	bool inicial = false;

	for (unsigned int k = 0; k < cadena.length(); k++)
	{
		if (isalpha(resultado.at(k)))
		{
			if (!inicial)
			{
				resultado.at(k) = toupper(cadena.at(k));
				inicial = true;
			}
			else
				resultado.at(k) = tolower(cadena.at(k));
		}
	}

	return resultado;
}

//Saca la parte numérica del identificador
int LibreriaJRDll::StringCLS::sacarIdentificadorNumerico(wstring cadena, char simbolo)
{
	int guion = -1;

	if (cadena.length() == 0)
		return -1;

	for (int unsigned i = 0; i < cadena.length(); i++)
		if (cadena.at(i) == simbolo)
		{
			guion = i;
			break;
		}

	//Si no existe el guion
	if (guion == -1)
		return -1;

	//Saca la parte numerica del identificador
	return Sys::Convert::ToInt(cadena.substr(guion+1));
}

