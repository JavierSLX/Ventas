#include "stdafx.h"  //_____________________________________________ busquedaVentasDlg.cpp
#include "busquedaVentasDlg.h"

void busquedaVentasDlg::Window_Open(Win::Event& e)
{
	this->SetWindowTextW(L"Busqueda");
	LibreriaJRDll::WintemplaCLS javObj;
	dtboxFecha.Visible = false;
	radioFolio.Checked = true;
	javObj.llenarDdRutasExclusiva(ddPuntosVenta,true,100);
	ddPuntosVenta.SetSelectedIndex(0);
	ddPuntosVenta.Visible = false;
	ddDepartamentos.Visible = false;
}



void busquedaVentasDlg::btBuscar_Click(Win::Event& e)
{
	LibreriaFBDll::Movimiento movObj;;
	LibreriaFBDll::bonoCredito bonoObj;
	int idpuntoVenta = movObj.sacarIDpuntoVenta(ddPuntosVenta.Text);
	if (radioClaveCliente.IsChecked() == true ||radioFolio.IsChecked()==true)
	{
		if (this->tbxOpcionBusqueda.Text == L"")
		{
			this->tbxOpcionBusqueda.ShowBalloonTip(L"ATENCION", L"Debes completar los campos", TTI_ERROR);

			return;
		}
	}
	

	if (radioFolio.IsChecked ()==true)
	{
		bonoObj.llenarFolioOrden(lvOrden, tbxOpcionBusqueda.Text, 100);
	}
	if (radioClaveCliente.IsChecked() == true)
	{
		bonoObj.llenarclaveCliente(lvOrden, idpuntoVenta, tbxOpcionBusqueda.Text, 100);
		

	}
	if (radioFecha.IsChecked() == true)
	{
		/*wstring fecha;
		Sys::Format(fecha, L"%02d/%02d/%d ",dtboxFecha.GetSelectedDateTime().wYear,dtboxFecha.GetSelectedDateTime().wMonth,dtboxFecha.GetSelectedDateTime().wDay);*/
		bonoObj.llenarFecha(lvOrden, dtboxFecha.GetSelectedDateTime(), 100);
		
		

	}
	if (radioDepartamento.IsChecked() == true)
	{
		bonoObj.llenarpuntoVenta(lvOrden, ddDepartamentos.Text, 100);

	}
}

void busquedaVentasDlg::radioFolio_Click(Win::Event& e)
{
	dtboxFecha.Visible = false;
	tbxOpcionBusqueda.SetFocus();
	ddPuntosVenta.Visible = false;
	tbxOpcionBusqueda.Enabled =true;
	ddDepartamentos.Visible = false;
	lvOrden.SetRedraw(false);
	lvOrden.Cols.DeleteAll();
	lvOrden.Items.DeleteAll();
	lvOrden.SetRedraw(true);
	tbxOpcionBusqueda.SetFocus();
}

void busquedaVentasDlg::radioClaveCliente_Click(Win::Event& e)
{
	dtboxFecha.Visible = false;
	tbxOpcionBusqueda.SetFocus();
	ddPuntosVenta.Visible = true;
	tbxOpcionBusqueda.Enabled = true;
	ddDepartamentos.Visible = false;
	lvOrden.SetRedraw(false);
	lvOrden.Cols.DeleteAll();
	lvOrden.Items.DeleteAll();
	lvOrden.SetRedraw(true);
	tbxOpcionBusqueda.SetFocus();
}

void busquedaVentasDlg::radioFecha_Click(Win::Event& e)
{
	dtboxFecha.Visible = true;
	tbxOpcionBusqueda.SetFocus();
	ddPuntosVenta.Visible = false;
	tbxOpcionBusqueda.Enabled = false;
	ddDepartamentos.Visible = false;
	lvOrden.SetRedraw(false);
	lvOrden.Cols.DeleteAll();
	lvOrden.Items.DeleteAll();
	lvOrden.SetRedraw(true);
	tbxOpcionBusqueda.SetFocus();
	tbxOpcionBusqueda.SetText(L"");
}

void busquedaVentasDlg::lvOrden_ItemActivate(Win::Event& e)
{
	LibreriaFBDll::Ciudad ciudadObj;
	wstring folio =ciudadObj.sacarTextoLV(lvOrden,0);
	detallesOrdenVentasDlg detallesObj(folio);
	detallesObj.BeginDialog(hWnd);
}

void busquedaVentasDlg::radioDepartamento_Click(Win::Event& e)
{
	LibreriaFBDll::bonoCredito bonoObj;
	ddDepartamentos.Visible = true;
	LibreriaJRDll::WintemplaCLS javObj;
	javObj.llenarDdRutasExclusiva(ddDepartamentos, true, 100);
	ddDepartamentos.SetSelectedIndex(0);
	dtboxFecha.Visible = false;
	tbxOpcionBusqueda.Enabled = false;
	tbxOpcionBusqueda.SetFocus();
	lvOrden.SetRedraw(false);
	lvOrden.Cols.DeleteAll();
	lvOrden.Items.DeleteAll();
	lvOrden.SetRedraw(true);
	tbxOpcionBusqueda.SetFocus();

}

void busquedaVentasDlg::btLimpiar_Click(Win::Event& e)
{
	tbxOpcionBusqueda.Enabled = true;
	tbxOpcionBusqueda.SetFocus();
	lvOrden.SetRedraw(false);
	lvOrden.Cols.DeleteAll();
	lvOrden.Items.DeleteAll();
	lvOrden.SetRedraw(true);
	radioFolio.Checked = true;
	radioClaveCliente.Checked =false;
	radioDepartamento.Checked = false;
	radioFecha.Checked = false;
	ddPuntosVenta.Visible = false;
	ddDepartamentos.Visible = false;
	dtboxFecha.Visible = false;
	tbxOpcionBusqueda.SetText(L"");
	

}

