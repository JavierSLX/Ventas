#pragma once   //_____________________________________________ LibreriaAdDll.h  
#include "resource.h"

class LibreriaAdDll: public Win::Dialog
{
public:
	LibreriaAdDll()
	{
	}
	~LibreriaAdDll()
	{
	}
	class marca : public Dialog
	{

	public:
		void  LibreriaAdDll::marca::llenarLVMarca(Win::ListView ddMarca, int large, bool activo);
		void LibreriaAdDll::marca::insertarMarca(wstring marca);
		wstring LibreriaAdDll::marca::sacarMarcaSiExiste(wstring marca);
		int LibreriaAdDll::marca::sacarIDOcultoLV(Win::ListView lv2);
		wstring LibreriaAdDll::marca::sacarMarcaAct(int marca_id);
		void  LibreriaAdDll::marca::llenarLVMarcaNoAct(Win::ListView lvMarcas, int large, bool activo);
		void LibreriaAdDll::marca::updateMarcaEliminar(int marca_id);
		void LibreriaAdDll::marca::updateMarcaRestaurar(int marca_id);
		void LibreriaAdDll::marca::updateNombreMarca(wstring nombre, int marca_id);

		
	};
	class articulo : public Dialog
	{

	public:
		void  LibreriaAdDll::articulo::llenarDDMarca(Win::DropDownList ddMarca, int large, bool activo);
		void  LibreriaAdDll::articulo::llenarDDModelo(Win::DropDownList ddModelo, wstring marca, int large, bool activo);
		void  LibreriaAdDll::articulo::llenarDDarticulo(Win::DropDownList ddTipoArticulo, int large, bool activo);
		void  LibreriaAdDll::articulo::llenarDDcolor(Win::DropDownList ddcolor, int large, bool activo);
		void LibreriaAdDll::articulo::llenarDDdepartamento(Win::DropDownList ddDepartamento, int large, bool activo);
		void LibreriaAdDll::articulo::llenarArticulo(Win::ListView lvDepartamento, int large, wstring puntoVenta);
		void LibreriaAdDll::articulo::insertArticulos(wstring codigo, double precio, int tipoArticulo, int modelo);
		void LibreriaAdDll::articulo::insertModelo(wstring modelo, int id_marca);
		int LibreriaAdDll::articulo::sacarIDPuntoVenta(wstring puntoVenta);
		int LibreriaAdDll::articulo::sacarIDMarca(wstring marca);
		int LibreriaAdDll::articulo::sacarIDModelo(wstring modelo);
		int LibreriaAdDll::articulo::sacarIDtipoArticulo(wstring tipoArticulo);
		int LibreriaAdDll::articulo::sacarIDcolor(wstring color);
		int LibreriaAdDll::articulo::sacarUltIDArticulos();
		void LibreriaAdDll::articulo::insertarCantidad(int valor, int articulo_id, int color_id, int puntoVenta_id);
		void LibreriaAdDll::articulo::insertarTelefono(wstring imei, int articulo_id);
		int LibreriaAdDll::articulo::sacarIDImei(wstring color);
		int LibreriaAdDll::articulo::sacarCantidadPV();
		void LibreriaAdDll::articulo::llenarTab(Win::Tab  tbBusqueda);
		wstring LibreriaAdDll::articulo::sacarDepartamento(int pv_id);
		wstring LibreriaAdDll::articulo::sacarCodigo(int modelo, int tipoArticulo, int marca, int puntoVenta);
		void LibreriaAdDll::articulo::llenarArticulosER(Win::ListView lvTabla, wstring tipoArticulo, bool activo, int large);
		void LibreriaAdDll::articulo::updateArticuloRestaurar(int articulo_id);
		void LibreriaAdDll::articulo::updateArticuloEliminar(int articulo_id);
		wstring LibreriaAdDll::articulo::sacarTextoLV(Win::ListView lvTabla, int columna);
		wstring LibreriaAdDll::articulo::sacarCodigoSiCodigo(wstring codigo);
		void LibreriaAdDll::articulo::updateTipoArticulo(int articulo_id, wstring tipoArticulo);
		void LibreriaAdDll::articulo::updateCodigo(int articulo_id, wstring codigo);
		void LibreriaAdDll::articulo::updatePrecio(int articulo_id, double precio);
		void LibreriaAdDll::articulo::updateModelo(int articulo_id, wstring modelo);
		void LibreriaAdDll::articulo::updateMarca(int articulo_id, wstring marca);
		void LibreriaAdDll::articulo::updateCantidad(int cantidad_id, int cantidad);
		void LibreriaAdDll::articulo::updateColor(int cantidad_id, int color_id);
		void LibreriaAdDll::articulo::updateCantidadENColor(int cantidad_id, int color_id);
		void LibreriaAdDll::articulo::updatePuntoVenta(int articulo_id, wstring punto_venta);
		void LibreriaAdDll::articulo::insertarFecha(int movimiento_id);
		void LibreriaAdDll::articulo::insertarMovimiento(int cantidad, int tipoMovimiento_id, int categoria_id, int articulo_id, int usuario_id);
		int LibreriaAdDll::articulo::sacarIDTipoMovimiento(wstring tipoMovimiento);
		int LibreriaAdDll::articulo::sacarUltIDMovimiento();
		double LibreriaAdDll::articulo::sacarPrecioSiCodigo(wstring codigo);
		wstring LibreriaAdDll::articulo::sacarModeloSiCodigo(wstring codigo);
		wstring LibreriaAdDll::articulo::sacarMarcaSiCodigo(wstring codigo);
		wstring LibreriaAdDll::articulo::sacartipoArticuloSiCodigo(wstring codigo);
		int LibreriaAdDll::articulo::sacarCantidadSiCodigo(wstring codigo, int departamento, int color);
		wstring LibreriaAdDll::articulo::sacarColorSiCodigo(Win::DropDownList ddMarca, wstring codigo);
		wstring LibreriaAdDll::articulo::sacarPuntoVentaSiCodigo(wstring codigo);
		int LibreriaAdDll::articulo::sacarCantidadDepartamento(wstring color, int departamento_id, wstring codigo);
		int LibreriaAdDll::articulo::sacarIDArticuloSiCodigo(wstring codigo);
		int LibreriaAdDll::articulo::sacarIDCantidad(int color, int departamento_id, int articulo_id);
		void LibreriaAdDll::articulo::updateCantidadENPuntoVenta(int cantidad_id, int departamento_id);
		int LibreriaAdDll::articulo::sacarIDCantidadSIcolor(int puntoVenta_id, int color_id, int articulo_id);


	};
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	void Window_Open(Win::Event& e);
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.style = DS_CENTER | DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU;

	}
};
