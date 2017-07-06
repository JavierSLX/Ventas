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
	YopObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, true, 200);
}

//Botón Registrar
void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;

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
		MessageBoxW(L"Agregue una opción válida de ciudad", L"Ciudad", MB_OK | MB_ICONERROR);
		return;
	}

	//Checa si el registro del cliente no está ya capturado
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
	wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, true, 200);

	//Actualiza la casilla de clave
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);
	limpiarCampos();
}

//Botón Actualizar
void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::StringCLS stringObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//Checa si hubo un cambio en la ruta
	if (ddPuntoVenta.Text != rutaVP)
	{
		//Verifica si el cliente no existe ya en esa ruta
		int puntoVenta_id = sqlObj.sacarIDPuntoVenta(rutaVP);
		int cliente_id = sqlObj.sacarIDCliente(tbxNombre.Text);
		if (cliente_id > 0)
		{
			//Verifica si no existe el registro en el nuevo punto de venta
			int new_puntoVenta_id = sqlObj.sacarIDPuntoVenta(ddPuntoVenta.Text);
			int claveCliente_id = sqlObj.sacarIDClaveCliente(cliente_id, new_puntoVenta_id);

			//Si existe lo cambia de estado
			if (claveCliente_id > 0)
			{
				sqlObj.actualizarEstadoClaveCliente(claveCliente_id, true);
			}
			//Si no existe inserta un nuevo registro en la bd clave_cliente
			else
			{
				int n = sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1;
				wstring numero;
				Sys::Format(numero, L"%03d", n);

				sqlObj.insertarClaveCliente(numero, cliente_id, new_puntoVenta_id);
			}

			//Cambia el estado del viejo registro
			sqlObj.actualizarEstadoClaveCliente(sqlObj.sacarIDClaveCliente(cliente_id, puntoVenta_id), false);
		}
		else
		{
			btRegistrar_Click(e);
		}
	}
	
	//Avisa y actualiza que se hizo el registro de manera correcta
	MessageBoxW(L"Registro hecho de manera correcta", L"Cliente", MB_OK | MB_ICONINFORMATION);
	wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, true, 200);

	//Actualiza la casilla de clave
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);
	limpiarCampos();
}

//Cuando la dropdownlist cambia
void ClienteVentasDlg::ddPuntoVenta_SelChange(Win::Event& e)
{
	//Saca la última clave del cliente
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	tbxClave.Text = ddPuntoVenta.Text + L"-" + Sys::Convert::ToString(sqlObj.sacarUltimoIDClaveCliente(ddPuntoVenta.Text) + 1);

	//Llena la listview
	wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, true, 200);

	//Limpia los campos del cliente
	limpiarCampos();
	ddCiudad.SetSelected(L"S/R");
}

//Limpia todos los campos de la ventana para poder registrar un nuevo registro
void ClienteVentasDlg::limpiarCampos(void)
{
	tbxNombre.Text = L"";
	tbxDireccion.Text = L"";
	tbxTelefono.Text = L"";
	tbxEmail.Text = L"";
}

//Cuando se elige una celda de la tabla
void ClienteVentasDlg::lvTabla_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	LibreriaJRDll::SqlCLS sqlObj;

	claveClienteIDVP = wintemplaObj.sacarIDOcultoLV(lvTabla);
	if (claveClienteIDVP > 0)
	{
		rutaVP = ddPuntoVenta.Text;
		claveVP = wintemplaObj.sacarTextoLV(lvTabla, 0);
		tbxClave.Text = claveVP;
		nombreVP = wintemplaObj.sacarTextoLV(lvTabla, 1);
		tbxNombre.Text = nombreVP;
		direccionVP = wintemplaObj.sacarTextoLV(lvTabla, 2);
		tbxDireccion.Text = direccionVP;
		telefonoVP = wintemplaObj.sacarTextoLV(lvTabla, 3);
		tbxTelefono.Text = telefonoVP;
		ciudadVP = wintemplaObj.sacarTextoLV(lvTabla, 4);
		ddCiudad.SetSelected(ciudadVP);
		emailVP = sqlObj.sacarEmailCliente(claveClienteIDVP);
		tbxEmail.Text = emailVP;
	}
}

//Cuando se presiona un botón sobre la tabla
void ClienteVentasDlg::lvTabla_KeyDown(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	LPNMLVKEYDOWN p = (LPNMLVKEYDOWN) e.lParam;

	//Cambia de estado el registro
	if (p->wVKey == VK_DELETE)
	{
		if (estadoVP)
		{
			//Cambia el estado del viejo registro
			sqlObj.actualizarEstadoClaveCliente(claveClienteIDVP, false);

			//Llena la listview
			wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, true, 200);
		}
		else
		{
			//Cambia el estado del viejo registro
			sqlObj.actualizarEstadoClaveCliente(claveClienteIDVP, true);

			//Llena la listview
			wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, false, 200);
		}

		claveClienteIDVP = 0;
	}

	//Muestra los registros de activos
	if (p->wVKey == VK_DOWN)
	{
		if (estadoVP)
		{
			//Llena la listview
			wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, true, 200);

			estadoVP = false;
		}
		else
		{
			//Llena la listview
			wintemplaObj.llenarLVClientes(lvTabla, ddPuntoVenta.Text, true, false, 200);

			estadoVP = true;
		}

		claveClienteIDVP = 0;
	}
}

