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
	LibreriaFBDll::Ciudad ciudadObj;
	LibreriaFBDll::Modelo modeloObj;
	idCreditoVP = modeloObj.sacarIDOculto(lvCredito);
	folioOrdenVP = ciudadObj.sacarTextoLV(lvCredito, 0);
	totalCreditoVP = Sys::Convert::ToDouble(ciudadObj.sacarTextoLV(lvCredito, 1));
	nombreClienteVP = ciudadObj.sacarTextoLV(lvCredito, 2);
	claveClienteVP = ciudadObj.sacarTextoLV(lvCredito, 3);
	puntoVentaVP = ciudadObj.sacarTextoLV(lvCredito, 4);

	registrarAbonosVentasDlg abonoObj;
	abonoObj.BeginDialog(hWnd);

}

