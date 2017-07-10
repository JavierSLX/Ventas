#include "stdafx.h"  //_____________________________________________ DescripcionOrdenVentasDlg.cpp
#include "DescripcionOrdenVentasDlg.h"

void DescripcionOrdenVentasDlg::Window_Open(Win::Event& e)
{
	Sys::Icon iconoAgregar;
	iconoAgregar.Load(hInstance, IDI_AGREGAR);
	btAgregar.SetImage(iconoAgregar);

	Sys::Icon editar;
	editar.Load(hInstance, IDI_EDITAR);
	btEditar.SetImage(editar);

	Sys::Icon terminar;
	terminar.Load(hInstance, IDI_ACEPTAR);
	btTerminar.SetImage(terminar);

	radioArticulo.Checked = true;

	//Llena la ddlist de tipo de articulo
	LibreriaAdDll::ordenNueva ordenObj;
	ordenObj.llenarDDTipoArticulo(ddTipo, 100, true, puntoVentaVP);
	ddTipo.SetSelectedIndex(0);

	//Llena la ddlist de marca
	ordenObj.llenarDDMarca(ddMarca, 100, true, ddTipo.Text);
	ddMarca.SetSelectedIndex(0);

	//Llena la ddlist de modelo
	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);

	//Saca el articulo_id y llena la ddlist de color
	LibreriaAdDll::articulo articuloObj;
	int articulo_id = ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
		articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP);
	double precioCliente = ordenObj.sacarPrecioArticulo(articulo_id, ordenObj.sacarIDCliente(CClienteVP, puntoVentaVP));
	
	tbxPrecio.SetText(Sys::Convert::ToString(precioCliente));
	tbxPrecio.Enabled = false;
	tbxFinal.SetText(Sys::Convert::ToString(precioCliente));

	if (articulo_id != 0)
	{
		ordenObj.llenarDDcolor(ddColor, 100, articulo_id, puntoVentaVP);
		ddColor.SetSelectedIndex(0);
	}
	else
	{
		MessageBoxW(L"No existe ningún artículo con esa combinación", L"Articulo", MB_OK | MB_ICONERROR);
		ddColor.DeleteAllItems();
	}
}

void DescripcionOrdenVentasDlg::radioArticulo_Click(Win::Event& e)
{
	radioArticulo.Checked = true;
	radioServicio.Checked = false;
	tbxCantidad.Text = L"";
	tbxPrecio.Text = L"";
	tbxFinal.Text = L"";
	lb3.Visible = true;
	lbMarca.Visible = true;
	lbColor.Visible = true;
	ddMarca.Visible = true;
	ddModelo.Visible = true;
	ddColor.Visible = true;
	//Llena la ddlist de tipo de articulo
	LibreriaAdDll::ordenNueva ordenObj;
	ordenObj.llenarDDTipoArticulo(ddTipo, 100, true, puntoVentaVP);
	ddTipo.SetSelectedIndex(0);

	//Llena la ddlist de marca
	ordenObj.llenarDDMarca(ddMarca, 100, true, ddTipo.Text);
	ddMarca.SetSelectedIndex(0);

	//Llena la ddlist de modelo
	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);

	//Saca el articulo_id y llena la ddlist de color
	LibreriaAdDll::articulo articuloObj;
	int articulo_id = ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
		articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP);
	double precioCliente = ordenObj.sacarPrecioArticulo(articulo_id, ordenObj.sacarIDCliente(CClienteVP, puntoVentaVP));

	tbxPrecio.SetText(Sys::Convert::ToString(precioCliente));
	tbxPrecio.Enabled = false;
	tbxFinal.SetText(Sys::Convert::ToString(precioCliente));

	if (articulo_id != 0)
	{
		ordenObj.llenarDDcolor(ddColor, 100, articulo_id, puntoVentaVP);
		ddColor.SetSelectedIndex(0);
	}
	else
	{
		MessageBoxW(L"No existe ningún artículo con esa combinación", L"Articulo", MB_OK | MB_ICONERROR);
		ddColor.DeleteAllItems();
	}
}

