#pragma once   //_____________________________________________ EliminarRestaurarServicioDlg.h  
#include "resource.h"
#include "LibreriaAngelDll.h"
class EliminarRestaurarServicioDlg: public Win::Dialog
{
public:
	EliminarRestaurarServicioDlg()
	{
	}
	~EliminarRestaurarServicioDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabEliminarRestaurarServicio;
	Win::ListView lvEliminarRestaurarServicio;
	Win::Button btEliminar;
	Win::Button btRestaurar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(15.34583);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.90083);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabEliminarRestaurarServicio.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.79375, 0.76729, 11.35063, 9.94833, hWnd, 1000);
		lvEliminarRestaurarServicio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 1.19063, 2.01083, 10.60979, 8.30792, hWnd, 1001);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 12.67354, 3.17500, 2.48708, 0.68792, hWnd, 1002);
		btRestaurar.CreateX(NULL, L"Restaurar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 12.67354, 4.25979, 2.48708, 0.68792, hWnd, 1003);
		lvEliminarRestaurarServicio.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabEliminarRestaurarServicio.Font = fontArial009A;
		lvEliminarRestaurarServicio.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		btRestaurar.Font = fontArial009A;
	}
	//_________________________________________________
	void tabEliminarRestaurarServicio_SelChange(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void btRestaurar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabEliminarRestaurarServicio.IsEvent(e, TCN_SELCHANGE)) {tabEliminarRestaurarServicio_SelChange(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		if (btRestaurar.IsEvent(e, BN_CLICKED)) {btRestaurar_Click(e); return true;}
		return false;
	}
};
