#pragma once   //_____________________________________________ EliminarRestaurarRango.h  
#include "resource.h"

class EliminarRestaurarRango: public Win::Dialog
{
public:
	EliminarRestaurarRango()
	{
	}
	~EliminarRestaurarRango()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabRango;
	Win::ListView lvRango;
	Win::Button btEliminar;
	Win::Button btRestaurar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(16.43062);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(11.00667);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabRango.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.42333, 0.50271, 11.95917, 10.31875, hWnd, 1000);
		lvRango.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.92604, 1.69333, 10.87438, 8.81062, hWnd, 1001);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 13.12333, 1.34938, 3.12208, 0.68792, hWnd, 1002);
		btRestaurar.CreateX(NULL, L"Restaurar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 13.12333, 2.40771, 3.12208, 0.68792, hWnd, 1003);
		lvRango.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabRango.Font = fontArial009A;
		lvRango.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		btRestaurar.Font = fontArial009A;
	}
	//_________________________________________________
	void btEliminar_Click(Win::Event& e);
	void btRestaurar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		if (btRestaurar.IsEvent(e, BN_CLICKED)) {btRestaurar_Click(e); return true;}
		return false;
	}
};
