#include "stdafx.h"  //_____________________________________________ detallesOrdenVentasDlg.cpp
#include "detallesOrdenVentasDlg.h"

void detallesOrdenVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	bonoObj.llenardetallesOrdenCompra(lv1, folioVP, 100, true);
}



