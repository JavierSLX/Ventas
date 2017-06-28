#pragma once   //_____________________________________________ registrarAbonosVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class registrarAbonosVentasDlg: public Win::Dialog
{
public:
	registrarAbonosVentasDlg()
	{
	}
	~registrarAbonosVentasDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbFolio;
	Win::Textbox tbxFolio;
	Win::Label lbClaveCliente;
	Win::Textbox tbxClavecliente;
	Win::Label lbNombre;
	Win::Textbox tbxNombre;
	Win::Label lbTotal;
	Win::Textbox tbxTotal;
	Win::Label lbAbono;
	Win::Textbox tbxCantidadAbono;
	Win::Button btAgregar;
	Win::ListView lvAbonos;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(13.57312);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(14.86958);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.92604, 0.79375, 3.94229, 0.60854, hWnd, 1000);
		tbxFolio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.05292, 1.53458, 5.23875, 0.60854, hWnd, 1001);
		lbClaveCliente.CreateX(NULL, L"Clave del cliente", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 6.82625, 0.79375, 5.26521, 0.60854, hWnd, 1002);
		tbxClavecliente.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 6.11188, 1.53458, 7.19667, 0.60854, hWnd, 1003);
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 6.90563, 2.85750, 5.08000, 0.60854, hWnd, 1004);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 6.29708, 3.65125, 6.93208, 0.60854, hWnd, 1005);
		lbTotal.CreateX(NULL, L"Total", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.47625, 2.85750, 4.86833, 0.60854, hWnd, 1006);
		tbxTotal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.07938, 3.65125, 5.23875, 0.60854, hWnd, 1007);
		lbAbono.CreateX(NULL, L"Abono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 3.51896, 4.70958, 4.60375, 0.60854, hWnd, 1008);
		tbxCantidadAbono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.75167, 5.58271, 6.05896, 0.60854, hWnd, 1009);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 3.33375, 6.53521, 5.13292, 0.68792, hWnd, 1010);
		lvAbonos.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.13229, 7.54062, 13.25563, 7.14375, hWnd, 1011);
		lvAbonos.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbFolio.Font = fontArial009A;
		tbxFolio.Font = fontArial009A;
		lbClaveCliente.Font = fontArial009A;
		tbxClavecliente.Font = fontArial009A;
		lbNombre.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		lbTotal.Font = fontArial009A;
		tbxTotal.Font = fontArial009A;
		lbAbono.Font = fontArial009A;
		tbxCantidadAbono.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		lvAbonos.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		return false;
	}
};
