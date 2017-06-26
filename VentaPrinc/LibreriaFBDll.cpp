#include "stdafx.h"  //_____________________________________________ LibreriaFBDll.cpp
#include "LibreriaFBDll.h"
/* ESTA LIBRERIA CONTIENE LOS METODOS NECESARIOS PARA LA PARTE DE MODELO(AGREGAR, EDITAR, ELIMINAR, RESTAURAR;
   ADEMAS DE LOS METODOS PARA LOS DIALOGOS DE LA BUSQUEDA Y EL DIALOGO DE MOVIMIENTO
*/

//Metodos que llenan los Drop Down List
void LibreriaFBDll::Modelo::llenarDDMarcas(Win::DropDownList ddMarcas, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddMarcas.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre \
			FROM marca \
			WHERE activo = true\
			ORDER BY nombre ASC  ");

		conn.ExecuteSelect(consulta, large, ddMarcas);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}



//------------------------------------------Modelo----------------------------------------------------------------
void LibreriaFBDll::Movimiento::llenarDDMovimientos(Win::DropDownList ddMarcas, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddMarcas.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, nombre \
			FROM tipo_movimiento \
			WHERE activo = true\
			ORDER BY nombre ASC  ");

		conn.ExecuteSelect(consulta, large, ddMarcas);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}


//Metodo para llenar un tab
void LibreriaFBDll::Busqueda::llenarTab(Win::Tab  tbBusqueda)
{
	LibreriaFBDll::Busqueda libreriaObj;
	 int _cantidadpuntosVP = libreriaObj.sacarCantidadPV();
	 wstring resultadoPuntosVenta;

	for (int i = 1 ;  i <= _cantidadpuntosVP; i++)
	{
	LibreriaFBDll::Busqueda libreriaObj;
	resultadoPuntosVenta = libreriaObj.sacarDepartamento(i);
	if (resultadoPuntosVenta != L"")
	{
	tbBusqueda.Items.Add(i, resultadoPuntosVenta);

	}
	}



}

// Metodos para insertar a la base de datos
void LibreriaFBDll::Modelo::insertarModelo(wstring modelo, int id_marca) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO modelo (nombre,activo,marca_id) \
				VALUES('%s',true,%d);", modelo.c_str(), id_marca);
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

// Sacar los ID dependiendo del nombre
int LibreriaFBDll::Modelo::sacarIDMarca(wstring marca) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int modelo_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM marca\
			WHERE nombre = '%s';", marca.c_str());
		modelo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return modelo_id;
}


int LibreriaFBDll::Movimiento::sacarIDUsuario(wstring usuario)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int modelo_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM usuario\
			WHERE nombre = '%s';", usuario.c_str());
		modelo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return modelo_id;
}

int LibreriaFBDll::Movimiento::sacarIDMovimiento(wstring movimiento)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int modelo_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM tipo_movimiento\
			WHERE nombre = '%s';", movimiento.c_str());
		modelo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return modelo_id;
}


//Llena los List View de todos los modelos
void LibreriaFBDll::Modelo::llenarLVModelos(Win::ListView lvDepartamento, int large, int marca)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 300, L"Modelos");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.id ,m.nombre \
			FROM modelo m \
			WHERE m.marca_id = %d \
			AND  activo = true\
			ORDER BY nombre ASC",marca);
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

// Recuperar o eliminar modelos de la base de datos

