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
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(24.02417);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(12.88521);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabVenta.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.58208, 1.24354, 23.25687, 11.45646, hWnd, 1000);
		piePastel.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE, 1.11125, 2.56646, 21.88104, 9.63083, hWnd, 1001);
		bchartBarras.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE, 1.11125, 2.56646, 21.88104, 9.63083, hWnd, 1002);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabVenta.Font = fontArial009A;
		piePastel.Font = fontArial009A;
		bchartBarras.Font = fontArial009A;
	}
	//_________________________________________________
	void tabVenta_SelChange(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabVenta.IsEvent(e, TCN_SELCHANGE)) {tabVenta_SelChange(e); return true;}
		return false;
	}
};
