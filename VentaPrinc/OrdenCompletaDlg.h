#pragma once   //_____________________________________________ OrdenCompletaDlg.h  
#include "resource.h"
#include "LibreriaAdDll.h"


class OrdenCompletaDlg: public Win::Dialog
{
public:
	OrdenCompletaDlg( double Total, wstring nombre, wstring folio)
	{
		this->CantidadPagarVP = Total;
		this->nombreVP = nombre;
	}
	~OrdenCompletaDlg()
	{
	}
private:
	double CantidadPagarVP;
	wstring nombreVP;
	wstring folioVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvTotal;
	Win::Label lbTotal;
	Win::Textbox tbxTotal;
	Win::Button btAceptar;
	Win::Button btEditar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(30.69167);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(12.85875);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lvTotal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.29104, 0.39688, 30.21542, 10.10708, hWnd, 1000);
		lbTotal.CreateX(NULL, L"Total", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 22.48958, 10.84792, 2.83104, 0.60854, hWnd, 1001);
		tbxTotal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 26.27313, 10.82146, 3.51896, 0.60854, hWnd, 1002);
		btAceptar.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 26.32604, 11.93271, 3.54542, 0.68792, hWnd, 1003);
		btEditar.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 22.54250, 11.98563, 3.30729, 0.68792, hWnd, 1004);
		lvTotal.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lvTotal.Font = fontArial009A;
		lbTotal.Font = fontArial009A;
		tbxTotal.Font = fontArial009A;
		btAceptar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAceptar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAceptar.IsEvent(e, BN_CLICKED)) {btAceptar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		return false;
	}
};
