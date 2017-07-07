#pragma once   //_____________________________________________ PrecioClienteDlg.h  
#include "resource.h"
#include "LibreriaAdDll.h"
#include "LibreriaJRDll.h"

class PrecioClienteDlg: public Win::Dialog
{
public:
	PrecioClienteDlg()
	{
	}
	~PrecioClienteDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::DropDownList ddTipo;
	Win::DropDownList ddMarca;
	Win::DropDownList ddModelo;
	Win::Tab tabTabla;
	Win::ListView lvTabla;
	Win::Textbox tbxPrecio;
	Win::Button btRegistrar;
	Win::ListView lvClientes;
	Win::DropDownList ddRuta;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(25.47938);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.23938);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.63500, 0.74083, 5.42396, 0.60854, hWnd, 1000);
		ddMarca.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 7.17021, 0.74083, 5.42396, 0.60854, hWnd, 1001);
		ddModelo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 13.54667, 0.74083, 5.42396, 0.60854, hWnd, 1002);
		tabTabla.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.63500, 1.77271, 17.85938, 8.17563, hWnd, 1003);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.92604, 2.67229, 17.22437, 6.98500, hWnd, 1004);
		tbxPrecio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 19.49979, 2.35479, 4.33917, 0.60854, hWnd, 1005);
		btRegistrar.CreateX(NULL, L"Registrar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 19.57917, 3.99521, 4.33917, 0.68792, hWnd, 1006);
		lvClientes.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 19.44688, 5.39750, 5.84729, 4.65667, hWnd, 1007);
		ddRuta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 19.87021, 0.74083, 5.42396, 0.60854, hWnd, 1008);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		lvClientes.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		ddTipo.Font = fontArial009A;
		ddMarca.Font = fontArial009A;
		ddModelo.Font = fontArial009A;
		tabTabla.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		tbxPrecio.Font = fontArial009A;
		btRegistrar.Font = fontArial009A;
		lvClientes.Font = fontArial009A;
		ddRuta.Font = fontArial009A;
	}
	//_________________________________________________
	void ddTipo_SelChange(Win::Event& e);
	void ddMarca_SelChange(Win::Event& e);
	void ddModelo_SelChange(Win::Event& e);
	void tabTabla_SelChange(Win::Event& e);
	void lvTabla_ItemChanged(Win::Event& e);
	void btRegistrar_Click(Win::Event& e);
	void lvClientes_ItemChanged(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (ddTipo.IsEvent(e, CBN_SELCHANGE)) {ddTipo_SelChange(e); return true;}
		if (ddMarca.IsEvent(e, CBN_SELCHANGE)) {ddMarca_SelChange(e); return true;}
		if (ddModelo.IsEvent(e, CBN_SELCHANGE)) {ddModelo_SelChange(e); return true;}
		if (tabTabla.IsEvent(e, TCN_SELCHANGE)) {tabTabla_SelChange(e); return true;}
		if (lvTabla.IsEvent(e, LVN_ITEMCHANGED)) {lvTabla_ItemChanged(e); return true;}
		if (btRegistrar.IsEvent(e, BN_CLICKED)) {btRegistrar_Click(e); return true;}
		if (lvClientes.IsEvent(e, LVN_ITEMCHANGED)) {lvClientes_ItemChanged(e); return true;}
		return false;
	}
};
