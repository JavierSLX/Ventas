#include "stdafx.h"  //_____________________________________________ DescripcionOrdenVentasDlg.cpp
#include "DescripcionOrdenVentasDlg.h"

void DescripcionOrdenVentasDlg::Window_Open(Win::Event& e)
{
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
		tbxFinal.SetText(Sys::Convert::ToString(ordenObj.sacarPrecio(ordenObj.sacarIDServicio(ddTipo.Text))));

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
	
	

		if (radioArticulo.IsChecked() == true)
		{
			if (tbxCantidad.IntValue > cantidadExistenteVP)
			{
				MessageBoxW(L"No se puede realizar", L"Articulo", MB_OK | MB_ICONERROR);

			}
			else
			{
				ordenObj.insertarCantidadRequerimiento(movObj.sacarIDCantidad(ddColor.Text, articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
					articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP)), ordenObj.sacarIDRequerimiento(L"Articulo"));

				ordenObj.insertOrdenDescripcion(ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text),
					articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP), tbxCantidad.IntValue, tbxPrecio.DoubleValue, tbxFinal.DoubleValue, ordenObj.sacarUltIDOrden(), ordenObj.sacarIDRequerimiento(L"Articulo"));
				MessageBoxW(L"Ya inserto", L"Articulo", MB_OK | MB_ICONERROR);
				ordenObj.llenarLVDetallesOrden(lvTabla, 100, true, folioVP);
			}
		}
		else  if (radioServicio.IsChecked()  == true)
		{
			ordenObj.insertarServicioRequerimiento(ordenObj.sacarIDServicio(ddTipo.Text), ordenObj.sacarIDRequerimiento(L"Servicio"));
			ordenObj.insertOrdenDescripcion(ordenObj.sacarIDServicio(ddTipo.Text), tbxCantidad.IntValue, tbxPrecio.DoubleValue, tbxFinal.DoubleValue, ordenObj.sacarUltIDOrden(), ordenObj.sacarIDRequerimiento(L"Servicio"));
			MessageBoxW(L"Ya inserto", L"Articulo", MB_OK | MB_ICONERROR);
			ordenObj.llenarLVDetallesOrden(lvTabla, 100, true, folioVP);
		}
		
	}
	



void DescripcionOrdenVentasDlg::tbxCantidad_Change(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;
	LibreriaAdDll::articulo articuloObj;
	/*int idCantidad=articuloObj.sacarIDCantidad(articuloObj.sacarIDcolor(ddColor.Text), articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text,articuloObj.sacarIDModelo(ddModelo.Text),articuloObj.sacarIDMarca(ddMarca.Text),puntoVentaVP));
	;*/
	LibreriaFBDll::Movimiento movObj;
	cantidadExistenteVP = movObj.sacarCantidadDepartamento(ddColor.Text, articuloObj.sacarIDPuntoVenta(puntoVentaVP), ordenObj.sacarIDArticulo(ddTipo.Text, articuloObj.sacarIDModelo(ddModelo.Text), articuloObj.sacarIDMarca(ddMarca.Text), puntoVentaVP));
	
}

