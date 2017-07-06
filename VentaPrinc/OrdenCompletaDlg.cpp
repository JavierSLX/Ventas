#include "stdafx.h"  //_____________________________________________ OrdenCompletaDlg.cpp
#include "OrdenCompletaDlg.h"

void OrdenCompletaDlg::Window_Open(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;
	int IdOrdenDesc = ordenObj.sacarUltIDOrden();
	ordenObj.llenarLVDetallesOrden(lvTotal, 100, true, folioVP);
	
}



void OrdenCompletaDlg::btAceptar_Click(Win::Event& e)
{
}

void OrdenCompletaDlg::btEditar_Click(Win::Event& e)
{
}

