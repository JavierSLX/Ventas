#include "stdafx.h"  //_____________________________________________ LadaDlg.cpp
#include "LadaDlg.h"
#include "RegionDlg.h"

void LadaDlg::Window_Open(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	ladaObj.MostrarLada(lvLada, 200, true);
	ladaObj.llenarLadaDD(ddRegion, 10);
	ddRegion.SetSelectedIndex(0);
}

void LadaDlg::btRegion_Click(Win::Event& e)
{
	RegionDlg regionObj;
	regionObj.BeginDialog(hWnd);
}

void LadaDlg::btActualizar_Click(Win::Event& e)
{
}

void LadaDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	if (this->tbxLada.GetTextLength() == 0)
	{
		this->tbxLada.ShowBalloonTip(L"Lada", L"Ingrese una Lada", TTI_ERROR);
	}
	else
	{
		wstring rango = ladaObj.verificarSiExisteLada(tbxLada.Text);
		if (rango == tbxLada.Text)
		{
			this->tbxLada.ShowBalloonTip(L"Lada", L"Ya existe esta Lada", TTI_ERROR);
		}
		else
		{
			ladaObj.InsertarLada(tbxLada.Text, true);
			//int idRegion = ladaObj.ObtenerIdUltimoRegistro();
			//ladaObj.InsertarRegion(ddRegion.Text, idRegion);
			tbxLada.Text = L"";
			ladaObj.MostrarLada(lvLada, 200, true);

		}

	}
}

void LadaDlg::lvLada_DblClk(Win::Event& e)
{
}

