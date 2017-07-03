#include "stdafx.h"  //_____________________________________________ DetallesOrdenVentaDlg.cpp
#include "DetallesOrdenVentaDlg.h"

void DetallesOrdenVentaDlg::Window_Open(Win::Event& e)
{
	
	LibreriaAdDll::ordenNueva consultasObj;
	LibreriaAdDll::articulo consultasArtObj;
	//llenar tipo de articulo
	consultasObj.llenarDDTipoArticulo(ddTipo, 100, true, _puntoVenta);
	ddTipo.SetSelectedIndex(0);
	tipoPV = ddTipo.Text;

	//llena la marca
	consultasObj.llenarDDMarca(ddMarca, 100, true, tipoPV);
	ddMarca.SetSelectedIndex(0);
	marcaWsPV = ddMarca.Text;
	int marca_id = consultasArtObj.sacarIDMarca(marcaWsPV);
	//llena el modelo
	consultasObj.llenarDDModelo(ddModelo, marcaWsPV, 100, true);
	ddModelo.SetSelectedIndex(0);
	wstring modeloWS = ddModelo.Text;
	int modelo_id = consultasArtObj.sacarIDModelo(modeloWS);


	//saca el id del articulo
	int articulo_id = consultasObj.sacarIDArticulo(tipoPV, modelo_id, marca_id,_puntoVenta);


	//llena el color
	consultasObj.llenarDDcolor(ddColor, 100, articulo_id, _puntoVenta);
	ddColor.SetSelectedIndex(0);
	int pv_id = consultasObj.sacarIDPuntoVenta(_puntoVenta);
	tbxPrecioSugerido.SetText(Sys::Convert::ToString(consultasObj.sacarPrecioArticulo(articulo_id, pv_id)));


	radioArticulo.Checked = true;
	tbxPrecioSugerido.Enabled = false;
	/*folioVP = consultasObj.sacarUltimoFolio();*/
	consultasObj.llenarDescripcionOrden(lvCaracteristicasOrden, 100, folioVP);
	
	
	
}



void DetallesOrdenVentaDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaAdDll::articulo consultasArObj;
	LibreriaAdDll::ordenNueva consultasObj;
	
	if (radioArticulo.IsChecked() == true)
	{
		int marca_id = consultasArObj.sacarIDMarca(ddMarca.Text);
		int modelo_id = consultasArObj.sacarIDModelo(ddModelo.Text);
		int color_id = consultasArObj.sacarIDcolor(ddColor.Text);
		int puntoVenta_id = consultasArObj.sacarIDPuntoVenta(_puntoVenta);
		int tipo_articulo = consultasObj.sacarIDTipoArticulo(ddTipo.Text);
		int articulo_id = consultasObj.sacarIDArticulo(color_id, puntoVenta_id, modelo_id, marca_id, tipo_articulo);
		int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
		double precioSugerido = Sys::Convert::ToDouble(tbxPrecioSugerido.Text);
		double precioFinal = Sys::Convert::ToDouble(tbxPrecioFinal.Text);
		int requerimienti_id = consultasObj.sacarIDRequerimiento(L"Articulo");
		int orden_id = consultasObj.sacarUltIDOrden();


		consultasObj.insertOrdenDescripcion(articulo_id, cantidad, precioSugerido, precioFinal, orden_id, requerimienti_id);
		MessageBoxW(L"Registro Exitoso", L"", MB_OK | MB_ICONINFORMATION);
		lb8.SetText(Sys::Convert::ToString(orden_id));
		LibreriaAngelDll::reporteVentasCLS reporteObj;
		reporteObj.llenarReporteVentasOrdenCompra(lvCaracteristicasOrden, folioVP, 100, true  );

		/*consultasObj.llenarDescripcionOrden(lvCaracteristicasOrden, 100, folioVP);*/
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
		lb8.SetText(Sys::Convert::ToString(orden_id));
		LibreriaAngelDll::reporteVentasCLS reporteObj;
		reporteObj.llenarReporteVentasOrdenCompra(lvCaracteristicasOrden, folioVP, 100, true);
		/*consultasObj.llenarDescripcionOrden(lvCaracteristicasOrden, 100, folioVP);*/
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

	LibreriaAdDll::ordenNueva consultasObj;
	LibreriaAdDll::articulo consultasArtObj;
	//llenar tipo de articulo
	consultasObj.llenarDDTipoArticulo(ddTipo, 100, true, _puntoVenta);
	ddTipo.SetSelectedIndex(0);
	tipoPV = ddTipo.Text;


	//llena la marca
	consultasObj.llenarDDMarca(ddMarca, 100, true, tipoPV);
	ddMarca.SetSelectedIndex(0);
	marcaWsPV = ddMarca.Text;
	int marca_id = consultasArtObj.sacarIDMarca(marcaWsPV);
	//llena el modelo
	consultasObj.llenarDDModelo(ddModelo, marcaWsPV, 100, true);
	ddModelo.SetSelectedIndex(0);
	wstring modeloWS = ddModelo.Text;
	int modelo_id = consultasArtObj.sacarIDModelo(modeloWS);


	//saca el id del articulo
	int articulo_id = consultasObj.sacarIDArticulo(tipoPV, modelo_id, marca_id, _puntoVenta);


	//llena el color
	consultasObj.llenarDDcolor(ddColor, 100, articulo_id, _puntoVenta);
	ddColor.SetSelectedIndex(0);

	radioArticulo.Checked = true;
	tbxPrecioSugerido.Enabled = false;
	wstring folio = consultasObj.sacarUltimoFolio();
	consultasObj.llenarDescripcionOrden(lvCaracteristicasOrden, 100, folio);
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
	tbxCantidad.SetText(L"");
	tbxPrecioFinal.SetText(L"");

}

