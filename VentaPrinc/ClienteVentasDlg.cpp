#include "stdafx.h"  //_____________________________________________ ClienteVentasDlg.cpp
#include "ClienteVentasDlg.h"

void ClienteVentasDlg::Window_Open(Win::Event& e)
{
	//Llena la ddlist de punto de venta
	LibreriaJRDll::WintemplaCLS YopObj;
	YopObj.llenarDdRutasExclusiva(ddPuntoVenta, true, 100);

	//Llena la ddlist de ciudad
	YopObj.llenarDdCiudad(ddCiudad, true, 100);

	//Ciclo que elimina todos los conceptos que no son de ruta de la dropdownlist
	/*LibreriaJRDll::StringCLS stringObj;
	for (int i = 0; i < ddPuntoVenta.GetItemCount(); i++)
	{
		if (!stringObj.verificaRuta(ddPuntoVenta.Items[i].Text))
			ddPuntoVenta.DeleteItem(i);
	}
	ddPuntoVenta.SetSelectedIndex(0);*/
}

void ClienteVentasDlg::btRegistrar_Click(Win::Event& e)
{
}

void ClienteVentasDlg::btActualizar_Click(Win::Event& e)
{
}

