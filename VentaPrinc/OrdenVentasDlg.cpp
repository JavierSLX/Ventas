#include "stdafx.h"  //_____________________________________________ OrdenVentasDlg.cpp
#include "OrdenVentasDlg.h"

void OrdenVentasDlg::Window_Open(Win::Event& e)
{

	//sacar el folio
	//llenar dropdawn
	LibreriaAdDll::ordenNueva consultasObj;
	consultasObj.llenarDDCliente(ddCliente, 100, true);
	ddCliente.SetSelectedIndex(0);
	consultasObj.llenarDDPuntoVenta(ddPuntoVenta, 100, true);
	ddPuntoVenta.SetSelectedIndex(0);
}



void OrdenVentasDlg::btAceptar_Click(Win::Event& e)
{
}

