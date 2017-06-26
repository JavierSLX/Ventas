#include "stdafx.h"  //_____________________________________________ LibreriaAdDll.cpp
#include "LibreriaAdDll.h"

//_______________________________________Marca____________________________________________________
void  LibreriaAdDll::marca::llenarLVMarca(Win::ListView lvMarcas, int large, bool activo) {
	wstring consulta;
	Sql::SqlConnection conn;
	lvMarcas.SetRedraw(false);
	lvMarcas.Cols.DeleteAll();
	lvMarcas.Items.DeleteAll();
	lvMarcas.SetRedraw(true);
	lvMarcas.Cols.Add(0, LVCFMT_CENTER, 100, L"Marca");
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre\
								FROM marca\
								WHERE activo = %d\
								ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, large, lvMarcas);
	}
	catch (Sql::SqlException e)
	{
		///*/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/*/
	}

	conn.CloseSession();
}

void  LibreriaAdDll::marca::llenarLVMarcaNoAct(Win::ListView lvMarcas, int large, bool activo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	lvMarcas.SetRedraw(false);
	lvMarcas.Cols.DeleteAll();
	lvMarcas.Items.DeleteAll();
	lvMarcas.SetRedraw(true);
	lvMarcas.Cols.Add(0, LVCFMT_CENTER, 100, L"Marca");
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre\
								FROM marca\
								WHERE activo = %d\
								ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, large, lvMarcas);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

void LibreriaAdDll::marca::insertarMarca(wstring marca) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO marca (nombre,activo) \
								VALUES('%s',true);", marca.c_str());
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();


}

wstring LibreriaAdDll::marca::sacarMarcaSiExiste(wstring marca) {
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.nombre\
			FROM marca m\
			WHERE m.nombre = '%s'", marca.c_str());
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}

wstring LibreriaAdDll::marca::sacarMarcaAct(int marca_id) {
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
								FROM marca\
								WHERE id = %d", marca_id);
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return ma;
}

int LibreriaAdDll::marca::sacarIDOcultoLV(Win::ListView lv2)
{
	int indice = lv2.GetSelectedIndex();
	int id = lv2.Items[indice].Data;

	return id;
}

void LibreriaAdDll::marca::updateMarcaEliminar(int marca_id) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE marca \
		SET activo = false\
		WHERE id = %d", marca_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::marca::updateMarcaRestaurar(int marca_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE marca \
		SET activo = true\
		WHERE id = %d", marca_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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

