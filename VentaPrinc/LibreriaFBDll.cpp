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


// esta consulta devuelve el nombre del punto de venta dependiendo del id de este 
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

//--------------------------------------------VENTAS--------------------------------------//
//Aqui empiezan los metodos para la parte  de ventas

//-----------------------------------CIUDAD------------------------//

//Llena un LV con las ciudades activas
void LibreriaFBDll::Ciudad::llenarLVCiudad(Win::ListView lvCiudad, int large) 
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCiudad.SetRedraw(false);
	lvCiudad.Cols.DeleteAll();
	lvCiudad.Items.DeleteAll();
	lvCiudad.SetRedraw(true);
	lvCiudad.Cols.Add(0, LVCFMT_CENTER, 300, L"Ciudad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.id,c.nombre \
			FROM ciudad c\
			WHERE c.activo = true\
			ORDER BY nombre ASC");
		conn.ExecuteSelect(consulta, large, lvCiudad);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}
// Llena un LV con las ciudades inactivas

void LibreriaFBDll::Ciudad::llenarLVCiudadInactiva(Win::ListView lvCiudad, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCiudad.SetRedraw(false);
	lvCiudad.Cols.DeleteAll();
	lvCiudad.Items.DeleteAll();
	lvCiudad.SetRedraw(true);
	lvCiudad.Cols.Add(0, LVCFMT_CENTER, 300, L"Ciudad");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.id,c.nombre \
			FROM ciudad c\
			WHERE c.activo = false\
			ORDER BY nombre ASC");
		conn.ExecuteSelect(consulta, large, lvCiudad);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//Inserta un ciudad en la base de datos

void LibreriaFBDll::Ciudad::insertarCiudad(wstring ciudad,int lada_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO ciudad (nombre,activo,lada_id) \
				VALUES( '%s',true, %d );", ciudad.c_str(),lada_id);
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

//Verifica que no exista la ciudad

wstring LibreriaFBDll::Ciudad::sacarCiudad(wstring ciudad,int lada)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
			FROM ciudad\
			WHERE nombre = '%s'",ciudad.c_str());
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return valor;
}
//saca la lada de una ciudad
wstring LibreriaFBDll::Ciudad::sacarLada(wstring ciudad)
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring valor;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT la.tipo\
			FROM lada la, ciudad c\
			WHERE c.lada_id = la.id\
			AND c.nombre = '%s'", ciudad.c_str());
		conn.GetString(consulta, valor, 100);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return valor;
}


// Saca un texto especifico
wstring LibreriaFBDll::Ciudad::sacarTextoLV(Win::ListView lvTabla, int columna)
{
	int s = lvTabla.GetSelectedIndex();
	wstring codigo = lvTabla.Items[s].GetText(columna);
	return codigo;
}

