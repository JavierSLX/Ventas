#pragma once   //_____________________________________________ RangoDlg.h  
#include "resource.h"
#include "LibreriaAngelDll.h"
#include "EliminarRestaurarRango.h"
class RangoDlg: public Win::Dialog
{
public:
	RangoDlg()
	{
	}
	~RangoDlg()
	{
	}
	int _id;
	
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbMinimo;
	Win::Textbox tbxMinimo;
	Win::Label lbMaximo;
	Win::Textbox tbxMaximo;
	Win::Label lbComision;
	Win::Textbox tbxComision;
	Win::Button btAgregar;
	Win::Button btActualizar;
	Win::ListView lvRango;
	Win::Button btEliminar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(11.66813);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(12.96458);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbMinimo.CreateX(NULL, L"Rango Mínimo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.68792, 0.18521, 3.41313, 0.60854, hWnd, 1000);
		tbxMinimo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.68792, 1.03188, 3.41313, 0.60854, hWnd, 1001);
		lbMaximo.CreateX(NULL, L"Rango Máximo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.25979, 0.18521, 3.33375, 0.60854, hWnd, 1002);
		tbxMaximo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 4.25979, 1.03188, 3.41313, 0.60854, hWnd, 1003);
		lbComision.CreateX(NULL, L"Comisión", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 7.91104, 0.18521, 3.22792, 0.60854, hWnd, 1004);
		tbxComision.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 7.91104, 1.03188, 3.41313, 0.60854, hWnd, 1005);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 1.71979, 2.01083, 2.51354, 0.68792, hWnd, 1006);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 7.38188, 2.01083, 2.51354, 0.68792, hWnd, 1007);
		lvRango.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.58208, 3.57187, 10.90083, 8.12271, hWnd, 1008);
		btEliminar.CreateX(NULL, L"Eliminar/Restaurar Rango", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_MULTILINE | BS_VCENTER, 0.66146, 11.87979, 3.06917, 0.89958, hWnd, 1009);
		lvRango.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbMinimo.Font = fontArial009A;
		tbxMinimo.Font = fontArial009A;
		lbMaximo.Font = fontArial009A;
		tbxMaximo.Font = fontArial009A;
		lbComision.Font = fontArial009A;
		tbxComision.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
		lvRango.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void lvRango_DblClk(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		if (lvRango.IsEvent(e, NM_DBLCLK)) {lvRango_DblClk(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		return false;
	}
};
