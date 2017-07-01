#pragma once   //_____________________________________________ DetallesOrdenVentaDlg.h  
#include "resource.h"
# include "libreriaAdDll.h"

class DetallesOrdenVentaDlg: public Win::Dialog
{
public:
	DetallesOrdenVentaDlg(wstring puntoVenta, wstring folio)
	{
		this->_puntoVenta = puntoVenta;
		this->folioVP = folio;
	}
	~DetallesOrdenVentaDlg()
	{
	}
	wstring _puntoVenta;
private:
	wstring marcaWsPV;
	wstring tipoPV;
	wstring folioVP;

	wstring TipoArticuloVP;
	wstring MarcaVP;
	wstring ModeloVP;
	wstring ColorVP;
	wstring CantidadVP;
	wstring PSugeridoVP;
	wstring PFinalVP;
	int idArtUPVP;
	int idColorVP;
	int idPuntoVentaVP;
	int cantidadVP;

	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button gboxOrden;
	Win::Button radioArticulo;
	Win::Button radioServicio;
	Win::DropDownList ddMarca;
	Win::DropDownList ddModelo;
	Win::DropDownList ddColor;
	Win::Label lbMarca;
	Win::Label lbModelo;
	Win::Label lbColor;
	Win::Textbox tbxPrecioSugerido;
	Win::Textbox tbxPrecioFinal;
	Win::ListView lvCaracteristicasOrden;
	Win::Label lbPrecio_Sugerido;
	Win::Label lbPrecioFinal;
	Win::Textbox tbxCantidad;
	Win::Label lbCantidad;
	Win::Label lbTipo;
	Win::DropDownList ddTipo;
	Win::Button gboxBotones;
	Win::Button btAgregar;
	Win::Button btLimpiar;
	Win::Button btTerminar;
	Win::Button btEditar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(27.35792);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(12.91167);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		gboxOrden.CreateX(WS_EX_TRANSPARENT, L"Orden", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 0.21167, 0.34396, 26.96104, 12.38250, hWnd, 1000);
		radioArticulo.CreateX(NULL, L"Articulo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.58208, 1.08479, 3.33375, 0.63500, hWnd, 1001);
		radioServicio.CreateX(NULL, L"Servicio", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.55563, 2.01083, 3.33375, 0.63500, hWnd, 1002);
		ddMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 8.70479, 1.98438, 3.75708, 0.60854, hWnd, 1003);
		ddModelo.CreateX(NULL, L"Modelo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 12.70000, 1.98438, 4.12750, 0.60854, hWnd, 1004);
		ddColor.CreateX(NULL, L"Color", WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 17.22437, 1.98438, 4.49792, 0.60854, hWnd, 1005);
		lbMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 8.70479, 1.05833, 3.75708, 0.60854, hWnd, 1006);
		lbModelo.CreateX(NULL, L"Modelo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 12.67354, 1.03188, 4.20688, 0.60854, hWnd, 1007);
		lbColor.CreateX(NULL, L"Color", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 17.19792, 0.97896, 4.55083, 0.60854, hWnd, 1008);
		tbxPrecioSugerido.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 22.25146, 4.57729, 4.41854, 0.60854, hWnd, 1009);
		tbxPrecioFinal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 22.27792, 6.32354, 4.41854, 0.60854, hWnd, 1010);
		lvCaracteristicasOrden.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_ALIGNMASK | LVS_REPORT, 0.47625, 3.57187, 21.16667, 8.86354, hWnd, 1011);
		lbPrecio_Sugerido.CreateX(NULL, L"Precio  Sugerido", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 22.25146, 3.65125, 4.44500, 0.60854, hWnd, 1012);
		lbPrecioFinal.CreateX(NULL, L"Precio final ", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 22.33083, 5.52979, 4.33917, 0.60854, hWnd, 1013);
		tbxCantidad.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER | ES_LEFT | ES_WINNORMALCASE, 22.19854, 1.85208, 4.47146, 0.60854, hWnd, 1014);
		lbCantidad.CreateX(NULL, L"Cantidad", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 22.19854, 1.00542, 4.49792, 0.60854, hWnd, 1015);
		lbTipo.CreateX(NULL, L"Tipo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.12750, 1.05833, 3.88937, 0.60854, hWnd, 1016);
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 4.10104, 2.01083, 3.96875, 0.60854, hWnd, 1017);
		gboxBotones.CreateX(WS_EX_TRANSPARENT, NULL, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 22.33083, 7.43479, 4.44500, 4.89479, hWnd, 1018);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 23.54792, 8.86354, 2.11667, 0.68792, hWnd, 1019);
		btLimpiar.CreateX(NULL, L"Limpiar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 23.62729, 10.02771, 2.03729, 0.68792, hWnd, 1020);
		btTerminar.CreateX(NULL, L"Terminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 23.68021, 11.16542, 1.95792, 0.68792, hWnd, 1021);
		btEditar.CreateX(NULL, L"Editar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 23.52146, 7.83167, 2.16958, 0.68792, hWnd, 1022);
		lvCaracteristicasOrden.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		gboxOrden.Font = fontArial009A;
		radioArticulo.Font = fontArial009A;
		radioServicio.Font = fontArial009A;
		ddMarca.Font = fontArial009A;
		ddModelo.Font = fontArial009A;
		ddColor.Font = fontArial009A;
		lbMarca.Font = fontArial009A;
		lbModelo.Font = fontArial009A;
		lbColor.Font = fontArial009A;
		tbxPrecioSugerido.Font = fontArial009A;
		tbxPrecioFinal.Font = fontArial009A;
		lvCaracteristicasOrden.Font = fontArial009A;
		lbPrecio_Sugerido.Font = fontArial009A;
		lbPrecioFinal.Font = fontArial009A;
		tbxCantidad.Font = fontArial009A;
		lbCantidad.Font = fontArial009A;
		lbTipo.Font = fontArial009A;
		ddTipo.Font = fontArial009A;
		gboxBotones.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btLimpiar.Font = fontArial009A;
		btTerminar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
	}
	//_________________________________________________
	void radioArticulo_Click(Win::Event& e);
	void radioServicio_Click(Win::Event& e);
	void ddMarca_SelChange(Win::Event& e);
	void lvCaracteristicasOrden_ItemChanged(Win::Event& e);
	void tbxCantidad_Change(Win::Event& e);
	void ddTipo_SelChange(Win::Event& e);
	void btAgregar_Click(Win::Event& e);
	void btLimpiar_Click(Win::Event& e);
	void btTerminar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioArticulo.IsEvent(e, BN_CLICKED)) {radioArticulo_Click(e); return true;}
		if (radioServicio.IsEvent(e, BN_CLICKED)) {radioServicio_Click(e); return true;}
		if (ddMarca.IsEvent(e, CBN_SELCHANGE)) {ddMarca_SelChange(e); return true;}
		if (lvCaracteristicasOrden.IsEvent(e, LVN_ITEMCHANGED)) {lvCaracteristicasOrden_ItemChanged(e); return true;}
		if (tbxCantidad.IsEvent(e, EN_CHANGE)) {tbxCantidad_Change(e); return true;}
		if (ddTipo.IsEvent(e, CBN_SELCHANGE)) {ddTipo_SelChange(e); return true;}
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btLimpiar.IsEvent(e, BN_CLICKED)) {btLimpiar_Click(e); return true;}
		if (btTerminar.IsEvent(e, BN_CLICKED)) {btTerminar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		return false;
	}
};
