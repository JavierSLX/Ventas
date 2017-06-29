#include "stdafx.h"  //_____________________________________________ bonoCreditoVentasDlg.cpp
#include "bonoCreditoVentasDlg.h"

void bonoCreditoVentasDlg::Window_Open(Win::Event& e)
{
	radioFolio.Checked = true;
	tbxOpcion.SetFocus();
	ddPuntosVenta.Visible = false;
}



void bonoCreditoVentasDlg::btBuscar_Click(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	LibreriaFBDll::Movimiento movimientoObj;
	if (radioClave.IsChecked() == true)
	{
		int puntoVentaId=movimientoObj.sacarIDpuntoVenta(ddPuntosVenta.Text);
		bonoObj.llenarLVCreditoCCliente(lvCredito, tbxOpcion.Text,puntoVentaId,100);
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
	LibreriaFBDll::bonoCredito bonoObj;
	LibreriaFBDll::Movimiento movimientoObj;
	idCreditoVP = modeloObj.sacarIDOculto(lvCredito);
	folioOrdenVP = ciudadObj.sacarTextoLV(lvCredito, 1);
	totalCreditoVP = Sys::Convert::ToDouble(ciudadObj.sacarTextoLV(lvCredito, 0));
	nombreClienteVP = ciudadObj.sacarTextoLV(lvCredito, 2);
	claveClienteVP = ciudadObj.sacarTextoLV(lvCredito, 3);
	puntoVentaVP = ciudadObj.sacarTextoLV(lvCredito, 4);

	registrarAbonosVentasDlg abonoObj(idCreditoVP,folioOrdenVP, totalCreditoVP, nombreClienteVP, claveClienteVP, puntoVentaVP);;
	abonoObj.BeginDialog(hWnd);
	if (radioClave.IsChecked() == true)
	{
		int puntoVentaId = movimientoObj.sacarIDpuntoVenta(ddPuntosVenta.Text);
		bonoObj.llenarLVCreditoCCliente(lvCredito, claveClienteVP, puntoVentaId, 100);
		tbxOpcion.SetText(L"");
		tbxOpcion.SetFocus();

	}
	else if (radioFolio.IsChecked() == true)
	{
		bonoObj.llenarLVCreditoFolio(lvCredito,folioOrdenVP, 100);
		tbxOpcion.SetText(L"");
		tbxOpcion.SetFocus();
	}
	else if (radioNombre.IsChecked() == true)
	{
		bonoObj.llenarLVCreditoNombre(lvCredito,nombreClienteVP, 100);
		tbxOpcion.SetText(L"");
		tbxOpcion.SetFocus();
	}



}

void bonoCreditoVentasDlg::radioClave_Click(Win::Event& e)
{
	ddPuntosVenta.Visible = true;
	LibreriaAdDll::articulo adObj;
	adObj.llenarDDdepartamento(ddPuntosVenta, 100, true);
	ddPuntosVenta.SetSelectedIndex(0);

}

void bonoCreditoVentasDlg::radioFolio_Click(Win::Event& e)
{
	ddPuntosVenta.Visible = false;
}

void bonoCreditoVentasDlg::radioNombre_Click(Win::Event& e)
{
	ddPuntosVenta.Visible = false;
}

