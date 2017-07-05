#pragma once   //_____________________________________________ AsignarRangoDlg.h  
#include "resource.h"
#include "LibreriaAngelDll.h"
#include "RangoDlg.h"
class AsignarRangoDlg: public Win::Dialog
{
public:
	AsignarRangoDlg(wstring requerimiento,wstring tipo,wstring marca,wstring modelo,int idArticulo,int opcion)
	{
		this->requerimientoVP = requerimiento;
		this->tipoVP = tipo;
		this->marcaVP = marca;
		this->modeloVP = modelo;
		this->idArticuloVP = idArticulo;
		this->opcionVP = opcion;
	}
	AsignarRangoDlg(wstring requerimiento, wstring tipo, wstring marca, wstring modelo,wstring minimo,wstring maximo,wstring comision, int idRango, int opcion)
	{
		this->requerimientoVP = requerimiento;
		this->tipoVP = tipo;
		this->marcaVP = marca;
		this->modeloVP = modelo;
		this->minimoVP = minimo;
		this->maximoVP = maximo;
		this->comisionVP = comision;
		this->idRangoVP = idRango;
		this->opcionVP = opcion;
	}
	~AsignarRangoDlg()
	{
	}
	int _idRango;
	double _minimo;
	double _maximo;
	double _comision;
private:
	wstring requerimientoVP;
	wstring tipoVP;
	wstring marcaVP;
	wstring modeloVP;
	int idArticuloVP;
	int opcionVP;
	wstring minimoVP;
	wstring maximoVP;
	wstring comisionVP;
	int idRangoVP;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbRequerimiento;
	Win::Textbox tbxRequerimiento;
	Win::Label lbMarca;
	Win::Textbox tbxMarca;
	Win::Label lbModelo;
	Win::Textbox tbxModelo;
	Win::Label lbMinimo;
	Win::Textbox tbxMinimo;
	Win::Label lbMaximo;
	Win::Textbox tbxMaximo;
	Win::Label lbComision;
	Win::Textbox tbxComision;
	Win::ListView lvRangos;
	Win::Button btAsignar;
	Win::Button btEditar;
	Win::Button btNuevoRango;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(16.88042);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(14.81667);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbRequerimiento.CreateX(NULL, L"Requerimiento", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 0.44979, 2.35479, 0.60854, hWnd, 1000);
		tbxRequerimiento.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 2.67229, 0.47625, 4.89479, 0.60854, hWnd, 1001);
		lbMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 1.40229, 2.35479, 0.60854, hWnd, 1002);
		tbxMarca.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 2.67229, 1.42875, 4.89479, 0.60854, hWnd, 1003);
		lbModelo.CreateX(NULL, L"Modelo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.21167, 2.48708, 2.35479, 0.60854, hWnd, 1004);
		tbxModelo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 2.67229, 2.54000, 4.89479, 0.60854, hWnd, 1005);
		lbMinimo.CreateX(NULL, L"Mínimo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 8.49313, 0.44979, 2.35479, 0.60854, hWnd, 1006);
		tbxMinimo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 10.87438, 0.44979, 4.89479, 0.60854, hWnd, 1007);
		lbMaximo.CreateX(NULL, L"Máximo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 8.49313, 1.40229, 2.35479, 0.60854, hWnd, 1008);
		tbxMaximo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 10.87438, 1.40229, 4.89479, 0.60854, hWnd, 1009);
		lbComision.CreateX(NULL, L"Comisión", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 8.65188, 2.48708, 2.35479, 0.60854, hWnd, 1010);
		tbxComision.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 10.87438, 2.48708, 4.89479, 0.60854, hWnd, 1011);
		lvRangos.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.47625, 4.31271, 15.21354, 10.31875, hWnd, 1012);
		btAsignar.CreateX(NULL, L"Asignar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.31271, 3.41313, 3.20146, 0.68792, hWnd, 1013);
		btEditar.CreateX(NULL, L"Editar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 9.02229, 3.41313, 3.20146, 0.68792, hWnd, 1014);
		btNuevoRango.CreateX(NULL, L"+", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 15.92792, 4.36563, 0.76729, 0.68792, hWnd, 1015);
		lvRangos.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbRequerimiento.Font = fontArial009A;
		tbxRequerimiento.Font = fontArial009A;
		lbMarca.Font = fontArial009A;
		tbxMarca.Font = fontArial009A;
		lbModelo.Font = fontArial009A;
		tbxModelo.Font = fontArial009A;
		lbMinimo.Font = fontArial009A;
		tbxMinimo.Font = fontArial009A;
		lbMaximo.Font = fontArial009A;
		tbxMaximo.Font = fontArial009A;
		lbComision.Font = fontArial009A;
		tbxComision.Font = fontArial009A;
		lvRangos.Font = fontArial009A;
		btAsignar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
		btNuevoRango.Font = fontArial009A;
	}
	//_________________________________________________
	void lvRangos_ItemChanged(Win::Event& e);
	void btAsignar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void btNuevoRango_Click(Win::Event& e);
	void Window_Activate(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvRangos.IsEvent(e, LVN_ITEMCHANGED)) {lvRangos_ItemChanged(e); return true;}
		if (btAsignar.IsEvent(e, BN_CLICKED)) {btAsignar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		if (btNuevoRango.IsEvent(e, BN_CLICKED)) {btNuevoRango_Click(e); return true;}
		return false;
	}
};
