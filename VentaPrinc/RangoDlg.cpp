#include "stdafx.h"  //_____________________________________________ RangoDlg.cpp
#include "RangoDlg.h"

void RangoDlg::Window_Open(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	rangoObj.mostrarRangoExistente(lvRango, 400, true);
}



void RangoDlg::btAgregar_Click(Win::Event& e)
{

}

void RangoDlg::btActualizar_Click(Win::Event& e)
{

}

void RangoDlg::lvRango_DblClk(Win::Event& e)
{
}

