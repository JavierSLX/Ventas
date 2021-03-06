#include "stdafx.h"  //_____________________________________________ EliminarRestaurarServicioDlg.cpp
#include "EliminarRestaurarServicioDlg.h"

void EliminarRestaurarServicioDlg::Window_Open(Win::Event& e)
{
	tabEliminarRestaurarServicio.Items.Add(0,L"Activos");
	tabEliminarRestaurarServicio.Items.Add(1, L"Inactivos");
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	servicioVentaObj.mostrarServiciosExistentes(lvEliminarRestaurarServicio, 200, true);
	btEliminar.Visible = true;
	btRestaurar.Visible = false;
}


//Metodo que permite eliminar un servicio
void EliminarRestaurarServicioDlg::btEliminar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	//Obtiene el id del servicio que se desea eliminar
	int id = tipoArticuloObj.obtenerIdOculto(lvEliminarRestaurarServicio);
	//Validaci�n de que se encuentre un servicio seleccionado
	if (id > 0)
	{
		//Cambia de estado el servicio a inactivo y actualzia la ListView
		servicioVentaObj.cambiarEstadoServicio(id, false);
		servicioVentaObj.mostrarServiciosExistentes(lvEliminarRestaurarServicio, 200, true);
		MessageBoxW(L"Se elimin� correctamente", L"Eliminar servicio", MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Eliminar servicio", MB_OK |MB_ICONERROR);
	}
}

//Metodo que permite restaurar un servicio
void EliminarRestaurarServicioDlg::btRestaurar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	//Obtiene el id del servicio que se desea eliminar
	int id = tipoArticuloObj.obtenerIdOculto(lvEliminarRestaurarServicio);
	//Validaci�n de que se encuentre un servicio seleccionado
	if (id > 0)
	{
		//Cambia de estado el servicio a activo y actualzia la ListView
		servicioVentaObj.cambiarEstadoServicio(id, true);
		servicioVentaObj.mostrarServiciosExistentes(lvEliminarRestaurarServicio, 200, false);
		MessageBoxW(L"Se restaur� correctamente", L"Eliminar servicio", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Eliminar servicio", MB_OK | MB_ICONERROR);
	}
}

//Metodo que controla la opcion que desea visualizar el usuario
void EliminarRestaurarServicioDlg::tabEliminarRestaurarServicio_SelChange(Win::Event& e)
{
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	switch (tabEliminarRestaurarServicio.GetSelectedIndex())
	{
		//Muestra los servicios activos y activa el boton de elimiar
		case 0:
			servicioVentaObj.mostrarServiciosExistentes(lvEliminarRestaurarServicio, 200, true);
			btEliminar.Visible = true;
			btRestaurar.Visible = false;
			break;
		//Muestra los servicios inactivos y activa el boton de elimiar
		case 1:
			servicioVentaObj.mostrarServiciosExistentes(lvEliminarRestaurarServicio, 200, false);
			btEliminar.Visible = false;
			btRestaurar.Visible = true;
			break;
	}
}

