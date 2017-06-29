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

	//Saca la �ltima clave del cliente
	LibreriaJRDll::SqlCLS sqlObj;
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);

	//Llena la listview
	YopObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, 200);
}

//Bot�n Registrar
void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//Verifica si no hay espacios vac�os
	if (tbxNombre.GetTextLength() == 0)
	{
		tbxNombre.ShowBalloonTip(L"Casilla vac�a", L"Nombre", TTI_ERROR);
		return;
	}

	if (tbxDireccion.GetTextLength() == 0)
	{
		tbxDireccion.ShowBalloonTip(L"Casilla vac�a", L"Direcci�n", TTI_ERROR);
		return;
	}

	if (tbxTelefono.GetTextLength() == 0)
	{
		tbxTelefono.ShowBalloonTip(L"Casilla vac�a", L"Telefono", TTI_ERROR);
		return;
	}

	//Checa que la opci�n de ciudad no sea "S/R"
	if (ddCiudad.Text == L"S/R")
	{
		MessageBoxW(L"Agregue una opci�n v�lida de ciudad", L"Ciudad", MB_OK | MB_ICONERROR);
		return;
	}

	//Checa si el registro del cliente no est� ya capturado
	int cliente_id = sqlObj.sacarIDCliente(tbxNombre.Text);
	if (cliente_id > 0)
	{
		MessageBoxW(L"Ya existe ese cliente en la BD", L"Cliente", MB_OK | MB_ICONERROR);
		return;
	}

	//Saca el id de la ciudad seleccionada y del punto de venta
	int ciudad_id = sqlObj.sacarIDCiudad(ddCiudad.Text);
	int puntoVenta_id = sqlObj.sacarIDPuntoVenta(ddPuntoVenta.Text);

	//Checa si hay un correo y en caso de no existir en la celda se coloca un "S/R"
	wstring correo;
	if (tbxEmail.GetTextLength() == 0)
		correo = tbxEmail.Text; 
	else
		correo = L"S/R";

	//Ingresa el nuevo registro a la base de datos en la tabla cliente
	sqlObj.insertarCliente(tbxNombre.Text, tbxDireccion.Text, tbxTelefono.Text, correo, ciudad_id);

	//Inserta una nueva clave de cliente
	cliente_id = sqlObj.sacarIDCliente(tbxNombre.Text);
	wstring numero;
	int n = sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1;
	Sys::Format(numero, L"%03d", n);
	sqlObj.insertarClaveCliente(numero, cliente_id, puntoVenta_id);

	//Avisa y actualiza que se hizo el registro de manera correcta
	MessageBoxW(L"Registro hecho de manera correcta", L"Cliente", MB_OK | MB_ICONINFORMATION);
	wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, 200);

	//Actualiza la casilla de clave
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);
	limpiarCampos();
}

//Bot�n Actualizar
void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
}

//Cuando la dropdownlist cambia
void ClienteVentasDlg::ddPuntoVenta_SelChange(Win::Event& e)
{
	//Saca la �ltima clave del cliente
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);

	//Llena la listview
	wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, 200);
}

//Limpia todos los campos de la ventana para poder registrar un nuevo registro
void ClienteVentasDlg::limpiarCampos(void)
{
	tbxNombre.Text = L"";
	tbxDireccion.Text = L"";
	tbxTelefono.Text = L"";
	tbxEmail.Text = L"";
}