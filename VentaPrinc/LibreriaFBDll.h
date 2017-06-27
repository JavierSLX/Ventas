#pragma once   //_____________________________________________ LibreriaFBDll.h  
#include "resource.h"

class LibreriaFBDll: public Win::Dialog
{
public:
	LibreriaFBDll()
	{
	}
	~LibreriaFBDll()
	{
	}
	//Clase Modeloo
	class Modelo : public Win::Dialog
	{
	public:
		Modelo()
		{

		}
		~Modelo()
		{

		}
		void LibreriaFBDll::Modelo::llenarDDMarcas(Win::DropDownList ddMarcas, int large);
		void LibreriaFBDll::Modelo::insertarModelo(wstring modelo, int id_marca);
		int LibreriaFBDll::Modelo::sacarIDMarca(wstring marca);
		void LibreriaFBDll::Modelo::llenarLVModelos(Win::ListView lvDepartamento, int large, int marca);
		void LibreriaFBDll::Modelo::llenarLVModelosInactivos(Win::ListView lvDepartamento, int large);
		void LibreriaFBDll::Modelo::llenarLVModelosActivos(Win::ListView lvDepartamento, int large);
		void LibreriaFBDll::Modelo::recuperarModelo(int modelo_id);
		void LibreriaFBDll::Modelo::eliminarModelo(int modelo_id);
		int  LibreriaFBDll::Modelo::sacarIDOculto(Win::ListView lv2);
		wstring LibreriaFBDll::Modelo::sacarModelo(int modelo_id);
		void LibreriaFBDll::Modelo::actualizarModelo(wstring modelo, int modelo_id);
		wstring LibreriaFBDll::Modelo::sacarMarcadelModelo(int modelo_id);
		wstring LibreriaFBDll::Modelo::sacarModeloSiExiste(wstring nombreModelo);
		wstring LibreriaFBDll::Modelo::sacarUltimaMarca();
		wstring LibreriaFBDll::Modelo::sacarUltimoModelo();
	private:

	};
	class Busqueda : public Win::Dialog
	{
	public:
		Busqueda()
		{
		}

		~Busqueda() 
		{

		}
		void LibreriaFBDll::Busqueda::llenarBusquedaCodigo(Win::ListView lvBusqueda, int large, wstring codigo);
		void LibreriaFBDll::Busqueda::llenarTab(Win::Tab   tbBusqueda);
		wstring LibreriaFBDll::Busqueda::sacarDepartamento(int articulo_id);
		int LibreriaFBDll::Busqueda::sacarCantidadPV();
		void LibreriaFBDll::Busqueda::llenarDDArticulos(Win::DropDownList ddMarcas, int large);
		void LibreriaFBDll::Busqueda::llenarLVTablaBusquedaCodigo(Win::ListView lvTabla, wstring busqueda,wstring puntoVenta, int large);
		void LibreriaFBDll::Busqueda::llenarArticulosCodigo(Win::ListView lvTabla, int puntoVenta,wstring codigo, int large);
		void LibreriaFBDll::Busqueda::llenarArticulosMarca(Win::ListView lvTabla, int puntoVenta, wstring marca, int large);
		int LibreriaFBDll::Busqueda::sacarIDPuntoV(wstring puntoVenta);
		void LibreriaFBDll::Busqueda::llenarColorCodigo(Win::ListView lvDepartamento, wstring codigo, int puntoId, int large);
		void LibreriaFBDll::Busqueda::llenarColorMarca(Win::ListView lvDepartamento, wstring marca, int puntoId, int large);
		void LibreriaFBDll::Busqueda::llenarArticulosModelo(Win::ListView lvTabla, int puntoVenta, wstring modelo, int large);
		void LibreriaFBDll::Busqueda::llenarColorModelo(Win::ListView lvDepartamento, wstring modelo, int puntoId, int large);
		void LibreriaFBDll::Busqueda::llenarArticulosTipoArt(Win::ListView lvTabla, int puntoVenta, wstring tipoArt, int large);
		void LibreriaFBDll::Busqueda::llenarColorTipoArt(Win::ListView lvDepartamento, wstring tipoArt, int puntoId, int large);
		wstring LibreriaFBDll::Busqueda::sacarCodigoLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacarMarcaLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacarModeloLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacartipoArtLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacarpuntoVentLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacarprecioLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacarcolorLV(Win::ListView lvTabla, int columna);
		wstring LibreriaFBDll::Busqueda::sacarcantidadLV(Win::ListView lvTabla, int columna);


