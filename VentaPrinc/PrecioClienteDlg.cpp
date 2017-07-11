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

//Cuando cambia la ddlist de Modelo
void PrecioClienteDlg::ddModelo_SelChange(Win::Event& e)
{
}

//Cuando se selecciona un elemento de la tabla
void PrecioClienteDlg::lvTabla_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;
}

//Cuando se le da click al botón Registrar
void PrecioClienteDlg::btRegistrar_Click(Win::Event& e)
{
}

//Cuando se selecciona un cliente específico
void PrecioClienteDlg::lvClientes_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	LibreriaJRDll::SqlCLS sqlObj;

	claveClienteID = wintemplaObj.sacarIDOcultoLV(lvClientes);
	wstring numero = wintemplaObj.sacarTextoLV(lvClientes, 0);

	if (claveClienteID > 0)
	{
		//Llena las textbox
		tbxNombre.Text = sqlObj.sacarNombreCliente(claveClienteID);
		tbxClave.Text = ddRuta.Text + L"-" + numero;

		//Llena la tabla de los artículos que faltan de registrar de precio cliente
		wintemplaObj.llenarLVFaltantesPrecioCliente(lvTabla, ddRuta.Text, numero, 200);

		//Llena la tabla de los registros que ya fueron realizados de precio cliente
		wintemplaObj.llenarLVPrecioCliente(lvRegistrados, ddRuta.Text, numero, 200);
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

