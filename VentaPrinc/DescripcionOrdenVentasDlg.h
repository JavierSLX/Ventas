#pragma once   //_____________________________________________ DescripcionOrdenVentasDlg.h  
#include "resource.h"
#include "LibreriaAdDll.h"
#include "LibreriaFBDll.h"

class DescripcionOrdenVentasDlg: public Win::Dialog
{
public:
	DescripcionOrdenVentasDlg(wstring punto_venta, wstring folio, wstring claveCliente)
	{
		this->puntoVentaVP = punto_venta;
		this->folioVP = folio;
		this->CClienteVP = claveCliente;
	}
	~DescripcionOrdenVentasDlg()
	{
	}
private:
	wstring folioVP;
	wstring puntoVentaVP;
	wstring CClienteVP;
	int cantidadExistenteVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button radioArticulo;
	Win::Button radioServicio;
	Win::DropDownList ddTipo;
	Win::DropDownList ddMarca;
	Win::DropDownList ddModelo;
	Win::DropDownList ddColor;
	Win::Textbox tbxCantidad;
	Win::Textbox tbxPrecio;
	Win::Textbox tbxFinal;
	Win::Button btAgregar;
	Win::ListView lvTabla;
	Win::Label lb1;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(29.50104);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(11.95917);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		radioArticulo.CreateX(NULL, L"Articulo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.55563, 0.63500, 2.96333, 0.63500, hWnd, 1000);
		radioServicio.CreateX(NULL, L"Servicio", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.55563, 1.82562, 2.96333, 0.63500, hWnd, 1001);
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.99521, 1.03188, 4.78896, 0.60854, hWnd, 1002);
		ddMarca.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 9.36625, 1.03188, 4.78896, 0.60854, hWnd, 1003);
		ddModelo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 14.55208, 1.03188, 4.78896, 0.60854, hWnd, 1004);
		ddColor.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 19.65854, 1.03188, 4.78896, 0.60854, hWnd, 1005);
		tbxCantidad.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 24.71208, 1.08479, 4.39208, 0.60854, hWnd, 1006);
		tbxPrecio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 24.71208, 4.04812, 4.39208, 0.60854, hWnd, 1007);
		tbxFinal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 24.71208, 5.60917, 4.39208, 0.60854, hWnd, 1008);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 24.71208, 7.51417, 4.15396, 0.68792, hWnd, 1009);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.74083, 3.14854, 23.36271, 8.62542, hWnd, 1010);
		lb1.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 25.21479, 2.24896, 4.10104, 0.60854, hWnd, 1011);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		radioArticulo.Font = fontArial009A;
		radioServicio.Font = fontArial009A;
		ddTipo.Font = fontArial009A;
		ddMarca.Font = fontArial009A;
		ddModelo.Font = fontArial009A;
		ddColor.Font = fontArial009A;
		tbxCantidad.Font = fontArial009A;
		tbxPrecio.Font = fontArial009A;
		tbxFinal.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		lb1.Font = fontArial009A;
	}
	//_________________________________________________
	void radioArticulo_Click(Win::Event& e);
	void radioServicio_Click(Win::Event& e);
	void ddTipo_SelChange(Win::Event& e);
	void ddMarca_SelChange(Win::Event& e);
	void ddModelo_SelChange(Win::Event& e);
	void tbxCantidad_Change(Win::Event& e);
	void btAgregar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioArticulo.IsEvent(e, BN_CLICKED)) {radioArticulo_Click(e); return true;}
		if (radioServicio.IsEvent(e, BN_CLICKED)) {radioServicio_Click(e); return true;}
		if (ddTipo.IsEvent(e, CBN_SELCHANGE)) {ddTipo_SelChange(e); return true;}
		if (ddMarca.IsEvent(e, CBN_SELCHANGE)) {ddMarca_SelChange(e); return true;}
		if (ddModelo.IsEvent(e, CBN_SELCHANGE)) {ddModelo_SelChange(e); return true;}
		if (tbxCantidad.IsEvent(e, EN_CHANGE)) {tbxCantidad_Change(e); return true;}
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		return false;
	}
};
