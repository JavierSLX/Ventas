#include "stdafx.h"  //_____________________________________________ reportesVentasDlg.cpp
#include "reportesVentasDlg.h"

void reportesVentasDlg::Window_Open(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	//________________________________________________________ ddTipoReporte
	ddTipoReporte.Items.Add(L"Ventas General");
	ddTipoReporte.Items.Add(L"Departamento");
	ddTipoReporte.Items.Add(L"Ciudad");
	ddTipoReporte.Items.Add(L"Orden de Compra");
	ddTipoReporte.SetSelectedIndex(0);
	ponerVisibleElementos(false);
	//________________________________________________________ ddRegion
	ddRegion.Items.Add(L"Todas las regiones");
	//________________________________________________________ ddCiudad
	ddCiudad.Items.Add(L"Todas las ciudades");
	//________________________________________________________ ddRequerimiento
	ddRequerimiento.Items.Add(L"Todos");
	reporteVentasObj.llenarRequerimiento(ddRequerimiento, 10);
	ddRequerimiento.SetSelectedIndex(0);
	_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	generarReporte(ddTipoReporte.Text);
}
void reportesVentasDlg::generarReporte(wstring tipoReporte)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	if (tipoReporte == L"Ventas General")
	{
		reporteVentasObj.llenarReporteVentasGeneral(lvReporte,_idRequerimiento,400,dtboxInicial.GetSelectedDateTime(),dtboxFinal.GetSelectedDateTime(),true);
	}
	else
	{
		if (tipoReporte == L"Departamento")
		{
			reporteVentasObj.llenarReporteVentasDepartamento(lvReporte, _idDepartamento, _idRegion, _idCiudad, _idRequerimiento, 300, true);
		}
		else
		{
			if (tipoReporte == L"Ciudad")
			{
				reporteVentasObj.llenarReporteVentasCiudad(lvReporte, _idRegion, _idCiudad, _idRequerimiento, 300, true);
			}
			else
			{
				if (tipoReporte == L"Orden de Compra")
				{
					reporteVentasObj.llenarReporteVentasOrdenCompra(lvReporte, tbxFolio.Text, 300, true);
				}
			}
		}
	}
}
void reportesVentasDlg::ponerVisibleElementos(bool activo)
{
	lbDepartamento.Visible = activo;
	ddDepartamento.Visible = activo;
	lbRegion.Visible = activo;
	ddRegion.Visible = activo;
	lbCiudad.Visible = activo;
	ddCiudad.Visible = activo;
	lbFolio.Visible = activo;
	tbxFolio.Visible = activo;
}



void reportesVentasDlg::ddTipoReporte_SelChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	if (ddTipoReporte.Text == L"Ventas General")
	{
		ponerVisibleElementos(false);
		generarReporte(ddTipoReporte.Text);
	}
	else
	{
		if (ddTipoReporte.Text == L"Departamento")
		{
			ponerVisibleElementos(true);
			lbFolio.Visible = false;
			tbxFolio.Visible = false;
			reporteVentasObj.llenarDepartamento(ddDepartamento, 100);
			ddDepartamento.SetSelectedIndex(0);
			_idDepartamento = reportesObj.obtenerIdOculto(ddDepartamento);
			reporteVentasObj.llenarRegion(ddRegion, 10);
			ddRegion.SetSelectedIndex(0);
			_idRegion = reportesObj.obtenerIdOculto(ddRegion);
			reporteVentasObj.llenarCiudad(ddCiudad, 200);
			ddCiudad.SetSelectedIndex(0);
			_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
			reporteVentasObj.llenarRequerimiento(ddRequerimiento, 10);
			ddRequerimiento.SetSelectedIndex(0);
			_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
			generarReporte(ddTipoReporte.Text);
		}
		else
		{
			if (ddTipoReporte.Text == L"Ciudad")
			{
				ponerVisibleElementos(true);
				lbDepartamento.Visible = false;
				ddDepartamento.Visible = false;
				lbFolio.Visible = false;
				tbxFolio.Visible = false;
				reporteVentasObj.llenarDepartamento(ddDepartamento, 100);
				ddDepartamento.SetSelectedIndex(0);
				_idDepartamento = reportesObj.obtenerIdOculto(ddDepartamento);
				reporteVentasObj.llenarRegion(ddRegion, 10);
				ddRegion.SetSelectedIndex(0);
				_idRegion = reportesObj.obtenerIdOculto(ddRegion);
				reporteVentasObj.llenarCiudad(ddCiudad, 200);
				ddCiudad.SetSelectedIndex(0);
				_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
				reporteVentasObj.llenarRequerimiento(ddRequerimiento, 10);
				ddRequerimiento.SetSelectedIndex(0);
				_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
				generarReporte(ddTipoReporte.Text);
			}
			else
			{
				ponerVisibleElementos(false);
				lbRequerimiento.Visible = false;
				ddRequerimiento.Visible = false;
				lbFolio.Visible = true;
				tbxFolio.Visible = true;
				generarReporte(ddTipoReporte.Text);
			}
			
		}
		
	}
}

void reportesVentasDlg::ddRegion_SelChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	if (ddRegion.Text == L"Todas las regiones")
	{
		reporteVentasObj.llenarCiudad(ddCiudad, 200);
		ddCiudad.SetSelectedIndex(0);
		_idRegion = reportesObj.obtenerIdOculto(ddRegion);
		_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
		_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	}
	else
	{
		_idRegion= reportesObj.obtenerIdOculto(ddRegion);
		reporteVentasObj.llenarCiudad(ddCiudad, _idRegion, 200);
		ddCiudad.SetSelectedIndex(0);
		_idRegion = reportesObj.obtenerIdOculto(ddRegion);
		_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
		_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	}
	generarReporte(ddTipoReporte.Text);
}

void reportesVentasDlg::ddDepartamento_SelChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	_idDepartamento = reportesObj.obtenerIdOculto(ddDepartamento);
	_idRegion = reportesObj.obtenerIdOculto(ddRegion);
	_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
	_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	generarReporte(ddTipoReporte.Text);
}

void reportesVentasDlg::ddCiudad_SelChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
	_idRegion = reportesObj.obtenerIdOculto(ddRegion);
	_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	generarReporte(ddTipoReporte.Text);
}

void reportesVentasDlg::ddRequerimiento_SelChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	_idRegion = reportesObj.obtenerIdOculto(ddRegion);
	_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
	generarReporte(ddTipoReporte.Text);
}

void reportesVentasDlg::tbxFolio_Change(Win::Event& e)
{
	generarReporte(ddTipoReporte.Text);
}

void reportesVentasDlg::dtboxInicial_DatetimeChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
	_idRegion = reportesObj.obtenerIdOculto(ddRegion);
	_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	generarReporte(ddTipoReporte.Text);
}

void reportesVentasDlg::dtboxFinal_DatetimeChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	_idCiudad = reportesObj.obtenerIdOculto(ddCiudad);
	_idRegion = reportesObj.obtenerIdOculto(ddRegion);
	_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
	generarReporte(ddTipoReporte.Text);
}

