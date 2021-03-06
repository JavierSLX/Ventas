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
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
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
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
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
//saca el precio de una orden 
double LibreriaAdDll::ordenNueva::sacarTotalOrdenDescripcion(int idOrden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	double ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT SUM(od.precio_final*od.cantidad)\
			from orden o, orden_descripcion od\
		where od.orden_id = o.id\
		and o.id = %d ",idOrden);
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



//-------------------------------------ORDEN-------------------------------------
//----------------------------------NUEVA ORDEN----------------------------------
//-------------------------------LLENAR DROPDOWNlIST-----------------------------
void  LibreriaAdDll::ordenNueva::llenarDDCliente(Win::DropDownList ddCliente, int id_pv, int large, bool activo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddCliente.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cc.id, cc.numero\
								FROM clave_cliente cc, punto_venta pv\
								WHERE cc.puntoVenta_id = pv.id\
								AND cc.activo = %d\
								AND pv.id = %d\
								ORDER BY numero ASC;",activo, id_pv);

		conn.ExecuteSelect(consulta, large, ddCliente);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

void  LibreriaAdDll::ordenNueva::llenarDDPuntoVenta(Win::DropDownList ddPuntoVenta, int large, bool activo) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddPuntoVenta.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, tipo\
								FROM punto_venta\
								WHERE activo = %d\
								ORDER BY tipo ASC;", activo);

		conn.ExecuteSelect(consulta, large, ddPuntoVenta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
wstring LibreriaAdDll::ordenNueva::sacarNombreCliente(int pv,wstring claveCliente)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cli.nombre\
			FROM punto_venta pv, cliente cli, clave_cliente cc \
			WHERE  pv.id= cc.puntoVenta_id\
			AND cli.id = cc.cliente_id\
			AND pv.id = %d\
			AND cc.numero = '%s'", pv, claveCliente.c_str());
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}

int LibreriaAdDll::ordenNueva::sacarIDpuntoVenta(wstring pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM punto_venta\
			WHERE tipo = '%s';", pv.c_str());
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}

int LibreriaAdDll::ordenNueva::sacarIDCliente(wstring clave_cliente, wstring pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cc.id\
			FROM cliente cli, clave_cliente cc, punto_venta pv\
			WHERE cc.cliente_id = cli.id\
			AND cc.puntoVenta_id = pv.id\
			AND cc.numero = '%s'\
			AND pv.tipo = '%s';", clave_cliente.c_str(), pv.c_str());

		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
//Saca el �ltimo identificador registrado
wstring LibreriaAdDll::ordenNueva::sacarUltimoFolio(void)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring folio = L"";

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT folio\
		from orden\
		order by folio desc LIMIT 1;");
		conn.GetString(consulta, folio, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		folio = L"";
	}

	conn.CloseSession();
	return folio;
}
//Saca la parte de la fecha del identificador
int LibreriaAdDll::ordenNueva::sacarIdentificadorFecha(wstring cadena)
{
	int guion = -1;

	if (cadena.length() == 0)
		return -1;

	for (int unsigned i = 0; i < cadena.length(); i++)
		if (cadena.at(i) == '/')
		{
			guion = i;
			break;
		}

	//Si no existe el guion
	if (guion == -1)
		return -1;

	//Saca la parte numerica del identificador
	return Sys::Convert::ToInt(cadena.substr(guion + 1));
}
//Saca la parte num�rica del identificador
int LibreriaAdDll::ordenNueva::sacarIdentificadorNumerico(wstring cadena)
{
	int guion = -1;

	if (cadena.length() == 0)
		return -1;

	for (int unsigned i = 0; i < cadena.length(); i++)
		if (cadena.at(i) == '/')
		{
			guion = i;
			break;
		}

	//Si no existe el guion
	if (guion == -1)
		return -1;

	//Saca la parte numerica del identificador
	return Sys::Convert::ToInt(cadena.substr(0, guion));
}
//insertar orden
void LibreriaAdDll::ordenNueva::insertOrden(wstring folio, int cliente, int pv, int usuario)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO orden (folio, fecha, cliente_id, puntoVenta_id, usuario_id) \
				VALUES('%s',now(),%d, %d, %d);", folio.c_str(), cliente, pv, usuario);
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
void  LibreriaAdDll::ordenNueva::llenarDDServicio(Win::DropDownList ddServicio, int large, bool activo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddServicio.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre\
								FROM servicio_venta\
								WHERE activo = %d\
								ORDER BY nombre ASC;", activo);

		conn.ExecuteSelect(consulta, large, ddServicio);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

void LibreriaAdDll::ordenNueva::insertOrdenDescripcion(int tipoVentaId, int cantidad, double precioSugerido, double precioFinal, int orden, int requerimiento)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO orden_descripcion (tipoVentaId, cantidad, precio_sugerido, precio_final, orden_id, requerimiento_id) \
				VALUES(%d,%d,%lf, %lf,%d,%d);", tipoVentaId, cantidad, precioSugerido, precioFinal, orden, requerimiento);
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
int LibreriaAdDll::ordenNueva::sacarIDRequerimiento(wstring requerimiento)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM requerimiento\
			WHERE tipo = '%s';",requerimiento.c_str());
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
int LibreriaAdDll::ordenNueva::sacarIDArticulo(int color, int departamento_id, int modelo, int marca, int ta)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int color_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ar.id\
			FROM cantidad ca, punto_venta pv, articulo ar, color co, marca ma, modelo mo, tipo_articulo ta\
			WHERE ca.puntoVenta_id = pv.id\
			AND ar.tipoArticulo_id = ta.id\
			AND ca.articulo_id = ar.id\
			AND ca.color_id = co.id\
			AND mo.id = ar.modelo_id\
			AND mo.marca_id = ma.id\
			AND co.id = %d\
			AND pv.id = %d\
			AND ta.id = %d\
			AND mo.id = %d\
			AND ma.id = %d; ", color, departamento_id,ta, modelo, marca);
		color_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return color_id;
}
int LibreriaAdDll::ordenNueva::sacarIDTipoArticulo(wstring tipoArticulo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM tipo_articulo\
			WHERE nombre = '%s';", tipoArticulo.c_str());
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
int LibreriaAdDll::ordenNueva::sacarIDServicio(wstring Servicio)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM servicio_venta\
			WHERE nombre = '%s';", Servicio.c_str());
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
double LibreriaAdDll::ordenNueva::sacarPrecio(int servicio_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	double pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT precio\
			FROM servicio_venta\
			WHERE id = %d;", servicio_id);
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
void LibreriaAdDll::ordenNueva::llenarDescripcionOrden(Win::ListView lvOrden, int large, wstring folio)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvOrden.SetRedraw(false);
	lvOrden.Cols.DeleteAll();
	lvOrden.Items.DeleteAll();
	lvOrden.SetRedraw(true);

	lvOrden.Cols.Add(0, LVCFMT_LEFT, 120, L"Tipo");
	lvOrden.Cols.Add(1, LVCFMT_LEFT, 120, L"Nombre");
	lvOrden.Cols.Add(2, LVCFMT_LEFT, 120, L"Marca");
	lvOrden.Cols.Add(3, LVCFMT_LEFT, 120, L"Modelo");
	lvOrden.Cols.Add(4, LVCFMT_LEFT, 120, L"Color");
	lvOrden.Cols.Add(5, LVCFMT_LEFT, 120, L"Cantidad");
	lvOrden.Cols.Add(6, LVCFMT_LEFT, 120, L"P. Sugerido");
	lvOrden.Cols.Add(7, LVCFMT_LEFT, 120, L"P. Final");
	lvOrden.Cols.Add(8, LVCFMT_LEFT, 120, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT od.id,r.tipo,sv.nombre\
			, 'NA', 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, o.fecha\
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
			AND o.folio = '%s'\
			UNION\
			SELECT DISTINCT od.id, r.tipo, ta.nombre, mo.nombre, ma.nombre,\
			col.nombre, od.cantidad, od.precio_sugerido, od.precio_final, o.fecha\
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
			AND can.color_id = col.id\
			AND a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND a.tipoArticulo_id = ta.id\
			AND a.id = od.tipoVentaId\
			AND o.folio = '%s'; ", folio.c_str(),folio.c_str());

		conn.ExecuteSelect(consulta, large, lvOrden);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void  LibreriaAdDll::ordenNueva::llenarDDMarca(Win::DropDownList ddMarca, int large, bool activo, wstring tipo, int pv) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddMarca.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct ma.nombre\
							FROM marca ma, tipo_articulo ta, modelo mo, articulo ar, punto_venta pv, cantidad can\
							WHERE ar.tipoArticulo_id = ta.id\
							AND ar.modelo_id = mo.id\
							AND mo.marca_id = ma.id\
							AND can.puntoVenta_id = pv.id\
							AND ma.activo = %d\
							AND pv.id = %d\
							AND ta.nombre = '%s'\
							ORDER BY ma.nombre ASC; ", activo, pv, tipo.c_str());

		conn.ExecuteSelect(consulta, large, ddMarca);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void  LibreriaAdDll::ordenNueva::llenarDDcolor(Win::DropDownList ddcolor, int large, int articulo_id, wstring pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddcolor.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT co.id,co.nombre\
			FROM color co, punto_venta pv, cantidad ca, articulo art\
			WHERE ca.articulo_id = art.id\
			AND ca.puntoVenta_id = pv.id\
			AND co.id = ca.color_id\
			AND ca.valor > 0\
			AND art.id = %d\
			AND co.activo = true\
			AND pv.tipo =  '%s' ", articulo_id, pv.c_str());

		conn.ExecuteSelect(consulta, large, ddcolor);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

int LibreriaAdDll::ordenNueva::sacarIDArticulo( wstring tipo, int modelo, int marca, wstring pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int marca_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ar.id\
			FROM articulo ar, tipo_articulo ta, modelo mo, marca ma, cantidad ca, punto_venta pv\
			WHERE ar.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND ar.tipoArticulo_id = ta.id\
			AND ca.articulo_id = ar.id\
			AND ca.puntoVenta_id = pv.id\
			AND ta.nombre = '%s'\
			AND mo.id = %d\
			AND pv.tipo = '%s'\
			AND ca.valor > 0\
			AND ma.id = %d; ", tipo.c_str(), modelo, pv.c_str(), marca);
			marca_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		marca_id = 0;
	}

	conn.CloseSession();
	return marca_id;
}
void  LibreriaAdDll::ordenNueva::llenarDDTipoArticulo(Win::DropDownList ddTipoArticulo, int large, bool activo, wstring pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddTipoArticulo.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT distinct ta.id, ta.nombre\
			From tipo_articulo ta, cantidad ca, articulo ar, punto_venta pv\
			WHERE ar.tipoArticulo_id = ta.id\
			AND ca.articulo_id = ar.id\
			AND ca.puntoVenta_id = pv.id\
			AND pv.tipo = '%s'\
			AND ca.valor > 0\
			AND ta.activo = true\
			ORDER BY ta.nombre ASC; ", pv.c_str(),activo);

		conn.ExecuteSelect(consulta, large, ddTipoArticulo);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
void  LibreriaAdDll::ordenNueva::llenarDDModelo(Win::DropDownList ddModelo, wstring marca, int large, bool activo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddModelo.DeleteAllItems();
	try


	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT mo.nombre\
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
double LibreriaAdDll::ordenNueva::sacarPrecioArticulo(int articulo_id, int ClaveCliente)

{
	wstring consulta;
	Sql::SqlConnection conn;
	double pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT precio\
			FROM precio_cliente\
			WHERE claveCliente_id = %d\
			AND articulo_id = %d;",ClaveCliente, articulo_id);
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
int LibreriaAdDll::ordenNueva::sacarIDPuntoVenta(wstring pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int pv_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM punto_venta\
			WHERE tipo = '%s';", pv.c_str());
		pv_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{

	}

	conn.CloseSession();
	return pv_id;
}
int LibreriaAdDll::ordenNueva::sacarIDOcultoLV(Win::ListView lv2)
{
	int indice = lv2.GetSelectedIndex();
	int id = lv2.Items[indice].Data;

	return id;
}
//Saca una cadena en una determinada celda de listview, lo regresa
wstring LibreriaAdDll::ordenNueva::sacarTextoLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring nombre = lvTabla.Items[s].GetText(columna);
	return nombre;
}
void LibreriaAdDll::ordenNueva::updateTipoArticulo(int articulo_id, wstring tipoArticulo)
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
		AND ar.id = %d", tipoArticulo.c_str(), articulo_id);
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
void LibreriaAdDll::ordenNueva::updateMarca(int articulo_id, wstring marca)
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
void LibreriaAdDll::ordenNueva::updateModelo(int articulo_id, wstring modelo)
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

int LibreriaAdDll::ordenNueva::sacarIDArticuloUpdate(wstring tipo, wstring modelo, wstring marca )
{
	wstring consulta;
	Sql::SqlConnection conn;
	int marca_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ar.id\
			FROM articulo ar, tipo_articulo ta, modelo mo, marca ma, cantidad ca\
			WHERE ar.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND ar.tipoArticulo_id = ta.id\
			AND ca.articulo_id = ar.id\
			AND ta.nombre = '%s'\
			AND mo.nombre= '%s'\
			AND ca.valor > 0\
			AND ma.nombre = '%s'; ", tipo.c_str(), modelo.c_str(), marca.c_str());
		marca_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return marca_id;
}

void LibreriaAdDll::ordenNueva::insertarCantidadRequerimiento(int cantidad,int requerimiento) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO cantidad_requerimiento (cantidad_id,requerimiento_id) \
								VALUES(%d,%d);",cantidad,requerimiento);
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


void LibreriaAdDll::ordenNueva::insertarServicioRequerimiento(int servicio, int requerimiento) {
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO servicio_requerimiento (servicio_id,requerimiento_id) \
								VALUES(%d,%d);", servicio, requerimiento);
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

void LibreriaAdDll::ordenNueva::llenarLVDetallesOrden(Win::ListView lvDetalles, int large, bool activo, wstring folio) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	lvDetalles.SetRedraw(false);
	lvDetalles.Cols.DeleteAll();
	lvDetalles.Items.DeleteAll();
	lvDetalles.SetRedraw(true);
	lvDetalles.Cols.Add(0, LVCFMT_CENTER, 100, L"Tipo");
	lvDetalles.Cols.Add(1, LVCFMT_CENTER, 100, L"Tipo");
	lvDetalles.Cols.Add(2, LVCFMT_CENTER, 100, L"Marca");
	lvDetalles.Cols.Add(3, LVCFMT_CENTER, 100, L"Modelo");
	lvDetalles.Cols.Add(4, LVCFMT_CENTER, 100, L"Color");
	lvDetalles.Cols.Add(5, LVCFMT_CENTER, 100, L"Cantidad");
	lvDetalles.Cols.Add(6, LVCFMT_CENTER, 100, L"P. Sugerido");
	lvDetalles.Cols.Add(7, LVCFMT_CENTER, 100, L"P. Final");
	lvDetalles.Cols.Add(8, LVCFMT_CENTER, 100, L"Total");
	lvDetalles.Cols.Add(9, LVCFMT_CENTER, 100, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT od.id, r.tipo, sv.nombre\
			, 'NA', 'NA', 'NA', od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad * od.precio_final, o.fecha\
			FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r, \
			servicio_requerimiento sr, servicio_venta sv\
			WHERE od.orden_id = o.id\
			AND o.cliente_id = c.id\
			AND cc.cliente_id = c.id\
			AND o.puntoVenta_id = pv.id\
			AND od.requerimiento_id = r.id\
			AND sr.requerimiento_id = r.id\
			AND sr.servicioVenta_id = sv.id\
			AND sv.id = od.tipoVentaId\
			AND o.folio = '%s'\
			AND od.cantidad > 0\
			UNION\
			SELECT DISTINCT od.id, r.tipo, ta.nombre, ma.nombre, mo.nombre, \
			col.nombre, od.cantidad, od.precio_sugerido, od.precio_final,od.cantidad * od.precio_final, o.fecha\
			FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r, \
			cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta, color col\
			WHERE od.orden_id = o.id\
			AND o.cliente_id = c.id\
			AND cc.cliente_id = c.id\
			AND o.puntoVenta_id = pv.id\
			AND od.requerimiento_id = r.id\
			AND cr.requerimiento_id = r.id\
			AND cr.cantidad_id = can.id\
			AND can.articulo_id = a.id\
			AND can.color_id = col.id\
			AND a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND a.tipoArticulo_id = ta.id\
			AND can.id = od.tipoVentaId\
			AND od.cantidad > 0\
			AND o.folio = '%s'; ", folio.c_str(), folio.c_str());

		conn.ExecuteSelect(consulta, large, lvDetalles);
	}
	catch (Sql::SqlException e)
	{
		///*/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/*/
	}

	conn.CloseSession();
}


void LibreriaAdDll::ordenNueva::updateCantidaDescrOreden(int descr_id, int cantidad)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE orden_descripcion \
		SET cantidad = %d\
		WHERE id = %d", cantidad,descr_id);
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

void LibreriaAdDll::ordenNueva::updatePrecioDescrOreden(int descr_id, double cantidad)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE orden_descripcion \
		SET precio_final = %lf\
		WHERE id = %d", cantidad, descr_id);
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
int LibreriaAdDll::ordenNueva::sacarCantidad(int id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cantidad\
			FROM cantidad\
			WHERE id = %d", id);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}

void LibreriaAdDll::ordenNueva::updateCantidadInventario(int cantidad_id, int valor)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cantidad \
		SET valor = %d\
		WHERE id = %d", valor, cantidad_id);
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
void  LibreriaAdDll::ordenNueva::llenarDDNombreR(Win::DropDownList ddNombre, int large, int pv_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddNombre.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT us.nombre\
			FROM punto_venta pv, usuario us, puntoVenta_usuario pvu\
			WHERE pvu.puntoVenta_id = pv.id\
			AND pvu.usuario_id = us.id\
			AND pv.id =  %d\
			AND us.activo = true ", pv_id);

		conn.ExecuteSelect(consulta, large, ddNombre);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
int LibreriaAdDll::ordenNueva::sacarIDUsuario(int pv, wstring nombre)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int marca_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT us.id\
			FROM punto_venta pv, usuario us, puntoVenta_usuario pvu\
			WHERE pvu.puntoVenta_id = pv.id\
			AND pvu.usuario_id = us.id\
			AND pv.id = %d\
			AND us.nombre = '%s' ", pv, nombre.c_str());
		marca_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		marca_id = 0;
	}

	conn.CloseSession();
	return marca_id;
}
int LibreriaAdDll::ordenNueva::sacarIDrango(int pFinal, int articulo, int pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ran.id\
			FROM rango ran, articulo art, articulo_rango ar, punto_venta pv\
			WHERE ar.rango_id = ran.id\
			AND ar.articulo_id = art.id\
			AND ar.puntoVenta_id = pv.id\
			AND pv.id = %d\
			AND art.id = %d\
			AND minimo <= %d\
			AND %d <= maximo", pv,articulo, pFinal, pFinal);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}


double LibreriaAdDll::ordenNueva::sacarComision(int id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	double ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT comision \
			FROM rango\
			WHERE id = %d", id);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
int LibreriaAdDll::ordenNueva::sacarUltIDOrden()
{
	wstring consulta;
	Sql::SqlConnection conn;
	int articulos_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM orden\
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

int LibreriaAdDll::ordenNueva::sacarUltIDOrdenDesc()
{
	wstring consulta;
	Sql::SqlConnection conn;
	int articulos_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM orden_descripcion\
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
void LibreriaAdDll::ordenNueva::insertarArticuloComision(double total, bool exito, int rango, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO articulo_comision (total, exito, rango_id, ordenDescripcion_id) \
								VALUES('%lf',%d, %d, %d);", total, exito, rango, orden );
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
void LibreriaAdDll::ordenNueva::actualizarArticuloComision(double total, bool exito, int rango, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE articulo_comision\
								SET total = '%lf' , \
								rango_id = %d \
								WHERE ordenDescripcion_id = %d ;", total, rango, orden);
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

void LibreriaAdDll::ordenNueva::actualizarServicioComision(double total, bool exito, int rango, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE servicio_comision\
								SET total = '%lf' , \
								rango_id = %d \
								WHERE ordenDescripcion_id = %d ;", total, rango, orden);
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
void LibreriaAdDll::ordenNueva::actualizarTotalArticuloComision(int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"update totalarticulo_comision set total=(select sum(ac.total) \
			from orden o, orden_descripcion od, articulo_comision ac\
		where ac.ordenDescripcion_id = od.id\
		and od.orden_id = o.id\
			and o.id = %d)\
		where orden_id = %d; ;",orden, orden);
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
void LibreriaAdDll::ordenNueva::actualizarTotalServicioComision(int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"update totalservicio_comision set total=(select sum(sc.total) \
			from orden o, orden_descripcion od, servicio_comision sc\
		where sc.ordenDescripcion_id = od.id\
		and od.orden_id = o.id\
			and o.id = %d)\
		where orden_id = %d;", orden, orden);
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

int LibreriaAdDll::ordenNueva::sacarIDrangoServicio(int pFinal, int servicio)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ran.id\
			FROM rango ran, servicio_venta sv, servicio_rango sr\
			WHERE sr.rango_id = ran.id\
			AND sr.servicio_id = sv.id\
			AND sv.id = %d\
			AND minimo <= %d\
			AND %d <= maximo", servicio,pFinal, pFinal);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
void LibreriaAdDll::ordenNueva::insertarServicioComision(double total, bool exito, int rango, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO servicio_comision (total, exito, rango_id, ordenDescripcion_id) \
								VALUES('%lf',%d, %d, %d);", total, exito, rango, orden);
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

void LibreriaAdDll::ordenNueva::insertarOrdenCompleta(double total, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO orden_completa (fecha, total, estado, orden_id) \
								VALUES(now(),'%lf',true, %d);", total, orden);
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

void LibreriaAdDll::ordenNueva::insertarCredito(double total, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO credito (total, estado, orden_id) \
								VALUES('%lf',true, %d);", total, orden);
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
void LibreriaAdDll::ordenNueva::insertarTotalServicioComision(double total, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO totalservicio_comision (total, orden_id) \
								VALUES(%lf, %d)", total, orden);
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
void LibreriaAdDll::ordenNueva::insertarTotalArticuloComision(double total, int orden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO totalarticulo_comision (total, orden_id) \
								VALUES(%lf, %d);", total, orden);
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
int LibreriaAdDll::ordenNueva::sacarIDTipoVenta(int ordenDesc)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int categoria_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT tipoVentaId\
			FROM orden_descripcion\
			WHERE id = %d", ordenDesc);
		categoria_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return categoria_id;
}



double LibreriaAdDll::ordenNueva::sacarTotalComision(int ordenDesc)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int categoria_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT total\
			FROM totalArticulo_comision\
			WHERE orden_id = %d", ordenDesc);
		categoria_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return categoria_id;
}
double LibreriaAdDll::ordenNueva::sacarTotalComisionServicio(int ordenDesc)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int categoria_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT total\
			FROM totalServicio_comision\
			WHERE orden_id = %d", ordenDesc);
		categoria_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return categoria_id;
}
double LibreriaAdDll::ordenNueva::sacarComisionArticulo(int id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	double ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT total \
			FROM articulo_comision\
			WHERE ordenDescripcion_id = %d", id);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
double LibreriaAdDll::ordenNueva::sacarComisionServicio(int id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	double ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT total \
			FROM servicio_comision\
			WHERE ordenDescripcion_id = %d", id);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
void LibreriaAdDll::ordenNueva::updateTotalArticuloComision(int id, double totalOrden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE totalArticulo_comision\
		SET total = '%s'\
		WHERE orden_id = %d", totalOrden, id);
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

void LibreriaAdDll::ordenNueva::updateTotalServicioComision(int id, double totalOrden)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE totalServicion_comision\
		SET total = '%s'\
		WHERE orden_id = %d", totalOrden, id);
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


int LibreriaAdDll::ordenNueva::sacarIDColocacion( int pv)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int ma = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT co.id\
			FROM punto_venta pv, colocacion co, puntoVenta_colocacion pvc\
			WHERE pvc.puntoVenta_id = pv.id\
			AND pvc.colocacion_id = co.id\
			AND pv.id = %d", pv);
		ma = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}