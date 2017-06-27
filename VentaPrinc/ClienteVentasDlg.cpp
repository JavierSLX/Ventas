#include "stdafx.h"  //_____________________________________________ ClienteVentasDlg.cpp
#include "ClienteVentasDlg.h"

void ClienteVentasDlg::Window_Open(Win::Event& e)
{
	//Llena la ddlist de punto de venta
	LibreriaAdDll::articulo AdiiObj;
	AdiiObj.llenarDDdepartamento(ddPuntoVenta, 100, true);
	ddPuntoVenta.SetSelectedIndex(0);

	//Llena la ddlist de ciudad
	LibreriaJRDll::WintemplaCLS YopObj;
	YopObj.llenarDdCiudad(ddCiudad, true, 100);

	//Verifica si el primer punto de venta es ruta o no
	LibreriaJRDll::StringCLS stringObj;
	if (stringObj.verificaRuta(ddPuntoVenta.Text))
	{

	}
	else
	{
		tolower
	}
}

void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
}

void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
}

