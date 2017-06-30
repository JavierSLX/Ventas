#pragma once   //_____________________________________________ ClienteVentasDlg.h  
#include "resource.h"
#include "LibreriaAdDll.h"
#include "LibreriaJRDll.h"

class ClienteVentasDlg: public Win::Dialog
{
public:
	ClienteVentasDlg()
	{
		estadoVP = true;
	}
	~ClienteVentasDlg()
	{
	}
private:
	int claveClienteIDVP;
	bool estadoVP;
	wstring rutaVP;
	wstring claveVP;
	wstring nombreVP;
	wstring direccionVP;
	wstring telefonoVP;
	wstring ciudadVP;
	wstring emailVP;
	void limpiarCampos(void);
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::DropDownList ddPuntoVenta;
	Win::Textbox tbxNombre;
	Win::Textbox tbxDireccion;
	Win::Textbox tbxTelefono;
	Win::DropDownList ddCiudad;
	Win::Textbox tbxEmail;
	Win::Button btRegistrar;
	Win::Button btActualizar;
	Win::ListView lvTabla;
	Win::Textbox tbxClave;
	Win::Label lbClave;
	Win::Label lbNombre;
	Win::Label lbDireccion;
	Win::Label lbTelefono;
	Win::Label lbEmail;
	Win::Label lbCiudad;
	Win::Label lbPuntoVenta;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(21.35188);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(14.57854);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		ddPuntoVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 4.84187, 0.87313, 5.60917, 0.60854, hWnd, 1000);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 11.40354, 0.87313, 6.72042, 0.60854, hWnd, 1001);
		tbxDireccion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.21167, 3.12208, 6.29708, 0.60854, hWnd, 1002);
		tbxTelefono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 10.29229, 3.12208, 5.18583, 0.60854, hWnd, 1003);
		ddCiudad.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.21167, 5.52979, 6.95854, 0.60854, hWnd, 1004);
		tbxEmail.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 9.12813, 5.52979, 5.74146, 0.60854, hWnd, 1005);
		btRegistrar.CreateX(NULL, L"Registrar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 17.46250, 2.91042, 3.59833, 0.68792, hWnd, 1006);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 17.46250, 4.15396, 3.59833, 0.68792, hWnd, 1007);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.21167, 6.85271, 20.95500, 7.54062, hWnd, 1008);
		tbxClave.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 0.21167, 0.87313, 3.49250, 0.60854, hWnd, 1009);
		lbClave.CreateX(NULL, L"Clave", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 0.21167, 2.96333, 0.60854, hWnd, 1010);
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11.40354, 0.21167, 2.96333, 0.60854, hWnd, 1011);
		lbDireccion.CreateX(NULL, L"Dirección", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 2.46062, 2.96333, 0.60854, hWnd, 1012);
		lbTelefono.CreateX(NULL, L"Teléfono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10.29229, 2.46062, 2.96333, 0.60854, hWnd, 1013);
		lbEmail.CreateX(NULL, L"Email", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9.12813, 4.86833, 2.96333, 0.60854, hWnd, 1014);
		lbCiudad.CreateX(NULL, L"Ciudad", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 4.86833, 2.96333, 0.60854, hWnd, 1015);
		lbPuntoVenta.CreateX(NULL, L"Punto de Venta", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.84187, 0.21167, 2.96333, 0.60854, hWnd, 1016);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		ddPuntoVenta.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		tbxDireccion.Font = fontArial009A;
		tbxTelefono.Font = fontArial009A;
		ddCiudad.Font = fontArial009A;
		tbxEmail.Font = fontArial009A;
		btRegistrar.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		tbxClave.Font = fontArial009A;
		lbClave.Font = fontArial009A;
		lbNombre.Font = fontArial009A;
		lbDireccion.Font = fontArial009A;
		lbTelefono.Font = fontArial009A;
		lbEmail.Font = fontArial009A;
		lbCiudad.Font = fontArial009A;
		lbPuntoVenta.Font = fontArial009A;
	}
	//_________________________________________________
	void ddPuntoVenta_SelChange(Win::Event& e);
	void btRegistrar_Click(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void lvTabla_ItemChanged(Win::Event& e);
	void lvTabla_KeyDown(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (ddPuntoVenta.IsEvent(e, CBN_SELCHANGE)) {ddPuntoVenta_SelChange(e); return true;}
		if (btRegistrar.IsEvent(e, BN_CLICKED)) {btRegistrar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		if (lvTabla.IsEvent(e, LVN_ITEMCHANGED)) {lvTabla_ItemChanged(e); return true;}
		if (lvTabla.IsEvent(e, LVN_KEYDOWN)) {lvTabla_KeyDown(e); return true;}
		return false;
	}
};
