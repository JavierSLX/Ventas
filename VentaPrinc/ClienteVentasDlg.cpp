#include "stdafx.h"  //_____________________________________________ ClienteVentasDlg.cpp
#include "ClienteVentasDlg.h"

void ClienteVentasDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ ddCiudad
	ddCiudad.Items.Add(L"Item 0 with value 10", 10);
	ddCiudad.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ ddPuntoVenta
	ddPuntoVenta.Items.Add(L"Item 0 with value 10", 10);
	ddPuntoVenta.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ lvTabla
	lvTabla.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvTabla.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvTabla.Items.Add(0, L"Monday");
	lvTabla.Items[0][1].Text = L"Math Class";
}



void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
}

void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
}

