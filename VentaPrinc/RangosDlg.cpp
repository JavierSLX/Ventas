#include "stdafx.h"  //_____________________________________________ RangosDlg.cpp
#include "RangosDlg.h"

void RangosDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ tabRangos
	tabRangos.Items.Add(0, L"Con Rango");
	tabRangos.Items.Add(1, L"Sin Rango");
	//________________________________________________________ lvRangos
	LibreriaAngelDll::rangoCLS rangoObj;
	rangoObj.mostrarRangoAsignado(lvRangos, 400, true);
	btEditar.Visible = true;
	btAgregar.Visible = false;
}

void RangosDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS textoObj;
	wstring requerimiento = textoObj.obtenerTextoListView(lvRangos, 0);
	wstring tipo = textoObj.obtenerTextoListView(lvRangos, 1);
	wstring marca = textoObj.obtenerTextoListView(lvRangos, 2);
	wstring modelo = textoObj.obtenerTextoListView(lvRangos, 3);
	int idArticulo = textoObj.obtenerIdOculto(lvRangos);
	if (idArticulo > 0)
	{
		AsignarRangoDlg asignarRangoObj(requerimiento, tipo, marca, modelo, idArticulo,1);
		asignarRangoObj.BeginDialog(hWnd);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Asignar Rango", MB_OK | MB_ICONERROR);
	}
}

void RangosDlg::btEditar_Click(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS textoObj;
	wstring requerimiento = textoObj.obtenerTextoListView(lvRangos, 0);
	wstring tipo = textoObj.obtenerTextoListView(lvRangos, 1);
	wstring marca = textoObj.obtenerTextoListView(lvRangos, 2);
	wstring modelo = textoObj.obtenerTextoListView(lvRangos, 3);
	wstring minimo= textoObj.obtenerTextoListView(lvRangos, 4);
	wstring maximo = textoObj.obtenerTextoListView(lvRangos, 5);
	wstring comision = textoObj.obtenerTextoListView(lvRangos, 6);
	int idRango = textoObj.obtenerIdOculto(lvRangos);
	if (idRango > 0)
	{
		AsignarRangoDlg asignarRangoObj(requerimiento, tipo, marca, modelo,minimo,maximo,comision,idRango, 2);
		asignarRangoObj.BeginDialog(hWnd);
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Asignar Rango", MB_OK | MB_ICONERROR);
	}
}

void RangosDlg::tabRangos_SelChange(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	switch (tabRangos.GetSelectedIndex())
	{
	case 0:
		rangoObj.mostrarRangoAsignado(lvRangos, 400, true);
		btEditar.Visible = true;
		btAgregar.Visible = false;
		break;
	case 1:
		rangoObj.mostrarRangoSinAsignar(lvRangos, 200, true);
		btEditar.Visible = false;
		btAgregar.Visible = true;
		break;
	}
}

void RangosDlg::Window_Activate(Win::Event& e)
{
	const bool activated = (e.wParam != WA_INACTIVE);
	e.returnValue = 0;
	LibreriaAngelDll::rangoCLS rangoObj;
	switch (tabRangos.GetSelectedIndex())
	{
	case 0:
		rangoObj.mostrarRangoAsignado(lvRangos, 400, true);
		btEditar.Visible = true;
		btAgregar.Visible = false;
		break;
	case 1:
		rangoObj.mostrarRangoSinAsignar(lvRangos, 200, true);
		btEditar.Visible = false;
		btAgregar.Visible = true;
		break;
	}
}

void RangosDlg::btCrearRango_Click(Win::Event& e)
{
	RangoDlg crearRangoObj;
	crearRangoObj.BeginDialog(hWnd);
}

