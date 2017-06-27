#include "stdafx.h"  //_____________________________________________ EliminarRegionDlg.cpp
#include "EliminarRegionDlg.h"

void EliminarRegionDlg::Window_Open(Win::Event& e)
{
	tabRegion.Items.Add(0, L"Activos");
	tabRegion.Items.Add(1, L"Inactivos");
	LibreriaJesusDll::datosRegionCLS regionObj;
	regionObj.MostrarRegion(lvRegion, 200, true);
	btEliminar.Visible = true;
	btRestaurar.Visible = false;
}

void EliminarRegionDlg::tabRegion_SelChange(Win::Event& e)
{
	LibreriaJesusDll::datosRegionCLS regionObj;
	switch (tabRegion.GetSelectedIndex())
	{
	case 0:
		regionObj.MostrarRegion(lvRegion, 200, true);
		btEliminar.Visible = true;
		btRestaurar.Visible = false;
		break;
	case 1:
		regionObj.MostrarRegion(lvRegion, 200, false);
		btEliminar.Visible = false;
		btRestaurar.Visible = true;
		break;
	}
}

void EliminarRegionDlg::btEliminar_Click(Win::Event& e)
{
	LibreriaJesusDll::datosRegionCLS regionObj;
	int id = regionObj.obtenerIdOculto(lvRegion);
	if (id > 0)
	{
		regionObj.CambiarEstadoRegion(id, false);
		regionObj.MostrarRegion(lvRegion, 200, true);
		MessageBox(L"Se elimino correcta mente", L"Eliminar region", MB_OK || MB_ICONINFORMATION);

	}
	else
	{
		MessageBox(L"No hay elementos seleccionados", L"Eliminar region", MB_OK || MB_ICONERROR);
	}
}

void EliminarRegionDlg::btRestaurar_Click(Win::Event& e)
{

	LibreriaJesusDll::datosRegionCLS regionObj;
	int id = regionObj.obtenerIdOculto(lvRegion);
	if (id > 0)
	{
		regionObj.CambiarEstadoRegion(id, true);
		regionObj.MostrarRegion(lvRegion, 200, false);
		MessageBox(L"Se restauro correcta mente", L"Restaurar region", MB_OK || MB_ICONINFORMATION);

	}
	else
	{
		MessageBox(L"No hay elementos seleccionados", L"Restaurar region", MB_OK || MB_ICONERROR);
	}
}

