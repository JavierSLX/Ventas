#pragma once   //_____________________________________________ bonoCreditoVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"
#include "registrarAbonosVentasDlg.h"
#include "LibreriaAdDll.h"
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
	int idCreditoVP;
	wstring folioOrdenVP;
	double totalCreditoVP;
	wstring nombreClienteVP;
	wstring claveClienteVP;
	wstring puntoVentaVP;

	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxOpcion;
	Win::Button radioFolio;
	Win::Button radioNombre;
	Win::Button radioClave;
	Win::Button btBuscar;
	Win::Label lbOpcion;
	Win::ListView lvCredito;
	Win::DropDownList ddPuntosVenta;
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
		tbxOpcion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 6.48229, 1.82562, 5.08000, 0.66146, hWnd, 1000);
		radioFolio.CreateX(NULL, L"Folio de venta", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.63500, 0.31750, 5.52979, 0.63500, hWnd, 1001);
		radioNombre.CreateX(NULL, L"Nombre del cliente", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 6.56167, 0.29104, 5.55625, 0.63500, hWnd, 1002);
		radioClave.CreateX(NULL, L"Clave del cliente", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.56771, 0.26458, 5.63563, 0.63500, hWnd, 1003);
		btBuscar.CreateX(NULL, L"Buscar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 6.48229, 2.93688, 5.63563, 0.79375, hWnd, 1004);
		lbOpcion.CreateX(NULL, L"Opcion", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.39208, 1.82562, 1.71979, 0.60854, hWnd, 1005);
		lvCredito.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.50271, 4.70958, 17.99167, 9.10167, hWnd, 1006);
		ddPuntosVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 12.14438, 1.82562, 3.46604, 0.60854, hWnd, 1007);
		lvCredito.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxOpcion.Font = fontArial009A;
		radioFolio.Font = fontArial009A;
		radioNombre.Font = fontArial009A;
		radioClave.Font = fontArial009A;
		btBuscar.Font = fontArial009A;
		lbOpcion.Font = fontArial009A;
		lvCredito.Font = fontArial009A;
		ddPuntosVenta.Font = fontArial009A;
	}
	//_________________________________________________
	void radioFolio_Click(Win::Event& e);
	void radioNombre_Click(Win::Event& e);
	void radioClave_Click(Win::Event& e);
	void btBuscar_Click(Win::Event& e);
	void lvCredito_ItemActivate(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioFolio.IsEvent(e, BN_CLICKED)) {radioFolio_Click(e); return true;}
		if (radioNombre.IsEvent(e, BN_CLICKED)) {radioNombre_Click(e); return true;}
		if (radioClave.IsEvent(e, BN_CLICKED)) {radioClave_Click(e); return true;}
		if (btBuscar.IsEvent(e, BN_CLICKED)) {btBuscar_Click(e); return true;}
		if (lvCredito.IsEvent(e, LVN_ITEMACTIVATE)) {lvCredito_ItemActivate(e); return true;}
		return false;
	}
};
