#pragma once   //_____________________________________________ bonoCreditoVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class bonoCreditoVentasDlg: public Win::Dialog
{
public:
	bonoCreditoVentasDlg()
	{
	}
	~bonoCreditoVentasDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxOpcion;
	Win::Button radioFolio;
	Win::Button radioNombre;
	Win::Button radioClave;
	Win::Button btBuscar;
	Win::Label lbOpcion;
	Win::ListView lvCredito;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(18.67958);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(13.99646);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tbxOpcion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 9.36625, 1.79917, 6.61458, 0.66146, hWnd, 1000);
		radioFolio.CreateX(NULL, L"Folio de venta", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.63500, 0.31750, 5.52979, 0.63500, hWnd, 1001);
		radioNombre.CreateX(NULL, L"Nombre del cliente", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 6.56167, 0.29104, 5.55625, 0.63500, hWnd, 1002);
		radioClave.CreateX(NULL, L"Clave del cliente", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.56771, 0.26458, 5.63563, 0.63500, hWnd, 1003);
		btBuscar.CreateX(NULL, L"Buscar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.48229, 2.93688, 5.63563, 0.79375, hWnd, 1004);
		lbOpcion.CreateX(NULL, L"Opcion", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 3.25438, 1.82562, 5.55625, 0.60854, hWnd, 1005);
		lvCredito.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.50271, 4.70958, 17.99167, 9.10167, hWnd, 1006);
		lvCredito.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxOpcion.Font = fontArial009A;
		radioFolio.Font = fontArial009A;
		radioNombre.Font = fontArial009A;
		radioClave.Font = fontArial009A;
		btBuscar.Font = fontArial009A;
		lbOpcion.Font = fontArial009A;
		lvCredito.Font = fontArial009A;
	}
	//_________________________________________________
	void btBuscar_Click(Win::Event& e);
	void lvCredito_ItemActivate(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btBuscar.IsEvent(e, BN_CLICKED)) {btBuscar_Click(e); return true;}
		if (lvCredito.IsEvent(e, LVN_ITEMACTIVATE)) {lvCredito_ItemActivate(e); return true;}
		return false;
	}
};
