#pragma once   //_____________________________________________ reportesVentasDlg.h  
#include "resource.h"
#include "LibreriaAngelDll.h"
class reportesVentasDlg: public Win::Dialog
{
public:
	reportesVentasDlg()
	{
	}
	~reportesVentasDlg()
	{
	}
	int _idDepartamento;
	int _idRegion;
	int _idCiudad;
	int _idRequerimiento;
	wstring _folio;
	void ponerVisibleElementos(bool activo);
	void generarReporte(wstring tipoReporte);
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::DropDownList ddTipoReporte;
	Win::Label lbTipoReporte;
	Win::Label lbDepartamento;
	Win::DropDownList ddDepartamento;
	Win::Label lbRegion;
	Win::DropDownList ddRegion;
	Win::Label lbCiudad;
	Win::DropDownList ddCiudad;
	Win::Label lbRequerimiento;
	Win::DropDownList ddRequerimiento;
	Win::ListView lvReporte;
	Win::Label lbFolio;
	Win::Textbox tbxFolio;
	Win::DateTimeBox dtboxInicial;
	Win::DateTimeBox dtboxFinal;
	Win::Label lbInicio;
	Win::Label lbFinal;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(25.92917);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(16.24542);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		ddTipoReporte.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.29104, 0.79375, 5.18583, 0.60854, hWnd, 1000);
		lbTipoReporte.CreateX(NULL, L"Tipo de Reporte", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.29104, 0.15875, 5.18583, 0.60854, hWnd, 1001);
		lbDepartamento.CreateX(NULL, L"Departamento", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 5.84729, 0.13229, 5.26521, 0.60854, hWnd, 1002);
		ddDepartamento.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 5.84729, 0.82021, 5.23875, 0.60854, hWnd, 1003);
		lbRegion.CreateX(NULL, L"Región", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11.32417, 0.13229, 2.61938, 0.60854, hWnd, 1004);
		ddRegion.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 11.32417, 0.82021, 4.12750, 0.60854, hWnd, 1005);
		lbCiudad.CreateX(NULL, L"Ciudad", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 15.58396, 0.13229, 2.61938, 0.60854, hWnd, 1006);
		ddCiudad.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 15.58396, 0.82021, 5.23875, 0.60854, hWnd, 1007);
		lbRequerimiento.CreateX(NULL, L"Requerimiento", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.29104, 1.64042, 5.18583, 0.60854, hWnd, 1008);
		ddRequerimiento.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.29104, 2.40771, 5.18583, 0.60854, hWnd, 1009);
		lvReporte.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.26458, 3.73062, 25.47938, 12.32958, hWnd, 1010);
		lbFolio.CreateX(NULL, L"Folio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 5.92667, 1.64042, 5.18583, 0.60854, hWnd, 1011);
		tbxFolio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 5.92667, 2.40771, 5.18583, 0.60854, hWnd, 1012);
		dtboxInicial.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 13.62604, 2.22250, 3.33375, 0.60854, hWnd, 1013);
		dtboxFinal.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 17.06563, 2.22250, 3.33375, 0.60854, hWnd, 1014);
		lbInicio.CreateX(NULL, L"Inicio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 14.55208, 1.56104, 0.95250, 0.60854, hWnd, 1015);
		lbFinal.CreateX(NULL, L"Final", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 17.93875, 1.56104, 0.95250, 0.60854, hWnd, 1016);
		lvReporte.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		ddTipoReporte.Font = fontArial009A;
		lbTipoReporte.Font = fontArial009A;
		lbDepartamento.Font = fontArial009A;
		ddDepartamento.Font = fontArial009A;
		lbRegion.Font = fontArial009A;
		ddRegion.Font = fontArial009A;
		lbCiudad.Font = fontArial009A;
		ddCiudad.Font = fontArial009A;
		lbRequerimiento.Font = fontArial009A;
		ddRequerimiento.Font = fontArial009A;
		lvReporte.Font = fontArial009A;
		lbFolio.Font = fontArial009A;
		tbxFolio.Font = fontArial009A;
		dtboxInicial.Font = fontArial009A;
		dtboxFinal.Font = fontArial009A;
		lbInicio.Font = fontArial009A;
		lbFinal.Font = fontArial009A;
	}
	//_________________________________________________
	void ddTipoReporte_SelChange(Win::Event& e);
	void ddDepartamento_SelChange(Win::Event& e);
	void ddRegion_SelChange(Win::Event& e);
	void ddCiudad_SelChange(Win::Event& e);
	void ddRequerimiento_SelChange(Win::Event& e);
	void tbxFolio_Change(Win::Event& e);
	void dtboxInicial_DatetimeChange(Win::Event& e);
	void dtboxFinal_DatetimeChange(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (ddTipoReporte.IsEvent(e, CBN_SELCHANGE)) {ddTipoReporte_SelChange(e); return true;}
		if (ddDepartamento.IsEvent(e, CBN_SELCHANGE)) {ddDepartamento_SelChange(e); return true;}
		if (ddRegion.IsEvent(e, CBN_SELCHANGE)) {ddRegion_SelChange(e); return true;}
		if (ddCiudad.IsEvent(e, CBN_SELCHANGE)) {ddCiudad_SelChange(e); return true;}
		if (ddRequerimiento.IsEvent(e, CBN_SELCHANGE)) {ddRequerimiento_SelChange(e); return true;}
		if (tbxFolio.IsEvent(e, EN_CHANGE)) {tbxFolio_Change(e); return true;}
		if (dtboxInicial.IsEvent(e, DTN_DATETIMECHANGE)) {dtboxInicial_DatetimeChange(e); return true;}
		if (dtboxFinal.IsEvent(e, DTN_DATETIMECHANGE)) {dtboxFinal_DatetimeChange(e); return true;}
		return false;
	}
};
