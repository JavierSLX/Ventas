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
		_idRequerimiento = reportesObj.obtenerIdOculto(ddRequerimiento);
		reporteVentasObj.llenarReporteVentasGeneral(lvReporte,_idRequerimiento,400, dtboxInicial.GetSelectedDateTime(), dtboxFinal.GetSelectedDateTime(),true);
		//reporteVentasObj.llenarReporteVentasGeneral(lvReporte, _idRequerimiento, 400,true);
	}
	else
	{
		if (tipoReporte == L"Departamento")
		{
			reporteVentasObj.llenarReporteVentasDepartamento(lvReporte, _idDepartamento, _idRegion, _idCiudad, _idRequerimiento, 300, dtboxInicial.GetSelectedDateTime(), dtboxFinal.GetSelectedDateTime(),true);
		}
		else
		{
			if (tipoReporte == L"Ciudad")
			{
				reporteVentasObj.llenarReporteVentasCiudad(lvReporte, _idRegion, _idCiudad, _idRequerimiento, 300, dtboxInicial.GetSelectedDateTime(), dtboxFinal.GetSelectedDateTime(),true);
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

void reportesVentasDlg::btImprimir_Click(Win::Event& e)
{
	Win::PrintDoc documento;
	Win::PrintPreviewDlg dialogo;
	LibreriaAngelDll::Logo *logo = new LibreriaAngelDll::Logo(L".\\logoAtc\\logo.emf", 2000);
	//Crea el nuevo documento
	documento.Create(L"Reporte de Inventario");

	//Obtiene la fecha y hora actual
	Sys::Time fecha = Sys::Time::Now();

	//Salto de linea
	tbxEspacio.Text = L"";

	//Creación del header del documento
	wstring header;
	Sys::Format(header, L"Ventas. A %02d/%02d/%d\r\n", fecha.wDay, fecha.wMonth, fecha.wYear);
	tbxCabecera.SetFont(_cursivas);
	tbxCabecera.Text = header;
	tbxCabecera.SetPrintAlignment(0);
	documento.Add(400, tbxCabecera.GetPrintLineCount(documento, 400) + 1, tbxCabecera);

	//Agrega el logo al documento
	documento.Add(200, 1, *logo);

	//Creacion del  título del documento
	wstring titulo;
	wstring tipoReporte = ddTipoReporte.Text;
	if (tipoReporte == L"Ventas General")
	{
		titulo = L"Reporte de Ventas General";
		//titulo += ddPuntoVenta.Text;
		tbxTitulo.Text = titulo;
		tbxTitulo.SetFont(_negritas);
		documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxTitulo);
		//Imprimir un espacio
		documento.Add(600, tbxEspacio.GetPrintLineCount(documento, 600) + 1, tbxEspacio);
		titulo = L"Periodo: De";
		titulo += dtboxInicial.Text;
		titulo += L" A ";
		titulo += dtboxFinal.Text;
		tbxEspecifico.Text = titulo;
		tbxEspecifico.SetFont(_negritas);
		documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxEspecifico);
	}
	else
	{
		if (tipoReporte == L"Departamento")
		{
			titulo = L"Reporte de ventas del departamento: ";
			titulo += ddDepartamento.Text;
			tbxTitulo.Text = titulo;
			tbxTitulo.SetFont(_negritas);
			documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxTitulo);
			//Imprimir un espacio
			documento.Add(600, tbxEspacio.GetPrintLineCount(documento, 600) + 1, tbxEspacio);
			titulo = L"Región: ";
			titulo += ddRegion.Text;
			titulo += L" Ciudad: ";
			titulo += ddCiudad.Text;
			tbxEspecifico.Text = titulo;
			tbxEspecifico.SetFont(_negritas);
			documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxEspecifico);
			//Imprimir un espacio
			documento.Add(600, tbxEspacio.GetPrintLineCount(documento, 600) + 1, tbxEspacio);
			titulo = L"Periodo: De";
			titulo += dtboxInicial.Text;
			titulo += L" A ";
			titulo += dtboxFinal.Text;
			tbxFecha.Text = titulo;
			tbxFecha.SetFont(_negritas);
			documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxFecha);
		}
		else
		{
			if (tipoReporte == L"Ciudad")
			{
				titulo = L"Reporte de Ventas de la Ciudad: ";
				titulo += ddCiudad.Text;
				tbxTitulo.Text = titulo;
				tbxTitulo.SetFont(_negritas);
				documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxTitulo);
				//Imprimir un espacio
				documento.Add(600, tbxEspacio.GetPrintLineCount(documento, 600) + 1, tbxEspacio);
				titulo = L"Periodo: De";
				titulo += dtboxInicial.Text;
				titulo += L" A ";
				titulo += dtboxFinal.Text;
				tbxFecha.Text = titulo;
				tbxFecha.SetFont(_negritas);
				documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxFecha);
			}
			else
			{
				if (tipoReporte == L"Orden de Compra")
				{
					titulo = L"Reporte de ventas por orden de compra: ";
					titulo += tbxFolio.Text;
					tbxTitulo.Text = titulo;
					tbxTitulo.SetFont(_negritas);
					documento.Add(700, tbxTitulo.GetPrintLineCount(documento, 700) + 1, tbxTitulo);
				}
			}
		}
	}

	//Imprimir un espacio
	documento.Add(600, tbxEspacio.GetPrintLineCount(documento, 600) + 1, tbxEspacio);

	//Imprime la tabla que contiene el reporte de inventario
	documento.Add(500, lvReporte.Items.Count + 1, lvReporte);

	//Imprime un espacio
	documento.Add(600, tbxEspacio.GetPrintLineCount(documento, 600) + 1, tbxEspacio);

	//Creacion de la firma
	wstring firma;
	LibreriaAngelDll::reportesCLS reportesObj;
	wstring usuario = reportesObj.obtenerNombreUsuario(26);
	Sys::Format(firma, L"Impreso en la fecha %02d/%02d/%d a las %02d:%02d:%02d hrs por %s", fecha.wDay, fecha.wMonth,
		fecha.wYear, fecha.wHour, fecha.wMinute, fecha.wSecond, usuario.c_str());
	tbxFirma.SetFont(_cursivas);
	tbxFirma.Text = firma;
	tbxFirma.SetPrintAlignment(1);
	documento.Add(400, tbxFirma.GetPrintLineCount(documento, 400) + 1, tbxFirma);

	//Muestra el dialogo de impresion
	dialogo.BeginDialog_(hWnd, &documento);

	delete logo;
}