// Llena un LV con los modelos inactivos
void LibreriaFBDll::Modelo::llenarLVModelosInactivos(Win::ListView lvDepartamento, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 300, L"Modelos");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.id,m.nombre \
			FROM modelo m\
			WHERE m.activo = false\
			ORDER BY nombre ASC");
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//llena un LV con los modelos activos
void LibreriaFBDll::Modelo::llenarLVModelosActivos(Win::ListView lvDepartamento, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 300, L"Modelos");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.id,m.nombre \
			FROM modelo m\
			WHERE m.activo = true\
			ORDER BY nombre ASC");
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//metodo para recuperar el modelo
void LibreriaFBDll::Modelo::recuperarModelo(int modelo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE modelo m\
		SET activo = true\
		WHERE m.id = %d", modelo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//metodo para eliminar un modelo 
void LibreriaFBDll::Modelo::eliminarModelo(int modelo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE modelo m\
		SET activo = false\
		WHERE m.id = %d", modelo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

int LibreriaFBDll::Modelo::sacarIDOculto(Win::ListView lv2)
{
	int indice = lv2.GetSelectedIndex();
	int id = lv2.Items[indice].Data;

	return id;
}

// Actualizar el modelo
// consulta para  saber si ya existe el modelo
wstring LibreriaFBDll::Modelo::sacarModelo(int marca_id) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.Nombre\
			FROM modelo m\
			WHERE m.id = %d", marca_id);
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
	/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
// metodo para actualizar el modelo

void LibreriaFBDll::Modelo::actualizarModelo( wstring modelo,int modelo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE modelo m \
		SET nombre = '%s'\
		WHERE m.id = %d ",modelo.c_str(), modelo_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{

			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//Esta consulta saca la marca dependiendo del modelo seleccionado
wstring LibreriaFBDll::Modelo:: sacarMarcadelModelo(int modelo_id) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ma.Nombre\
			FROM marca ma, modelo mo\
			WHERE mo.marca_id= ma.id\
			AND mo.id = %d",modelo_id);
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}
//
//wstring LibreriaFBDll::Movimiento::sacarPuntosVentaCodigo(wstring codigo)
//{
//	wstring consulta;
//	Sql::SqlConnection conn;
//	wstring ma;
//
//	try
//	{
//		conn.OpenSession(hWnd, CONNECTION_STRING);
//		Sys::Format(consulta, L"SELECT  distinct  pv.tipo\
//			FROM punto_venta pv, articulo a,cantidad ca\
//			WHERE ca.articulo_id = a.id\
//			AND  ca.puntoVenta_id = pv.id\
//			AND a.codigo = \
//			ORDER BY pv.tipo ASC limit 1 '%s'",codigo.c_str());
//		conn.GetString(consulta, ma, 50);
//	}
//	catch (Sql::SqlException e)
//	{
//		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
//	}
//
//	conn.CloseSession();
//	return ma;
//}
//
//
//wstring LibreriaFBDll::Movimiento::sacarPuntosVentaMarca(wstring marca)
//{
//	wstring consulta;
//	Sql::SqlConnection conn;
//	wstring ma;
//
//	try
//	{
//		conn.OpenSession(hWnd, CONNECTION_STRING);
//		Sys::Format(consulta, L"SELECT  distinct pv.id , pv.tipo\
//			FROM punto_venta pv, articulo a, modelo mo, marca ma, cantidad ca\
//			WHERE a.modelo_id = mo.id\
//			AND mo.marca_id = ma.id\
//			AND ca.articulo_id = a.id\
//			AND pv.id = ca.puntoVenta_id\
//			AND ma.nombre = \
//			ORDER BY id ASC limit 1 '%s'", marca.c_str());
//		conn.GetString(consulta, ma, 50);
//	}
//	catch (Sql::SqlException e)
//	{
//		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
//	}
//
//	conn.CloseSession();
//	return ma;
//}
//
//wstring LibreriaFBDll::Movimiento::sacarPuntosVentaModelo(wstring modelo)
//{
//	wstring consulta;
//	Sql::SqlConnection conn;
//	wstring ma;
//
//	try
//	{
//		conn.OpenSession(hWnd, CONNECTION_STRING);
//		Sys::Format(consulta, L"SELECT  distinct pv.id ,pv.tipo\
//			FROM articulo a, modelo mo, punto_venta pv, cantidad ca\
//			WHERE a.modelo_id = mo.id\
//			AND ca.articulo_id = a.id\
//			AND ca.puntoVenta_id = pv.id\
//			AND mo.nombre =   \
//			ORDER BY id ASC limit 1'%s'", modelo.c_str());
//		conn.GetString(consulta, ma, 50);
//	}
//	catch (Sql::SqlException e)
//	{
//		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
//	}
//
//	conn.CloseSession();
//	return ma;
//}
//
//wstring LibreriaFBDll::Movimiento::sacarPuntosVentatipoArt(wstring tipoArt)
//{
//	wstring consulta;
//	Sql::SqlConnection conn;
//	wstring ma;
//
//	try
//	{
//		conn.OpenSession(hWnd, CONNECTION_STRING);
//		Sys::Format(consulta, L"SELECT  distinct pv.id,pv.tipo\
//			FROM articulo a, modelo mo, punto_venta pv, cantidad ca, tipo_articulo ta\
//			WHERE a.modelo_id = mo.id\
//			AND a.tipoArticulo_id = ta.id\
//			AND ca.articulo_id = a.id\
//			AND ca.puntoVenta_id = pv.id\
//			AND ta.nombre = \
//			ORDER BY id ASC limit 1 '%s'", tipoArt.c_str());
//		conn.GetString(consulta, ma, 50);
//	}
//	catch (Sql::SqlException e)
//	{
//		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
//	}
//
//	conn.CloseSession();
//	return ma;
//}



//Consulta para saber si el modelo ya existe
wstring LibreriaFBDll::Modelo::sacarModeloSiExiste(wstring nombreModelo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
			FROM modelo\
			WHERE nombre = '%s' ", nombreModelo.c_str());
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return valor;
}

//void LibreriaFBDll::Busqueda::llenarArticulos(Win::ListView lvBusqueda, wstring nombre, int large) {
//
//	wstring consulta;
//	Sql::SqlConnection conn;
//	int rows = 0;
//	lvBusqueda.SetRedraw(false);
//	lvBusqueda.Cols.DeleteAll();
//	lvBusqueda.Items.DeleteAll();
//	lvBusqueda.SetRedraw(true);
//	lvBusqueda.Cols.Add(0, LVCFMT_CENTER, 100, L"Código");
//	lvBusqueda.Cols.Add(1, LVCFMT_CENTER, 100, L"Tipo de Articulo");
//	lvBusqueda.Cols.Add(2, LVCFMT_CENTER, 100, L"Modelo");
//	lvBusqueda.Cols.Add(3, LVCFMT_CENTER, 100, L"Marca");
//	lvBusqueda.Cols.Add(4, LVCFMT_CENTER, 100, L"Precio");
//	lvBusqueda.Cols.Add(5, LVCFMT_CENTER, 100, L"Color");
//	lvBusqueda.Cols.Add(7, LVCFMT_CENTER, 100, L"Departamento");
//	lvBusqueda.Cols.Add(8, LVCFMT_CENTER, 100, L"Cantidad");
//
//
//	try
//	{
//		conn.OpenSession(hWnd, CONNECTION_STRING);
//		Sys::Format(consulta, L"select a.id,a.Codigo,ta.nombre,mo.nombre, ma.nombre, a.precio, co.nombre,pv.tipo,can.valor\
//			from articulo a, modelo mo, marca ma, punto_venta pv, color co, cantidad can, tipo_articulo ta\
//		where a.modelo_id = mo.id\
//		and a.tipoArticulo_id = ta.id\
//			and can.articulo_id = a.id\
//			and can.color_id = co.id\
//			and can.puntoVenta_id = pv.id\
//			and a.codigo = '%s'", nombre.c_str());
//
//		conn.ExecuteSelect(consulta, large, lvBusqueda);
//	}
//	catch (Sql::SqlException e)
//	{
//		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
//	}
//
//	conn.CloseSession();
//}


// esta consukta devuelve el nombre del punto de venta dependiendo del id de este 
wstring LibreriaFBDll::Busqueda::sacarDepartamento(int pv_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT pv.tipo\
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

int LibreriaFBDll::Movimiento::sacarIDpuntoVenta(wstring puntoVenta) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int valor = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM  punto_venta \
			WHERE tipo = '%s' \
			AND activo = true ",puntoVenta.c_str());
		valor = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}

int LibreriaFBDll::Busqueda::sacarCantidadPV() 
{
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





//subconsultas para las busquedas
//Subconsulta que busca por codigo de articulo
void LibreriaFBDll::Busqueda::llenarArticulosCodigo(Win::ListView lvTabla,int puntoVenta, wstring codigo, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"Código");
	lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Tipo de articulo");
	lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");
	lvTabla.Cols.Add(3, LVCFMT_LEFT, 120, L"Marca");
	lvTabla.Cols.Add(4, LVCFMT_LEFT, 120, L"Precio");
	lvTabla.Cols.Add(6, LVCFMT_LEFT, 120, L"Departamento");
	lvTabla.Cols.Add(7, LVCFMT_LEFT, 120, L"Cantidad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT  DISTINCT a.id,a.codigo,ta.nombre,mo.nombre, ma.nombre, a.precio,pv.tipo,\
			(SELECT SUM(ca.valor)\
				FROM articulo art, punto_venta pva, cantidad ca\
				WHERE ca.articulo_id = a.id\
				AND pva.id = pv.id\
				AND ca.puntoVenta_id = pva.id\
				AND art.id = a.id)\
				FROM articulo a, modelo mo, marca ma, punto_venta pv, cantidad can, tipo_articulo ta\
				WHERE a.modelo_id = mo.id\
				AND mo.marca_id = ma.id\
				AND a.tipoArticulo_id = ta.id\
				AND can.articulo_id = a.id\
				AND can.puntoVenta_id = pv.id\
				AND can.valor > 0\
				AND pv.id = %d \
				AND a.codigo = '%s'",puntoVenta, codigo.c_str());

		conn.ExecuteSelect(consulta,large,lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//esta consulta saca el color de un determinado articulo dependiendo del codigo
void LibreriaFBDll::Busqueda::llenarColorCodigo(Win::ListView lvDepartamento, wstring codigo, int puntoId, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.DeleteAllItems();
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 140, L"Colores disponibles");
	lvDepartamento.Cols.Add(1, LVCFMT_CENTER, 150, L"Cantidad disponible");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L" SELECT co.id,co.nombre,ca.valor \
			FROM color co, punto_venta pv, cantidad ca, articulo art \
			WHERE ca.articulo_id = art.id \
			AND ca.puntoVenta_id = pv.id \
			AND co.id = ca.color_id \
			AND ca.valor > 0\
			AND art.codigo = '%s' \
			AND co.activo = true \
			AND pv.id=  %d ", codigo.c_str(), puntoId);
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

 //Subconsulta que busca por marca 
void LibreriaFBDll::Busqueda::llenarArticulosMarca(Win::ListView lvTabla, int puntoVenta, wstring marca, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"Código");
	lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Tipo de articulo");
	lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");
	lvTabla.Cols.Add(3, LVCFMT_LEFT, 120, L"Marca");
	lvTabla.Cols.Add(4, LVCFMT_LEFT, 120, L"Precio");
	lvTabla.Cols.Add(6, LVCFMT_LEFT, 120, L"Departamento");
	lvTabla.Cols.Add(7, LVCFMT_LEFT, 120, L"Cantidad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT  DISTINCT a.id,a.codigo,ta.nombre,mo.nombre, ma.nombre, a.precio,pv.tipo,\
			(SELECT SUM(ca.valor)\
				FROM articulo art, punto_venta pva, cantidad ca\
				WHERE ca.articulo_id = a.id\
				AND pva.id = pv.id\
				AND ca.puntoVenta_id = pva.id\
				AND art.id = a.id)\
				FROM articulo a, modelo mo, marca ma, punto_venta pv, cantidad can, tipo_articulo ta\
				WHERE a.modelo_id = mo.id\
				AND mo.marca_id = ma.id\
				AND a.tipoArticulo_id = ta.id\
				AND can.articulo_id = a.id\
				AND can.puntoVenta_id = pv.id\
				AND can.valor > 0\
				AND pv.id = %d \
				AND ma.nombre = '%s'", puntoVenta, marca.c_str());

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		
	}

	conn.CloseSession();
}

//Subconsulta para la busqueda por modelos
void LibreriaFBDll::Busqueda::llenarArticulosModelo(Win::ListView lvTabla, int puntoVenta, wstring modelo, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"Código");
	lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Tipo de articulo");
	lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");
	lvTabla.Cols.Add(3, LVCFMT_LEFT, 120, L"Marca");
	lvTabla.Cols.Add(4, LVCFMT_LEFT, 120, L"Precio");
	lvTabla.Cols.Add(6, LVCFMT_LEFT, 120, L"Departamento");
	lvTabla.Cols.Add(7, LVCFMT_LEFT, 120, L"Cantidad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT a.id,a.codigo,ta.nombre,mo.nombre, ma.nombre, a.precio,pv.tipo,\
			(SELECT SUM(ca.valor)\
				FROM articulo art, punto_venta pva, cantidad ca\
				WHERE ca.articulo_id = a.id\
				AND pva.id = pv.id\
				AND ca.puntoVenta_id = pva.id\
				AND art.id = a.id)\
			FROM articulo a, modelo mo, marca ma, punto_venta pv, cantidad can, tipo_articulo ta\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND a.tipoArticulo_id = ta.id\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND can.valor > 0\
			AND pv.id = %d \
			AND mo.nombre = '%s'", puntoVenta, modelo.c_str());

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}
//subconsulta que hace la busqueda por tipo de articulo

