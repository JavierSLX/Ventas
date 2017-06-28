#pragma once   //_____________________________________________ agregarCiudadVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"

class agregarCiudadVentasDlg: public Win::Dialog
{
public:
	agregarCiudadVentasDlg(wstring opcionSeleccionada)
	{
		this->opcionSeleccionadaVP = opcionSeleccionada;
	}
	~agregarCiudadVentasDlg()
	{
	}
private:
	wstring opcionSeleccionadaVP;
	int ciudadIdVP;
	wstring nombreCiudadVP;
	
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbNombre;
	Win::Textbox tbxNombre;
	Win::Button btAgregar;
	Win::Button btEditar;
	Win::ListView lvCiudades;
	Win::DropDownList ddLadas;
	Win::Label lbLada;
	Win::Button btAgregarMarca;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(13.22917);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.04333);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.34396, 0.52917, 3.59833, 0.60854, hWnd, 1000);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 4.28625, 0.52917, 3.65125, 0.60854, hWnd, 1001);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 9.44562, 0.50271, 3.54542, 0.68792, hWnd, 1002);
		btEditar.CreateX(NULL, L"Editar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 9.44562, 1.40229, 3.51896, 0.68792, hWnd, 1003);
		lvCiudades.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.31750, 2.54000, 12.72646, 5.31813, hWnd, 1004);
		ddLadas.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 4.39208, 1.48167, 3.57187, 0.60854, hWnd, 1005);
		lbLada.CreateX(NULL, L"Lada", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.39688, 1.50812, 3.57187, 0.60854, hWnd, 1006);
		btAgregarMarca.CreateX(NULL, L"+", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.17563, 1.42875, 1.03188, 0.68792, hWnd, 1007);
		lvCiudades.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btAgregar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbNombre.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
		lvCiudades.Font = fontArial009A;
		ddLadas.Font = fontArial009A;
		lbLada.Font = fontArial009A;
		btAgregarMarca.Font = fontArial009A;
	}
	//_________________________________________________
	void btAgregar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void lvCiudades_ItemChanged(Win::Event& e);
	void btAgregarMarca_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		if (lvCiudades.IsEvent(e, LVN_ITEMCHANGED)) {lvCiudades_ItemChanged(e); return true;}
		if (btAgregarMarca.IsEvent(e, BN_CLICKED)) {btAgregarMarca_Click(e); return true;}
		return false;
	}
};