void LibreriaAdDll::marca::updateNombreMarca(wstring nombre,int marca_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE marca \
		SET nombre = '%s'\
		WHERE id = %d", nombre.c_str(), marca_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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

//_________________________________________________Articulo___________________________________________________-
//llena los dropDouwList de la ventana articulo
void  LibreriaAdDll::articulo::llenarDDMarca(Win::DropDownList ddMarca, int large, bool activo) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddMarca.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre\
								FROM marca\
								WHERE activo = %d\
								ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, large, ddMarca);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void  LibreriaAdDll::articulo::llenarDDModelo(Win::DropDownList ddModelo, wstring marca, int large, bool activo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddModelo.DeleteAllItems();
	try

		
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT mo.id, mo.nombre\
								FROM modelo mo, marca ma\
								WHERE mo.marca_id = ma.id\
								AND ma.nombre = '%s'\
								AND mo.activo = %d\
								ORDER BY mo.nombre ASC;", marca.c_str(), activo);

		conn.ExecuteSelect(consulta, large, ddModelo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void  LibreriaAdDll::articulo::llenarDDarticulo(Win::DropDownList ddTipoArticulo, int large, bool activo) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddTipoArticulo.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"select id, nombre\
								from tipo_articulo\
								where activo = %d\
								ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, large, ddTipoArticulo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void  LibreriaAdDll::articulo::llenarDDcolor(Win::DropDownList ddcolor, int large, bool activo) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddcolor.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre\
								FROM color\
								WHERE activo = %d\
								ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, large, ddcolor);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::llenarDDdepartamento(Win::DropDownList ddDepartamento, int large, bool activo) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddDepartamento.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, tipo\
								FROM punto_venta\
								WHERE activo = %d\
								ORDER BY tipo ASC;", activo);

		conn.ExecuteSelect(consulta, large, ddDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::llenarArticulo(Win::ListView lvDepartamento, int large, wstring puntoVenta)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);

	lvDepartamento.Cols.Add(0, LVCFMT_LEFT, 120, L"C�digo");
	lvDepartamento.Cols.Add(1, LVCFMT_LEFT, 120, L"Tipo de articulo");
	lvDepartamento.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");
	lvDepartamento.Cols.Add(3, LVCFMT_LEFT, 120, L"Marca");
	lvDepartamento.Cols.Add(4, LVCFMT_LEFT, 120, L"Precio");
	lvDepartamento.Cols.Add(6, LVCFMT_LEFT, 120, L"Departamento");
	lvDepartamento.Cols.Add(7, LVCFMT_LEFT, 120, L"Cantidad");
	lvDepartamento.Cols.Add(8, LVCFMT_LEFT, 120, L"Color");
	lvDepartamento.Cols.Add(9, LVCFMT_LEFT, 120, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT ar.id, ar.codigo,ta.nombre, mo.nombre, ma.nombre, ar.precio, pv.tipo, ca.valor, co.nombre, fm.fecha\
			FROM articulo ar, modelo mo, tipo_articulo ta, marca ma, punto_venta pv, cantidad ca, color co, movimiento mov, fecha_movimiento fm\
			WHERE pv.tipo = '%s'\
			AND ca.articulo_id = ar.id\
			AND ca.puntoVenta_id = pv.id\
			AND ta.id = ar.tipoArticulo_id\
			AND ca.color_id = co.id\
			AND mo.id = ar.modelo_id\
			AND mo.marca_id = ma.id\
			AND mov.articulo_id = ar.id\
			AND fm.movimiento_id = mov.id\
			AND ca.valor > 0\
			AND ar.activo = true\
			ORDER BY fm.fecha DESC;", puntoVenta.c_str());

		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
//Subconsulta que busca por codigo de articulo
void LibreriaAdDll::articulo::llenarArticulosER(Win::ListView lvTabla, wstring tipoArticulo, bool activo, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"C�digo");
	lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Tipo de articulo");
	lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");
	lvTabla.Cols.Add(3, LVCFMT_LEFT, 120, L"Marca");
	lvTabla.Cols.Add(4, LVCFMT_LEFT, 120, L"Precio");
	lvTabla.Cols.Add(6, LVCFMT_LEFT, 120, L"Departamento");
	lvTabla.Cols.Add(7, LVCFMT_LEFT, 120, L"Cantidad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT a.id,a.codigo,ta.nombre,mo.nombre, ma.nombre, a.precio, pv.tipo,\
			(SELECT SUM(ca.valor)\
				FROM articulo art, punto_venta pva, cantidad ca\
				WHERE ca.articulo_id = a.id\
				AND pva.id = pv.id\
				AND ca.puntoVenta_id = pva.id\
				AND art.id = a.id)\
			FROM articulo a, modelo mo, marca ma, punto_venta pv, cantidad can, tipo_articulo ta, color co\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND can.color_id = co.id\
			AND a.tipoArticulo_id = ta.id\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND ta.nombre = '%s'\
			AND can.valor > 0\
			AND a.activo = %d", tipoArticulo.c_str(), activo);

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::llenarTab(Win::Tab  tbBusqueda)
{
	LibreriaAdDll::articulo libreriaObj;
	int _cantidadpuntosVP = libreriaObj.sacarCantidadPV();
	wstring resultadoPuntosVenta;

	for (int i = 1; i <= _cantidadpuntosVP; i++)
	{
		LibreriaAdDll::articulo libreriaObj;
		resultadoPuntosVenta = libreriaObj.sacarDepartamento(i);
		if (resultadoPuntosVenta != L"")
		{
			tbBusqueda.Items.Add(i, resultadoPuntosVenta);

		}
	}



}


//Metodos para insertar un articulo
void LibreriaAdDll::articulo::insertArticulos(wstring codigo, double precio,  int tipoArticulo, int modelo)
{
	wstring consulta;

	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)\
				VALUES('%s',%lf, true, %d, %d);", codigo.c_str(), precio, tipoArticulo, modelo);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::insertModelo(wstring modelo, int id_marca)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO modelo (nombre,activo,id_marca) \
				VALUES('%s',true,%d);", modelo.c_str(), id_marca);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();


}
void LibreriaAdDll::articulo::insertarCantidad(int valor, int articulo_id, int color_id, int puntoVenta_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) \
				VALUES(%d, %d, %d, %d);", valor, articulo_id, color_id, puntoVenta_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::insertarMovimiento(int cantidad, int tipoMovimiento_id, int puntoVenta_id, int articulo_id, int usuario_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO movimiento (cantidad, tipoMovimiento_id, puntoVenta_id, articulo_id, usuario_id) \
				VALUES(%d, %d, %d, %d, %d);", cantidad, tipoMovimiento_id, puntoVenta_id, articulo_id, usuario_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

