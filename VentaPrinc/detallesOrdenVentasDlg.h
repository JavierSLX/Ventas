#pragma once   //_____________________________________________ detallesOrdenVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class detallesOrdenVentasDlg : public Win::Dialog
{
public:
	detallesOrdenVentasDlg(wstring folio)
	{
		this->folioVP = folio;
	}
	~detallesOrdenVentasDlg()
	{
	}
private:
	wstring folioVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lv1;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(31.90875);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(15.42521);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lv1.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.26458, 0.34396, 31.45896, 14.89604, hWnd, 1000);
		lv1.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lv1.Font = fontArial009A;
	}
	//_________________________________________________
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		return false;
	}
};
