#include "stdafx.h"  //_____________________________________________ ClienteVentasDlg.cpp
#include "ClienteVentasDlg.h"

void ClienteVentasDlg::Window_Open(Win::Event& e)
{
	//Llena la ddlist de punto de venta
	LibreriaJRDll::WintemplaCLS YopObj;
	YopObj.llenarDdRutasExclusiva(ddPuntoVenta, true, 100);

	//Llena la ddlist de ciudad
	YopObj.llenarDdCiudad(ddCiudad, true, 100);

	//Saca la última clave del cliente
	LibreriaJRDll::SqlCLS sqlObj;
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);

	//Llena la listview
	YopObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, 200);
}

//Botón Registrar
void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
}

//Botón Actualizar
void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
}

//Cuando la dropdownlist cambia
void ClienteVentasDlg::ddPuntoVenta_SelChange(Win::Event& e)
{
	//Saca la última clave del cliente
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);

	//Llena la listview
	wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, 200);
}

