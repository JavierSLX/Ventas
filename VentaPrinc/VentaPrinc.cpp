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

//Opci�n "Nueva Orden" del men�
void VentaPrinc::Cmd_Neworden(Win::Event& e)
{
	OrdenVentasDlg ventana;
	ventana.BeginDialog(hWnd);
}

//Opci�n "Editar Orden" del men�
void VentaPrinc::Cmd_Editorden(Win::Event& e)
{
}

//Opci�n "Consulta Orden" del men�
void VentaPrinc::Cmd_Consorden(Win::Event& e)
{
}

//Opci�n "Busqueda Orden" del men�
void VentaPrinc::Cmd_Busqorden(Win::Event& e)
{
	busquedaVentasDlg busquedaObj;
	busquedaObj.BeginDialog(hWnd);
}

//Opci�n "Registrar Cr�dito" del men�
void VentaPrinc::Cmd_Regcredito(Win::Event& e)
{
}

//Opci�n "Abono Cr�dito" del men�
void VentaPrinc::Cmd_Abonocredito(Win::Event& e)
{
	bonoCreditoVentasDlg bonoObj;
	bonoObj.BeginDialog(hWnd);
}

//Opci�n "Registrar Comisi�n" del men�
void VentaPrinc::Cmd_Regcomision(Win::Event& e)
{
}

//Opci�n "Rango Comisi�n" del men�
void VentaPrinc::Cmd_Rangocomision(Win::Event& e)
{
	RangoDlg rangoObj;
	rangoObj.BeginDialog(hWnd);
}

//Opci�n "Nuevo Cliente" del men�
void VentaPrinc::Cmd_Newcliente(Win::Event& e)
{
	ClienteVentasDlg clienteObj;
	clienteObj.BeginDialog(hWnd);
}

//Opci�n "Editar Cliente" del men�
void VentaPrinc::Cmd_Editcliente(Win::Event& e)
{
	ClienteVentasDlg clienteObj;
	clienteObj.BeginDialog(hWnd);
}

//Opci�n "Eliminar Cliente" del men�
void VentaPrinc::Cmd_Delcliente(Win::Event& e)
{
	EliminarClienteVentasDlg clienteObj;
	clienteObj.BeginDialog(hWnd);
}

//Opci�n "Precio Cliente" del men�
void VentaPrinc::Cmd_Preciocliente(Win::Event& e)
{
}

//Opci�n "Nueva Ciudad" del men�
void VentaPrinc::Cmd_Newciudad(Win::Event& e)
{
	agregarCiudadVentasDlg ciudadObj(L"Agregar");
	ciudadObj.BeginDialog(hWnd);
}

//Opci�n "Editar ciudad" del men�
void VentaPrinc::Cmd_Editciudad(Win::Event& e)
{
	agregarCiudadVentasDlg ciudadObj(L"Editar");
	ciudadObj.BeginDialog(hWnd);
}

//Opci�n "Borrar Ciudad" del men�
void VentaPrinc::Cmd_Delciudad(Win::Event& e)
{
	Eliminar_RestaurarCiudadVentasDlg eliminarObj;
	eliminarObj.BeginDialog(hWnd);
}

//Opci�n "Nueva Regi�n" del men�
void VentaPrinc::Cmd_Newregion(Win::Event& e)
{
	RegionDlg regionObj;
	regionObj.BeginDialog(hWnd);
}

//Opci�n "Editar Regi�n" del men�
void VentaPrinc::Cmd_Editregion(Win::Event& e)
{
	RegionDlg regionObj;
	regionObj.BeginDialog(hWnd);
}

//Opci�n "Borrar Regi�n" del men�
void VentaPrinc::Cmd_Delregion(Win::Event& e)
{
	EliminarRegionDlg regionObj;
	regionObj.BeginDialog(hWnd);
}

//Opci�n "Registrar Lada" del men�
void VentaPrinc::Cmd_Reglada(Win::Event& e)
{
	LadaDlg ladaObj;
	ladaObj.BeginDialog(hWnd);
}

//Opci�n "Editar Lada" del men�
void VentaPrinc::Cmd_Editlada(Win::Event& e)
{
	LadaDlg ladaObj;
	ladaObj.BeginDialog(hWnd);
}

//Opci�n "Borrar Lada" del men�
void VentaPrinc::Cmd_Dellada(Win::Event& e)
{
	EliminarLadaDlg regionObj;
	regionObj.BeginDialog(hWnd);
}

//Opci�n "Nuevo Servicio" del men�
void VentaPrinc::Cmd_Newservicio(Win::Event& e)
{
	ServicioDlg servicioObj;
	servicioObj.BeginDialog(hWnd);
}

//Opci�n "Editar Servicio" del men�
void VentaPrinc::Cmd_Editservicio(Win::Event& e)
{
	ServicioDlg servicioObj;
	servicioObj.BeginDialog(hWnd);
}

//Opci�n "Borrar Servicio" del men�
void VentaPrinc::Cmd_Delservicio(Win::Event& e)
{
	EliminarRestaurarServicioDlg eliminarRestaurarServicioObj;
	eliminarRestaurarServicioObj.BeginDialog(hWnd);
}

//Opci�n "Reporte" del men�
void VentaPrinc::Cmd_Reporteventa(Win::Event& e)
{
	reportesVentasDlg reportesObj;
	reportesObj.BeginDialog(hWnd);
}

//Opci�n "Gr�fica" del men�
void VentaPrinc::Cmd_Graficaventas(Win::Event& e)
{
}

