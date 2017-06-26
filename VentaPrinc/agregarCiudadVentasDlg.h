#pragma once   //_____________________________________________ agregarCiudadVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class agregarCiudadVentasDlg: public Win::Dialog
{
public:
	agregarCiudadVentasDlg()
	{
	}
	~agregarCiudadVentasDlg()
	{
	}
private:
	int ciudadIdVP;
	wstring nombreCiudadVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbNombre;
	Win::Textbox tbxNombre;
	Win::Button btAgregar;
	Win::Button btEditar;
	Win::ListView lvCiudades;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.20208);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(7.99042);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.34396, 0.52917, 3.59833, 0.60854, hWnd, 1000);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.29104, 1.32292, 3.65125, 0.60854, hWnd, 1001);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.47146, 0.44979, 3.54542, 0.68792, hWnd, 1002);
		btEditar.CreateX(NULL, L"Editar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.47146, 1.34938, 3.51896, 0.68792, hWnd, 1003);
		lvCiudades.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.29104, 2.51354, 7.67292, 5.29167, hWnd, 1004);
		lvCiudades.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btAgregar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbNombre.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
		lvCiudades.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void lvCiudades_ItemChanged(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		if (lvCiudades.IsEvent(e, LVN_ITEMCHANGED)) {lvCiudades_ItemChanged(e); return true;}
		return false;
	}
};
