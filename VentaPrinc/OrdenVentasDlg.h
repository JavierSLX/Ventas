#pragma once   //_____________________________________________ OrdenVentasDlg.h  
#include "resource.h"
# include "libreriaAdDll.h"
#include "DetallesOrdenVentaDlg.h"
#include "DescripcionOrdenVentasDlg.h"

class OrdenVentasDlg: public Win::Dialog
{
public:
	OrdenVentasDlg()
	{
	}
	~OrdenVentasDlg()
	{
	}
	wstring _puntoVenta;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button gboxCliente;
	Win::Button gboxDepartamento;
	Win::Label lbFolio;
	Win::Textbox tbxFolio;
	Win::DropDownList ddCliente;
	Win::DropDownList ddPuntoVenta;
	Win::Button btAceptar;
	Win::Textbox tbxIdentificador;
	Win::Textbox tbxNombreCliente;
	Win::Label lbTipo;
	Win::Label lbNombre;
	Win::DropDownList ddNombreResponsable;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(14.49917);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.75771);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		gboxCliente.CreateX(WS_EX_TRANSPARENT, L"Cliente", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 1.48167, 5.23875, 12.83229, 2.24896, hWnd, 1000);
		gboxDepartamento.CreateX(WS_EX_TRANSPARENT, L"Depaartamento", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 1.48167, 2.67229, 12.80583, 2.43417, hWnd, 1001);
		lbFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.71979, 0.66146, 4.60375, 0.60854, hWnd, 1002);
		tbxFolio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 1.71979, 1.45521, 4.60375, 0.79375, hWnd, 1003);
		ddCliente.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.88937, 6.37646, 2.48708, 0.60854, hWnd, 1004);
		ddPuntoVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 1.69333, 4.02167, 4.73604, 0.60854, hWnd, 1005);
		btAceptar.CreateX(NULL, L"Aceptar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 11.64167, 7.75229, 2.67229, 0.82021, hWnd, 1006);
		tbxIdentificador.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 1.71979, 6.40292, 1.79917, 0.60854, hWnd, 1007);
		tbxNombreCliente.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 7.14375, 6.24417, 6.13833, 0.74083, hWnd, 1008);
		lbTipo.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 7.06438, 2.98979, 6.21771, 0.60854, hWnd, 1009);
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 7.09083, 5.39750, 6.24417, 0.60854, hWnd, 1010);
		ddNombreResponsable.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 7.03792, 3.99521, 6.29708, 0.60854, hWnd, 1011);
		this->SetDefaultButton(btAceptar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		gboxCliente.Font = fontArial009A;
		gboxDepartamento.Font = fontArial009A;
		lbFolio.Font = fontArial009A;
		tbxFolio.Font = fontArial009A;
		ddCliente.Font = fontArial009A;
		ddPuntoVenta.Font = fontArial009A;
		btAceptar.Font = fontArial009A;
		tbxIdentificador.Font = fontArial009A;
		tbxNombreCliente.Font = fontArial009A;
		lbTipo.Font = fontArial009A;
		lbNombre.Font = fontArial009A;
		ddNombreResponsable.Font = fontArial009A;
	}
	//_________________________________________________
	void ddCliente_SelChange(Win::Event& e);
	void ddPuntoVenta_SelChange(Win::Event& e);
	void btAceptar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (ddCliente.IsEvent(e, CBN_SELCHANGE)) {ddCliente_SelChange(e); return true;}
		if (ddPuntoVenta.IsEvent(e, CBN_SELCHANGE)) {ddPuntoVenta_SelChange(e); return true;}
		if (btAceptar.IsEvent(e, BN_CLICKED)) {btAceptar_Click(e); return true;}
		return false;
	}
};
