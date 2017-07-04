#pragma once   //_____________________________________________ registrarAbonosVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class registrarAbonosVentasDlg: public Win::Dialog
{
public:
	registrarAbonosVentasDlg(int idCredito,wstring folio, double totalCredito,wstring nombreCliente,wstring claveCliente,wstring puntoVenta)
	{
		this->folioOrdenVP = folio;
		this->totalCreditoVP = totalCredito;
		this->nombreClienteVP = nombreCliente;
		this->claveClientevP = claveCliente;
		this->puntoVentaVP = puntoVenta;
		this->idCreditoVP = idCredito;
	}
	~registrarAbonosVentasDlg()
	{
	}
private:
	int idCreditoVP;
	wstring folioOrdenVP;
	double totalCreditoVP;
	wstring nombreClienteVP;
	wstring claveClientevP;
	wstring puntoVentaVP;

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
	Win::Label lb6;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(17.75354);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(14.86958);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.19063, 0.79375, 5.18583, 0.60854, hWnd, 1000);
		tbxFolio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.05292, 1.53458, 6.87917, 0.60854, hWnd, 1001);
		lbClaveCliente.CreateX(NULL, L"Clave del cliente", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 8.94292, 0.79375, 6.90563, 0.60854, hWnd, 1002);
		tbxClavecliente.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 8.01688, 1.53458, 9.44562, 0.60854, hWnd, 1003);
		lbNombre.CreateX(NULL, L"Nombre del cliente", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.84667, 2.91042, 6.66750, 0.60854, hWnd, 1004);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.05292, 3.70417, 9.10167, 0.60854, hWnd, 1005);
		lbTotal.CreateX(NULL, L"Total de credito", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10.13354, 2.88396, 6.40292, 0.60854, hWnd, 1006);
		tbxTotal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 9.60437, 3.67771, 7.75229, 0.60854, hWnd, 1007);
		lbAbono.CreateX(NULL, L"Abono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.60375, 4.70958, 6.05896, 0.60854, hWnd, 1008);
		tbxCantidadAbono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.59833, 5.58271, 7.96396, 0.60854, hWnd, 1009);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.36563, 6.53521, 6.74688, 0.68792, hWnd, 1010);
		lvAbonos.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.15875, 7.54062, 17.40958, 7.14375, hWnd, 1011);
		lb6.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 12.88521, 4.97417, 3.25438, 0.60854, hWnd, 1012);
		lvAbonos.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btAgregar);
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
		lb6.Font = fontArial009A;
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