void LibreriaFBDll::Busqueda::llenarArticulosTipoArt(Win::ListView lvTabla, int puntoVenta, wstring tipoArt, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_LEFT, 120, L"Código");
	lvTabla.Cols.Add(1, LVCFMT_LEFT, 120, L"Tipo de articulo");
	lvTabla.Cols.Add(2, LVCFMT_LEFT, 120, L"Modelo");
	lvTabla.Cols.Add(3, LVCFMT_LEFT, 120, L"Marca");
	lvTabla.Cols.Add(4, LVCFMT_LEFT, 120, L"Precio");
	lvTabla.Cols.Add(6, LVCFMT_LEFT, 120, L"Departamento");
	lvTabla.Cols.Add(7, LVCFMT_LEFT, 120, L"Cantidad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT DISTINCT a.id,a.codigo,ta.nombre,mo.nombre, ma.nombre, a.precio,pv.tipo,\
			(SELECT SUM(ca.valor)\
				FROM articulo art, punto_venta pva, cantidad ca\
				WHERE ca.articulo_id = a.id\
				AND pva.id = pv.id\
				AND ca.puntoVenta_id = pva.id\
				AND art.id = a.id)\
			FROM articulo a, modelo mo, marca ma, punto_venta pv, cantidad can, tipo_articulo ta\
			WHERE a.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND a.tipoArticulo_id = ta.id\
			AND can.articulo_id = a.id\
			AND can.puntoVenta_id = pv.id\
			AND can.valor > 0\
			AND pv.id = %d \
			AND ta.nombre = '%s'", puntoVenta, tipoArt.c_str());

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//esta consulta saca el color de un determinado tipo de articulo 
void LibreriaFBDll::Busqueda::llenarColorTipoArt(Win::ListView lvDepartamento, wstring tipoArt, int puntoId, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.DeleteAllItems();
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 140, L"Colores disponibles");
	lvDepartamento.Cols.Add(1, LVCFMT_CENTER, 150, L"Cantidad disponible");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L" SELECT co.id,co.nombre, ca.valor \
			FROM color co, punto_venta pv, cantidad ca, articulo art , tipo_articulo ta\
			WHERE ca.articulo_id = art.id \
			AND ca.puntoVenta_id = pv.id \
			AND co.id = ca.color_id \
			AND art.tipoArticulo_id = ta.id\
			AND ca.valor > 0\
			AND ta.nombre = '%s' \
			AND co.activo = true \
			AND pv.id=  %d ", tipoArt.c_str(), puntoId);
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}


 // llena un LV con los colores disponibles de un modelo en especifico
