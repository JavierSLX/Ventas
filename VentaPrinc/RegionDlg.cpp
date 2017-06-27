#include "stdafx.h"  //_____________________________________________ RegionDlg.cpp
#include "RegionDlg.h"

void RegionDlg::Window_Open(Win::Event& e)
{
	LibreriaJesusDll::datosRegionCLS regionObj;
	regionObj.MostrarRegion(lvRegion, 200, true);
}

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
		}

	}
}

void RegionDlg::btActualizar_Click(Win::Event& e)
{
}

