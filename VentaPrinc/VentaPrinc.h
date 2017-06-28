#pragma once  //______________________________________ VentaPrinc.h  
#include "Resource.h"
#include "agregarCiudadVentasDlg.h"
#include "Eliminar_RestaurarCiudadVentasDlg.h"
#include "RegionDlg.h"
#include "OrdenVentasDlg.h"
#include "ServicioDlg.h"
#include "EliminarRestaurarServicioDlg.h"
#include "ClienteVentasDlg.h"
#include "bonoCreditoVentasDlg.h"
#include "registrarAbonosVentasDlg.h"
class VentaPrinc: public Win::Window
{
public:
	VentaPrinc()
	{
	}
	~VentaPrinc()
	{
	}
	const wchar_t * GetClassName(){return L"VentaPrinc";}
	Win::Menu menu;
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
protected:
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.style = WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"VentaPrinc";
	}
	//_________________________________________________
	void Window_Open(Win::Event& e);
	void Cmd_About(Win::Event& e);
	void Cmd_Neworden(Win::Event& e);
	void Cmd_Editorden(Win::Event& e);
	void Cmd_Consorden(Win::Event& e);
	void Cmd_Busqorden(Win::Event& e);
	void Cmd_Regcredito(Win::Event& e);
	void Cmd_Abonocredito(Win::Event& e);
	void Cmd_Regcomision(Win::Event& e);
	void Cmd_Rangocomision(Win::Event& e);
	void Cmd_Newcliente(Win::Event& e);
	void Cmd_Editcliente(Win::Event& e);
	void Cmd_Delcliente(Win::Event& e);
	void Cmd_Preciocliente(Win::Event& e);
	void Cmd_Newciudad(Win::Event& e);
	void Cmd_Editciudad(Win::Event& e);
	void Cmd_Delciudad(Win::Event& e);
	void Cmd_Newregion(Win::Event& e);
	void Cmd_Editregion(Win::Event& e);
	void Cmd_Delregion(Win::Event& e);
	void Cmd_Reglada(Win::Event& e);
	void Cmd_Editlada(Win::Event& e);
	void Cmd_Dellada(Win::Event& e);
	void Cmd_Newservicio(Win::Event& e);
	void Cmd_Editservicio(Win::Event& e);
	void Cmd_Delservicio(Win::Event& e);
	void Cmd_Reporteventa(Win::Event& e);
	void Cmd_Graficaventas(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (this->IsEvent(e, IDM_ABOUT)) {Cmd_About(e); return true;}
		if (this->IsEvent(e, IDM_NEWORDEN)) {Cmd_Neworden(e); return true;}
		if (this->IsEvent(e, IDM_EDITORDEN)) {Cmd_Editorden(e); return true;}
		if (this->IsEvent(e, IDM_CONSORDEN)) {Cmd_Consorden(e); return true;}
		if (this->IsEvent(e, IDM_BUSQORDEN)) {Cmd_Busqorden(e); return true;}
		if (this->IsEvent(e, IDM_REGCREDITO)) {Cmd_Regcredito(e); return true;}
		if (this->IsEvent(e, IDM_ABONOCREDITO)) {Cmd_Abonocredito(e); return true;}
		if (this->IsEvent(e, IDM_REGCOMISION)) {Cmd_Regcomision(e); return true;}
		if (this->IsEvent(e, IDM_RANGOCOMISION)) {Cmd_Rangocomision(e); return true;}
		if (this->IsEvent(e, IDM_NEWCLIENTE)) {Cmd_Newcliente(e); return true;}
		if (this->IsEvent(e, IDM_EDITCLIENTE)) {Cmd_Editcliente(e); return true;}
		if (this->IsEvent(e, IDM_DELCLIENTE)) {Cmd_Delcliente(e); return true;}
		if (this->IsEvent(e, IDM_PRECIOCLIENTE)) {Cmd_Preciocliente(e); return true;}
		if (this->IsEvent(e, IDM_NEWCIUDAD)) {Cmd_Newciudad(e); return true;}
		if (this->IsEvent(e, IDM_EDITCIUDAD)) {Cmd_Editciudad(e); return true;}
		if (this->IsEvent(e, IDM_DELCIUDAD)) {Cmd_Delciudad(e); return true;}
		if (this->IsEvent(e, IDM_NEWREGION)) {Cmd_Newregion(e); return true;}
		if (this->IsEvent(e, IDM_EDITREGION)) {Cmd_Editregion(e); return true;}
		if (this->IsEvent(e, IDM_DELREGION)) {Cmd_Delregion(e); return true;}
		if (this->IsEvent(e, IDM_REGLADA)) {Cmd_Reglada(e); return true;}
		if (this->IsEvent(e, IDM_EDITLADA)) {Cmd_Editlada(e); return true;}
		if (this->IsEvent(e, IDM_DELLADA)) {Cmd_Dellada(e); return true;}
		if (this->IsEvent(e, IDM_NEWSERVICIO)) {Cmd_Newservicio(e); return true;}
		if (this->IsEvent(e, IDM_EDITSERVICIO)) {Cmd_Editservicio(e); return true;}
		if (this->IsEvent(e, IDM_DELSERVICIO)) {Cmd_Delservicio(e); return true;}
		if (this->IsEvent(e, IDM_REPORTEVENTA)) {Cmd_Reporteventa(e); return true;}
		if (this->IsEvent(e, IDM_GRAFICAVENTAS)) {Cmd_Graficaventas(e); return true;}
		return false;
	}
};
