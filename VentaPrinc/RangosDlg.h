#pragma once   //_____________________________________________ RangosDlg.h  
#include "resource.h"
#include "LibreriaAngelDll.h"
#include "AsignarRangoDlg.h"
#include "RangoDlg.h"
class RangosDlg: public Win::Dialog
{
public:
	RangosDlg()
	{
	}
	~RangosDlg()
	{
	}
	int _idColocacion;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Tab tabRangos;
	Win::ListView lvRangos;
	Win::Button btAgregar;
	Win::Button btEditar;
	Win::Button btCrearRango;
	Win::Label lbColocacion;
	Win::DropDownList ddColocacion;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(21.00792);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(16.32479);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tabRangos.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 0.68792, 2.16958, 16.53646, 13.97000, hWnd, 1000);
		lvRangos.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 1.00542, 3.20146, 15.82208, 12.59417, hWnd, 1001);
		btAgregar.CreateX(NULL, L"Asignar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 17.70062, 2.96333, 3.12208, 0.68792, hWnd, 1002);
		btEditar.CreateX(NULL, L"Editar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 17.70062, 3.96875, 3.12208, 0.68792, hWnd, 1003);
		btCrearRango.CreateX(NULL, L"Crear Nuevo Rango", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_MULTILINE | BS_VCENTER, 17.70062, 4.84187, 2.27542, 1.00542, hWnd, 1004);
		lbColocacion.CreateX(NULL, L"Colocación", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.52917, 0.55563, 2.56646, 0.60854, hWnd, 1005);
		ddColocacion.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.12208, 0.52917, 5.74146, 0.60854, hWnd, 1006);
		lvRangos.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tabRangos.Font = fontArial009A;
		lvRangos.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
		btCrearRango.Font = fontArial009A;
		lbColocacion.Font = fontArial009A;
		ddColocacion.Font = fontArial009A;
	}
	//_________________________________________________
	void tabRangos_SelChange(Win::Event& e);
	void btAgregar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void btCrearRango_Click(Win::Event& e);
	void ddColocacion_SelChange(Win::Event& e);
	void Window_Activate(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tabRangos.IsEvent(e, TCN_SELCHANGE)) {tabRangos_SelChange(e); return true;}
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		if (btCrearRango.IsEvent(e, BN_CLICKED)) {btCrearRango_Click(e); return true;}
		if (ddColocacion.IsEvent(e, CBN_SELCHANGE)) {ddColocacion_SelChange(e); return true;}
		return false;
	}
};
