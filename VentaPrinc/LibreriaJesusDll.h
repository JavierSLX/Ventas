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
		//Creacion de la clase para region
		datosRegionCLS()
		{

		}
		~datosRegionCLS()
		{

		}
		//Declaracion de metodos dentro de la case de region
		void LibreriaJesusDll::datosRegionCLS::MostrarRegion(Win::ListView lvRegion, int longuitud, bool activo);
		void LibreriaJesusDll::datosRegionCLS::InsertarRegion(wstring nombre, bool activo);
		int LibreriaJesusDll::datosRegionCLS::ObtenerIdUltimoRegistro();
		wstring LibreriaJesusDll::datosRegionCLS::verificarSiExisteRegion(wstring region);
		int LibreriaJesusDll::datosRegionCLS::obtenerIdOculto(Win::ListView lvRegion);
		wstring LibreriaJesusDll::datosRegionCLS::obtenerRegion(Win::ListView lvRegion, int columna);
		void LibreriaJesusDll::datosRegionCLS::ActualizarRegion(int idRegion, wstring nombreRegion);
		void LibreriaJesusDll::datosRegionCLS::CambiarEstadoRegion(int idRegion, bool regionActivo);


	private:

	};

	class datosLadaCLS :public Win::Dialog
	{
	public:
		//Creacion de la clase de Lada
		datosLadaCLS()
		{

		}
		~datosLadaCLS()
		{

		}
		//Declaracion de metodos dentro de la clase lada
		void LibreriaJesusDll::datosLadaCLS::MostrarLada(Win::ListView lvLada, int longuitud, bool activo);
		void LibreriaJesusDll::datosLadaCLS::llenarLadaDD(Win::DropDownList ddLada, int large);
		void LibreriaJesusDll::datosLadaCLS::InsertarLada(wstring tipo,int idRegion, bool activo);
		wstring LibreriaJesusDll::datosLadaCLS::verificarSiExisteLada(wstring lada);
		int LibreriaJesusDll::datosLadaCLS::obtenerIdOculto(Win::ListView ddLada);
		int LibreriaJesusDll::datosLadaCLS::obtenerIdOcultoDropDown(Win::DropDownList ddLada);
		void LibreriaJesusDll::datosLadaCLS::CambiarEstadoLada(int idLada, bool ladaActivo);
		void LibreriaJesusDll::datosLadaCLS::MostrarLadaEliminar(Win::ListView lvLada, int longuitud, bool activo);
		int LibreriaJesusDll::datosLadaCLS::ObtenerIdUltimoRegistro();
		wstring LibreriaJesusDll::datosLadaCLS::obtenerlada(Win::ListView lvLada, int columna);
		void LibreriaJesusDll::datosLadaCLS::ActualizarLada(int idLada, wstring nombreLada);
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
