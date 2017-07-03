#pragma once   //_____________________________________________ GraficoVentas.h  
#include "resource.h"

class GraficoVentas: public Win::Dialog
{
public:
	GraficoVentas()
	{
	}
	~GraficoVentas()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabVenta;
	Win::PieChart piePastel;
	Win::BarChart bchartBarras;
	Win::DropDownList ddTipo;
	Win::DropDownList ddDepartamento;
	Win::DropDownList ddArticulo;
	Win::DateTimeBox dtboxInicial;
	Win::DateTimeBox dtboxFinal;
	Win::Button btGenerar;
	Win::Button btImprimir;
	Win::Button ckPastel;
	Win::Button ckBarras;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(24.10354);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(15.50458);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabVenta.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.66146, 3.86292, 23.25687, 11.45646, hWnd, 1000);
		piePastel.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE, 1.19063, 5.18583, 21.88104, 9.63083, hWnd, 1001);
		bchartBarras.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE, 1.19063, 5.18583, 21.88104, 9.63083, hWnd, 1002);
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.66146, 0.52917, 5.87375, 0.60854, hWnd, 1003);
		ddDepartamento.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 8.54604, 0.52917, 5.87375, 0.60854, hWnd, 1004);
		ddArticulo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 16.29833, 0.52917, 5.87375, 0.60854, hWnd, 1005);
		dtboxInicial.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 0.66146, 1.87854, 5.87375, 0.60854, hWnd, 1006);
		dtboxFinal.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 8.54604, 1.93146, 5.87375, 0.60854, hWnd, 1007);
		btGenerar.CreateX(NULL, L"Generar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 15.92792, 1.90500, 3.01625, 0.68792, hWnd, 1008);
		btImprimir.CreateX(NULL, L"Imprimir", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 19.49979, 1.90500, 3.01625, 0.68792, hWnd, 1009);
		ckPastel.CreateX(NULL, L"Imprimir", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 6.32354, 3.17500, 4.04812, 0.63500, hWnd, 1010);
		ckBarras.CreateX(NULL, L"Imprimir", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 12.70000, 3.17500, 4.04812, 0.63500, hWnd, 1011);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabVenta.Font = fontArial009A;
		piePastel.Font = fontArial009A;
		bchartBarras.Font = fontArial009A;
		ddTipo.Font = fontArial009A;
		ddDepartamento.Font = fontArial009A;
		ddArticulo.Font = fontArial009A;
		dtboxInicial.Font = fontArial009A;
		dtboxFinal.Font = fontArial009A;
		btGenerar.Font = fontArial009A;
		btImprimir.Font = fontArial009A;
		ckPastel.Font = fontArial009A;
		ckBarras.Font = fontArial009A;
	}
	//_________________________________________________
	void tabVenta_SelChange(Win::Event& e);
	void btGenerar_Click(Win::Event& e);
	void btImprimir_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabVenta.IsEvent(e, TCN_SELCHANGE)) {tabVenta_SelChange(e); return true;}
		if (btGenerar.IsEvent(e, BN_CLICKED)) {btGenerar_Click(e); return true;}
		if (btImprimir.IsEvent(e, BN_CLICKED)) {btImprimir_Click(e); return true;}
		return false;
	}
};
