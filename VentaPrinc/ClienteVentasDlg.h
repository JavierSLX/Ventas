#pragma once   //_____________________________________________ ClienteVentasDlg.h  
#include "resource.h"

class ClienteVentasDlg: public Win::Dialog
{
public:
	ClienteVentasDlg()
	{
	}
	~ClienteVentasDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxClave;
	Win::Textbox tbxNombre;
	Win::Textbox tbxDireccion;
	Win::Textbox tbxTelefono;
	Win::Textbox tbxEmail;
	Win::DropDownList ddCiudad;
	Win::DropDownList ddPuntoVenta;
	Win::ListView lvTabla;
	Win::Label lbClave;
	Win::Label lbNombre;
	Win::Label lbDireccion;
	Win::Label lbTelefono;
	Win::Label lbEmail;
	Win::Label lbCiudad;
	Win::Label lbPuntoVenta;
	Win::Button btRegistrar;
	Win::Button btActualizar;
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
		tbxClave.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.21167, 0.87313, 3.49250, 0.60854, hWnd, 1000);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 4.57729, 0.87313, 6.72042, 0.60854, hWnd, 1001);
		tbxDireccion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 12.06500, 0.87313, 6.29708, 0.60854, hWnd, 1002);
		tbxTelefono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 1.71979, 3.33375, 5.18583, 0.60854, hWnd, 1003);
		tbxEmail.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 10.34521, 3.33375, 5.74146, 0.60854, hWnd, 1004);
		ddCiudad.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.21167, 5.52979, 6.95854, 0.60854, hWnd, 1005);
		ddPuntoVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 9.84250, 5.52979, 5.60917, 0.60854, hWnd, 1006);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.21167, 6.85271, 20.95500, 7.54062, hWnd, 1007);
		lbClave.CreateX(NULL, L"Clave", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 0.21167, 2.96333, 0.60854, hWnd, 1008);
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.57729, 0.21167, 2.96333, 0.60854, hWnd, 1009);
		lbDireccion.CreateX(NULL, L"Dirección", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 12.06500, 0.21167, 2.96333, 0.60854, hWnd, 1010);
		lbTelefono.CreateX(NULL, L"Teléfono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.71979, 2.67229, 2.96333, 0.60854, hWnd, 1011);
		lbEmail.CreateX(NULL, L"Email", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10.34521, 2.67229, 2.96333, 0.60854, hWnd, 1012);
		lbCiudad.CreateX(NULL, L"Ciudad", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 4.86833, 2.96333, 0.60854, hWnd, 1013);
		lbPuntoVenta.CreateX(NULL, L"Punto de Venta", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9.84250, 4.86833, 2.96333, 0.60854, hWnd, 1014);
		btRegistrar.CreateX(NULL, L"Registrar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 17.46250, 2.91042, 3.59833, 0.68792, hWnd, 1015);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 17.46250, 4.15396, 3.59833, 0.68792, hWnd, 1016);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxClave.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		tbxDireccion.Font = fontArial009A;
		tbxTelefono.Font = fontArial009A;
		tbxEmail.Font = fontArial009A;
		ddCiudad.Font = fontArial009A;
		ddPuntoVenta.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		lbClave.Font = fontArial009A;
		lbNombre.Font = fontArial009A;
		lbDireccion.Font = fontArial009A;
		lbTelefono.Font = fontArial009A;
		lbEmail.Font = fontArial009A;
		lbCiudad.Font = fontArial009A;
		lbPuntoVenta.Font = fontArial009A;
		btRegistrar.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
	}
	//_________________________________________________
	void btRegistrar_Click(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btRegistrar.IsEvent(e, BN_CLICKED)) {btRegistrar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		return false;
	}
};
