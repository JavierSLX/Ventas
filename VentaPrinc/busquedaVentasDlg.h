#pragma once   //_____________________________________________ busquedaVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class busquedaVentasDlg: public Win::Dialog
{
public:
	busquedaVentasDlg()
	{
	}
	~busquedaVentasDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxOpcionBusqueda;
	Win::Button radioFolio;
	Win::Button radioClaveCliente;
	Win::Button radioFecha;
	Win::DateTimeBox dtboxFecha;
	Win::Button btBuscar;
	Win::ListView lvOrden;
	Win::Label lb1;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(22.56896);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(13.57312);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tbxOpcionBusqueda.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.82021, 0.84667, 10.90083, 0.68792, hWnd, 1000);
		radioFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.25021, 0.13229, 6.24417, 0.63500, hWnd, 1001);
		radioClaveCliente.CreateX(NULL, L"Clave del cliente", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.22375, 1.05833, 6.29708, 0.63500, hWnd, 1002);
		radioFecha.CreateX(NULL, L"Fecha", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.14438, 1.98438, 1.56104, 0.63500, hWnd, 1003);
		dtboxFecha.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 13.97000, 1.98438, 4.55083, 0.68792, hWnd, 1004);
		btBuscar.CreateX(NULL, L"Buscar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 2.43417, 2.56646, 6.79979, 0.68792, hWnd, 1005);
		lvOrden.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.42333, 4.55083, 18.20333, 8.83708, hWnd, 1006);
		lb1.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 19.55271, 1.13771, 2.83104, 0.60854, hWnd, 1007);
		lvOrden.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btBuscar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxOpcionBusqueda.Font = fontArial009A;
		radioFolio.Font = fontArial009A;
		radioClaveCliente.Font = fontArial009A;
		radioFecha.Font = fontArial009A;
		dtboxFecha.Font = fontArial009A;
		btBuscar.Font = fontArial009A;
		lvOrden.Font = fontArial009A;
		lb1.Font = fontArial009A;
	}
	//_________________________________________________
	void radioFolio_Click(Win::Event& e);
	void radioClaveCliente_Click(Win::Event& e);
	void radioFecha_Click(Win::Event& e);
	void btBuscar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioFolio.IsEvent(e, BN_CLICKED)) {radioFolio_Click(e); return true;}
		if (radioClaveCliente.IsEvent(e, BN_CLICKED)) {radioClaveCliente_Click(e); return true;}
		if (radioFecha.IsEvent(e, BN_CLICKED)) {radioFecha_Click(e); return true;}
		if (btBuscar.IsEvent(e, BN_CLICKED)) {btBuscar_Click(e); return true;}
		return false;
	}
};
