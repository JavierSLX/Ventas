#pragma once   //_____________________________________________ EliminarClienteVentasDlg.h  
#include "resource.h"
#include "LibreriaJRDll.h"

class EliminarClienteVentasDlg: public Win::Dialog
{
public:
	EliminarClienteVentasDlg()
	{
	}
	~EliminarClienteVentasDlg()
	{
	}
private:
	int claveClienteIDVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabCliente;
	Win::ListView lvTabla;
	Win::Button btAccion;
	Win::DropDownList ddRutas;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(22.35729);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(9.65729);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabCliente.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.42333, 1.45521, 21.74875, 8.01688, hWnd, 1000);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.68792, 2.32833, 21.08729, 6.87917, hWnd, 1001);
		btAccion.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.42333, 0.42333, 3.70417, 0.68792, hWnd, 1002);
		ddRutas.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 5.87375, 0.42333, 5.00063, 0.60854, hWnd, 1003);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabCliente.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		btAccion.Font = fontArial009A;
		ddRutas.Font = fontArial009A;
	}
	//_________________________________________________
	void tabCliente_SelChange(Win::Event& e);
	void lvTabla_ItemChanged(Win::Event& e);
	void btAccion_Click(Win::Event& e);
	void ddRutas_SelChange(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabCliente.IsEvent(e, TCN_SELCHANGE)) {tabCliente_SelChange(e); return true;}
		if (lvTabla.IsEvent(e, LVN_ITEMCHANGED)) {lvTabla_ItemChanged(e); return true;}
		if (btAccion.IsEvent(e, BN_CLICKED)) {btAccion_Click(e); return true;}
		if (ddRutas.IsEvent(e, CBN_SELCHANGE)) {ddRutas_SelChange(e); return true;}
		return false;
	}
};