void LibreriaAdDll::articulo::insertarFecha(int movimiento_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO fecha_movimiento (fecha, movimiento_id) \
				VALUES(now(), %d);", movimiento_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::insertarTelefono(wstring imei, int articulo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO telefono (imei, activo, articulo_id)\
							VALUES('%s', true , %d);", imei.c_str(), articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows != 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}


//metodos para sacar los id de las tablas relacionadas con un articulo
int LibreriaAdDll::articulo::sacarIDPuntoVenta(wstring puntoVenta)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int categoria_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM punto_venta\
			WHERE tipo = '%s'", puntoVenta.c_str());
		categoria_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return categoria_id;
}



int LibreriaAdDll::articulo::sacarIDMarca(wstring marca)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int marca_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM marca\
			WHERE nombre = '%s';", marca.c_str());
		marca_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return marca_id;
}
int LibreriaAdDll::articulo::sacarIDTipoMovimiento(wstring tipoMovimiento)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int marca_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM tipo_movimiento\
			WHERE nombre = '%s';", tipoMovimiento.c_str());
		marca_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return marca_id;
}
int LibreriaAdDll::articulo::sacarIDArticuloSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int marca_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
								FROM articulo\
								WHERE codigo = '%s';", codigo.c_str());
		marca_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return marca_id;
}
int LibreriaAdDll::articulo::sacarIDModelo(wstring modelo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int modelo_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM modelo\
			WHERE nombre = '%s';", modelo.c_str());
		modelo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return modelo_id;
}
int LibreriaAdDll::articulo::sacarIDtipoArticulo(wstring tipoArticulo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int tipoArticulo_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM tipo_articulo\
			WHERE nombre = '%s';", tipoArticulo.c_str());
		tipoArticulo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return tipoArticulo_id;
}
int LibreriaAdDll::articulo::sacarIDcolor(wstring color)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int color_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM color\
			WHERE nombre = '%s';", color.c_str());
		color_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return color_id;
}

int LibreriaAdDll::articulo::sacarIDCantidad(int color, int departamento_id, int articulo_id )
{
	wstring consulta;
	Sql::SqlConnection conn;
	int color_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ca.id\
			FROM cantidad ca, punto_venta pv, articulo ar, color co\
			WHERE ca.puntoVenta_id = pv.id\
			AND ca.articulo_id = ar.id\
			AND co.id = ca.color_id\
			AND co.id = %d\
			AND pv.id = %d\
			AND ar.id = %d;",color, departamento_id, articulo_id);
		color_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return color_id;
}

