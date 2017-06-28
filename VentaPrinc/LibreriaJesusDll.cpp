#include "stdafx.h"  //_____________________________________________ LibreriaJesusDll.cpp
#include "LibreriaJesusDll.h"

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
		Sys::Format(consulta, L"SELECT la.id,la.tipo,re.nombre FROM lada la, region re WHERE la.activo=true ORDER BY la.id ASC;", activo);
		coneccion.ExecuteSelect(consulta, longuitud, lvLada);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
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
void LibreriaJesusDll::datosLadaCLS::InsertarLada(wstring tipo, bool activo)
{
	Sql::SqlConnection coneccion;
	wstring consulta;
	try
	{
		coneccion.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"INSERT INTO lada(tipo,activo)VALUES('%s',%d)", tipo.c_str(), activo);
		coneccion.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK);
	}
}
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
void LibreriaJesusDll::Window_Open(Win::Event& e)
{
}



