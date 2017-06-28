#include "stdafx.h"  //_____________________________________________ DetallesOrdenVentaDlg.cpp
#include "DetallesOrdenVentaDlg.h"

void DetallesOrdenVentaDlg::Window_Open(Win::Event& e)
{
	LibreriaAdDll::articulo consultasArtObj;
	consultasArtObj.llenarDDMarca(ddMarca, 100, true);
	ddMarca.SetSelectedIndex(0);
	marcaWsPV = ddMarca.Text;
	consultasArtObj.llenarDDModelo(ddModelo, marcaWsPV, 100, true);
	ddModelo.SetSelectedIndex(0);
	consultasArtObj.llenarDDcolor(ddColor, 100, true);
	ddColor.SetSelectedIndex(0);
	consultasArtObj.llenarDDarticulo(ddTipo, 100, true);
	ddTipo.SetSelectedIndex(0);
	radioArticulo.Checked = true;
	
	
	//________________________________________________________ lvCaracteristicasOrden
	lvCaracteristicasOrden.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvCaracteristicasOrden.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvCaracteristicasOrden.Items.Add(0, L"Monday");
	lvCaracteristicasOrden.Items[0][1].Text = L"Math Class";
	
}



void DetallesOrdenVentaDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaAdDll::articulo consultasArObj;
	LibreriaAdDll::ordenNueva consultasObj;
	int marca_id = consultasArObj.sacarIDMarca(ddMarca.Text);
	int modelo_id = consultasArObj.sacarIDModelo(ddModelo.Text);
	int color_id = consultasArObj.sacarIDcolor(ddColor.Text);
	int puntoVenta_id = consultasArObj.sacarIDPuntoVenta(_puntoVenta);
	int tipo_articulo = consultasObj.sacarIDTipoArticulo(ddTipo.Text);
	int articulo_id = consultasObj.sacarIDArticulo(color_id,puntoVenta_id,modelo_id,marca_id, tipo_articulo);
	if (radioArticulo.IsChecked() == true)
	{
		int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
		double precioSugerido = Sys::Convert::ToDouble(tbxPrecioSugerido.Text);
		double precioFinal = Sys::Convert::ToDouble(tbxPrecioFinal.Text);
		int requerimienti_id = consultasObj.sacarIDRequerimiento(L"Articulo");
		int orden_id = consultasObj.sacarUltIDOrden();
		consultasObj.insertOrdenDescripcion(articulo_id, cantidad, precioSugerido, precioFinal, orden_id, requerimienti_id);
		MessageBoxW(L"Registro Exitoso", L"", MB_OK | MB_ICONINFORMATION);
	}
	else if(radioServicio.IsChecked() == true)
	{
		int servicio_id = consultasObj.sacarIDServicio(ddTipo.Text);
		int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
		double precioSugerido = Sys::Convert::ToDouble(tbxPrecioSugerido.Text);
		double precioFinal = Sys::Convert::ToDouble(tbxPrecioFinal.Text);
		int requerimienti_id = consultasObj.sacarIDRequerimiento(L"Servicio");
		int orden_id = consultasObj.sacarUltIDOrden();
		consultasObj.insertOrdenDescripcion(servicio_id, cantidad, precioSugerido, precioFinal, orden_id, requerimienti_id);
		MessageBoxW(L"Registro Exitoso", L"", MB_OK | MB_ICONINFORMATION);
	}

	

}

void DetallesOrdenVentaDlg::btLimpiar_Click(Win::Event& e)
{
}

void DetallesOrdenVentaDlg::btTerminar_Click(Win::Event& e)
{
	if (MessageBoxW(L"La compra es al CONTADO", L"Opcion compra", MB_YESNO | MB_ICONINFORMATION) == IDYES)
	{
	}
	else {

	}
}

void DetallesOrdenVentaDlg::ddMarca_SelChange(Win::Event& e)
{
	LibreriaAdDll::articulo consultasObj;
	marcaWsPV = ddMarca.Text;
	consultasObj.llenarDDModelo(ddModelo, marcaWsPV, 100, true);
	ddModelo.SetSelectedIndex(0);
}

void DetallesOrdenVentaDlg::radioArticulo_Click(Win::Event& e)
{
	radioArticulo.Checked = true;
	radioServicio.Checked = false;
	ddMarca.Visible = true;
	ddModelo.Visible = true;
	ddColor.Visible = true;
	lbMarca.Visible = true;
	lbModelo.Visible = true;
	lbColor.Visible = true;
	LibreriaAdDll::articulo consultasArtObj;
	consultasArtObj.llenarDDMarca(ddMarca, 100, true);
	ddMarca.SetSelectedIndex(0);
	marcaWsPV = ddMarca.Text;
	consultasArtObj.llenarDDModelo(ddModelo, marcaWsPV, 100, true);
	ddModelo.SetSelectedIndex(0);
	consultasArtObj.llenarDDcolor(ddColor, 100, true);
	ddColor.SetSelectedIndex(0);
	consultasArtObj.llenarDDarticulo(ddTipo, 100, true);
	ddTipo.SetSelectedIndex(0);
	radioArticulo.Checked = true;
}

void DetallesOrdenVentaDlg::radioServicio_Click(Win::Event& e)
{
	LibreriaAdDll::ordenNueva consultasObj;
	radioArticulo.Checked = false;
	radioServicio.Checked = true;
	consultasObj.llenarDDServicio(ddTipo, 100, true);
	ddTipo.SetSelectedIndex(0);
	ddMarca.Visible = false;
	ddModelo.Visible = false;
	ddColor.Visible = false;
	lbMarca.Visible = false;
	lbModelo.Visible = false;
	lbColor.Visible = false;

}

