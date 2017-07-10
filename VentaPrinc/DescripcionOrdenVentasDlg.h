#pragma once   //_____________________________________________ DescripcionOrdenVentasDlg.h  
#include "resource.h"
#include "LibreriaAdDll.h"
#include "LibreriaFBDll.h"
#include "OrdenCompletaDlg.h"


class DescripcionOrdenVentasDlg: public Win::Dialog
{
public:
	DescripcionOrdenVentasDlg(wstring punto_venta, wstring folio, wstring claveCliente)
	{
		this->puntoVentaVP = punto_venta;
		this->folioVP = folio;
		this->CClienteVP = claveCliente;
		
	}
	~DescripcionOrdenVentasDlg()
	{
	}
private:
	vector<int>articulosSinRangoVP;
	vector<int>articuloSinRangoOdVP;
	vector<int>cantidadArticuloSinRangoVP;
	vector<int>serviciosSinRangoVP;
	vector<int>serviciosSinRangoOdVP;
	vector<int>cantidadServiciosSinRangoVP;
	double TotalPrecioArticulosVP;
	double TotalPrecioServiciosVP;
	double TotalComisionArticulosVP;
	double TotalComisionServiciosVP;
	double TotalComisionOrdenVP;
	int contadorVP = 0;
	wstring folioVP;
	wstring puntoVentaVP;
	wstring CClienteVP;
	int cantidadExistenteVP;
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
	int idDetalles;
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button radioArticulo;
	Win::Button radioServicio;
	Win::DropDownList ddTipo;
	Win::DropDownList ddMarca;
	Win::DropDownList ddModelo;
	Win::DropDownList ddColor;
	Win::Textbox tbxCantidad;
	Win::Textbox tbxPrecio;
	Win::Textbox tbxFinal;
	Win::ListView lvTabla;
	Win::Label lbTipo;
	Win::Label lbMarca;
	Win::Label lb3;
	Win::Label lbColor;
	Win::Label lbCantidad;
	Win::Label lbPrecioSugerido;
	Win::Label lbPrecio_Final;
	Win::Button gbox1;
	Win::Button btAgregar;
	Win::Button btEditar;
	Win::Button btTerminar;
	Win::Button btEliminar;
	Win::Label lb8;
	Win::Label lb9;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(30.98271);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(13.07042);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		radioArticulo.CreateX(NULL, L"Articulo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.55563, 0.63500, 2.96333, 0.63500, hWnd, 1000);
		radioServicio.CreateX(NULL, L"Servicio", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 0.55563, 1.82562, 2.96333, 0.63500, hWnd, 1001);
		ddTipo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 4.60375, 1.77271, 4.78896, 0.60854, hWnd, 1002);
		ddMarca.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 10.26583, 1.74625, 4.78896, 0.60854, hWnd, 1003);
		ddModelo.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 15.50458, 1.71979, 4.78896, 0.60854, hWnd, 1004);
		ddColor.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 20.90208, 1.69333, 4.78896, 0.60854, hWnd, 1005);
		tbxCantidad.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 26.32604, 1.69333, 4.39208, 0.60854, hWnd, 1006);
		tbxPrecio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 26.32604, 3.86292, 4.39208, 0.60854, hWnd, 1007);
		tbxFinal.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 26.32604, 5.60917, 4.39208, 0.60854, hWnd, 1008);
		lvTabla.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.74083, 3.14854, 25.26771, 8.62542, hWnd, 1009);
		lbTipo.CreateX(NULL, L"Tipo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 4.60375, 0.58208, 4.81542, 0.60854, hWnd, 1010);
		lbMarca.CreateX(NULL, L"Marca", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10.10708, 0.58208, 4.84187, 0.60854, hWnd, 1011);
		lb3.CreateX(NULL, L"Modelo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 15.42521, 0.55563, 4.89479, 0.60854, hWnd, 1012);
		lbColor.CreateX(NULL, L"Color", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 20.87562, 0.52917, 4.92125, 0.60854, hWnd, 1013);
		lbCantidad.CreateX(NULL, L"Cantidad", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 26.37896, 0.52917, 4.39208, 0.60854, hWnd, 1014);
		lbPrecioSugerido.CreateX(NULL, L"Precio Sugerido", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 26.37896, 3.09563, 4.33917, 0.60854, hWnd, 1015);
		lbPrecio_Final.CreateX(NULL, L"Precio Final", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 26.37896, 4.89479, 4.36563, 0.60854, hWnd, 1016);
		gbox1.CreateX(WS_EX_TRANSPARENT, NULL, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 26.27313, 6.79979, 4.52438, 5.02708, hWnd, 1017);
		btAgregar.CreateX(NULL, L"Agregar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 26.45833, 7.32896, 4.15396, 0.68792, hWnd, 1018);
		btEditar.CreateX(NULL, L"Editar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 26.53771, 8.38729, 4.02167, 0.68792, hWnd, 1019);
		btTerminar.CreateX(NULL, L"Terminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 26.59062, 9.39271, 3.96875, 0.68792, hWnd, 1020);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 29.21000, 10.66271, 1.42875, 0.92604, hWnd, 1021);
		lb8.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 1.11125, 12.22375, 4.55083, 0.60854, hWnd, 1022);
		lb9.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 6.66750, 12.27667, 4.33917, 0.60854, hWnd, 1023);
		lvTabla.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		this->SetDefaultButton(btAgregar);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		radioArticulo.Font = fontArial009A;
		radioServicio.Font = fontArial009A;
		ddTipo.Font = fontArial009A;
		ddMarca.Font = fontArial009A;
		ddModelo.Font = fontArial009A;
		ddColor.Font = fontArial009A;
		tbxCantidad.Font = fontArial009A;
		tbxPrecio.Font = fontArial009A;
		tbxFinal.Font = fontArial009A;
		lvTabla.Font = fontArial009A;
		lbTipo.Font = fontArial009A;
		lbMarca.Font = fontArial009A;
		lb3.Font = fontArial009A;
		lbColor.Font = fontArial009A;
		lbCantidad.Font = fontArial009A;
		lbPrecioSugerido.Font = fontArial009A;
		lbPrecio_Final.Font = fontArial009A;
		gbox1.Font = fontArial009A;
		btAgregar.Font = fontArial009A;
		btEditar.Font = fontArial009A;
		btTerminar.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		lb8.Font = fontArial009A;
		lb9.Font = fontArial009A;
	}
	//_________________________________________________
	void radioArticulo_Click(Win::Event& e);
	void radioServicio_Click(Win::Event& e);
	void ddTipo_SelChange(Win::Event& e);
	void ddMarca_SelChange(Win::Event& e);
	void ddModelo_SelChange(Win::Event& e);
	void lvTabla_ItemChanged(Win::Event& e);
	void btAgregar_Click(Win::Event& e);
	void btEditar_Click(Win::Event& e);
	void btTerminar_Click(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void Window_Activate(Win::Event& e);
	void Window_Close(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioArticulo.IsEvent(e, BN_CLICKED)) {radioArticulo_Click(e); return true;}
		if (radioServicio.IsEvent(e, BN_CLICKED)) {radioServicio_Click(e); return true;}
		if (ddTipo.IsEvent(e, CBN_SELCHANGE)) {ddTipo_SelChange(e); return true;}
		if (ddMarca.IsEvent(e, CBN_SELCHANGE)) {ddMarca_SelChange(e); return true;}
		if (ddModelo.IsEvent(e, CBN_SELCHANGE)) {ddModelo_SelChange(e); return true;}
		if (lvTabla.IsEvent(e, LVN_ITEMCHANGED)) {lvTabla_ItemChanged(e); return true;}
		if (btAgregar.IsEvent(e, BN_CLICKED)) {btAgregar_Click(e); return true;}
		if (btEditar.IsEvent(e, BN_CLICKED)) {btEditar_Click(e); return true;}
		if (btTerminar.IsEvent(e, BN_CLICKED)) {btTerminar_Click(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		return false;
	}
};
