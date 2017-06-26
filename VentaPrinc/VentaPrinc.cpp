#include "stdafx.h"  //________________________________________ VentaPrinc.cpp
#include "VentaPrinc.h"
#include "AboutDlg.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	VentaPrinc app;
	app.CreateMainWindow(L"VentaPrinc", cmdShow, IDI_VentaPrinc, IDC_VentaPrinc, (HBRUSH)(COLOR_WINDOW+1), hInstance);
	return app.MessageLoop(IDC_VentaPrinc);
}

void VentaPrinc::Window_Open(Win::Event& e)
{
	// Use Resource View to edit the menu
	menu.Attach(hWnd, false);
}

void VentaPrinc::Cmd_About(Win::Event& e)
{
	AboutDlg dlg;
	dlg.BeginDialog(hWnd);
}

//Opción "Nueva Orden" del menú
void VentaPrinc::Cmd_Neworden(Win::Event& e)
{
	OrdenVentasDlg ventana;
	ventana.BeginDialog(hWnd);
}

//Opción "Editar Orden" del menú
void VentaPrinc::Cmd_Editorden(Win::Event& e)
{
}

//Opción "Consulta Orden" del menú
void VentaPrinc::Cmd_Consorden(Win::Event& e)
{
}

//Opción "Busqueda Orden" del menú
void VentaPrinc::Cmd_Busqorden(Win::Event& e)
{
}

//Opción "Registrar Crédito" del menú
void VentaPrinc::Cmd_Regcredito(Win::Event& e)
{
}

//Opción "Abono Crédito" del menú
void VentaPrinc::Cmd_Abonocredito(Win::Event& e)
{
}

//Opción "Registrar Comisión" del menú
void VentaPrinc::Cmd_Regcomision(Win::Event& e)
{
}

//Opción "Rango Comisión" del menú
void VentaPrinc::Cmd_Rangocomision(Win::Event& e)
{
}

//Opción "Nuevo Cliente" del menú
void VentaPrinc::Cmd_Newcliente(Win::Event& e)
{
}

//Opción "Editar Cliente" del menú
void VentaPrinc::Cmd_Editcliente(Win::Event& e)
{
}

//Opción "Eliminar Cliente" del menú
void VentaPrinc::Cmd_Delcliente(Win::Event& e)
{
}

//Opción "Precio Cliente" del menú
void VentaPrinc::Cmd_Preciocliente(Win::Event& e)
{
}

//Opción "Nueva Ciudad" del menú
void VentaPrinc::Cmd_Newciudad(Win::Event& e)
{
}

//Opción "Editar ciudad" del menú
void VentaPrinc::Cmd_Editciudad(Win::Event& e)
{
}

//Opción "Borrar Ciudad" del menú
void VentaPrinc::Cmd_Delciudad(Win::Event& e)
{
}

//Opción "Nueva Región" del menú
void VentaPrinc::Cmd_Newregion(Win::Event& e)
{
}

//Opción "Editar Región" del menú
void VentaPrinc::Cmd_Editregion(Win::Event& e)
{
}

//Opción "Borrar Región" del menú
void VentaPrinc::Cmd_Delregion(Win::Event& e)
{
}

//Opción "Registrar Lada" del menú
void VentaPrinc::Cmd_Reglada(Win::Event& e)
{
}

//Opción "Editar Lada" del menú
void VentaPrinc::Cmd_Editlada(Win::Event& e)
{
}

//Opción "Borrar Lada" del menú
void VentaPrinc::Cmd_Dellada(Win::Event& e)
{
}

//Opción "Nuevo Servicio" del menú
void VentaPrinc::Cmd_Newservicio(Win::Event& e)
{
}

//Opción "Editar Servicio" del menú
void VentaPrinc::Cmd_Editservicio(Win::Event& e)
{
}

//Opción "Borrar Servicio" del menú
void VentaPrinc::Cmd_Delservicio(Win::Event& e)
{
}

//Opción "Reporte" del menú
void VentaPrinc::Cmd_Reporteventa(Win::Event& e)
{
}

//Opción "Gráfica" del menú
void VentaPrinc::Cmd_Graficaventas(Win::Event& e)
{
}

