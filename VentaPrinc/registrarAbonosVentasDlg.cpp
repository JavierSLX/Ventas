#include "stdafx.h"  //_____________________________________________ registrarAbonosVentasDlg.cpp
#include "registrarAbonosVentasDlg.h"


void registrarAbonosVentasDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ lvAbonos
	lvAbonos.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvAbonos.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvAbonos.Items.Add(0, L"Monday");
	lvAbonos.Items[0][1].Text = L"Math Class";
}



void registrarAbonosVentasDlg::btAgregar_Click(Win::Event& e)
{
}

