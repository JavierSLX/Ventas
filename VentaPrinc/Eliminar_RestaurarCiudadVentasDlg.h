#pragma once   //_____________________________________________ Eliminar_RestaurarCiudadVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class Eliminar_RestaurarCiudadVentasDlg: public Win::Dialog
{
public:
	Eliminar_RestaurarCiudadVentasDlg()
	{
	}
	~Eliminar_RestaurarCiudadVentasDlg()
	{
	}
private:
	int ciudadIdVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabCiudades;
	Win::ListView lvE_Rciudades;
	Win::Button btEliminar;
	Win::Button btRestaurar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(10.31875);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.23938);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabCiudades.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.39688, 3.17500, 9.68375, 6.87917, hWnd, 1000);
		lvE_Rciudades.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.52917, 4.02167, 9.33979, 5.87375, hWnd, 1001);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.21167, 2.19604, 4.49792, 0.68792, hWnd, 1002);
		btRestaurar.CreateX(NULL, L"Restaurar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.97417, 2.22250, 5.15937, 0.68792, hWnd, 1003);
		lvE_Rciudades.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btEliminar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabCiudades.Font = fontArial009A;
		lvE_Rciudades.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		btRestaurar.Font = fontArial009A;
	}
	//_________________________________________________
	void tabCiudades_SelChange(Win::Event& e);
	void lvE_Rciudades_ItemChanged(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void btRestaurar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabCiudades.IsEvent(e, TCN_SELCHANGE)) {tabCiudades_SelChange(e); return true;}
		if (lvE_Rciudades.IsEvent(e, LVN_ITEMCHANGED)) {lvE_Rciudades_ItemChanged(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		if (btRestaurar.IsEvent(e, BN_CLICKED)) {btRestaurar_Click(e); return true;}
		return false;
	}
};
