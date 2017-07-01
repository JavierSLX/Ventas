#include "stdafx.h"  //_____________________________________________ EliminarLadaDlg.cpp
#include "EliminarLadaDlg.h"
//Metodo que nos permite mostrar todos los valores declarados en el wintemplad con sus valores
void EliminarLadaDlg::Window_Open(Win::Event& e)
{
	tabLada.Items.Add(0, L"Activos");
	tabLada.Items.Add(1, L"Inactivos");
	LibreriaJesusDll::datosLadaCLS ladaObj;
	ladaObj.MostrarLadaEliminar(lvLada, 200, true);
	btEliminar.Visible = true;
	btRestaurar.Visible = false;
}

//Metodo que permite eliminar los elemento dentro de lada
void EliminarLadaDlg::btEliminar_Click(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	int id = ladaObj.obtenerIdOculto(lvLada);
	if (id > 0)
	{
		ladaObj.CambiarEstadoLada(id, false);
		ladaObj.MostrarLadaEliminar(lvLada, 200, true);
		MessageBox(L"Se elimino correcta mente", L"Eliminar region", MB_OK );

	}
	else
	{
		MessageBox(L"No hay elementos seleccionados", L"Eliminar region", MB_OK );
	}
}
//Permite restaurar los valores que fueron eliminados o viceversa
void EliminarLadaDlg::btRestaurar_Click(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	int id = ladaObj.obtenerIdOculto(lvLada);
	if (id > 0)
	{
		ladaObj.CambiarEstadoLada(id, true);
		ladaObj.MostrarLadaEliminar(lvLada, 200, false);
		MessageBox(L"Se restauro correcta mente", L"Restaurar region", MB_OK );

	}
	else
	{
		MessageBox(L"No hay elementos seleccionados", L"Restaurar region", MB_OK );
	}
}
//Permite cambiar de tabla de inactivos y activos
void EliminarLadaDlg::tabLada_SelChange(Win::Event& e)
{
	LibreriaJesusDll::datosLadaCLS ladaObj;
	switch (tabLada.GetSelectedIndex())
	{
	case 0:
		ladaObj.MostrarLadaEliminar(lvLada, 200, true);
		btEliminar.Visible = true;
		btRestaurar.Visible = false;
		break;
	case 1:
		ladaObj.MostrarLadaEliminar(lvLada, 200, false);
		btEliminar.Visible = false;
		btRestaurar.Visible = true;
		break;
	}
}

