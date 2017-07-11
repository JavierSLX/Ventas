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
	int articuloIDVP;
	int claveClienteID;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button gboxFaltantes;
	Win::DropDownList ddTipo;
	Win::DropDownList ddMarca;
	Win::DropDownList ddModelo;
	Win::ListView lvTabla;
	Win::Textbox tbxPrecio;
	Win::Button btRegistrar;
	Win::ListView lvClientes;
	Win::DropDownList ddRuta;
	Win::Button gboxRegistrados;
	Win::ListView lvRegistrados;
	Win::Textbox tbxClave;
	Win::Textbox tbxNombre;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(27.64896);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(11.03313);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		gboxFaltantes.CreateX(WS_EX_TRANSPARENT, L"Faltantes", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 0.44979, 2.93688, 9.84250, 7.91104, hWnd, 1000);
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.63500, 0.74083, 5.42396, 0.60854, hWnd, 1001);
		ddMarca.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 7.17021, 0.74083, 5.42396, 0.60854, hWnd, 1002);
		ddModelo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 13.54667, 0.74083, 5.42396, 0.60854, hWnd, 1003);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.71437, 3.36021, 9.28688, 6.98500, hWnd, 1004);
		tbxPrecio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 21.66938, 3.12208, 4.33917, 0.60854, hWnd, 1005);
		btRegistrar.CreateX(NULL, L"Registrar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 21.74875, 4.76250, 4.33917, 0.68792, hWnd, 1006);
		lvClientes.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 21.61646, 6.16479, 5.84729, 4.65667, hWnd, 1007);
		ddRuta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 19.87021, 0.74083, 5.42396, 0.60854, hWnd, 1008);
		gboxRegistrados.CreateX(WS_EX_TRANSPARENT, L"Registrados", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 10.90083, 2.93688, 10.16000, 7.91104, hWnd, 1009);
		lvRegistrados.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 11.29771, 3.36021, 9.28688, 6.98500, hWnd, 1010);
		tbxClave.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.63500, 1.77271, 5.26521, 0.60854, hWnd, 1011);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 8.09625, 1.77271, 8.06979, 0.60854, hWnd, 1012);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		lvClientes.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		lvRegistrados.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		gboxFaltantes.Font = fontArial009A;
		ddTipo.Font = fontArial009A;
		ddMarca.Font = fontArial009A;
		ddModelo.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		tbxPrecio.Font = fontArial009A;
		btRegistrar.Font = fontArial009A;
		lvClientes.Font = fontArial009A;
		ddRuta.Font = fontArial009A;
		gboxRegistrados.Font = fontArial009A;
		lvRegistrados.Font = fontArial009A;
		tbxClave.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
	}
	//_________________________________________________
	void ddTipo_SelChange(Win::Event& e);
	void ddMarca_SelChange(Win::Event& e);
	void ddModelo_SelChange(Win::Event& e);
	void lvTabla_ItemChanged(Win::Event& e);
	void btRegistrar_Click(Win::Event& e);
	void lvClientes_ItemChanged(Win::Event& e);
	void ddRuta_SelChange(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (ddTipo.IsEvent(e, CBN_SELCHANGE)) {ddTipo_SelChange(e); return true;}
		if (ddMarca.IsEvent(e, CBN_SELCHANGE)) {ddMarca_SelChange(e); return true;}
		if (ddModelo.IsEvent(e, CBN_SELCHANGE)) {ddModelo_SelChange(e); return true;}
		if (lvTabla.IsEvent(e, LVN_ITEMCHANGED)) {lvTabla_ItemChanged(e); return true;}
		if (btRegistrar.IsEvent(e, BN_CLICKED)) {btRegistrar_Click(e); return true;}
		if (lvClientes.IsEvent(e, LVN_ITEMCHANGED)) {lvClientes_ItemChanged(e); return true;}
		if (ddRuta.IsEvent(e, CBN_SELCHANGE)) {ddRuta_SelChange(e); return true;}
		return false;
	}
};
