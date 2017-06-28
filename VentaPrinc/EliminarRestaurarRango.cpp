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



void EliminarRestaurarRango::btEliminar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	LibreriaAngelDll::rangoCLS rangoObj;
	int id = tipoArticuloObj.obtenerIdOculto(lvRango);
	if (id > 0)
	{
		rangoObj.cambiarEstadoRango(id, false);
		rangoObj.mostrarRangoExistente(lvRango, 200, true);
		MessageBoxW(L"Se eliminó correctamente", L"Eliminar Rango", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Eliminar Rango", MB_OK | MB_ICONERROR);
	}
}

void EliminarRestaurarRango::btRestaurar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	LibreriaAngelDll::rangoCLS rangoObj;
	int id = tipoArticuloObj.obtenerIdOculto(lvRango);
	if (id > 0)
	{
		rangoObj.cambiarEstadoRango(id, true);
		rangoObj.mostrarRangoExistente(lvRango, 200, false);
		MessageBoxW(L"Se restauró correctamente", L"Eliminar Rango", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Eliminar Rango", MB_OK | MB_ICONERROR);
	}
}

void EliminarRestaurarRango::tabRango_SelChange(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	switch (tabRango.GetSelectedIndex())
	{

	case 0:
		rangoObj.mostrarRangoExistente(lvRango, 200, true);
		btEliminar.Visible = true;
		btRestaurar.Visible = false;
		break;
	case 1:
		rangoObj.mostrarRangoExistente(lvRango, 200, false);
		btEliminar.Visible = false;
		btRestaurar.Visible = true;
		break;
	}
}