	private:

	};
	class Movimiento : public Win::Dialog
	{
	public:
		Movimiento()
		{

		}
		~Movimiento()
		{

		}
		void LibreriaFBDll::Movimiento::llenarDDMovimientos(Win::DropDownList ddMarcas, int large);
		int LibreriaFBDll::Movimiento::sacarCantidadDepartamento(wstring color, int departamento_id, int articulo_id);
		int LibreriaFBDll::Movimiento::sacarIDpuntoVenta(wstring puntoVenta);
		int LibreriaFBDll::Movimiento::sacarIDMovimiento(wstring movimiento);
		void LibreriaFBDll::Movimiento::llenarDDusuarios(Win::DropDownList ddUsuarios, int large);
		int LibreriaFBDll::Movimiento::sacarIDUsuario(wstring usuario);
		void LibreriaFBDll::Movimiento::insertarMovimiento(int cantidad, int tipoMovimiento_id, int puntoVenta_id, int articulo_id, int usuario_id);
		int LibreriaFBDll::Movimiento::sacarIDUltimoMovimiento();
		void LibreriaFBDll::Movimiento::insertarfechaMovimiento(int movimiento_id);
		int LibreriaFBDll::Movimiento::sacarIDCantidad(wstring color, int departamento_id, int articulo_id);
		void LibreriaFBDll::Movimiento::updateCantidad(int valor, int cantidadId);
		void LibreriaFBDll::Movimiento::insertarcantidad(int valor, int articulo_id, int color_id, int puntoVenta_id);
		int LibreriaFBDll::Movimiento::sacarIDcolor(wstring color);
		void LibreriaFBDll::Movimiento::llenarDDdepartamentoFiltro(Win::DropDownList ddDepartamento, int large, bool activo, wstring departamento);
		/*wstring LibreriaFBDll::Movimiento::sacarPuntosVentaCodigo(wstring codigo);
		wstring LibreriaFBDll::Movimiento::sacarPuntosVentaMarca(wstring marca);
		wstring LibreriaFBDll::Movimiento::sacarPuntosVentaModelo(wstring modelo);
		wstring LibreriaFBDll::Movimiento::sacarPuntosVentatipoArt(wstring tipoArt);*/
	private:
	};

	class Ciudad :public Win::Dialog
	{
	public:
		Ciudad()
		{

		}
		~Ciudad()
		{

		}
		void LibreriaFBDll::Ciudad::llenarLVCiudad(Win::ListView lvCiudad,int large);
		void LibreriaFBDll::Ciudad::llenarLVCiudadInactiva(Win::ListView lvCiudad, int large);
		void LibreriaFBDll::Ciudad::insertarCiudad(wstring ciudad);
		wstring LibreriaFBDll::Ciudad::sacarCiudad(wstring ciudad);
		wstring LibreriaFBDll::Ciudad::sacarTextoLV(Win::ListView lvTabla, int columna);
		void LibreriaFBDll::Ciudad::actualizarCiudad(wstring nombre, int ciudad_id);
		void LibreriaFBDll::Ciudad::eliminarRecuperarCiudad(int modelo_id, bool estado);
		void LibreriaFBDll::Ciudad::llenarDDLada(Win::DropDownList ddLada, int large);
		/*void LibreriaFBDll::Ciudad::llenarLVCiudadNombre(Win::ListView lvCiudad, wstring ciudad, int large);*/
	private:

	};
	class bonoCredito : public Win::Dialog
	{
	public:
		bonoCredito()
		{

		}
		~bonoCredito()
		{

		}
		void LibreriaFBDll::bonoCredito::llenarLVCreditoCCliente(Win::ListView lvCredito,wstring claveCliente,int large);
		void LibreriaFBDll::bonoCredito::llenarLVCreditoFolio(Win::ListView lvCredito, wstring folio, int large);
		void LibreriaFBDll::bonoCredito::llenarLVCreditoNombre(Win::ListView lvCredito, wstring nombre, int large);


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
