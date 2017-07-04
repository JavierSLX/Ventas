#pragma once   //_____________________________________________ ServicioDlg.h  
#include "resource.h"
#include "LibreriaAngelDll.h"

class ServicioDlg: public Win::Dialog
{
public:
	ServicioDlg()
	{
	}
	~ServicioDlg()
	{
	}
	int _idServicio;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxServicio;
	Win::Textbox tbxPrecio;
	Win::Button btAgregar;
	Win::Button btActualizar;
	Win::ListView lvServicio;
	Win::Label lbServicio;
	Win::Label lbPrecio;
	Win::Button btLimpiar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(14.28750);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.99583);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Servicios";
		tbxServicio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.50271, 1.13771, 6.24417, 0.60854, hWnd, 1000);
		tbxPrecio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.50271, 3.12208, 2.85750, 0.60854, hWnd, 1001);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.50271, 4.15396, 2.77812, 0.68792, hWnd, 1002);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 3.51896, 4.15396, 2.77812, 0.68792, hWnd, 1003);
		lvServicio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 7.17021, 0.10583, 6.93208, 8.70479, hWnd, 1004);
		lbServicio.CreateX(NULL, L"Servicio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.50271, 0.31750, 2.85750, 0.60854, hWnd, 1005);
		lbPrecio.CreateX(NULL, L"Precio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.50271, 2.24896, 2.85750, 0.60854, hWnd, 1006);
		btLimpiar.CreateX(NULL, L"Limpiar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.50271, 5.21229, 2.77812, 0.68792, hWnd, 1007);
		lvServicio.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxServicio.Font = fontArial009A;
		tbxPrecio.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
		lvServicio.Font = fontArial009A;
		lbServicio.Font = fontArial009A;
		lbPrecio.Font = fontArial009A;
		btLimpiar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void lvServicio_ItemChanged(Win::Event& e);
	void lvServicio_DblClk(Win::Event& e);
	void btLimpiar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		if (lvServicio.IsEvent(e, LVN_ITEMCHANGED)) {lvServicio_ItemChanged(e); return true;}
		if (lvServicio.IsEvent(e, NM_DBLCLK)) {lvServicio_DblClk(e); return true;}
		if (btLimpiar.IsEvent(e, BN_CLICKED)) {btLimpiar_Click(e); return true;}
		return false;
	}
};