void LibreriaFBDll::Busqueda::llenarColorModelo(Win::ListView lvDepartamento, wstring modelo, int puntoId, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.DeleteAllItems();
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 140, L"Colores disponibles");
	lvDepartamento.Cols.Add(1, LVCFMT_CENTER, 150, L"Cantidad disponible");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L" SELECT co.id,co.nombre, ca.valor \
			FROM color co, punto_venta pv, cantidad ca, articulo art, modelo mo \
			WHERE ca.articulo_id = art.id \
			AND ca.puntoVenta_id = pv.id \
			AND mo.id = art.modelo_id\
			AND co.id = ca.color_id \
			AND ca.valor > 0\
			AND mo.nombre = '%s' \
			AND co.activo = true \
			AND pv.id=  %d ", modelo.c_str(), puntoId);
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}




// llena una LV con los colores disponibles de una marca en especifico
void LibreriaFBDll::Busqueda::llenarColorMarca(Win::ListView lvDepartamento, wstring marca, int puntoId, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.DeleteAllItems();
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 140, L"Colores disponibles");
	lvDepartamento.Cols.Add(1, LVCFMT_CENTER, 150, L"Cantidad disponible");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L" SELECT co.id,co.nombre, ca.valor\
			FROM color co, punto_venta pv, cantidad ca, articulo art,marca ma, modelo mo \
			WHERE ca.articulo_id = art.id \
			AND ca.puntoVenta_id = pv.id \
			AND art.modelo_id = mo.id\
			AND mo.marca_id = ma.id\
			AND co.id = ca.color_id \
			AND ca.valor > 0\
			AND ma.nombre = '%s' \
			AND co.activo = true \
			AND pv.id=  %d ", marca.c_str(), puntoId);
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}




