#include "stdafx.h"  //_____________________________________________ DetallesOrdenVentaDlg.cpp
#include "DetallesOrdenVentaDlg.h"

void DetallesOrdenVentaDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ ddMarca
	ddMarca.Items.Add(L"Item 0 with value 10", 10);
	ddMarca.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ ddModelo
	ddModelo.Items.Add(L"Item 0 with value 10", 10);
	ddModelo.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ ddColor
	ddColor.Items.Add(L"Item 0 with value 10", 10);
	ddColor.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ lvCaracteristicasOrden
	lvCaracteristicasOrden.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvCaracteristicasOrden.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvCaracteristicasOrden.Items.Add(0, L"Monday");
	lvCaracteristicasOrden.Items[0][1].Text = L"Math Class";
	//________________________________________________________ ddTipo
	ddTipo.Items.Add(L"Item 0 with value 10", 10);
	ddTipo.Items.Add(L"Item 1 with value 20", 20);
}



void DetallesOrdenVentaDlg::btAgregar_Click(Win::Event& e)
{
}

void DetallesOrdenVentaDlg::btLimpiar_Click(Win::Event& e)
{
}

void DetallesOrdenVentaDlg::btTerminar_Click(Win::Event& e)
{
}

