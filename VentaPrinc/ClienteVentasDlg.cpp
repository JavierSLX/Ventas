#include "stdafx.h"  //_____________________________________________ ClienteVentasDlg.cpp
#include "ClienteVentasDlg.h"

void ClienteVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaAdDll::articulo AdiiObj;
	AdiiObj.llenarDDdepartamento(ddPuntoVenta, 100, true);
	ddPuntoVenta.SetSelectedIndex(0);

	LibreriaJRDll::WintemplaCLS YopObj;
	YopObj.llenarDdCiudad(ddCiudad, true, 100);
}

void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
}

void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
}

