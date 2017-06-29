#include "stdafx.h"  //_____________________________________________ busquedaVentasDlg.cpp
#include "busquedaVentasDlg.h"

void busquedaVentasDlg::Window_Open(Win::Event& e)
{
	dtboxFecha.Visible = false;
	radioFolio.Checked = true;
	//________________________________________________________ lvOrden
	lvOrden.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvOrden.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvOrden.Items.Add(0, L"Monday");
	lvOrden.Items[0][1].Text = L"Math Class";
}



void busquedaVentasDlg::btBuscar_Click(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	if (this->tbxOpcionBusqueda.Text == L"")
	{
		this->tbxOpcionBusqueda.ShowBalloonTip(L"ATENCION", L"Debes completar los campos", TTI_ERROR);

		return;
	}

	if (radioFolio.IsChecked ()==true)
	{
		int idCredito=bonoObj.sacaridCreditoSiFolio(tbxOpcionBusqueda.Text);
		if (idCredito != 0)
		{
			int orcomId = bonoObj.sacarTotalCompletaSiFolio(tbxOpcionBusqueda.Text);
			bonoObj.llenarLVOrdenCompleta(lvOrden, tbxOpcionBusqueda.Text, orcomId,100);
		}
		else
		{
			bonoObj.llenarLVCreditoFolio(lvOrden,tbxOpcionBusqueda.Text,100);
		}

	}
}

void busquedaVentasDlg::radioFolio_Click(Win::Event& e)
{
	dtboxFecha.Visible = false;
	tbxOpcionBusqueda.SetFocus();
}

void busquedaVentasDlg::radioClaveCliente_Click(Win::Event& e)
{
	dtboxFecha.Visible = false;
	tbxOpcionBusqueda.SetFocus();
}

void busquedaVentasDlg::radioFecha_Click(Win::Event& e)
{
	dtboxFecha.Visible = true;
	tbxOpcionBusqueda.SetFocus();
}

