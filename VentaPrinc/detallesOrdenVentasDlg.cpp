#include "stdafx.h"  //_____________________________________________ detallesOrdenVentasDlg.cpp
#include "detallesOrdenVentasDlg.h"

void detallesOrdenVentasDlg::Window_Open(Win::Event& e)
{
	this->SetWindowTextW(L"Detalles de la Orden");
	LibreriaFBDll::bonoCredito bonoObj;
	bonoObj.llenardetallesOrdenCompra(lv1, folioVP, 100, true);
}



