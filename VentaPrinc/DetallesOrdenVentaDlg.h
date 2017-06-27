#pragma once   //_____________________________________________ DetallesOrdenVentaDlg.h  
#include "resource.h"
# include "libreriaAdDll.h"

class DetallesOrdenVentaDlg: public Win::Dialog
{
public:
	DetallesOrdenVentaDlg()
	{
	}
	~DetallesOrdenVentaDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button gboxOrden;
	Win::Button radioArticulo;
	Win::Button radioServicio;
	Win::DropDownList ddMarca;
	Win::DropDownList ddModelo;
	Win::DropDownList ddColor;
	Win::Label lbMarca;
	Win::Label lbModelo;
	Win::Label lbColor;
	Win::Textbox tbxPrecioSugerido;
	Win::Textbox tbxPrecioFinal;
	Win::ListView lvCaracteristicasOrden;
	Win::Label lbPrecio_Sugerido;
	Win::Label lbPrecioFinal;
	Win::Textbox tbxCantidad;
	Win::Label lbCantidad;
	Win::Label lbTipo;
	Win::DropDownList ddTipo;
	Win::Button gboxBotones;
	Win::Button btAgregar;
	Win::Button btLimpiar;
	Win::Button btTerminar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(25.58521);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(12.91167);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		gboxOrden.CreateX(WS_EX_TRANSPARENT, L"Orden", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 0.21167, 0.34396, 25.18833, 12.38250, hWnd, 1000);
		radioArticulo.CreateX(NULL, L"Articulo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.58208, 1.08479, 4.07458, 0.63500, hWnd, 1001);
		radioServicio.CreateX(NULL, L"Servicio", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.55563, 2.01083, 4.10104, 0.63500, hWnd, 1002);
		ddMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 9.68375, 1.98438, 4.70958, 0.60854, hWnd, 1003);
		ddModelo.CreateX(NULL, L"Modelo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 15.13417, 1.98438, 4.70958, 0.60854, hWnd, 1004);
		ddColor.CreateX(NULL, L"Color", WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 20.42583, 1.98438, 4.49792, 0.60854, hWnd, 1005);
		lbMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9.63083, 1.05833, 4.73604, 0.60854, hWnd, 1006);
		lbModelo.CreateX(NULL, L"Modelo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 15.00188, 1.03188, 4.97417, 0.60854, hWnd, 1007);
		lbColor.CreateX(NULL, L"Color", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 20.39937, 0.97896, 4.55083, 0.60854, hWnd, 1008);
		tbxPrecioSugerido.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 20.50521, 5.50333, 4.41854, 0.60854, hWnd, 1009);
		tbxPrecioFinal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 20.53167, 7.24958, 4.41854, 0.60854, hWnd, 1010);
		lvCaracteristicasOrden.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.47625, 3.57187, 19.47333, 8.86354, hWnd, 1011);
		lbPrecio_Sugerido.CreateX(NULL, L"Precio Sugerido", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 20.50521, 4.57729, 4.44500, 0.60854, hWnd, 1012);
		lbPrecioFinal.CreateX(NULL, L"Precio Final", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 20.58458, 6.45583, 4.33917, 0.60854, hWnd, 1013);
		tbxCantidad.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 20.45229, 3.78354, 4.47146, 0.60854, hWnd, 1014);
		lbCantidad.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 20.45229, 2.93688, 4.49792, 0.60854, hWnd, 1015);
		lbTipo.CreateX(NULL, L"Tipo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 5.05354, 1.05833, 4.25979, 0.60854, hWnd, 1016);
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 5.02708, 2.01083, 4.33917, 0.60854, hWnd, 1017);
		gboxBotones.CreateX(WS_EX_TRANSPARENT, NULL, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 20.58458, 8.36083, 4.44500, 3.96875, hWnd, 1018);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 21.80167, 8.86354, 2.11667, 0.68792, hWnd, 1019);
		btLimpiar.CreateX(NULL, L"Limpiar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 21.88104, 10.02771, 2.03729, 0.68792, hWnd, 1020);
		btTerminar.CreateX(NULL, L"Terminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 21.93396, 11.16542, 1.95792, 0.68792, hWnd, 1021);
		lvCaracteristicasOrden.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		gboxOrden.Font = fontArial009A;
		radioArticulo.Font = fontArial009A;
		radioServicio.Font = fontArial009A;
		ddMarca.Font = fontArial009A;
		ddModelo.Font = fontArial009A;
		ddColor.Font = fontArial009A;
		lbMarca.Font = fontArial009A;
		lbModelo.Font = fontArial009A;
		lbColor.Font = fontArial009A;
		tbxPrecioSugerido.Font = fontArial009A;
		tbxPrecioFinal.Font = fontArial009A;
		lvCaracteristicasOrden.Font = fontArial009A;
		lbPrecio_Sugerido.Font = fontArial009A;
		lbPrecioFinal.Font = fontArial009A;
		tbxCantidad.Font = fontArial009A;
		lbCantidad.Font = fontArial009A;
		lbTipo.Font = fontArial009A;
		ddTipo.Font = fontArial009A;
		gboxBotones.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btLimpiar.Font = fontArial009A;
		btTerminar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void btLimpiar_Click(Win::Event& e);
	void btTerminar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btLimpiar.IsEvent(e, BN_CLICKED)) {btLimpiar_Click(e); return true;}
		if (btTerminar.IsEvent(e, BN_CLICKED)) {btTerminar_Click(e); return true;}
		return false;
	}
};
