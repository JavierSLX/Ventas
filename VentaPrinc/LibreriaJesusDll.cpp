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

void LibreriaJesusDll::Window_Open(Win::Event& e)
{
}



