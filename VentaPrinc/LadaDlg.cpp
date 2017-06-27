#include "stdafx.h"  //_____________________________________________ LadaDlg.cpp
#include "LadaDlg.h"

void LadaDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ ddRegion
	ddRegion.Items.Add(L"Item 0 with value 10", 10);
	ddRegion.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ lvLada
	lvLada.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvLada.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvLada.Items.Add(0, L"Monday");
	lvLada.Items[0][1].Text = L"Math Class";
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



