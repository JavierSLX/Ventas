#include "stdafx.h"  //_____________________________________________ ClienteVentasDlg.cpp
#include "ClienteVentasDlg.h"

void ClienteVentasDlg::Window_Open(Win::Event& e)
{
	//Llena la ddlist de punto de venta
	LibreriaJRDll::WintemplaCLS YopObj;
	YopObj.llenarDdRutasExclusiva(ddPuntoVenta, true, 100);

	//Llena la ddlist de ciudad
	YopObj.llenarDdCiudad(ddCiudad, true, 100);
	ddCiudad.SetSelected(L"S/R");

	//Saca la última clave del cliente
	LibreriaJRDll::SqlCLS sqlObj;
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);

	//Llena la listview
	YopObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, 200);
}

//Botón Registrar
void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;

	//Verifica si no hay espacios vacíos
	if (tbxNombre.GetTextLength() == 0)
	{
		tbxNombre.ShowBalloonTip(L"Casilla vacía", L"Nombre", TTI_ERROR);
		return;
	}

	if (tbxDireccion.GetTextLength() == 0)
	{
		tbxDireccion.ShowBalloonTip(L"Casilla vacía", L"Dirección", TTI_ERROR);
		return;
	}

	if (tbxTelefono.GetTextLength() == 0)
	{
		tbxTelefono.ShowBalloonTip(L"Casilla vacía", L"Telefono", TTI_ERROR);
		return;
	}

	//Checa que la opción de ciudad no sea "S/R"
	if (ddCiudad.Text == L"S/R")
	{
		MessageBoxW(L"Agregue una opción válida de ciudad", L"Ciudad", MB_OK | MB_ICONINFORMATION);
		return;
	}

	//Checa si el registro del cliente no está ya capturado
	int cliente_id = sqlObj.sacarIDCliente(tbxNombre.Text);
	if (cliente_id > 0)
	{
		MessageBoxW(L"Ya existe ese cliente en la BD", L"Cliente", MB_OK | MB_ICONINFORMATION);
		return;
	}

	//Saca el id de la ciudad seleccionada y del punto de venta
	int ciudad_id = sqlObj.sacarIDCiudad(ddCiudad.Text);
	int puntoVenta_id = sqlObj.sacarIDPuntoVenta(ddPuntoVenta.Text);

	//Checa si hay un correo y en caso de no existir en la celda se coloca un "S/R"
	wstring correo;
	tbxEmail.GetTextLength() == 0 ? correo = tbxEmail.Text : correo = L"S/R";

	//Ingresa el nuevo registro a la base de datos en la tabla cliente
	sqlObj.insertarCliente(tbxNombre.Text, tbxDireccion.Text, tbxTelefono.Text, correo, ciudad_id);
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