void DescripcionOrdenVentasDlg::radioServicio_Click(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;
	radioArticulo.Checked = false;
	radioServicio.Checked = true;
	ddMarca.Visible = false;
	ddModelo.Visible = false;
	ddColor.Visible = false;
	lb3.Visible = false;
	lbMarca.Visible = false;
	lbColor.Visible = false;
	ordenObj.llenarDDServicio(ddTipo, 100, true);
	ddTipo.SetSelectedIndex(0);
	tbxCantidad.Text = L"";
	tbxPrecio.Text = L"";
	tbxFinal.Text = L"";
	tbxPrecio.SetText(Sys::Convert::ToString(ordenObj.sacarPrecio(ordenObj.sacarIDServicio(ddTipo.Text))));
	tbxFinal.SetText(Sys::Convert::ToString(ordenObj.sacarPrecio(ordenObj.sacarIDServicio(ddTipo.Text))));
}

void DescripcionOrdenVentasDlg::ddTipo_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;
	if (radioArticulo.IsChecked() == true)
	{
	
	//Llena la ddlist de marca
	ordenObj.llenarDDMarca(ddMarca, 100, true, ddTipo.Text);
	ddMarca.SetSelectedIndex(0);

	//Llena la ddlist de modelo
	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);

	//Saca el articulo_id y llena la ddlist de color
	LibreriaAdDll::articulo articuloObj;
	int articulo_id = ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
		articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP);

	if (articulo_id != 0)
	{
		ordenObj.llenarDDcolor(ddColor, 100, articulo_id, puntoVentaVP);
		ddColor.SetSelectedIndex(0);
	}
	else
	{
		MessageBoxW(L"No existe ningún artículo con esa combinación", L"Articulo", MB_OK | MB_ICONERROR);
		ddColor.DeleteAllItems();
	}
	}
	else if (radioServicio.IsChecked()== true)
	{
		tbxPrecio.SetText(Sys::Convert::ToString(ordenObj.sacarPrecio(ordenObj.sacarIDServicio(ddTipo.Text))));
		tbxFinal.SetText(tbxPrecio.Text);

	}

}

void DescripcionOrdenVentasDlg::ddMarca_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;

	//Llena la ddlist de modelo
	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);

	//Saca el articulo_id y llena la ddlist de color
	LibreriaAdDll::articulo articuloObj;
	int articulo_id = ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
		articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP);

	if (articulo_id != 0)
	{
		ordenObj.llenarDDcolor(ddColor, 100, articulo_id, puntoVentaVP);
		ddColor.SetSelectedIndex(0);
	}
	else
	{
		MessageBoxW(L"No existe ningún artículo con esa combinación", L"Articulo", MB_OK | MB_ICONERROR);
		ddColor.DeleteAllItems();
	}
}

void DescripcionOrdenVentasDlg::ddModelo_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;

	//Saca el articulo_id y llena la ddlist de color
	LibreriaAdDll::articulo articuloObj;
	int articulo_id = ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
		articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP);
	double precioCliente = ordenObj.sacarPrecioArticulo(articulo_id, ordenObj.sacarIDCliente(CClienteVP, puntoVentaVP));
	tbxPrecio.SetText(Sys::Convert::ToString(precioCliente));
	tbxFinal.SetText(tbxPrecio.Text);
	tbxCantidad.SetText(L"");
	if (articulo_id != 0)
	{
		ordenObj.llenarDDcolor(ddColor, 100, articulo_id, puntoVentaVP);
		ddColor.SetSelectedIndex(0);
		//tbxPrecio.DoubleValue = ordenObj.sacarPrecioArticulo(articulo_id, puntoVentaVP);
	}
	else
	{
		MessageBoxW(L"No existe ningún artículo con esa combinación", L"Articulo", MB_OK | MB_ICONERROR);
		ddColor.DeleteAllItems();
	}
}

void DescripcionOrdenVentasDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaFBDll::Movimiento movObj;
	LibreriaAdDll::ordenNueva ordenObj;
	LibreriaAdDll::articulo articuloObj;
	cantidadExistenteVP = movObj.sacarCantidadDepartamento(ddColor.Text, articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text), articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP));
		

		if (radioArticulo.IsChecked() == true)
		{
			if (tbxCantidad.IntValue >= cantidadExistenteVP)
			{
				MessageBoxW(L"No se puede realizar", L"Articulo", MB_OK | MB_ICONERROR);
				tbxCantidad.Text = L"";
				tbxPrecio.Text = L"";
				tbxFinal.Text = L"";

			}
			else
			{
				//inserta en la tabla cantidad requerimienti
				ordenObj.insertarCantidadRequerimiento(movObj.sacarIDCantidad(ddColor.Text, articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
					//insertar en orden descripcion
					articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP)), ordenObj.sacarIDRequerimiento(L"Articulo"));
				int cantidadOrden = Sys::Convert::ToInt(tbxCantidad.Text);
				int orden_id = ordenObj.sacarUltIDOrden();
				ordenObj.insertOrdenDescripcion(ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
					articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP), tbxCantidad.IntValue, tbxPrecio.DoubleValue, tbxFinal.DoubleValue, orden_id, ordenObj.sacarIDRequerimiento(L"Articulo"));
				MessageBoxW(L"Se agregó correctamente", L"Articulo", MB_OK | MB_ICONINFORMATION);
				ordenObj.llenarLVDetallesOrden(lvTabla, 100, true, folioVP);
				int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
				double precio = Sys::Convert::ToDouble(tbxFinal.Text);
				//sacar el total del precio a pagar de ese articulo
				double Total= (double)cantidad * precio;
				//sacar el total del precio a pagar de todos los articulos de la orden
				TotalPrecioArticulosVP += Total;
				
				//Descontar cantidad de inventario
				int idCantidad = articuloObj.sacarIDCantidad(articuloObj.sacarIDcolor(ddColor.Text), articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text), articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP));
				int cantidadActualizar = cantidadExistenteVP - cantidadOrden;
				articuloObj.updateCantidad(idCantidad, cantidadActualizar);

				int idArticulo = ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
					articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP);
				//Insertar en tabla movimiento
				int idPuntoVenta = ordenObj.sacarIDPuntoVenta(puntoVentaVP);
				movObj.insertarMovimiento(cantidadOrden, 2, idPuntoVenta, idArticulo, 26);
				//inserta la fecha del movimiento
				int movimiento = movObj.sacarIDUltimoMovimiento();
				movObj.insertarfechaMovimiento(movimiento);

				//insertar comisiones
				
					int idRango = ordenObj.sacarIDrango(Sys::Convert::ToInt(tbxFinal.Text), idArticulo);
					/*lb9.SetText(Sys::Convert::ToString(idRango));*/
					
					//verifica si existe comision para ese articulo
				if (idRango == 0)
				{
					//si no hay comision para ese se genera comision 0 pr default
					/*contadorVP = 0;*/
					int IdOrdenDesc = ordenObj.sacarUltIDOrdenDesc();
					ordenObj.insertarArticuloComision(0.0, true, 1, IdOrdenDesc);
					contadorVP++;
					articulosSinRangoVP.push_back(idArticulo);
					articuloSinRangoOdVP.push_back(IdOrdenDesc);
					cantidadArticuloSinRangoVP.push_back(tbxCantidad.IntValue);
					precioArticuloSinRangoVP.push_back(tbxFinal.DoubleValue);
					lb8.SetText(Sys::Convert::ToString(contadorVP));
				}
				else
				{
					
					//si hay comision ...
					double comision = ordenObj.sacarComision(idRango);
					int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
					//saca el total de la comision de un articulo
					double totalComision = (double)cantidad * comision;
					int IdOrdenDesc = ordenObj.sacarUltIDOrdenDesc();
					//inserta el total del ese articulo en la tabla articulo comision
					ordenObj.insertarArticuloComision(totalComision, true, idRango, IdOrdenDesc);
					//saca el total de comisiones de la orden
					TotalComisionArticulosVP += totalComision;

				}
				
			}

		}
		else  if (radioServicio.IsChecked() == true)
		{
			ordenObj.insertarServicioRequerimiento(ordenObj.sacarIDServicio(ddTipo.Text), ordenObj.sacarIDRequerimiento(L"Servicio"));
			ordenObj.insertOrdenDescripcion(ordenObj.sacarIDServicio(ddTipo.Text), tbxCantidad.IntValue, tbxPrecio.DoubleValue, tbxFinal.DoubleValue, ordenObj.sacarUltIDOrden(), ordenObj.sacarIDRequerimiento(L"Servicio"));
			MessageBoxW(L"Se agregó correctamente", L"Servicio", MB_OK | MB_ICONINFORMATION);

			int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
			double precio = Sys::Convert::ToDouble(tbxFinal.Text);

			ordenObj.llenarLVDetallesOrden(lvTabla, 100, true, folioVP);
			//sacar el total por pagar en los servicios
			double Total = (double)cantidad * precio;
			TotalPrecioServiciosVP += Total;

			int idServicio = ordenObj.sacarIDServicio(ddTipo.Text);
			int idRango = ordenObj.sacarIDrangoServicio(Sys::Convert::ToInt(tbxFinal.Text), idServicio);
			lb8.SetText(Sys::Convert::ToString(idRango));
			//verifica si el servicio tiene cio
			if (idRango == 0)
			{
				int IdOrdenDesc = ordenObj.sacarUltIDOrdenDesc();
				ordenObj.insertarServicioComision(0.0, true, 2, IdOrdenDesc);
				contadorVP++;
				serviciosSinRangoVP.push_back(idServicio);
				serviciosSinRangoOdVP.push_back(IdOrdenDesc);
				cantidadServiciosSinRangoVP.push_back(tbxCantidad.IntValue);
				precioservicioSinRangoVP.push_back(tbxFinal.DoubleValue);
				lb9.SetText(Sys::Convert::ToString(contadorVP));

			}
			else
			{
				// si hay comision para ese servicio
				double comision = ordenObj.sacarComision(idServicio);
				int cantidad = Sys::Convert::ToInt(tbxCantidad.Text);
				//sacar la comision total de ese articulo
				double totalComision = (double)cantidad * comision;
				int IdOrdenDesc = ordenObj.sacarUltIDOrdenDesc();
				//inserta la comision en la tabla servicio comision
				ordenObj.insertarServicioComision(totalComision, true, idRango, IdOrdenDesc);
				//sacar el total de comisiones de todos los servicios de esas ordenes
				totalComision += totalComision;
			}
		}
		
	}
	
	
