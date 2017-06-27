#include "stdafx.h"  //_____________________________________________ bonoCreditoVentasDlg.cpp
#include "bonoCreditoVentasDlg.h"

void bonoCreditoVentasDlg::Window_Open(Win::Event& e)
{
	radioFolio.Checked = true;
	tbxOpcion.SetFocus();
}



void bonoCreditoVentasDlg::btBuscar_Click(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	if (radioClave.IsChecked() == true)
	{
		
		bonoObj.llenarLVCreditoCCliente(lvCredito, tbxOpcion.Text, 100);
		tbxOpcion.SetText(L"");
		tbxOpcion.SetFocus();

	}
	else if (radioFolio.IsChecked() == true)
	{
		bonoObj.llenarLVCreditoFolio(lvCredito, tbxOpcion.Text, 100);
		tbxOpcion.SetText(L"");
		tbxOpcion.SetFocus();
	}
	else if (radioNombre.IsChecked() == true)
	{
		bonoObj.llenarLVCreditoNombre(lvCredito, tbxOpcion.Text, 100);
		tbxOpcion.SetText(L"");
		tbxOpcion.SetFocus();
	}
	
}


void bonoCreditoVentasDlg::lvCredito_ItemActivate(Win::Event& e)
{
}

