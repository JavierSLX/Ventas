#include "stdafx.h"  //_____________________________________________ ServicioDlg.cpp
#include "ServicioDlg.h"

void ServicioDlg::Window_Open(Win::Event& e)
{
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	servicioVentaObj.mostrarServiciosExistentes(lvServicio, 200, true);
}


//boton que permite agregar un nuevo servicio
void ServicioDlg::btAgregar_Click(Win::Event& e)
{
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	//Validación que servicio tenga valor
	if (this->tbxServicio.GetTextLength() == 0)
	{
		this->tbxServicio.ShowBalloonTip(L"Servicios", L"Ingrese el nombre del servicio", TTI_ERROR);
		return;
	}
	else
	{
		//Validación que precio tenga valor
		if (this->tbxPrecio.GetTextLength() == 0)
		{
			this->tbxPrecio.ShowBalloonTip(L"Servicios", L"Ingrese el precio del servicio", TTI_ERROR);
			return;
		}
		else
		{
			//Validación que el servicio no existe en la base de datos
			wstring servicio = servicioVentaObj.sacarServicioSiExiste(tbxServicio.Text);
			if (servicio == tbxServicio.Text)
			{
				if (MessageBoxW(L"Ya existe el tipo de articulo", L"Error", MB_OK | MB_ICONERROR) == IDYES)
				{

				}
				tbxServicio.SetText(L"");
				tbxPrecio.SetText(L"");
				tbxServicio.SetFocus();
			}
			else
			{
				//Inserta un nuevo servicio y actualiza la base de datos
				servicioVentaObj.insertarServicio(tbxServicio.Text, tbxPrecio.IntValue, true);
				servicioVentaObj.mostrarServiciosExistentes(lvServicio, 200, true);
				this->MessageBoxW(L"Se agrego correctamente", L"Nuevo servicio", MB_OK);
				tbxServicio.Text = L"";
				tbxPrecio.Text = L"";
				tbxServicio.SetFocus();
			}
		}
	}
}

//Botón que permite actualiar la información de un servicio
void ServicioDlg::btActualizar_Click(Win::Event& e)
{
	LibreriaAngelDll::servicioVentaCLS servicioVentaObj;
	//Validación que servicio tenga valor
	if (this->tbxServicio.GetTextLength() == 0)
	{
		this->tbxServicio.ShowBalloonTip(L"Servicios", L"Ingrese el nombre del servicio", TTI_ERROR);
		return;
	}
	else
	{
		//Validación que precio tenga valor
		if (this->tbxPrecio.GetTextLength() == 0)
		{
			this->tbxPrecio.ShowBalloonTip(L"Servicios", L"Ingrese el precio del servicio", TTI_ERROR);
			return;
		}
		else
		{
			//Valor que el servicio no exista en la base de datos
			wstring servicio = servicioVentaObj.sacarServicioSiExiste(tbxServicio.Text);
			if (servicio == tbxServicio.Text)
			{
				if (MessageBoxW(L"Ya existe el tipo de articulo", L"Error", MB_OK | MB_ICONERROR) == IDYES)
				{

				}
				tbxServicio.SetText(L"");
				tbxPrecio.SetText(L"");
				tbxServicio.SetFocus();
			}
			else
			{
				//Actualiza el servicio en la base de datos y actualiza la ListView
				servicioVentaObj.actualizarServicio(_idServicio, tbxServicio.Text, tbxPrecio.IntValue, true);
				servicioVentaObj.mostrarServiciosExistentes(lvServicio, 200, true);
				this->MessageBoxW(L"Se agrego correctamente", L"Nuevo servicio", MB_OK);
				tbxServicio.Text = L"";
				tbxPrecio.Text = L"";
				tbxServicio.SetFocus();
			}
		}
	}
}

//Metodo que muestra la información en el formulario del servicio seleccionado
void ServicioDlg::lvServicio_DblClk(Win::Event& e)
{
	LibreriaAngelDll::tipoArticuloCLS tipoArticuloObj;
	_idServicio = tipoArticuloObj.obtenerIdOculto(lvServicio);
	tbxServicio.Text = tipoArticuloObj.obtenerTextoListView(lvServicio, 1);
	tbxPrecio.Text = tipoArticuloObj.obtenerTextoListView(lvServicio, 0);
}

