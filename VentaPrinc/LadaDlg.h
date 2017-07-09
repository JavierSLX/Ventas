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
	int _id;
	bool ladaBool;
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
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.67833);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(9.57792);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Lada", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.71437, 0.21167, 1.08479, 0.76729, hWnd, 1000);
		tbxLada.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.07938, 1.24354, 2.40771, 0.68792, hWnd, 1001);
		ddRegion.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.07938, 2.24896, 2.40771, 0.68792, hWnd, 1002);
		btRegion.CreateX(NULL, L"+", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 2.83104, 2.24896, 1.00542, 0.68792, hWnd, 1003);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.07938, 3.25438, 2.40771, 0.68792, hWnd, 1004);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.07938, 4.25979, 2.40771, 0.68792, hWnd, 1005);
		lvLada.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 4.15396, 0.18521, 4.33917, 9.20750, hWnd, 1006);
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
	void lvLada_DblClk(Win::Event& e);
	void Window_Activate(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btRegion.IsEvent(e, BN_CLICKED)) {btRegion_Click(e); return true;}
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		if (lvLada.IsEvent(e, NM_DBLCLK)) {lvLada_DblClk(e); return true;}
		return false;
	}
};
