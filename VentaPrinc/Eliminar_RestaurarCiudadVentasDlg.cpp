#include "stdafx.h"  //_____________________________________________ Eliminar_RestaurarCiudadVentasDlg.cpp
#include "Eliminar_RestaurarCiudadVentasDlg.h"

void Eliminar_RestaurarCiudadVentasDlg::Window_Open(Win::Event& e)
{
	this->SetWindowTextW(L"Eliminar/Restaurar Ciudad");

	Sys::Icon iconoEliminar;
	iconoEliminar.Load(hInstance,IDI_BORRAR);
	btEliminar.SetImage(iconoEliminar);

	Sys::Icon iconoRestaurar;
	iconoRestaurar.Load(hInstance,IDI_CARGAR);
	btRestaurar.SetImage(iconoRestaurar);

	LibreriaFBDll::Ciudad ciudadObj;
	ciudadObj.llenarLVCiudad(lvE_Rciudades, 100);
	//________________________________________________________ tabCiudades
	tabCiudades.Items.Add(0, L"Eliminar");
	tabCiudades.Items.Add(1, L"Restaurar");
	btRestaurar.Enabled = false;

}



void Eliminar_RestaurarCiudadVentasDlg::btEliminar_Click(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	LibreriaFBDll::Modelo modeloObj;
	ciudadObj.eliminarRecuperarCiudad(ciudadIdVP, false);
	if (ciudadIdVP == 0)
	{
		if (MessageBoxW(L"No hay nada seleccionado", L"", MB_OK | MB_ICONERROR) == IDYES)
		{

		}
		
	}
	else
	{
		if (MessageBoxW(L"Se elimino este registro", L"", MB_OK | MB_ICONINFORMATION) == IDYES)
		{

		}
		ciudadObj.llenarLVCiudad(lvE_Rciudades, 100);
		ciudadIdVP = 0;
	}
	
}

void Eliminar_RestaurarCiudadVentasDlg::btRestaurar_Click(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	LibreriaFBDll::Modelo modeloObj;
	ciudadObj.eliminarRecuperarCiudad(ciudadIdVP,true);
	if (ciudadIdVP == 0)
	{
		if (MessageBoxW(L"No hay nada seleccionado", L"", MB_OK | MB_ICONERROR) == IDYES)
		{

		}

	}
	else
	{
		if (MessageBoxW(L"Se restauro este registro", L"", MB_OK | MB_ICONINFORMATION) == IDYES)
		{

		}
		ciudadObj.llenarLVCiudadInactiva(lvE_Rciudades, 100);
		ciudadIdVP = 0;
	}

}

void Eliminar_RestaurarCiudadVentasDlg::lvE_Rciudades_ItemChanged(Win::Event& e)
{
	 LibreriaFBDll::Modelo modeloObj;
	 ciudadIdVP = modeloObj.sacarIDOculto(lvE_Rciudades);
}

void Eliminar_RestaurarCiudadVentasDlg::tabCiudades_SelChange(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	if (tabCiudades.GetSelectedIndex() == 0)
	{
		ciudadObj.llenarLVCiudad(lvE_Rciudades, 100);
		btEliminar.Enabled = true;
		btRestaurar.Enabled = false;

	}
	else if (tabCiudades.GetSelectedIndex() == 1)
	{
		ciudadObj.llenarLVCiudadInactiva(lvE_Rciudades, 100);
		btRestaurar.Enabled = true;
		btEliminar.Enabled = false;
	}

}

