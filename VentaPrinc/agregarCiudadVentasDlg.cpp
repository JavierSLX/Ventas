#include "stdafx.h"  //_____________________________________________ agregarCiudadVentasDlg.cpp
#include "agregarCiudadVentasDlg.h"

void agregarCiudadVentasDlg::Window_Open(Win::Event& e)
{
	tbxNombre.SetFocus();
	LibreriaFBDll::Ciudad ciudadObj;
	ciudadObj.llenarLVCiudad(lvCiudades, 100);
	ciudadObj.llenarDDLada(ddLadas, 100);
	ddLadas.SetSelectedIndex(0);
	if (opcionSeleccionadaVP == L"Agregar")
	{
		btEditar.Visible = false;


	}
	else if (opcionSeleccionadaVP == L"Editar")
		btAgregar.Visible = false;
	{

	}
}



void agregarCiudadVentasDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	int ladaId = ciudadObj.sacarIDLada(ddLadas.Text);
	wstring ciudadConsulta=ciudadObj.sacarCiudad(tbxNombre.Text,ladaId);
	
	if (ciudadConsulta == tbxNombre.Text)
	{
		if (MessageBoxW(L"Ya existe este registro", L"ERROR", MB_OK | MB_ICONERROR) == IDYES)
		{

		}
		tbxNombre.SetText(L"");
		tbxNombre.SetFocus();
		

	}
	else
	{
		
		ciudadObj.insertarCiudad(tbxNombre.Text,ladaId);
		if (MessageBoxW(L"Se agrego correctamente", L"Registro exitoso", MB_OK | MB_ICONINFORMATION) == IDYES)
		{

		}
		tbxNombre.SetText(L"");
		tbxNombre.SetFocus();
		ciudadObj.llenarLVCiudad(lvCiudades, 100);
		ddLadas.SetSelectedIndex(0);

	}


}

void agregarCiudadVentasDlg::btEditar_Click(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	if (nombreCiudadVP == tbxNombre.Text)
	{
		if (MessageBoxW(L"No hay cambios que guardar", L"ERROR", MB_OK | MB_ICONERROR) == IDYES)
		{

		}

	}
	else
	{
		ciudadObj.actualizarCiudad(tbxNombre.Text, ciudadIdVP);
		if (MessageBoxW(L"Se guardaron los cambios",L"",MB_OK | MB_ICONINFORMATION) == IDYES)
		{

		}
		tbxNombre.SetText(L"");
		tbxNombre.SetFocus();
		ciudadObj.llenarLVCiudad(lvCiudades, 100);
	}
}

void agregarCiudadVentasDlg::lvCiudades_ItemChanged(Win::Event& e)
{
	LibreriaFBDll::Modelo modeloObj;
	LibreriaFBDll::Ciudad ciudadObj;
	ciudadIdVP = modeloObj.sacarIDOculto(lvCiudades);
	nombreCiudadVP = ciudadObj.sacarTextoLV(lvCiudades, 0);
	wstring lada = ciudadObj.sacarLada(nombreCiudadVP);
	lb3.SetText(lada);
	tbxNombre.SetText(nombreCiudadVP);
	ddLadas.SetSelected(lada);

}

void agregarCiudadVentasDlg::btAgregarLada_Click(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	LadaDlg ladaObj;
	ladaObj.BeginDialog(hWnd);
	if (ladaObj.ladaBool == true)
	{
		ciudadObj.llenarDDLada(ddLadas, 100);
		wstring ultimaLada = ciudadObj.sacarUltimaLada();
		ddLadas.SetSelected(ultimaLada);
	}

}

