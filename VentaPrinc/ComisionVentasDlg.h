#pragma once   //_____________________________________________ ComisionVentasDlg.h  
#include "resource.h"
#include "LibreriaJRDll.h"
#include "LibreriaFBDll.h"

class ComisionVentasDlg: public Win::Dialog
{
public:
	ComisionVentasDlg()
	{
	}
	~ComisionVentasDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::DropDownList ddPuntoVenta;
	Win::Label lbDepartamento;
	Win::Button btBuscar;
	Win::ListView lvDetalles;
	Win::DateTimeBox dtboxFecha;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(14.89604);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.63625);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"Fecha", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.68792, 0.29104, 5.18583, 0.60854, hWnd, 1000);
		ddPuntoVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 6.50875, 1.32292, 4.84187, 0.60854, hWnd, 1001);
		lbDepartamento.CreateX(NULL, L"Departamento", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 6.58813, 0.29104, 4.78896, 0.60854, hWnd, 1002);
		btBuscar.CreateX(NULL, L"Buscar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 11.61521, 1.21708, 2.98979, 0.68792, hWnd, 1003);
		lvDetalles.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.74083, 2.35479, 13.97000, 8.09625, hWnd, 1004);
		dtboxFecha.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 0.60854, 1.32292, 5.74146, 0.60854, hWnd, 1005);
		lvDetalles.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btBuscar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		ddPuntoVenta.Font = fontArial009A;
		lbDepartamento.Font = fontArial009A;
		btBuscar.Font = fontArial009A;
		lvDetalles.Font = fontArial009A;
		dtboxFecha.Font = fontArial009A;
	}
	//_________________________________________________
	void btBuscar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btBuscar.IsEvent(e, BN_CLICKED)) {btBuscar_Click(e); return true;}
		return false;
	}
};
