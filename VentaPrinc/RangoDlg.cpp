#include "stdafx.h"  //_____________________________________________ RangoDlg.cpp
#include "RangoDlg.h"

void RangoDlg::Window_Open(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	rangoObj.mostrarRangoExistente(lvRango, 400, true);
}

//Agrega un nuevo rango en la base de datos
void RangoDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	//Validación el rango mínimo tenga valor
	if (this->tbxMinimo.GetTextLength() == 0)
	{
		this->tbxMinimo.ShowBalloonTip(L"Rangos", L"Ingrese la cantidad mínima", TTI_ERROR);
		return;
	}
	else
	{
		//Validación el rango máximo tenga valor
		if (this->tbxMaximo.GetTextLength() == 0)
		{
			this->tbxMaximo.ShowBalloonTip(L"Rangos", L"Ingrese la cantidad máxima", TTI_ERROR);
			return;
		}
		else
		{
			//Validación la comisión tenga valor
			if (this->tbxComision.GetTextLength() == 0)
			{
				this->tbxComision.ShowBalloonTip(L"Rangos", L"Ingrese la comsión asignada", TTI_ERROR);
			}
			else
			{
				//Validación de que el rango no exista en la base de datos
				wstring minimo = rangoObj.sacarRangoSiExiste(tbxMinimo.DoubleValue, tbxMaximo.DoubleValue, tbxComision.DoubleValue);
				if (minimo == tbxMinimo.Text)
				{
					if (MessageBoxW(L"Ya existe el rango", L"Error", MB_OK | MB_ICONERROR) == IDYES)
					{

					}
					tbxMinimo.SetText(L"");
					tbxMaximo.SetText(L"");
					tbxComision.SetText(L"");
					tbxMinimo.SetFocus();
				}
				//Inserción del nuevo rango en la base de datos
				else
				{
					rangoObj.insertaRango(tbxMinimo.DoubleValue, tbxMaximo.DoubleValue, tbxComision.DoubleValue, true);
					rangoObj.mostrarRangoExistente(lvRango, 200, true);
					this->MessageBoxW(L"Se agrego correctamente", L"Nuevo Rango", MB_OK);
					tbxMinimo.SetText(L"");
					tbxMaximo.SetText(L"");
					tbxComision.SetText(L"");
					tbxMinimo.SetFocus();
				}
			}
		}
	}
}

//Actualzia la información de un rango
void RangoDlg::btActualizar_Click(Win::Event& e)
{
	LibreriaAngelDll::rangoCLS rangoObj;
	//Validación el rango mínimo tenga valor
	if (this->tbxMinimo.GetTextLength() == 0)
	{
		this->tbxMinimo.ShowBalloonTip(L"Rangos", L"Ingrese la cantidad mínima", TTI_ERROR);
		return;
	}
	else
	{
		//Validación el rango máximo tenga valor
		if (this->tbxMaximo.GetTextLength() == 0)
		{
			this->tbxMaximo.ShowBalloonTip(L"Rangos", L"Ingrese la cantidad máxima", TTI_ERROR);
			return;
		}
		else
		{
			//Validación el rango comisión tenga valor
			if (this->tbxComision.GetTextLength() == 0)
			{
				this->tbxComision.ShowBalloonTip(L"Rangos", L"Ingrese la comsión asignada", TTI_ERROR);
			}
			else
			{
				//Validación que no exista el rango en la base de datos
				wstring minimo = rangoObj.sacarRangoSiExiste(tbxMinimo.DoubleValue, tbxMaximo.DoubleValue, tbxComision.DoubleValue);
				if (minimo == tbxMinimo.Text)
				{
					if (MessageBoxW(L"Ya existe el rango", L"Error", MB_OK | MB_ICONERROR) == IDYES)
					{

					}
					tbxMinimo.SetText(L"");
					tbxMaximo.SetText(L"");
					tbxComision.SetText(L"");
					tbxMinimo.SetFocus();
				}
				//Actualización del rango en la base de datos
				else
				{
					rangoObj.actualizarRango(_id,tbxMinimo.DoubleValue, tbxMaximo.DoubleValue, tbxComision.DoubleValue, true);
					rangoObj.mostrarRangoExistente(lvRango, 200, true);
					this->MessageBoxW(L"Se actualizó correctamente", L"Actualizar Rango", MB_OK);
					tbxMinimo.SetText(L"");
					tbxMaximo.SetText(L"");
					tbxComision.SetText(L"");
					tbxMinimo.SetFocus();
				}
			}
		}
	}
}

//Muestra la información del rango seleccionado en el ListView
void RangoDlg::lvRango_DblClk(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	_id = tipoArticuloObj.obtenerIdOculto(lvRango);
	tbxMinimo.Text = tipoArticuloObj.obtenerTextoListView(lvRango, 0);
	tbxMaximo.Text = tipoArticuloObj.obtenerTextoListView(lvRango, 1);
	tbxComision.Text = tipoArticuloObj.obtenerTextoListView(lvRango, 2);
}

//Muestra el dialogo para eliminar o restaurar un rango
void RangoDlg::btEliminar_Click(Win::Event& e)
{
	EliminarRestaurarRango rangoObj;
	rangoObj.BeginDialog(hWnd);
}