int LibreriaAdDll::articulo::sacarIDCantidadSIcolor(int puntoVenta_id,int color_id, int articulo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int colorTabla_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ca.id\
			FROM cantidad ca, punto_venta pv, articulo ar, color co\
			WHERE ca.puntoVenta_id = pv.id\
			AND ca.articulo_id = ar.id\
			AND ca.color_id = co.id\
			AND pv.id = %d\
			AND co.id = %d\
			AND ar.id = %d;", puntoVenta_id,color_id, articulo_id);
		colorTabla_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return colorTabla_id;
}

int LibreriaAdDll::articulo::sacarUltIDArticulos()
{
	wstring consulta;
	Sql::SqlConnection conn;
	int articulos_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM articulo\
			ORDER BY id DESC limit 1;");
		articulos_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return articulos_id;
}
int LibreriaAdDll::articulo::sacarUltIDMovimiento()
{
	wstring consulta;
	Sql::SqlConnection conn;
	int articulos_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM movimiento\
			ORDER BY id DESC limit 1;");
		articulos_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return articulos_id;
}
int LibreriaAdDll::articulo::sacarIDImei(wstring color)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int color_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM telefono\
			WHERE imei = '%s';", color.c_str());
		color_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return color_id;
}


//metodos para sacar los datos si ya existen con el codigo
double LibreriaAdDll::articulo::sacarPrecioSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	double ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT precio\
			FROM articulo\
			WHERE codigo = '%s'", codigo.c_str());
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
wstring LibreriaAdDll::articulo::sacarModeloSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT mo.nombre\
			FROM modelo mo, articulo ar\
			WHERE ar.modelo_id = mo.id\
			AND ar.codigo = '%s'", codigo.c_str());
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
wstring LibreriaAdDll::articulo::sacarMarcaSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct ma.nombre\
			FROM modelo mo, articulo ar, marca ma\
			WHERE ar.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND ar.codigo = '%s'", codigo.c_str());
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
wstring LibreriaAdDll::articulo::sacarColorSiCodigo(Win::DropDownList ddMarca, wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct co.nombre\
			FROM cantidad ca, articulo ar, color co\
			WHERE ca.articulo_id = ar.id\
			AND ca.color_id = co.id\
			AND ar.codigo = '%s'\
			ORDER BY valor DESC LIMIT 1", codigo.c_str());
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
wstring LibreriaAdDll::articulo::sacartipoArticuloSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct ta.nombre\
			FROM tipo_articulo ta, articulo ar\
			WHERE ar.tipoArticulo_id = ta.id\
			AND ar.codigo = '%s'", codigo.c_str());
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
wstring LibreriaAdDll::articulo::sacarPuntoVentaSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct pv.tipo\
			FROM cantidad ca, articulo ar, punto_venta pv\
			WHERE ca.articulo_id = ar.id\
			AND ca.puntoVenta_id = pv.id\
			AND ar.codigo = '%s'", codigo.c_str());
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}

int LibreriaAdDll::articulo::sacarCantidadSiCodigo(wstring codigo, int departamento, int color)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ca.valor\
			FROM cantidad ca, articulo ar, punto_venta pv, color co\
			WHERE ca.articulo_id = ar.id\
			AND ca.color_id = co.id\
			AND ca.puntoVenta_id = pv.id\
			AND co.id = %d\
			AND pv.id = %d\
			AND ar.codigo = '%s'", color, departamento,codigo.c_str());
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}


//Saca el ultimo id agregado de las tablas
wstring LibreriaAdDll::articulo::sacarDepartamento(int pv_id) {
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct pv.tipo\
			FROM punto_venta pv \
			WHERE  pv.id= %d\
			AND pv.activo = true", pv_id);
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}
int LibreriaAdDll::articulo::sacarCantidadPV() {
	wstring consulta;
	Sql::SqlConnection conn;
	int valor = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT count(*)\
			FROM  punto_venta \
			WHERE activo = true ");
		valor = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}