//esta consulta saca el id del punto de venta dependiendo de nombre proporcionado
int LibreriaFBDll::Busqueda::sacarIDPuntoV(wstring puntoVenta)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int dpto_id = 0;

	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM punto_venta\
			WHERE tipo = '%s';", puntoVenta.c_str());
		dpto_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
	}

	conn.CloseSession();
	return dpto_id;


}
 //esta consulta saca la ultima marca registrada
wstring LibreriaFBDll::Modelo::sacarUltimaMarca()
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.nombre\
			FROM marca m\
			ORDER BY id DESC limit 1;");
		conn.GetString(consulta, ma, 50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return ma;
}


wstring LibreriaFBDll::Modelo::sacarUltimoModelo() 
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring mo;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT m.nombre\
			FROM modelo m\
			ORDER BY id DESC limit 1;");
		conn.GetString(consulta, mo, 50);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return mo;
}

// sacar el codigo de la LV
wstring LibreriaFBDll::Busqueda::sacarCodigoLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring codigo = lvTabla.Items[s].GetText(columna);
	return codigo;
}
// sacar la marca de la LV
wstring LibreriaFBDll::Busqueda::sacarMarcaLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring marca = lvTabla.Items[s].GetText(columna);
	return marca;
}

// sacar el modelo de la LV
wstring LibreriaFBDll::Busqueda::sacarModeloLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring marca = lvTabla.Items[s].GetText(columna);
	return marca;
}

