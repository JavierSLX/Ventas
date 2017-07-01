#pragma once   //_____________________________________________ EliminarLadaDlg.h  
#include "resource.h"
#include "LibreriaJesusDll.h"

class EliminarLadaDlg: public Win::Dialog
{
public:
	EliminarLadaDlg()
	{
	}
	~EliminarLadaDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabLada;
	Win::ListView lvLada;
	Win::Button btEliminar;
	Win::Button btRestaurar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(7.27604);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.94292);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabLada.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.44979, 0.23813, 6.29708, 7.56708, hWnd, 1000);
		lvLada.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.87313, 1.29646, 5.47687, 6.03250, hWnd, 1001);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.21167, 8.06979, 2.93688, 0.68792, hWnd, 1002);
		btRestaurar.CreateX(NULL, L"Restaurar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.15396, 8.06979, 2.93688, 0.68792, hWnd, 1003);
		lvLada.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabLada.Font = fontArial009A;
		lvLada.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		btRestaurar.Font = fontArial009A;
	}
	//_________________________________________________
	void tabLada_SelChange(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void btRestaurar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabLada.IsEvent(e, TCN_SELCHANGE)) {tabLada_SelChange(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		if (btRestaurar.IsEvent(e, BN_CLICKED)) {btRestaurar_Click(e); return true;}
		return false;
	}
};
