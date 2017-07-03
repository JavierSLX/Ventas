#include "stdafx.h"  //_____________________________________________ EliminarRestaurarRango.cpp
#include "EliminarRestaurarRango.h"

void EliminarRestaurarRango::Window_Open(Win::Event& e)
{
	tabRango.Items.Add(0, L"Activos");
	tabRango.Items.Add(1, L"Inactivos");
	LibreriaAngelDll::rangoCLS rangoObj;
	rangoObj.mostrarRangoExistente(lvRango, 200, true);
	btEliminar.Visible = true;
	btRestaurar.Visible = false;	
}

//Permite cambiar de estado un rango a inactivo
void EliminarRestaurarRango::btEliminar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	LibreriaAngelDll::rangoCLS rangoObj;
	//Obtiene el id del rango que se desea eliminar
	int id = tipoArticuloObj.obtenerIdOculto(lvRango);
	//Validación de que se encuentre un rango seleccionado
	if (id > 0)
	{
		//Cambia de estado el rango a inactivo y actualzia la ListView
		rangoObj.cambiarEstadoRango(id, false);
		rangoObj.mostrarRangoExistente(lvRango, 200, true);
		MessageBoxW(L"Se eliminó correctamente", L"Eliminar Rango", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Eliminar Rango", MB_OK | MB_ICONERROR);
	}
}

//Permite cambiar de estado un rango a activo
void EliminarRestaurarRango::btRestaurar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	LibreriaAngelDll::rangoCLS rangoObj;
	//Obtiene el id del rango que se desea eliminar
	int id = tipoArticuloObj.obtenerIdOculto(lvRango);
	//Validación de que se encuentre un rango seleccionado
	if (id > 0)
	{
		//Cambia de estado el rango a inactivo y actualzia la ListView
		rangoObj.cambiarEstadoRango(id, true);
		rangoObj.mostrarRangoExistente(lvRango, 200, false);
		MessageBoxW(L"Se restauró correctamente", L"Eliminar Rango", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Eliminar Rango", MB_OK | MB_ICONERROR);
	}
}

//Permite mostrar en la ListView la opcion seleccionada por el usuario(eliminar o restaurar)
void EliminarRestaurarRango::tabRango_SelChange(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	switch (tabRango.GetSelectedIndex())
	{
		//Muestra los rangos activos y activa el boton de elimiar
		case 0:
			rangoObj.mostrarRangoExistente(lvRango, 200, true);
			btEliminar.Visible = true;
			btRestaurar.Visible = false;
			break;
		//Muestra los rangos inactivos y activa el boton restaurar
		case 1:
			rangoObj.mostrarRangoExistente(lvRango, 200, false);
			btEliminar.Visible = false;
			btRestaurar.Visible = true;
			break;
	}
}

