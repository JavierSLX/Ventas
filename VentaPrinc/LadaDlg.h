#pragma once   //_____________________________________________ LadaDlg.h  
#include "resource.h"
#include "LibreriaJesusDll.h"

class LadaDlg: public Win::Dialog
{
public:
	LadaDlg()
	{
	}
	~LadaDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Textbox tbxLada;
	Win::DropDownList ddRegion;
	Win::Button btRegion;
	Win::Button btAgregar;
	Win::Button btActualizar;
	Win::ListView lvLada;
protected:
	Win::Gdi::Font fontArial009A;
	Win::Gdi::Font fontArial012A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.36083);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(5.45042);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Lada", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 3.36021, 0.26458, 1.08479, 0.76729, hWnd, 1000);
		tbxLada.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.10583, 1.45521, 2.40771, 0.68792, hWnd, 1001);
		ddRegion.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.10583, 2.46062, 2.40771, 0.68792, hWnd, 1002);
		btRegion.CreateX(NULL, L"+", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 2.85750, 2.46062, 1.00542, 0.68792, hWnd, 1003);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.10583, 3.46604, 2.40771, 0.68792, hWnd, 1004);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.10583, 4.47146, 2.40771, 0.68792, hWnd, 1005);
		lvLada.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 4.20688, 1.45521, 3.96875, 3.81000, hWnd, 1006);
		lvLada.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		fontArial012A.CreateX(L"Arial", 0.423333, false, false, false, false);
		lb1.Font = fontArial012A;
		tbxLada.Font = fontArial009A;
		ddRegion.Font = fontArial009A;
		btRegion.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
		lvLada.Font = fontArial009A;
	}
	//_________________________________________________
	void btRegion_Click(Win::Event& e);
	void btAgregar_Click(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void lvLada_RdblClk (Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btRegion.IsEvent(e, BN_CLICKED)) {btRegion_Click(e); return true;}
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		if (lvLada.IsEvent(e, NM_RDBLCLK )) {lvLada_RdblClk (e); return true;}
		return false;
	}
};