//Actualiza una ciudad
void LibreriaFBDll::Ciudad::actualizarCiudad(wstring nombre,int ciudad_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE ciudad \
		SET nombre = '%s' \
		WHERE id = %d",nombre.c_str(),ciudad_id);
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


void LibreriaFBDll::Ciudad::actualizarLadaCiudad( int ciudad_id,int lada_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE ciudad \
		SET lada_id = %d \
		WHERE id = %d", lada_id, ciudad_id);
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

//Elimina o recupera una ciudad 

void LibreriaFBDll::Ciudad::eliminarRecuperarCiudad(int modelo_id,bool estado)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE ciudad \
		SET activo = %d\
		WHERE id = %d",estado, modelo_id);
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


int LibreriaFBDll::Ciudad::sacarIDLada(wstring tipo)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int modelo_id = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id\
			FROM lada\
			WHERE tipo = '%s';", tipo.c_str());
		modelo_id = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return modelo_id;
}

//------------------------------BONO CREDITO------------------------------------//
void LibreriaFBDll::bonoCredito::llenarLVCreditoCCliente(Win::ListView lvCredito, wstring claveCliente,int puntoVenta_id, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCredito.SetRedraw(false);
	lvCredito.Cols.DeleteAll();
	lvCredito.Items.DeleteAll();
	lvCredito.SetRedraw(true);
	lvCredito.Cols.Add(0, LVCFMT_CENTER, 100, L"Total");
	lvCredito.Cols.Add(1, LVCFMT_CENTER, 100, L"Folio");
	lvCredito.Cols.Add(2, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvCredito.Cols.Add(3, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvCredito.Cols.Add(4, LVCFMT_CENTER, 100, L"Departamento");
	lvCredito.Cols.Add(5, LVCFMT_CENTER, 130, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cre.id,cre.total,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y')\
			FROM credito cre, orden ord, cliente cli, clave_cliente ccli, punto_venta pv\
			WHERE cre.orden_id = ord.id\
			AND ord.cliente_id = cli.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ccli.numero = '%s'\
			AND cli.activo = true\
			AND pv.id = %d\
			AND cre.estado = true \
			AND cre.total > 0 ;", claveCliente.c_str(), puntoVenta_id);
		conn.ExecuteSelect(consulta, large, lvCredito);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//Este metodo llena el LV con los datos de un credito dependiendo del folio de la orden
void LibreriaFBDll::bonoCredito::llenarLVCreditoFolio(Win::ListView lvCredito, wstring folio, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCredito.SetRedraw(false);
	lvCredito.Cols.DeleteAll();
	lvCredito.Items.DeleteAll();
	lvCredito.SetRedraw(true);
	lvCredito.Cols.Add(0, LVCFMT_CENTER, 100, L"Total");
	lvCredito.Cols.Add(1, LVCFMT_CENTER, 100, L"Folio");
	lvCredito.Cols.Add(2, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvCredito.Cols.Add(3, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvCredito.Cols.Add(4, LVCFMT_CENTER, 100, L"Departamento");
	lvCredito.Cols.Add(5, LVCFMT_CENTER, 130, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cre.id,cre.total,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y')\
			FROM credito cre, orden ord, cliente cli, clave_cliente ccli, punto_venta pv\
			WHERE cre.orden_id = ord.id\
			AND ord.cliente_id = cli.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ord.folio = '%s'\
			AND cli.activo = true\
			AND cre.estado = true\
			AND cre.total > 0 ;", folio.c_str());
		conn.ExecuteSelect(consulta, large, lvCredito);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}


void LibreriaFBDll::bonoCredito::llenarLVCreditoNombre(Win::ListView lvCredito, wstring nombre, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCredito.SetRedraw(false);
	lvCredito.Cols.DeleteAll();
	lvCredito.Items.DeleteAll();
	lvCredito.SetRedraw(true);
	lvCredito.Cols.Add(0, LVCFMT_CENTER, 100, L"Folio");
	lvCredito.Cols.Add(1, LVCFMT_CENTER, 100, L"Total");
	lvCredito.Cols.Add(2, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvCredito.Cols.Add(3, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvCredito.Cols.Add(4, LVCFMT_CENTER, 100, L"Departamento");
	lvCredito.Cols.Add(5, LVCFMT_CENTER, 130, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cre.id,ord.folio,cre.total,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y')\
			FROM credito cre, orden ord, cliente cli, clave_cliente ccli, punto_venta pv\
			WHERE cre.orden_id = ord.id\
			AND ord.cliente_id = cli.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND cli.nombre = '%s'\
			AND cli.activo = true\
			AND cre.estado = true\
			and cre.cantidad > 0; ", nombre.c_str());
		conn.ExecuteSelect(consulta, large, lvCredito);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

void LibreriaFBDll::Ciudad::llenarDDLada(Win::DropDownList ddLada, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddLada.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id, tipo \
			FROM lada\
			WHERE activo = true\
			ORDER BY tipo ASC ");

		conn.ExecuteSelect(consulta, large, ddLada);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

void LibreriaFBDll::bonoCredito::updateCantidadCredito(double valor, int creditoId)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE credito \
		SET total = %lf \
		WHERE id = %d ", valor, creditoId);
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

void LibreriaFBDll::bonoCredito::llenarLVCreditoAbonos(Win::ListView lvCredito, int creditoId,wstring folio, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCredito.SetRedraw(false);
	lvCredito.Cols.DeleteAll();
	lvCredito.Items.DeleteAll();
	lvCredito.SetRedraw(true);
	lvCredito.Cols.Add(0, LVCFMT_CENTER, 100, L"Abono");
	lvCredito.Cols.Add(1, LVCFMT_CENTER, 100, L"Folio");
	lvCredito.Cols.Add(2, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvCredito.Cols.Add(3, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvCredito.Cols.Add(4, LVCFMT_CENTER, 100, L"Departamento");
	lvCredito.Cols.Add(5, LVCFMT_CENTER, 130, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cre.id,bono.cantidad,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(bono.fecha,'%%d/%%b/%%y')\
			FROM credito cre, orden ord, cliente cli, clave_cliente ccli, punto_venta pv,bono_credito bono\
			WHERE cre.orden_id = ord.id\
			AND ord.cliente_id = cli.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND bono.credito_id= cre.id\
			AND cre.id = %d \
			AND cli.activo = true\
			AND ord.folio = '%s'\
			AND cre.estado = true\
			AND cre.total > 0; ", creditoId,folio.c_str());
		conn.ExecuteSelect(consulta, large, lvCredito);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

void LibreriaFBDll::bonoCredito::insertarbonoCredito(double cantidad,int creditoId)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO bono_credito (cantidad,fecha,credito_id) \
				VALUES(%lf,now(),%d);",cantidad,creditoId);
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
//PENDIENTE

//
void LibreriaFBDll::bonoCredito::llenarLVOrdenCredito(Win::ListView lvCredito, wstring folio,int creditoId,int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCredito.SetRedraw(false);
	lvCredito.Cols.DeleteAll();
	lvCredito.Items.DeleteAll();
	lvCredito.SetRedraw(true);
	lvCredito.Cols.Add(0, LVCFMT_CENTER, 100, L"Total");
	lvCredito.Cols.Add(1, LVCFMT_CENTER, 100, L"Folio");
	lvCredito.Cols.Add(2, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvCredito.Cols.Add(3, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvCredito.Cols.Add(4, LVCFMT_CENTER, 100, L"Departamento");
	lvCredito.Cols.Add(5, LVCFMT_CENTER, 130, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cre.id,cre.total,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y')\
			FROM credito cre, orden ord, cliente cli, clave_cliente ccli, punto_venta pv\
			WHERE cre.orden_id = ord.id\
			AND ord.cliente_id = cli.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ord.folio = '%s'\
			AND cli.activo = true\
			AND cre.id = %d\
			AND cre.estado = true; ", folio.c_str(),creditoId);
		conn.ExecuteSelect(consulta, large, lvCredito);
	}

	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
} 

void LibreriaFBDll::bonoCredito::llenarLVOrdenCompleta(Win::ListView lvCredito, wstring folio, int orcomId, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvCredito.SetRedraw(false);
	lvCredito.Cols.DeleteAll();
	lvCredito.Items.DeleteAll();
	lvCredito.SetRedraw(true);
	lvCredito.Cols.Add(0, LVCFMT_CENTER, 100, L"Total");
	lvCredito.Cols.Add(1, LVCFMT_CENTER, 100, L"Folio");
	lvCredito.Cols.Add(2, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvCredito.Cols.Add(3, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvCredito.Cols.Add(4, LVCFMT_CENTER, 100, L"Departamento");
	lvCredito.Cols.Add(5, LVCFMT_CENTER, 130, L"Fecha");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT cre.id,orcom.total,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y')\
			FROM credito cre, orden ord, cliente cli, clave_cliente ccli, punto_venta pv,orden_completa orcom\
			WHERE cre.orden_id = ord.id\
			AND ord.cliente_id = cli.id\
			AND orcom.orden_id = ord.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ord.folio = '%s'\
			AND cli.activo = true\
			AND orcom.id = %d\
			AND cre.estado = true; ", folio.c_str(), orcomId);
		conn.ExecuteSelect(consulta, large, lvCredito);
	}

	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}




int LibreriaFBDll::bonoCredito::sacaridCreditoSiFolio(wstring folio)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int total = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT c.id\
			FROM credito c,orden ord\
			WHERE c.orden_id = ord.id\
			AND ord.folio = '%s'", folio.c_str());
			total = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return total;
}


int LibreriaFBDll::bonoCredito::sacarTotalCompletaSiFolio(wstring folio)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int total = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT orcom.id\
			FROM orden_completa orcom,orden ord\
			WHERE orcom.orden_id = ord.id\
			AND ord.folio = '%s'", folio.c_str());
		total = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*	this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
	return total;
}



//Subconsultas
//Llena un list view con los totales de una orden y dependiendo del cliente y el punto de venta
void LibreriaFBDll::bonoCredito::llenarclaveCliente(Win::ListView lvTabla, int puntoVenta_id, wstring folio, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;

	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_CENTER, 100, L"Folio");
	lvTabla.Cols.Add(1, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvTabla.Cols.Add(2, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvTabla.Cols.Add(3, LVCFMT_CENTER, 100, L"Departamento");
	lvTabla.Cols.Add(4, LVCFMT_CENTER, 130, L"Fecha");
	lvTabla.Cols.Add(5, LVCFMT_CENTER, 130, L"Total");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ord.id,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y'),\
			(select distinct sum(oddescr.cantidad)\
				from orden_descripcion oddescr, orden o, cliente cl, punto_venta pvta, clave_cliente ccte\
		where oddescr.orden_id = o.id\
		and o.cliente_id = cl.id\
			and ccte.cliente_id = cl.id\
			and o.puntoVenta_id = pvta.id\
			AND o.id = ord.id)\
			FROM orden ord, cliente cli, clave_cliente ccli, orden_completa orcom, punto_venta pv\
			WHERE ord.cliente_id = cli.id\
			AND orcom.orden_id = ord.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ccli.numero = '%s'\
			AND ord.puntoVenta_id = pv.id\
			AND pv.id = %d\
			AND cli.activo = true",folio.c_str(),puntoVenta_id,folio.c_str(),puntoVenta_id);

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//Llena un list view con los totales de una orden dependiendo del folio de la orden
void LibreriaFBDll::bonoCredito::llenarFolioOrden(Win::ListView lvTabla, wstring folio, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;

	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_CENTER, 100, L"Folio");
	lvTabla.Cols.Add(1, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvTabla.Cols.Add(2, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvTabla.Cols.Add(3, LVCFMT_CENTER, 100, L"Departamento");
	lvTabla.Cols.Add(4, LVCFMT_CENTER, 130, L"Fecha");
	lvTabla.Cols.Add(5, LVCFMT_CENTER, 130, L"Total");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ord.id, ord.folio, cli.nombre, ccli.numero, pv.tipo, DATE_FORMAT(ord.fecha, '%%d/%%b/%%y'),\
			(select distinct sum(oddescr.cantidad)\
				from orden_descripcion oddescr, orden o, cliente cl, punto_venta pvta, clave_cliente ccte\
		where oddescr.orden_id = o.id\
		and o.cliente_id = cl.id\
			and ccte.cliente_id = cl.id\
			and o.puntoVenta_id = pvta.id\
			AND o.id = ord.id)\
			FROM  orden ord, cliente cli, clave_cliente ccli, orden_completa orcom, punto_venta pv\
			WHERE ord.cliente_id = cli.id\
			AND orcom.orden_id = ord.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ord.puntoVenta_id = pv.id\
			AND ord.folio = '%s'\
			AND cli.activo = true; ", folio.c_str());

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//llena un list view con los totales de una orden dependiendo de la fecha de la orden
void LibreriaFBDll::bonoCredito::llenarFecha(Win::ListView lvTabla, Sys::Time fecha, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;

	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_CENTER, 100, L"Folio");
	lvTabla.Cols.Add(1, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvTabla.Cols.Add(2, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvTabla.Cols.Add(3, LVCFMT_CENTER, 100, L"Departamento");
	lvTabla.Cols.Add(4, LVCFMT_CENTER, 130, L"Fecha");
	lvTabla.Cols.Add(5, LVCFMT_CENTER, 130, L"Total");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ord.id,ord.folio,cli.nombre,ccli.numero,pv.tipo,DATE_FORMAT(ord.fecha,'%%d/%%b/%%y'),\
			(select distinct sum(oddescr.cantidad)\
				from orden_descripcion oddescr, orden o, cliente cl, punto_venta pvta, clave_cliente ccte\
		where oddescr.orden_id = o.id\
		and o.cliente_id = cl.id\
			and ccte.cliente_id = cl.id\
			and o.puntoVenta_id = pvta.id\
			AND o.id = ord.id)\
			FROM  orden ord, cliente cli, clave_cliente ccli, orden_completa orcom, punto_venta pv\
			WHERE ord.cliente_id = cli.id\
			AND orcom.orden_id = ord.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			and ord.fecha >= '%d-%d-%d 00:00:00'\
			and ord.fecha <= '%d-%d-%d 23:59:59'\
			AND ord.puntoVenta_id = pv.id\
			AND cli.activo = true", fecha.wYear, fecha.wMonth, fecha.wDay, fecha.wYear, fecha.wMonth, fecha.wDay);

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}

//LLENA UN LIST VIEW con los totales de las ordenes dependiendo del departamento

void LibreriaFBDll::bonoCredito::llenarpuntoVenta(Win::ListView lvTabla, wstring puntoVenta, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;

	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_CENTER, 100, L"Folio");
	lvTabla.Cols.Add(1, LVCFMT_CENTER, 130, L"Nombre del cliente");
	lvTabla.Cols.Add(2, LVCFMT_CENTER, 130, L"Clave del cliente");
	lvTabla.Cols.Add(3, LVCFMT_CENTER, 100, L"Departamento");
	lvTabla.Cols.Add(4, LVCFMT_CENTER, 130, L"Fecha");
	lvTabla.Cols.Add(5, LVCFMT_CENTER, 130, L"Total");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT ord.id, ord.folio, cli.nombre, ccli.numero, pv.tipo, DATE_FORMAT(ord.fecha, '%%d/%%b/%%y'),\
			(select distinct sum(oddescr.cantidad)\
				from orden_descripcion oddescr, orden o, cliente cl, punto_venta pvta, clave_cliente ccte\
		where oddescr.orden_id = o.id\
		and o.cliente_id = cl.id\
			and ccte.cliente_id = cl.id\
			and o.puntoVenta_id = pvta.id\
			AND o.id = ord.id)\
			FROM  orden ord, cliente cli, clave_cliente ccli, orden_completa orcom, punto_venta pv\
			WHERE ord.cliente_id = cli.id\
			AND orcom.orden_id = ord.id\
			AND ccli.cliente_id = cli.id\
			AND ccli.puntoVenta_id = pv.id\
			AND ord.puntoVenta_id = pv.id\
			AND pv.tipo = '%s'\
			AND cli.activo = true;", puntoVenta.c_str());

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}


// saca la ultima lada insertada
wstring LibreriaFBDll::Ciudad::sacarUltimaLada()
{
	wstring consulta;
	Sql::SqlConnection conn;
	wstring ma;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT tipo\
			FROM lada \
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

void LibreriaFBDll::bonoCredito::llenardetallesOrdenCompra(Win::ListView lvReporte, wstring folio, int longuitud, bool activo)
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
	lvReporte.Cols.Add(3, LVCFMT_CENTER, 100, L"Requerimiento");
	lvReporte.Cols.Add(4, LVCFMT_CENTER, 100, L"Marca");
	lvReporte.Cols.Add(5, LVCFMT_CENTER, 100, L"Modelo");
	lvReporte.Cols.Add(6, LVCFMT_CENTER, 80, L"Cantidad");
	lvReporte.Cols.Add(7, LVCFMT_CENTER, 100,  L"Precio sugerido");
	lvReporte.Cols.Add(8, LVCFMT_CENTER, 100, L"Precio Final");
	lvReporte.Cols.Add(9, LVCFMT_CENTER, 100, L"Total");
	lvReporte.Cols.Add(10, LVCFMT_CENTER, 100, L"Fecha");
	//reporte general de todos los requerimientos
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en el list view (Solo muestra los tipos de rangos activos)
		Sys::Format(consulta, L"SELECT DISTINCT od.id,o.folio,CONCAT(pv.tipo,'-',cc.numero),r.tipo,sv.nombre\
			, 'NA', 'NA',od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final, DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
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
			SELECT DISTINCT od.id, o.folio, CONCAT(pv.tipo, '-', cc.numero), r.tipo, ta.nombre, mo.nombre, ma.nombre,\
			od.cantidad, od.precio_sugerido, od.precio_final, od.cantidad*od.precio_final,DATE_FORMAT(o.fecha, '%%d/%%b/%%y')\
			FROM orden o, orden_descripcion od, cliente c, clave_cliente cc, punto_venta pv, requerimiento r,\
			cantidad_requerimiento cr, cantidad can, articulo a, modelo mo, marca ma, tipo_articulo ta\
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
			AND o.folio = '%s'; ", folio.c_str(), folio.c_str());

		coneccion.ExecuteSelect(consulta, longuitud, lvReporte);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	coneccion.CloseSession();
}

void LibreriaFBDll::Comisiones::llenarComisiones(Win::ListView lvTabla, wstring puntoVenta, Sys::Time fecha, int large)
{
	Sql::SqlConnection conn;

	wstring consulta;
	lvTabla.DeleteAllItems();
	lvTabla.SetRedraw(false);
	lvTabla.Cols.DeleteAll();
	lvTabla.Items.DeleteAll();
	lvTabla.SetRedraw(true);

	lvTabla.Cols.Add(0, LVCFMT_CENTER, 120, L"Folio");
	lvTabla.Cols.Add(1, LVCFMT_CENTER, 95, L"Departamento");
	lvTabla.Cols.Add(2, LVCFMT_CENTER, 200, L"Encargado");
	lvTabla.Cols.Add(3, LVCFMT_CENTER, 95, L"Total ");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L" SELECT distinct o.id, o.folio,pv.tipo,u.nombre,tac.total + tsc.total\
			FROM orden o, punto_venta pv, usuario u, puntoventa_usuario pvu, totalarticulo_comision tac,\
			totalservicio_comision tsc, orden_descripcion od, articulo_comision ac, servicio_comision sc, puesto pu\
			WHERE o.puntoVenta_id = pv.id\
			AND o.id = tac.orden_id\
			AND o.id = tsc.orden_id\
			AND pvu.usuario_id = u.id\
			AND u.puesto_id = pu.id\
			AND pvu.puntoVenta_id = pv.id\
			AND ac.ordenDescripcion_id = od.id\
			AND od.orden_id = o.id\
			AND sc.ordenDescripcion_id = od.id\
			and o.fecha >= '%d-%d-%d 00:00:00'\
			and o.fecha <= '%d-%d-%d 23:59:59'\
			AND pv.tipo = '%s'\
			AND pu.tipo = 'Responsable';", fecha.wYear, fecha.wMonth, fecha.wDay, fecha.wYear, fecha.wMonth, fecha.wDay,puntoVenta.c_str());

		conn.ExecuteSelect(consulta, large, lvTabla);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}
