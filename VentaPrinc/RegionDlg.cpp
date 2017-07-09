#include "stdafx.h"  //_____________________________________________ RegionDlg.cpp
#include "RegionDlg.h"
//Metodo que nos permite mostrar todos los valores declarados en el wintempla con sus valores
void RegionDlg::Window_Open(Win::Event& e)
{
	LibreriaJesusDll::datosRegionCLS regionObj;
	regionObj.MostrarRegion(lvRegion, 200, true);
}
////Metodo que permite agragar regiones
void RegionDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaJesusDll::datosRegionCLS regionObj;
	if (this->tbxRegion.GetTextLength() == 0)
	{
		this->tbxRegion.ShowBalloonTip(L"Region", L"Ingrese una Región", TTI_ERROR);
	}
	else
	{
		wstring rango = regionObj.verificarSiExisteRegion(tbxRegion.Text);
		if (rango == tbxRegion.Text)
		{
			this->tbxRegion.ShowBalloonTip(L"Region", L"Ya existe esta region", TTI_ERROR);
		}
		else
		{
			regionObj.InsertarRegion(tbxRegion.Text, true);
			tbxRegion.Text = L"";
			regionObj.MostrarRegion(lvRegion, 200, true);
			tbxRegion.ShowBalloonTip(L"Region", L"Se agrego la region", TTI_NONE);
		}

	}
}
//Metodo que permite modificar los valores que tenemos en lada
void RegionDlg::btActualizar_Click(Win::Event& e)
{
	if (this->tbxRegion.GetTextLength() == 0)
	{
		this->tbxRegion.ShowBalloonTip(L"Region", L"Seleccione una Región", TTI_ERROR);
	}
	else
	{
		LibreriaJesusDll::datosRegionCLS regionObj;
		regionObj.ActualizarRegion(_id, tbxRegion.Text);
		tbxRegion.Text = L"";
		regionObj.MostrarRegion(lvRegion, 200, true);
		tbxRegion.ShowBalloonTip(L"Region", L"Se actualizo region", TTI_NONE);
	}
}
//Metodo que nos permite optener los valores dentro del listview
void RegionDlg::lvRegion_Click(Win::Event& e)
{
	LibreriaJesusDll::datosRegionCLS regionObj;
	_id = regionObj.obtenerIdOculto(lvRegion);
	tbxRegion.Text = regionObj.obtenerRegion(lvRegion, 0);
}

