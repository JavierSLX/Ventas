#include "stdafx.h"  //_____________________________________________ PrecioClienteDlg.cpp
#include "PrecioClienteDlg.h"

void PrecioClienteDlg::Window_Open(Win::Event& e)
{
	LibreriaAdDll::articulo articuloObj;
	LibreriaAdDll::ordenNueva ordenObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//Llena las ddlist
	articuloObj.llenarDDarticulo(ddTipo, 100, true);
	ddTipo.SetSelectedIndex(0);

	ordenObj.llenarDDMarca(ddMarca, 100, true, ddTipo.Text);
	ddMarca.SetSelectedIndex(0);
	
	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);

	wintemplaObj.llenarDdRutasExclusiva(ddRuta, true, 100);
	ddRuta.SetSelectedIndex(0);
	
	//Llena la tabla de las clave de los clientes cuando cambian
	wintemplaObj.llevarLVClaveClientes(lvClientes, ddRuta.Text, true, 100);
}

//Cuando cambia la ddlist de tipo de artículo
void PrecioClienteDlg::ddTipo_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;

	ordenObj.llenarDDMarca(ddMarca, 100, true, ddTipo.Text);
	ddMarca.SetSelectedIndex(0);

	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);
}

//Cuando cambia la ddlist de Marca
void PrecioClienteDlg::ddMarca_SelChange(Win::Event& e)
{
	LibreriaAdDll::ordenNueva ordenObj;

	ordenObj.llenarDDModelo(ddModelo, ddMarca.Text, 100, true);
	ddModelo.SetSelectedIndex(0);
}

//Cuando se selecciona un elemento de la tabla
void PrecioClienteDlg::lvTabla_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	articuloIDVP = wintemplaObj.sacarIDOcultoLV(lvTabla);

	if (articuloIDVP > 0)
	{
		//Predefine las ddlist
		wstring tipoArticulo = wintemplaObj.sacarTextoLV(lvTabla, 0);
		ddTipo.SetSelected(tipoArticulo);

		wstring marca = wintemplaObj.sacarTextoLV(lvTabla, 1);
		wintemplaObj.llenarDdMarca(ddMarca, tipoArticulo, 100);
		ddMarca.SetSelected(marca);

		wstring modelo = wintemplaObj.sacarTextoLV(lvTabla, 2);
		wintemplaObj.llenarDdModelo(ddModelo, marca, 100);
		ddModelo.SetSelected(modelo);
	}
}

//Cuando se le da click al botón Registrar
void PrecioClienteDlg::btRegistrar_Click(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	if (articuloIDVP > 0)
	{
		//Verifica que no exista un espacio vacío
		if ((tbxPrecio.GetTextLength() == 0) || (ddMarca.Items.Count == 0) || (ddModelo.Items.Count == 0))
		{
			MessageBoxW(L"Error. Espacio vacío", L"Error", MB_OK | MB_ICONERROR);
			return;
		}

		//Inserta un nuevo registro al precio cliente
		sqlObj.insertarPrecioCliente(tbxPrecio.DoubleValue, claveClienteIDVP, articuloIDVP);

		//Anuncia que se registro de manera correcta el precio
		MessageBoxW(L"Registro realizado de manera correcta", L"Precio Cliente", MB_OK | MB_ICONINFORMATION);

		//Actualiza y limpia datos
		wintemplaObj.llenarLVFaltantesPrecioCliente(lvTabla, ddRuta.Text, numeroVP, 200);
		wintemplaObj.llenarLVPrecioCliente(lvRegistrados, ddRuta.Text, numeroVP, 200);
		tbxPrecio.Text = L"";
		articuloIDVP = 0;
		claveClienteIDVP = 0;
	}
}

//Cuando se selecciona un cliente específico
void PrecioClienteDlg::lvClientes_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	LibreriaJRDll::SqlCLS sqlObj;

	claveClienteIDVP = wintemplaObj.sacarIDOcultoLV(lvClientes);
	numeroVP = wintemplaObj.sacarTextoLV(lvClientes, 0);

	if (claveClienteIDVP > 0)
	{
		//Llena las textbox
		tbxNombre.Text = sqlObj.sacarNombreCliente(claveClienteIDVP);
		tbxClave.Text = ddRuta.Text + L"-" + numeroVP;

		//Llena la tabla de los artículos que faltan de registrar de precio cliente
		wintemplaObj.llenarLVFaltantesPrecioCliente(lvTabla, ddRuta.Text, numeroVP, 200);

		//Llena la tabla de los registros que ya fueron realizados de precio cliente
		wintemplaObj.llenarLVPrecioCliente(lvRegistrados, ddRuta.Text, numeroVP, 200);
	}
}

//Cuando se cambia la opción en la ddlist de ruta
void PrecioClienteDlg::ddRuta_SelChange(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//Llena la tabla de las clave de los clientes cuando cambian
	wintemplaObj.llevarLVClaveClientes(lvClientes, ddRuta.Text, true, 100);

	//Limpia las textbox
	tbxClave.Text = L"";
	tbxNombre.Text = L"";
}

//Cuando se le da click al botón de Actualizar
void PrecioClienteDlg::btActualizar_Click(Win::Event& e)
{
}