wstring LibreriaAdDll::articulo::sacarCodigo(int modelo, int tipoArticulo, int marca, int puntoVenta)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT codigo\
			FROM  articulo ar, modelo mo, tipo_articulo ta, marca ma, punto_venta pv\
			WHERE pv.id = %d\
			AND ta.id = %d\
			AND mo.id = %d\
			AND ma.id =%d\
			AND ca.articulo_id = ar.id\
			AND ca.puntoVenta_id = pv.id\
			AND ta.id = ar.tipoArticulo_id\
			AND mo.id = ar.modelo_id\
			AND mo.marca_id = ma.id\
			AND pv.activo = true;", puntoVenta, tipoArticulo, modelo, marca);
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}
//Saca una cadena en una determinada celda de listview, lo regresa
wstring LibreriaAdDll::articulo::sacarTextoLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring nombre = lvTabla.Items[s].GetText(columna);
	return nombre;
}
wstring LibreriaAdDll::articulo::sacarCodigoSiCodigo(wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT a.codigo\
			FROM articulo a \
			WHERE a.codigo = '%s'", codigo.c_str());
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}

//Actualiza los campos
void LibreriaAdDll::articulo::updateTipoArticulo(int articulo_id, wstring tipoArticulo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE tipo_articulo ta, articulo ar \
		SET ta.nombre = '%s'\
		WHERE ar.tipoArticulo_id = ta.id\
		AND ar.id = %d", tipoArticulo.c_str(),articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::articulo::updateCodigo(int articulo_id, wstring codigo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE articulo\
		SET codigo = '%s'\
		WHERE id = %d", codigo.c_str(), articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::articulo::updatePrecio(int articulo_id, double precio)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE articulo\
		SET precio = %f\
		WHERE id = %d", precio, articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::articulo::updateModelo(int articulo_id, wstring modelo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE modelo mo, articulo ar \
		SET mo.nombre = '%s'\
		WHERE ar.modelo_id = mo.id\
		AND ar.id = %d", modelo.c_str(), articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::articulo::updateMarca(int articulo_id, wstring marca)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE modelo mo, marca ma, articulo ar \
		SET ma.nombre = '%s'\
		WHERE ar.modelo_id = mo.id\
		AND mo.marca_id = ma.id\
		AND ar.id = %d", marca.c_str(), articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::articulo::updateCantidad(int cantidad_id, int cantidad)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cantidad\
		SET valor = %d\
		WHERE id = %d", cantidad, cantidad_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

void LibreriaAdDll::articulo::updateCantidadENPuntoVenta(int cantidad_id, int departamento_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cantidad\
		SET puntoVenta_id = %d\
		WHERE id = %d", departamento_id, cantidad_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}


void LibreriaAdDll::articulo::updateCantidadENColor(int cantidad_id, int color_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cantidad\
		SET color_id = %d\
		WHERE id = %d", color_id, cantidad_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{

		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void LibreriaAdDll::articulo::updateColor(int cantidad_id, int color_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cantidad\
		SET color_id = %d\
		WHERE id = %d", color_id, cantidad_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
int LibreriaAdDll::articulo::sacarCantidadDepartamento(wstring color,int departamento_id, wstring codigo)
{
		wstring consulta;
		Sql::SqlConnection conn;
		int valor = 0;

		try
		{
			conn.OpenSession(hWnd, CONNECTION_STRING);
			Sys::Format(consulta, L"SELECT can.valor\
									FROM  cantidad can, articulo art, color co, punto_venta pv\
									WHERE can.puntoVenta_id = pv.id\
									AND can.color_id = co.id\
									AND can.articulo_id = art.id\
									AND co.nombre = '%s'\
									AND pv.id = %d \
									AND art.codigo = '%s' ", color.c_str(),departamento_id, codigo.c_str());
			valor = conn.GetInt(consulta);
		}
		catch (Sql::SqlException e)
		{
			/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
		}

		conn.CloseSession();

		return valor;
	}
void LibreriaAdDll::articulo::updateArticuloEliminar(int articulo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE articulo \
		SET activo = false\
		WHERE id = %d", articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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
void LibreriaAdDll::articulo::updateArticuloRestaurar(int articulo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE articulo \
		SET activo = true\
		WHERE id = %d", articulo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
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