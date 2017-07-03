#include "stdafx.h"  //_____________________________________________ ComisionVentasDlg.cpp
#include "ComisionVentasDlg.h"

void ComisionVentasDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ ddPuntoVenta
	ddPuntoVenta.Items.Add(L"Item 0 with value 10", 10);
	ddPuntoVenta.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ lvDetalles
	lvDetalles.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvDetalles.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvDetalles.Items.Add(0, L"Monday");
	lvDetalles.Items[0][1].Text = L"Math Class";
}



void ComisionVentasDlg::btBuscar_Click(Win::Event& e)
{
}

