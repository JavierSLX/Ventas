#include "stdafx.h"  //_____________________________________________ reportesVentasDlg.cpp
#include "reportesVentasDlg.h"

void reportesVentasDlg::Window_Open(Win::Event& e)
{

	//________________________________________________________ ddTipoReporte
	ddTipoReporte.Items.Add(L"Ventas General");
	ddTipoReporte.Items.Add(L"Departamento");
	ddTipoReporte.SetSelectedIndex(0);
	ponerVisibleElementos(false);
	//________________________________________________________ ddRegion
	ddRegion.Items.Add(L"Todas las regiones");
	//________________________________________________________ ddCiudad
	ddCiudad.Items.Add(L"Todas las ciudades");
	//________________________________________________________ ddRequerimiento
	ddRequerimiento.Items.Add(L"Todos");
	//________________________________________________________ lvReporte
	lvReporte.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	lvReporte.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	lvReporte.Items.Add(0, L"Monday");
	lvReporte.Items[0][1].Text = L"Math Class";
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
	}
	else
	{
		ponerVisibleElementos(true);
		reporteVentasObj.llenarDepartamento(ddDepartamento, 100);
		ddDepartamento.SetSelectedIndex(0);
		_idDepartamento = reportesObj.obtenerIdOculto(ddDepartamento);
		reporteVentasObj.llenarRegion(ddRegion, 10);
		ddRegion.SetSelectedIndex(0);
		reporteVentasObj.llenarCiudad(ddCiudad, 200);
		ddCiudad.SetSelectedIndex(0);
		reporteVentasObj.llenarRequerimiento(ddRequerimiento, 10);
		ddRequerimiento.SetSelectedIndex(0);
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

