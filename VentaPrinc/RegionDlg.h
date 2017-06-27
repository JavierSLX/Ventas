#pragma once   //_____________________________________________ RegionDlg.h  
#include "resource.h"
#include "LibreriaJesusDll.h"

class RegionDlg: public Win::Dialog
{
public:
	RegionDlg()
	{
	}
	~RegionDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Textbox tbxRegion;
	Win::Button btAgregar;
	Win::Button btActualizar;
	Win::ListView lvRegion;
protected:
	Win::Gdi::Font fontArial009A;
	Win::Gdi::Font fontArial012A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(6.03250);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(4.57729);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Región", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.61396, 0.34396, 1.66688, 0.74083, hWnd, 1000);
		tbxRegion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.23813, 1.48167, 2.16958, 0.68792, hWnd, 1001);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.23813, 2.40771, 2.16958, 0.68792, hWnd, 1002);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 0.23813, 3.49250, 2.16958, 0.68792, hWnd, 1003);
		lvRegion.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 2.77812, 1.40229, 3.06917, 2.98979, hWnd, 1004);
		lvRegion.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		fontArial012A.CreateX(L"Arial", 0.423333, false, false, false, false);
		lb1.Font = fontArial012A;
		tbxRegion.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
		lvRegion.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		return false;
	}
};