void DescripcionOrdenVentasDlg::btEditar_Click(Win::Event& e)
{

	bool cambio =false;
	LibreriaFBDll::Movimiento movObj;
	LibreriaAdDll::ordenNueva ordenObj;
	LibreriaAdDll::articulo  articuloObj;
	cantidadExistenteVP = movObj.sacarCantidadDepartamento(ddColor.Text, articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text), articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP));
	int idCantidad = articuloObj.sacarIDCantidad(articuloObj.sacarIDcolor(ddColor.Text), articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text), articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP));
	//Cuando se hizo un cambio de codigo
	if (tbxCantidad.Text != CantidadVP)
	{
	
		int cantidadNueva = Sys::Convert::ToInt(tbxCantidad.Text);
		ordenObj.updateCantidaDescrOreden(idDetalles, cantidadNueva);
		int cantidadInventario = Sys::Convert::ToInt(CantidadVP) - cantidadNueva;
		ordenObj.updateCantidadInventario(idCantidad, cantidadExistenteVP + cantidadInventario);
		cambio = true;
	}
	if (tbxFinal.Text != PFinalVP)
	{
		int articulo_id = idDetalles;
		double precio = Sys::Convert::ToInt(tbxFinal.Text);
		ordenObj.updatePrecioDescrOreden(idDetalles, precio);
		cambio = true;
	}
	if (cambio == true) {

		MessageBoxW(L"Se guardaron los cambios", L"", MB_OK | MB_ICONINFORMATION);

	}
	else {
		MessageBoxW(L"No se realizó ningun cambio", L"", MB_OK | MB_ICONINFORMATION);
	}
	ordenObj.llenarLVDetallesOrden(lvTabla, 100, true, folioVP);
}

