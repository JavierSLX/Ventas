#pragma once   //_____________________________________________ EliminarRegionDlg.h  
#include "resource.h"
#include "LibreriaJesusDll.h"
class EliminarRegionDlg: public Win::Dialog
{
public:
	EliminarRegionDlg()
	{
	}
	~EliminarRegionDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabRegion;
	Win::ListView lvRegion;
	Win::Button btEliminar;
	Win::Button btRestaurar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(6.42938);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.25500);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabRegion.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.50271, 0.18521, 5.74146, 6.87917, hWnd, 1000);
		lvRegion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.92604, 1.34938, 4.97417, 5.42396, hWnd, 1001);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.42333, 7.35542, 2.80458, 0.68792, hWnd, 1002);
		btRestaurar.CreateX(NULL, L"Restaurar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 3.38667, 7.38188, 2.75167, 0.68792, hWnd, 1003);
		lvRegion.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabRegion.Font = fontArial009A;
		lvRegion.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		btRestaurar.Font = fontArial009A;
	}
	//_________________________________________________
	void tabRegion_SelChange(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void btRestaurar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabRegion.IsEvent(e, TCN_SELCHANGE)) {tabRegion_SelChange(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		if (btRestaurar.IsEvent(e, BN_CLICKED)) {btRestaurar_Click(e); return true;}
		return false;
	}
};
