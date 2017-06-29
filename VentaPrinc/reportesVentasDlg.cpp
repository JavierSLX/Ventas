#include "stdafx.h"  //_____________________________________________ reportesVentasDlg.cpp
#include "reportesVentasDlg.h"

void reportesVentasDlg::Window_Open(Win::Event& e)
{

	//________________________________________________________ ddTipoReporte
	ddTipoReporte.Items.Add(L"Ventas General");
	ddTipoReporte.Items.Add(L"Departamento");
	ddTipoReporte.Items.Add(L"Orden de Compra");
	ddTipoReporte.SetSelectedIndex(0);
	ponerVisibleElementos(false);
	//________________________________________________________ ddRegion
	ddRegion.Items.Add(L"Todas las regiones");
	//________________________________________________________ ddCiudad
	ddCiudad.Items.Add(L"Todas las ciudades");
	//________________________________________________________ ddRequerimiento
	ddRequerimiento.Items.Add(L"Todos");
	generarReporte(ddTipoReporte.Text);
}
void reportesVentasDlg::generarReporte(wstring tipoReporte)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	if (tipoReporte == L"Ventas General")
	{
		reporteVentasObj.llenarReporteVentasGeneral(lvReporte, 300, true);
	}
	else
	{
		if (tipoReporte == L"Departamento")
		{
			reporteVentasObj.llenarReporteVentasDepartamento(lvReporte, _idDepartamento, 300, true);
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
	lbRequerimiento.Visible = activo;
	ddRequerimiento.Visible = activo;
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
	}
	else
	{
		_idRegion= reportesObj.obtenerIdOculto(ddRegion);
		lb6.Text = Sys::Convert::ToString(_idRegion);
		reporteVentasObj.llenarCiudad(ddCiudad, _idRegion, 200);
		ddCiudad.SetSelectedIndex(0);
	}
}

void reportesVentasDlg::ddDepartamento_SelChange(Win::Event& e)
{
	LibreriaAngelDll::reporteVentasCLS reporteVentasObj;
	LibreriaAngelDll::reportesCLS reportesObj;
	_idDepartamento = reportesObj.obtenerIdOculto(ddDepartamento);
	generarReporte(ddTipoReporte.Text);
}