void DescripcionOrdenVentasDlg::btTerminar_Click(Win::Event& e)
{
	LibreriaAdDll::articulo articuloObj;
	LibreriaAdDll::ordenNueva ordenObj;
	lb8.SetText(Sys::Convert::ToString(contadorVP));
	
	int orden = ordenObj.sacarUltIDOrden();
	//saca el total a pagar de esa orden
	double totalOrden = ordenObj.sacarTotalOrdenDescripcion(orden);
	ordenObj.insertarTotalServicioComision(TotalComisionServiciosVP, ordenObj.sacarUltIDOrden());
	ordenObj.insertarTotalArticuloComision(TotalComisionArticulosVP, ordenObj.sacarUltIDOrden());
	

	if (MessageBoxW(L"¿La compra es al CONTADO?", L"Opcion compra", MB_YESNO | MB_ICONINFORMATION) == IDYES)
	{
		//si la orden se paga al contado se inserta en orden completa 
		ordenObj.insertarOrdenCompleta(totalOrden, orden);
		lb9.SetText(Sys::Convert::ToString(contadorVP));
		OrdenCompletaDlg ventana(totalOrden,L"Contado", folioVP, contadorVP);
		ventana.BeginDialog(hWnd);
		this->EndDialog(IDOK);
		
	}
	else {
		//si la orden se hizo a credito se inserta en credito
		ordenObj.insertarCredito(totalOrden, orden);
		OrdenCompletaDlg ventana(totalOrden, L"Credito", folioVP, contadorVP);
		ventana.BeginDialog(hWnd);
		this->EndDialog(IDOK);
		

	}
}

