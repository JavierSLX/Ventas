#include "stdafx.h"  //_____________________________________________ LadaDlg.cpp
#include "LadaDlg.h"

void LadaDlg::Window_Open(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS regionObj;
	regionObj.MostrarLada(lvLada, 200, true);
}

void LadaDlg::btRegion_Click(Win::Event& e)
{
}

void LadaDlg::btActualizar_Click(Win::Event& e)
{
}

void LadaDlg::btAgregar_Click(Win::Event& e)
{
}

void LadaDlg::lvLada_DblClk(Win::Event& e)
{
}

