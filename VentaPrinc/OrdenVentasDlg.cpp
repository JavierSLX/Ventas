#include "stdafx.h"  //_____________________________________________ OrdenVentasDlg.cpp
#include "OrdenVentasDlg.h"

void OrdenVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaAdDll::ordenNueva consultasObj;

	//Llena la celda de folio
	wstring folio = consultasObj.sacarUltimoFolio();
	Sys::Time fecha = Sys::Time::Now();
	wstring cadena;
	if (folio.length() == 0)
	{
		Sys::Format(cadena, L"%06d", 1);
		tbxFolio.Text = cadena + L"/" + Sys::Convert::ToString(fecha.wYear);
	}
	else
	{
		//Compara si el año es el mismo que se cursa
		if (fecha.wYear == consultasObj.sacarIdentificadorFecha(folio))
		{
			Sys::Format(cadena, L"%04d", consultasObj.sacarIdentificadorNumerico(folio) + 1);
			tbxFolio.Text = cadena + L"/" + Sys::Convert::ToString(fecha.wYear);
		}
		else
		{
			Sys::Format(cadena, L"%04d", 1);
			tbxFolio.Text = cadena + L"/" + Sys::Convert::ToString(fecha.wYear);
		}
	}
	//llenar dropdawn

	consultasObj.llenarDDCliente(ddCliente, 100, true);
	ddCliente.SetSelectedIndex(0);
	consultasObj.llenarDDPuntoVenta(ddPuntoVenta, 100, true);
	ddPuntoVenta.SetSelectedIndex(3);
	tbxFolio.Enabled = false;
	tbxIdentificador.SetText(L"R0");

}



void OrdenVentasDlg::btAceptar_Click(Win::Event& e)
{
}

void OrdenVentasDlg::ddPuntoVenta_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva consultasObj;
	wstring puntoVenta = ddPuntoVenta.Text;
	int idPuntoVenta = consultasObj.sacarIDpuntoVenta(puntoVenta);

	if (puntoVenta == L"R1")
	{
		tbxIdentificador.SetText(L"R1");
	}
	else if (puntoVenta == L"R2")
	{
		tbxIdentificador.SetText(L"R2");
	}
	else if (puntoVenta == L"R3")
	{
		tbxIdentificador.SetText (L"R3");
	}
	else if (puntoVenta == L"R4")
	{
		tbxIdentificador.SetText(L"R4");
	}
	else if (puntoVenta == L"R0")
	{
		tbxIdentificador.SetText(L"R0");
	}
	else 
	{
		tbxIdentificador.Visible = false;
		tbxNombreCliente.Visible = false;
		ddCliente.Enabled = false;
	}

}