void DescripcionOrdenVentasDlg::lvTabla_ItemChanged(Win::Event& e)
{

	LibreriaAdDll::ordenNueva consultasObj;
	LibreriaAdDll::articulo consultasArtObj;
	LibreriaAdDll::ordenNueva ordenObj;
	LibreriaAdDll::articulo articuloObj;

	idDetalles = consultasObj.sacarIDOcultoLV(lvTabla);
	wstring requerimiento = consultasObj.sacarTextoLV(lvTabla, 0);
	if (requerimiento == L"Articulo")
	{
		
		TipoArticuloVP = consultasObj.sacarTextoLV(lvTabla, 1);

		MarcaVP = consultasObj.sacarTextoLV(lvTabla, 2);
		ModeloVP = consultasObj.sacarTextoLV(lvTabla, 3);
		ColorVP = consultasObj.sacarTextoLV(lvTabla, 4);
		CantidadVP = consultasObj.sacarTextoLV(lvTabla, 5);
		PSugeridoVP = consultasObj.sacarTextoLV(lvTabla, 6);
		PFinalVP = consultasObj.sacarTextoLV(lvTabla, 7);

		ddTipo.SetSelected(TipoArticuloVP);
		/*Llena la ddlist de marca*/
		ordenObj.llenarDDMarca(ddMarca, 100, true,TipoArticuloVP);
		ddMarca.SetSelected(MarcaVP);

		//Llena la ddlist de modelo
		ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
		ddModelo.SetSelected(ModeloVP);

		//Llena la ddlist con los colores
		ordenObj.llenarDDcolor(ddColor, 100, ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
			articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP), puntoVentaVP);
		ddColor.SetSelected(ColorVP);
		
		tbxCantidad.SetText(CantidadVP);
		tbxPrecio.SetText(PSugeridoVP);
		tbxFinal.SetText(PFinalVP);
		ddMarca.Visible = true;
		ddModelo.Visible = true;
		ddColor.Visible = true;
		lbMarca.Visible = true;
		lb3.Visible = true;
		lbColor.Visible = true;
		ddMarca.Enabled = true;
		ddModelo.Enabled = true;
		ddColor.Enabled = true;
		ddTipo.Enabled = true;
		
	}
	else if (requerimiento == L"Servicio")
	{
		TipoArticuloVP = consultasObj.sacarTextoLV(lvTabla, 1);
		CantidadVP = consultasObj.sacarTextoLV(lvTabla, 5);
		PSugeridoVP = consultasObj.sacarTextoLV(lvTabla, 6);
		PFinalVP = consultasObj.sacarTextoLV(lvTabla, 7);

		ddTipo.SetSelected(TipoArticuloVP);
		ddMarca.Visible = false;
		ddModelo.Visible = false;
		ddColor.Visible = false;
		lbMarca.Visible = false;
		lb3.Visible = false;
		lbColor.Visible = false;
		ddTipo.Enabled = true;
		tbxCantidad.SetText(CantidadVP);
		tbxPrecio.SetText(PSugeridoVP);
		tbxFinal.SetText(PFinalVP);
	}
}


void DescripcionOrdenVentasDlg::Window_Close(Win::Event& e)
{
	//this->Destroy(); // Use this to close and destroy the Window

}

void DescripcionOrdenVentasDlg::Window_Activate(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;
	const bool activated = (e.wParam != WA_INACTIVE);
	e.returnValue = 0;

	if (contadorVP != 0)
	{
		int rangoVectorContador = articulosSinRangoVP.size();
		for (int i = 0; i < rangoVectorContador; i++)
		{
			int idRango = ordenObj.sacarIDrango(precioArticuloSinRangoVP[i], articulosSinRangoVP[i]);
			//Hacer la operacion para calcular total del articulo-comision
			//si hay comision ...
			double comision = ordenObj.sacarComision(idRango);
			int cantidad = cantidadArticuloSinRangoVP[i];
			//saca el total de la comision de un articulo
			double totalComision = (double)cantidad * comision;
			int IdOrdenDesc = articuloSinRangoOdVP[i];
			//update el total del ese articulo en la tabla articulo comision
			ordenObj.actualizarArticuloComision(totalComision, true, idRango, IdOrdenDesc);
			
		}
		int ultimaOrden = ordenObj.sacarUltIDOrden();
		ordenObj.actualizarTotalArticuloComision(ultimaOrden);

		 rangoVectorContador = serviciosSinRangoVP.size();
		for (int i = 0; i < rangoVectorContador; i++)
		{
			int idRango = ordenObj.sacarIDrangoServicio(precioservicioSinRangoVP[i], serviciosSinRangoVP[i]);
			//Hacer la operacion para calcular total del articulo-comision
			//si hay comision ...
			double comision = ordenObj.sacarComision(idRango);
			int cantidad = cantidadServiciosSinRangoVP[i];
			//saca el total de la comision de un articulo
			double totalComision = (double)cantidad * comision;
			int IdOrdenDesc = serviciosSinRangoOdVP[i];
			//update el total del ese articulo en la tabla articulo comision
			ordenObj.actualizarServicioComision(totalComision, true, idRango, IdOrdenDesc);

		}
		ordenObj.actualizarTotalServicioComision(ultimaOrden);
	}
}

