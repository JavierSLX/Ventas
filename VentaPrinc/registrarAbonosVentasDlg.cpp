#include "stdafx.h"  //_____________________________________________ registrarAbonosVentasDlg.cpp
#include "registrarAbonosVentasDlg.h"


void registrarAbonosVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	bonoObj.llenarLVCreditoAbonos(lvAbonos, idCreditoVP, folioOrdenVP, 100);
	tbxFolio.SetText(folioOrdenVP);
	tbxClavecliente.SetText(puntoVentaVP + L"-"+claveClientevP);
	tbxNombre.SetText(nombreClienteVP);
	tbxTotal.SetText(Sys::Convert::ToString(totalCreditoVP));
	tbxFolio.Enabled = false;
	tbxClavecliente.Enabled =false;
	tbxNombre.Enabled = false;
	tbxTotal.Enabled = false;

}



void registrarAbonosVentasDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	if (this->tbxCantidadAbono.Text == L"")
	{
		this->tbxCantidadAbono.ShowBalloonTip(L"Cantidad", L"Ingrese una cantidad", TTI_ERROR);

		return;
	}
	else
	{
		if (tbxTotal.Text == L"0")
		{
			MessageBoxW(L"Se completo el monto del credito", L"", MB_OK | MB_ICONINFORMATION);
		}
		else
		{
			double abono = Sys::Convert::ToDouble(tbxCantidadAbono.Text);
			double cantidadAbonoActualizar = totalCreditoVP - abono;
			bonoObj.insertarbonoCredito(abono, idCreditoVP);
			bonoObj.updateCantidadCredito(cantidadAbonoActualizar, idCreditoVP);
			MessageBoxW(L"Se agrego el abono", L"", MB_OK | MB_ICONINFORMATION);

			bonoObj.llenarLVCreditoAbonos(lvAbonos, idCreditoVP, folioOrdenVP, 100);
			tbxTotal.SetText(Sys::Convert::ToString(cantidadAbonoActualizar));
			tbxCantidadAbono.SetText(L"");
		}
		

	}
	




}

