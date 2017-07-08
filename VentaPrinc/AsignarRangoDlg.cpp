#include "stdafx.h"  //_____________________________________________ AsignarRangoDlg.cpp
#include "AsignarRangoDlg.h"

void AsignarRangoDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ lvRangos
	tbxRequerimiento.Text = tipoVP;
	tbxMarca.Text = marcaVP;
	tbxModelo.Text = modeloVP;
	LibreriaAngelDll::rangoCLS rangoObj;
	rangoObj.mostrarRangoExistente(lvRangos, 400, true);
	if (opcionVP == 1)
	{
		btAsignar.Visible = true;
		btEditar.Visible = false;
	}
	else
	{
		btAsignar.Visible = false;
		btEditar.Visible = true;
		tbxMinimo.Text = minimoVP;
		tbxMaximo.Text = maximoVP;
		tbxComision.Text = comisionVP;
	}
	if (requerimientoVP == L"Artículo")
	{
		lbMarca.Visible = true;
		tbxMarca.Visible = true;
		lbModelo.Visible = true;
		tbxModelo.Visible = true;
	}
	else
	{
		lbMarca.Visible = false;
		tbxMarca.Visible = false;
		lbModelo.Visible = false;
		tbxModelo.Visible = false;
	}
}


void AsignarRangoDlg::btAsignar_Click(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	if (_idRango > 0)
	{
		if (requerimientoVP == L"Artículo")
		{
			rangoObj.insertaRangoArticulo(idArticuloVP, _idRango, 1);
			this->MessageBoxW(L"Se agrego correctamente", L"Rango", MB_OK);
			Close();
		}
		else
		{
			rangoObj.insertaRangoServicio(idArticuloVP, _idRango, 2);
			this->MessageBoxW(L"Se agrego correctamente", L"Rango", MB_OK);
			Close();
		}
	}
	else
	{
		MessageBoxW(L"No hay elementos seleccionados", L"Asignar Rango", MB_OK | MB_ICONERROR);
	}
	
	
}

void AsignarRangoDlg::btEditar_Click(Win::Event& e)
{
	if (_idRango > 0)
	{
		LibreriaAngelDll::rangoCLS rangoObj;
		if (requerimientoVP == L"Artículo")
		{
			rangoObj.actualizarRangoArticulo(idRangoVP, _idRango, 2);
			this->MessageBoxW(L"Se actualizó correctamente", L"Rango", MB_OK);
			Close();
		}
		else
		{
			rangoObj.actualizarRangoServicio(idRangoVP, _idRango, 2);
			this->MessageBoxW(L"Se actualizó correctamente", L"Rango", MB_OK);
			Close();
		}
	}
	else
	{
		MessageBoxW(L"No selecciono el nuevo rango", L"Asignar Rango", MB_OK | MB_ICONERROR);
	}
	
}

void AsignarRangoDlg::lvRangos_ItemChanged(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	_idRango = tipoArticuloObj.obtenerIdOculto(lvRangos);
	tbxMinimo.Text = tipoArticuloObj.obtenerTextoListView(lvRangos, 0);
	tbxMaximo.Text = tipoArticuloObj.obtenerTextoListView(lvRangos, 1);
	tbxComision.Text = tipoArticuloObj.obtenerTextoListView(lvRangos, 2);
}

void AsignarRangoDlg::btNuevoRango_Click(Win::Event& e)
{
	RangoDlg rangoNuevoObj;
	rangoNuevoObj.BeginDialog(hWnd);
}

void AsignarRangoDlg::Window_Activate(Win::Event& e)
{
	const bool activated = (e.wParam != WA_INACTIVE);
	e.returnValue = 0;
	LibreriaAngelDll::rangoCLS rangoObj;
	rangoObj.mostrarRangoExistente(lvRangos, 400, true);
}

