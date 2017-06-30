#include "stdafx.h"  //_____________________________________________ EliminarClienteVentasDlg.cpp
#include "EliminarClienteVentasDlg.h"

void EliminarClienteVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	//________________________________________________________ tabCliente
	tabCliente.Items.Add(0, L"Activos");
	tabCliente.Items.Add(1, L"Eliminados");
	
	//Llena la ddlist
	wintemplaObj.llenarDdRutasExclusiva(ddRutas, true, 100);

	//Llena la list view
	wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, true, 200);

	//Le da nombre al botón
	btAccion.Text = L"Eliminar";
}

//Cuando se elije una tab
void EliminarClienteVentasDlg::tabCliente_SelChange(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	if (tabCliente.GetSelectedIndex() == 0)
	{
		//Llena la list view
		wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, true, 200);

		//Le da nombre al botón
		btAccion.Text = L"Eliminar";
	}
	else
	{
		//Llena la list view
		wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, false, 200);

		//Le da nombre al botón
		btAccion.Text = L"Restaurar";
	}
}

//Cuando se le da click al botón de accion
void EliminarClienteVentasDlg::btAccion_Click(Win::Event& e)
{
	LibreriaJRDll::SqlCLS sqlObj;
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	if (claveClienteIDVP > 0)
	{
		if (tabCliente.GetSelectedIndex() == 0)
		{
			sqlObj.actualizarEstadoClaveCliente(claveClienteIDVP, false);

			//Llena la list view
			wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, true, 200);
		}
		else
		{
			sqlObj.actualizarEstadoClaveCliente(claveClienteIDVP, true);

			//Llena la list view
			wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, false, 200);
		}
	}
}

//Cuando se cambia la dropdownlist
void EliminarClienteVentasDlg::ddRutas_SelChange(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;

	if (tabCliente.GetSelectedIndex() == 0)
	{
		//Llena la list view
		wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, true, 200);
	}
	else
	{
		//Llena la list view
		wintemplaObj.llenarLVClientes(lvTabla, ddRutas.Text, true, false, 200);
	}
}

//Cuando se elige un registro de la listview
void EliminarClienteVentasDlg::lvTabla_ItemChanged(Win::Event& e)
{
	LibreriaJRDll::WintemplaCLS wintemplaObj;
	claveClienteIDVP = wintemplaObj.sacarIDOcultoLV(lvTabla);
}