// sacar el tipo de articulo de la LV
wstring LibreriaFBDll::Busqueda::sacartipoArtLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring tipoArt = lvTabla.Items[s].GetText(columna);
	return tipoArt;
}

// sacar el punto de venta de la LV
wstring LibreriaFBDll::Busqueda::sacarpuntoVentLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring puntoVenta = lvTabla.Items[s].GetText(columna);
	return puntoVenta;
}

// sacar el precio de la LV
wstring LibreriaFBDll::Busqueda::sacarprecioLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring precio = lvTabla.Items[s].GetText(columna);
	return precio;
}

// sacar el color de la LV
wstring LibreriaFBDll::Busqueda::sacarcolorLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring color = lvTabla.Items[s].GetText(columna);
	return color;
}

// sacar la cantidad de la LV
wstring LibreriaFBDll::Busqueda::sacarcantidadLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring cantidad = lvTabla.Items[s].GetText(columna);
	return cantidad;
}

//---------------------------------------Movimiento------------------------------------------------

int LibreriaFBDll::Movimiento::sacarCantidadDepartamento(wstring color,int departamento_id, int articulo_id)
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
				AND art.id = %d ", color.c_str(),departamento_id, articulo_id);
			valor = conn.GetInt(consulta);
		}
		catch (Sql::SqlException e)
		{
			/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
		}

		conn.CloseSession();

		return valor;
	}
