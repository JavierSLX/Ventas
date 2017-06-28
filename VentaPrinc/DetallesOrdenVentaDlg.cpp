#include "stdafx.h"  //_____________________________________________ DetallesOrdenVentaDlg.cpp
#include "DetallesOrdenVentaDlg.h"

void DetallesOrdenVentaDlg::Window_Open(Win::Event& e)
{
	LibreriaAdDll::articulo consultasObj;
	consultasObj.llenarDDMarca(ddMarca, 100, true);
	wstring marcaWs = ddMarca.Text;
	ddMarca.SetSelectedIndex(0);
	consultasObj.llenarDDModelo(ddModelo, marcaWs, 100, true);
	consultasObj.llenarDDcolor(ddColor, 100, true);
	ddColor.SetSelectedIndex(0);
	consultasObj.llenarDDarticulo(ddTipo, 100, true);
	ddColor.SetSelectedIndex(0);
	
	
	//________________________________________________________ lvCaracteristicasOrden
	lvCaracteristicasOrden.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvCaracteristicasOrden.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvCaracteristicasOrden.Items.Add(0, L"Monday");
	lvCaracteristicasOrden.Items[0][1].Text = L"Math Class";
	
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

