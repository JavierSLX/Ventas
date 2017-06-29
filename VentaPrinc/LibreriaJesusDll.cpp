#include "stdafx.h"  //_____________________________________________ LibreriaJesusDll.cpp
#include "LibreriaJesusDll.h"

//Muestra el contenido del listview de las regiones
void LibreriaJesusDll::datosRegionCLS::MostrarRegion(Win::ListView lvRegion, int longuitud, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//borrar el contenido del listview
	lvRegion.SetRedraw(false);
	lvRegion.Cols.DeleteAll();
	lvRegion.Items.DeleteAll();
	lvRegion.SetRedraw(true);
	lvRegion.Cols.Add(0, LVCFMT_CENTER, 100, L"nombre");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id,nombre FROM region WHERE activo=%d ORDER BY nombre ASC;", activo);
		coneccion.ExecuteSelect(consulta, longuitud, lvRegion);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//Agrega regiones
void LibreriaJesusDll::datosRegionCLS::InsertarRegion(wstring nombre, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO region(nombre,activo)VALUES('%s',%d)", nombre.c_str(), activo);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//verifica si existe la region para asi no permitir agragar las misma
wstring LibreriaJesusDll::datosRegionCLS::verificarSiExisteRegion(wstring region)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	wstring existeRegion;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nombre\
		FROM region\
		WHERE nombre='%s'", region.c_str());
		coneccion.GetString(consulta, existeRegion, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
	coneccion.CloseSession();
	return existeRegion;
}
//Permite hacer modificaciones en rango
void LibreriaJesusDll::datosRegionCLS::ActualizarRegion(int idRegion, wstring nombreRegion)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE region SET nombre='%s' WHERE id=%d", nombreRegion.c_str(), idRegion);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
// peromite obtener el id de rangos,para poder llamar el rango con ese id
int LibreriaJesusDll::datosRegionCLS::obtenerIdOculto(Win::ListView lvRegion)
{
	int indice = lvRegion.GetSelectedIndex();
	return lvRegion.Items[indice].Data;
}

wstring LibreriaJesusDll::datosRegionCLS::obtenerRegion(Win::ListView lvRegion, int columna)
{
	int indice = lvRegion.GetSelectedIndex();
	return lvRegion.Items[indice].GetText(columna);
}
//Permite cambiar de estado a activo o a false las regiones
void LibreriaJesusDll::datosRegionCLS::CambiarEstadoRegion(int idRegion, bool regionActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE region SET activo=%d WHERE id=%d", regionActivo, idRegion);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//muestra los campos de lada en un listview
void LibreriaJesusDll::datosLadaCLS::MostrarLada(Win::ListView lvLada, int longuitud, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//borrar el contenido del listview
	lvLada.SetRedraw(false);
	lvLada.Cols.DeleteAll();
	lvLada.Items.DeleteAll();
	lvLada.SetRedraw(true);
	lvLada.Cols.Add(0, LVCFMT_CENTER, 80, L"lada");
	lvLada.Cols.Add(1, LVCFMT_CENTER, 100, L"region");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT la.id,la.tipo,re.nombre FROM lada la, region re WHERE la.region_id=re.id AND la.activo=true ORDER BY la.id ASC;", activo);
		coneccion.ExecuteSelect(consulta, longuitud, lvLada);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//muestra los rangos en el dropdownlist 
void LibreriaJesusDll::datosLadaCLS::llenarLadaDD(Win::DropDownList ddRegion, int large)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	ddRegion.DeleteAllItems();
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id,nombre FROM region WHERE activo=true ORDER BY nombre ASC ");
		conn.ExecuteSelect(consulta, large, ddRegion);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();
}
//Permite insertar lada
void LibreriaJesusDll::datosLadaCLS::InsertarLada(wstring tipo,int idRegion, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO lada(tipo,activo,region_id)VALUES('%s',%d,%d)", tipo.c_str(), activo,idRegion);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//Verifica si existe la lada
wstring LibreriaJesusDll::datosLadaCLS::verificarSiExisteLada(wstring lada)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	wstring existeLada;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT tipo\
		FROM lada\
		WHERE tipo='%s'", lada.c_str());
		coneccion.GetString(consulta, existeLada, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
	coneccion.CloseSession();
	return existeLada;
}
//NOs permite obtener el id de Lada
int LibreriaJesusDll::datosLadaCLS::obtenerIdOculto(Win::ListView ddLada)
{
	int indice = ddLada.GetSelectedIndex();
	return ddLada.Items[indice].Data;
}
//Permite obtener el id oculto de lada
int LibreriaJesusDll::datosLadaCLS::obtenerIdOcultoDropDown(Win::DropDownList ddLada)
{
	int indice = ddLada.GetSelectedIndex();
	return ddLada.Items[indice].Data;
}
//Permite cambiar de estado de vardadero a falso
void LibreriaJesusDll::datosLadaCLS::CambiarEstadoLada(int idLada, bool ladaActivo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE lada SET activo=%d WHERE id=%d", ladaActivo, idLada);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//Muestra las ladas
void LibreriaJesusDll::datosLadaCLS::MostrarLadaEliminar(Win::ListView lvLada, int longuitud, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;

	//borrar el contenido del listview
	lvLada.SetRedraw(false);
	lvLada.Cols.DeleteAll();
	lvLada.Items.DeleteAll();
	lvLada.SetRedraw(true);
	lvLada.Cols.Add(0, LVCFMT_CENTER, 80, L"lada");
	//lvLada.Cols.Add(1, LVCFMT_CENTER, 100, L"region");
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id,tipo FROM lada WHERE activo=%d ORDER BY tipo ASC;", activo);
		coneccion.ExecuteSelect(consulta, longuitud, lvLada);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
//Permite obtener el ultimo id de lada
int LibreriaJesusDll::datosLadaCLS::ObtenerIdUltimoRegistro()
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	int id;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id FROM lada ORDER BY id DESC LIMIT 1;");
		id = coneccion.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
	coneccion.CloseSession();
	return id;
}
wstring LibreriaJesusDll::datosLadaCLS::obtenerlada(Win::ListView lvLada, int columna)
{
	int indice = lvLada.GetSelectedIndex();
	return lvLada.Items[indice].GetText(columna);
}
void LibreriaJesusDll::datosLadaCLS::ActualizarLada(int idLada, wstring nombreLada)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE lada SET tipo='%s' WHERE id=%d", nombreLada.c_str(), idLada);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
void LibreriaJesusDll::Window_Open(Win::Event& e)
{
}