void DetallesOrdenVentaDlg::ddTipo_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva consultasObj;
	LibreriaAdDll::articulo consultasArtObj;
	if (radioArticulo.IsChecked() == true)
	{
		//llenar tipo de articulo
		consultasObj.llenarDDTipoArticulo(ddTipo, 100, true, _puntoVenta);
		ddTipo.SetSelectedIndex(0);
		wstring tipo = ddTipo.Text;

		//llena la marca
		consultasObj.llenarDDMarca(ddMarca, 100, true, tipo);
		ddMarca.SetSelectedIndex(0);
		marcaWsPV = ddMarca.Text;
		int marca_id = consultasArtObj.sacarIDMarca(marcaWsPV);
		//llena el modelo
		consultasObj.llenarDDModelo(ddModelo, marcaWsPV, 100, true);
		ddModelo.SetSelectedIndex(0);
		wstring modeloWS = ddModelo.Text;
		int modelo_id = consultasArtObj.sacarIDModelo(modeloWS);


		//saca el id del articulo
		int articulo_id = consultasObj.sacarIDArticulo(tipo, modelo_id, marca_id, _puntoVenta);


		//llena el color
		consultasObj.llenarDDcolor(ddColor, 100, articulo_id, _puntoVenta);
		ddColor.SetSelectedIndex(0);

		radioArticulo.Checked = true;
		tbxPrecioSugerido.Enabled = false;
		wstring folio = consultasObj.sacarUltimoFolio();
		consultasObj.llenarDescripcionOrden(lvCaracteristicasOrden, 100, folio);
	}
	else
	{
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
		tbxCantidad.SetText(L"");
		tbxPrecioFinal.SetText(L"");
		wstring folio = consultasObj.sacarUltimoFolio();
		consultasObj.llenarDescripcionOrden(lvCaracteristicasOrden, 100, folio);

	}
	
	
}

void DetallesOrdenVentaDlg::tbxCantidad_Change(Win::Event& e)
{
	int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
	double precio = Sys::Convert::ToDouble(tbxPrecioSugerido.Text);
	double precioTotal = cantidad*precio;
	tbxPrecioFinal.SetText(Sys::Convert::ToString(precioTotal));
}

void DetallesOrdenVentaDlg::btEditar_Click(Win::Event& e)
{
	LibreriaAdDll::articulo consultasArtObj;
	LibreriaAdDll::ordenNueva consultasObj;
	bool cambio;
	//Checa si todas las celdas tienen texto
	if (this->tbxCantidad.GetTextLength() <= 0) {
		this->tbxCantidad.ShowBalloonTip(L"Cantidad", L"Ingrese una cantidad", TTI_ERROR);
		return;
	}
	else if (this->tbxPrecioSugerido.GetTextLength() <= 1) {
		this->tbxPrecioSugerido.ShowBalloonTip(L"Precio", L"Ingrese un precio", TTI_ERROR);
		return;
	}

	else if (this->tbxPrecioFinal.GetTextLength() <= 1)
	{
		this->tbxPrecioFinal.ShowBalloonTip(L"Cantidad", L"Ingrese una Precio final", TTI_ERROR);
		return;
	}


	if (ddColor.Text != ColorVP)
	{
		//sacar id del departamento donde esta
		
		/*int colorNuevo_id = consultasArtObj.sacarIDcolor(ddColor.Text);
		consultasArtObj.sacarIDCantidad(idColorVP, idPuntoVentaVP, idArtUPVP);
		consultaObj.updateCantidadENColor(cantidad_id, colorNuevo_id);
		cambio = true;*/
	}
	

	
}

void DetallesOrdenVentaDlg::lvCaracteristicasOrden_ItemChanged(Win::Event& e)
{
	LibreriaAdDll::ordenNueva consultasObj;
	LibreriaAdDll::articulo consultasArtObj;
	TipoArticuloVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 0);
	MarcaVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 1);
	ModeloVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 2);
	ColorVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 3);
	CantidadVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 4);
	PSugeridoVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 5);
	PFinalVP = consultasObj.sacarTextoLV(lvCaracteristicasOrden, 6);
	
	idArtUPVP = consultasObj.sacarIDArticuloUpdate(TipoArticuloVP, ModeloVP, marcaWsPV );
	idColorVP = consultasArtObj.sacarIDcolor(ColorVP);
	idPuntoVentaVP = consultasObj.sacarIDPuntoVenta(_puntoVenta);

	cantidadVP = consultasArtObj.sacarIDCantidad(idColorVP, idPuntoVentaVP, idArtUPVP);
	ddTipo.SetSelected(TipoArticuloVP);
	ddMarca.SetText(MarcaVP);
	ddModelo.SetSelected(ModeloVP);
	ddColor.SetSelected(ColorVP);
	tbxCantidad.SetText(CantidadVP);
	tbxPrecioSugerido.SetText(PSugeridoVP);
	tbxPrecioFinal.SetText(PFinalVP);
}

