#pragma once   //_____________________________________________ LibreriaJesusDll.h  
#include "resource.h"

class LibreriaJesusDll: public Win::Dialog
{
public:
	LibreriaJesusDll()
	{
	}
	~LibreriaJesusDll()
	{
	}
	class datosRegionCLS :public Win::Dialog
	{
	public:
		datosRegionCLS()
		{

		}
		~datosRegionCLS()
		{

		}
		void LibreriaJesusDll::datosRegionCLS::MostrarRegion(Win::ListView lvRegion, int longuitud, bool activo);
		void LibreriaJesusDll::datosRegionCLS::InsertarRegion(wstring nombre, bool activo);
		int LibreriaJesusDll::datosRegionCLS::ObtenerIdUltimoRegistro();
		wstring LibreriaJesusDll::datosRegionCLS::verificarSiExisteRegion(wstring region);
		void LibreriaJesusDll::datosRegionCLS::ActualizarRegion(int idRegion, wstring nombreRegion);


	private:

	};
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	void Window_Open(Win::Event& e);
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.style = DS_CENTER | DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU;

	}
};
