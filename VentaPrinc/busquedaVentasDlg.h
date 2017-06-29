#pragma once   //_____________________________________________ busquedaVentasDlg.h  
#include "resource.h"
#include "LibreriaFBDll.h"
#include "LibreriaAdDll.h"
#include "LibreriaJRDll.h"
#include "detallesOrdenVentasDlg.h"

class busquedaVentasDlg: public Win::Dialog
{
public:
	busquedaVentasDlg()
	{
	}
	~busquedaVentasDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxOpcionBusqueda;
	Win::Button radioFolio;
	Win::Button radioClaveCliente;
	Win::Button radioFecha;
	Win::DateTimeBox dtboxFecha;
	Win::Button btBuscar;
	Win::ListView lvOrden;
	Win::DropDownList ddPuntosVenta;
	Win::Button radioDepartamento;
	Win::DropDownList ddDepartamentos;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(18.81188);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(13.57312);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tbxOpcionBusqueda.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 0.82021, 0.84667, 10.90083, 0.68792, hWnd, 1000);
		radioFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.25021, 0.13229, 6.24417, 0.63500, hWnd, 1001);
		radioClaveCliente.CreateX(NULL, L"Clave del cliente", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.22375, 1.05833, 2.93688, 0.63500, hWnd, 1002);
		radioFecha.CreateX(NULL, L"Fecha", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.14438, 1.98438, 1.56104, 0.63500, hWnd, 1003);
		dtboxFecha.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 13.97000, 1.98438, 4.55083, 0.68792, hWnd, 1004);
		btBuscar.CreateX(NULL, L"Buscar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 2.43417, 2.56646, 6.79979, 0.68792, hWnd, 1005);
		lvOrden.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.42333, 4.55083, 18.20333, 8.83708, hWnd, 1006);
		ddPuntosVenta.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 15.47813, 1.03188, 3.06917, 0.60854, hWnd, 1007);
		radioDepartamento.CreateX(NULL, L"Departamento", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 12.14438, 3.12208, 3.17500, 0.63500, hWnd, 1008);
		ddDepartamentos.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 15.53104, 3.12208, 2.98979, 0.60854, hWnd, 1009);
		lvOrden.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btBuscar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxOpcionBusqueda.Font = fontArial009A;
		radioFolio.Font = fontArial009A;
		radioClaveCliente.Font = fontArial009A;
		radioFecha.Font = fontArial009A;
		dtboxFecha.Font = fontArial009A;
		btBuscar.Font = fontArial009A;
		lvOrden.Font = fontArial009A;
		ddPuntosVenta.Font = fontArial009A;
		radioDepartamento.Font = fontArial009A;
		ddDepartamentos.Font = fontArial009A;
	}
	//_________________________________________________
	void radioFolio_Click(Win::Event& e);
	void radioClaveCliente_Click(Win::Event& e);
	void radioFecha_Click(Win::Event& e);
	void btBuscar_Click(Win::Event& e);
	void lvOrden_ItemActivate(Win::Event& e);
	void radioDepartamento_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioFolio.IsEvent(e, BN_CLICKED)) {radioFolio_Click(e); return true;}
		if (radioClaveCliente.IsEvent(e, BN_CLICKED)) {radioClaveCliente_Click(e); return true;}
		if (radioFecha.IsEvent(e, BN_CLICKED)) {radioFecha_Click(e); return true;}
		if (btBuscar.IsEvent(e, BN_CLICKED)) {btBuscar_Click(e); return true;}
		if (lvOrden.IsEvent(e, LVN_ITEMACTIVATE)) {lvOrden_ItemActivate(e); return true;}
		if (radioDepartamento.IsEvent(e, BN_CLICKED)) {radioDepartamento_Click(e); return true;}
		return false;
	}
};