int LibreriaFBDll::Movimiento::sacarIDCantidad(wstring color, int departamento_id, int articulo_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int valor = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT can.id\
				FROM  cantidad can, articulo art, color co, punto_venta pv\
				WHERE can.puntoVenta_id = pv.id\
				AND can.color_id = co.id\
				AND can.articulo_id = art.id\
				AND co.nombre = '%s'\
				AND pv.id = %d \
				AND art.id = %d ", color.c_str(), departamento_id, articulo_id);
		valor = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return valor;
}
void LibreriaFBDll::Movimiento::llenarDDdepartamentoFiltro(Win::DropDownList ddDepartamento, int large, bool activo, wstring departamento) {
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
								AND tipo  != '%s'\
								ORDER BY tipo ASC;", activo, departamento.c_str());

		conn.ExecuteSelect(consulta, large, ddDepartamento);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}




void LibreriaFBDll::Movimiento::llenarDDusuarios(Win::DropDownList ddUsuarios, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddUsuarios.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre \
			FROM usuario \
			WHERE activo = true\
			ORDER BY nombre ASC  ");

		conn.ExecuteSelect(consulta, large, ddUsuarios);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}


void LibreriaFBDll::Movimiento::insertarMovimiento(int cantidad , int tipoMovimiento_id,int puntoVenta_id,int articulo_id,int usuario_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO movimiento (cantidad,tipoMovimiento_id,puntoVenta_id,articulo_id,usuario_id) \
				VALUES(%d,%d,%d,%d,%d);",cantidad,tipoMovimiento_id,puntoVenta_id,articulo_id,usuario_id);
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

int LibreriaFBDll::Movimiento::sacarIDUltimoMovimiento() 
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
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return articulos_id;
}
void LibreriaFBDll::Movimiento::insertarfechaMovimiento(int movimiento_id) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO fecha_movimiento (fecha,movimiento_id) \
				VALUES(now(),%d);", movimiento_id);
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

void LibreriaFBDll::Movimiento::updateCantidad(int valor,int cantidadId)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE cantidad \
		SET valor = %d \
		WHERE id = %d " ,valor,cantidadId);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

void LibreriaFBDll::Movimiento::insertarcantidad(int valor,int articulo_id,int color_id, int puntoVenta_id) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO cantidad (valor,articulo_id,color_id,puntoVenta_id) \
				VALUES(%d, %d, %d, %d);", valor,articulo_id,color_id,puntoVenta_id);
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

int LibreriaFBDll::Movimiento::sacarIDcolor(wstring color)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int modelo_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM color\
			WHERE nombre = '%s';", color.c_str());
		modelo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return modelo_id;
}