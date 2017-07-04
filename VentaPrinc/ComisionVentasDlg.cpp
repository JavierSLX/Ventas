#include "stdafx.h"  //_____________________________________________ ComisionVentasDlg.cpp
#include "ComisionVentasDlg.h"

void ComisionVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS jrdObj;
	jrdObj.llenarDdRutasExclusiva(ddPuntoVenta, true, 100);
	ddPuntoVenta.SetSelectedIndex(0);
}


void ComisionVentasDlg::btBuscar_Click(Win::Event& e)
{
}

