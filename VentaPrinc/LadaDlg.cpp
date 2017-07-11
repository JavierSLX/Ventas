#include "stdafx.h"  //_____________________________________________ LadaDlg.cpp
#include "LadaDlg.h"
#include "RegionDlg.h"
//Metodo que nos permite mostrar todos los valores declarados en el wintemplad con sus valores
void LadaDlg::Window_Open(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	ladaObj.MostrarLada(lvLada, 200, true);
	ladaObj.llenarLadaDD(ddRegion, 10);
	ddRegion.SetSelectedIndex(0);
}
//metodo que llama la tabla de region
void LadaDlg::btRegion_Click(Win::Event& e)
{
	RegionDlg regionObj;
	regionObj.BeginDialog(hWnd);
}
//Metodo que permite modificar los valores que tenemos en lada
void LadaDlg::btActualizar_Click(Win::Event& e)
{
	if (this->tbxLada.GetTextLength() == 0)
	{
		this->tbxLada.ShowBalloonTip(L"Lada", L"Seleccione una Lada", TTI_ERROR);
	}
	else
	{
		LibreriaJesusDll::datosLadaCLS ladaObj;
		//LibreriaJesusDll::datosRegionCLS regionObj;
		int idRegion = ladaObj.obtenerIdOcultoDropDown(ddRegion);
		ladaObj.ActualizarLada(_id, tbxLada.Text, idRegion);
		tbxLada.Text = L"";
		ladaObj.MostrarLada(lvLada, 200, true);
		//tbxLada.ShowBalloonTip(L"Lada", L"Se actualizo lada", TTI_NONE);
		MessageBox(L"Se actualizo lada", L"Lada", MB_OK);
		tbxLada.SetFocus();
	}
}
//Metodo que permite agragar ladas
void LadaDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	//LibreriaJesusDll::datosRegionCLS regionObj;
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
			int idRegion = ladaObj.obtenerIdOcultoDropDown(ddRegion);
			ladaObj.InsertarLada(tbxLada.Text, idRegion, true);
			tbxLada.Text = L"";
			ladaObj.MostrarLada(lvLada, 200, true);
			ladaBool = true;
			//tbxLada.ShowBalloonTip(L"Lada", L"Se agrego lada", TTI_NONE);
			MessageBox(L"Se agrego lada", L"Lada", MB_OK);
			tbxLada.SetFocus();
		}

	}
}
//Metodo que nos permite optener los valores dentro del listview
void LadaDlg::lvLada_DblClk(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	_id = ladaObj.obtenerIdOculto(lvLada);
	tbxLada.Text = ladaObj.obtenerlada(lvLada, 0);
}

void LadaDlg::Window_Activate(Win::Event& e)
{
	const bool activated = (e.wParam != WA_INACTIVE);
	e.returnValue = 0;
	LibreriaJesusDll::datosLadaCLS ladaObj;
	ladaObj.MostrarLada(lvLada, 200, true);
	ladaObj.llenarLadaDD(ddRegion, 10);
	ddRegion.SetSelectedIndex(0);
}

