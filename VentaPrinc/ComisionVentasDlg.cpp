#include "stdafx.h"  //_____________________________________________ ComisionVentasDlg.cpp
#include "ComisionVentasDlg.h"

void ComisionVentasDlg::Window_Open(Win::Event& e)
{
	this->SetWindowTextW(L"Comisiones");
	LibreriaJRDll::WintemplaCLS jrdObj;
	jrdObj.llenarDdRutasExclusiva(ddPuntoVenta, true, 100);
	ddPuntoVenta.SetSelectedIndex(0);
}


void ComisionVentasDlg::btBuscar_Click(Win::Event& e)
{
	
	wstring fecha;
	Sys::Format(fecha, L"%02d/%02d/%d ", dtboxFecha.GetSelectedDateTime().wYear, dtboxFecha.GetSelectedDateTime().wMonth, dtboxFecha.GetSelectedDateTime().wDay);
	//lb1.SetText(Sys::Convert::ToString(dtboxFecha.GetSelectedDateTime()));
	LibreriaFBDll::Comisiones comObj;
	comObj.llenarComisiones(lvDetalles, ddPuntoVenta.Text, dtboxFecha.GetSelectedDateTime(),100);
}


