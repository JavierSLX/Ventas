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
	
	//________________________________________________________ tabTabla
	tabTabla.Items.Add(0, L"Activos");
	tabTabla.Items.Add(1, L"Eliminados");
	
	//Llena la tabla de las clave de los clientes cuando cambian
	wintemplaObj.llevarLVClaveClientes(lvClientes, ddRuta.Text, true, 100);

	//Llena la tabla de los art�culos que faltan de registrar de precio cliente
	wintemplaObj.llenarLVFaltantesPrecioCliente(lvTabla, ddRuta.Text, wintemplaObj.sacarTextoLV(lvClientes, 0), 200);
}

//Cuando cambia la ddlist de tipo de art�culo
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

//Cuando cambia la tab
void PrecioClienteDlg::tabTabla_SelChange(Win::Event& e)
{
}

//Cuando se selecciona un elemento de la tabla
void PrecioClienteDlg::lvTabla_ItemChanged(Win::Event& e)
{
}

//Cuando se le da click al bot�n Registrar
void PrecioClienteDlg::btRegistrar_Click(Win::Event& e)
{
}

//Cuando se selecciona un cliente espec�fico
void PrecioClienteDlg::lvClientes_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//Llena la tabla de los art�culos que faltan de registrar de precio cliente
	wintemplaObj.llenarLVFaltantesPrecioCliente(lvTabla, ddRuta.Text, wintemplaObj.sacarTextoLV(lvClientes, 0), 200);
}

//Cuando se cambia la opci�n en la ddlist de ruta
void PrecioClienteDlg::ddRuta_SelChange(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//Llena la tabla de las clave de los clientes cuando cambian
	wintemplaObj.llevarLVClaveClientes(lvClientes, ddRuta.Text, true, 100);
}

