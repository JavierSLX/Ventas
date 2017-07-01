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
	Win::Label lbFolio;
	Win::Textbox tbxFolio;
	Win::Label lbCliente;
	Win::DropDownList ddCliente;
	Win::Label lbPuntoVenta;
	Win::DropDownList ddPuntoVenta;
	Win::Button btAceptar;
	Win::Textbox tbxIdentificador;
	Win::Textbox tbxNombreCliente;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(6.61458);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.57250);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.71979, 0.66146, 4.60375, 0.60854, hWnd, 1000);
		tbxFolio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 1.71979, 1.45521, 4.60375, 0.79375, hWnd, 1001);
		lbCliente.CreateX(NULL, L"Cliente", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.71979, 4.49792, 4.60375, 0.60854, hWnd, 1002);
		ddCliente.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.88937, 5.42396, 2.48708, 0.60854, hWnd, 1003);
		lbPuntoVenta.CreateX(NULL, L"Departamento", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.74625, 2.61938, 4.65667, 0.60854, hWnd, 1004);
		ddPuntoVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 1.69333, 3.57187, 4.73604, 0.60854, hWnd, 1005);
		btAceptar.CreateX(NULL, L"Aceptar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 2.75167, 7.69937, 2.64583, 0.68792, hWnd, 1006);
		tbxIdentificador.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 1.71979, 5.47687, 1.79917, 0.60854, hWnd, 1007);
		tbxNombreCliente.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 1.69333, 6.64104, 4.68312, 0.84667, hWnd, 1008);
		this->SetDefaultButton(btAceptar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbFolio.Font = fontArial009A;
		tbxFolio.Font = fontArial009A;
		lbCliente.Font = fontArial009A;
		ddCliente.Font = fontArial009A;
		lbPuntoVenta.Font = fontArial009A;
		ddPuntoVenta.Font = fontArial009A;
		btAceptar.Font = fontArial009A;
		tbxIdentificador.Font = fontArial009A;
		tbxNombreCliente.Font = fontArial009A;
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
