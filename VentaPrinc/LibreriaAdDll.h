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

	class ordenNueva : public Dialog
	{

	public:
		void  LibreriaAdDll::ordenNueva::llenarDDCliente(Win::DropDownList ddCliente, int id_pv, int large, bool activo);
		void  LibreriaAdDll::ordenNueva::llenarDDPuntoVenta(Win::DropDownList ddPuntoVenta, int large, bool activo);
		wstring LibreriaAdDll::ordenNueva::sacarNombreCliente(int pv, wstring claveCliente);
		int LibreriaAdDll::ordenNueva::sacarIDpuntoVenta(wstring pv);
		wstring LibreriaAdDll::ordenNueva::sacarUltimoFolio(void);
		int LibreriaAdDll::ordenNueva::sacarIdentificadorFecha(wstring cadena);
		int LibreriaAdDll::ordenNueva::sacarIdentificadorNumerico(wstring cadena);
		void LibreriaAdDll::ordenNueva::insertOrden(wstring folio, int cliente, int pv, int usuario);
		int LibreriaAdDll::ordenNueva::sacarIDCliente(wstring clave_cliente, wstring pv);
		void  LibreriaAdDll::ordenNueva::llenarDDServicio(Win::DropDownList ddServicio, int large, bool activo);
		void LibreriaAdDll::ordenNueva::insertOrdenDescripcion(int tipoVentaId, int cantidad, double precioSugerido, double precioFinal, int orden, int requerimiento);
		int LibreriaAdDll::ordenNueva::sacarIDArticulo(int color, int departamento_id, int modelo, int marca, int ta);
		int LibreriaAdDll::ordenNueva::sacarIDRequerimiento(wstring requerimiento);
		int LibreriaAdDll::ordenNueva::sacarUltIDOrden();
		int LibreriaAdDll::ordenNueva::sacarIDTipoArticulo(wstring tipoArticulo);
		int LibreriaAdDll::ordenNueva::sacarIDServicio(wstring Servicio);
		double LibreriaAdDll::ordenNueva::sacarPrecio(int servicio_id);
		void LibreriaAdDll::ordenNueva::llenarDescripcionOrden(Win::ListView lvOrden, int large, wstring folio);
		void  LibreriaAdDll::ordenNueva::llenarDDMarca(Win::DropDownList ddMarca, int large, bool activo, wstring tipo);
		int LibreriaAdDll::ordenNueva::sacarIDArticulo(wstring tipo, int modelo, int marca, wstring pv);
			void  LibreriaAdDll::ordenNueva::llenarDDcolor(Win::DropDownList ddcolor, int large, int articulo_id, wstring pv);
			void  LibreriaAdDll::ordenNueva::llenarDDTipoArticulo(Win::DropDownList ddTipoArticulo, int large, bool activo, wstring pv);
			void  LibreriaAdDll::ordenNueva::llenarDDModelo(Win::DropDownList ddModelo, wstring marca, int large, bool activo);
			double LibreriaAdDll::ordenNueva::sacarPrecioArticulo(int articulo_id);
			int LibreriaAdDll::ordenNueva::sacarIDPuntoVenta(wstring PV);
			double LibreriaAdDll::ordenNueva::sacarPrecioArticulo(int articulo_id, int ClaveCliente);
			int LibreriaAdDll::ordenNueva::sacarIDOcultoLV(Win::ListView lv2);
			wstring LibreriaAdDll::ordenNueva::sacarTextoLV(Win::ListView lvTabla, int columna);
			void LibreriaAdDll::ordenNueva::updateTipoArticulo(int articulo_id, wstring tipoArticulo);
			void LibreriaAdDll::ordenNueva::updateMarca(int articulo_id, wstring marca);
			void LibreriaAdDll::ordenNueva::updateModelo(int articulo_id, wstring modelo);
			int LibreriaAdDll::ordenNueva::sacarIDArticuloUpdate(wstring tipo, wstring modelo, wstring marca);
			void LibreriaAdDll::ordenNueva::insertarCantidadRequerimiento(int cantidad, int requerimiento);
			void LibreriaAdDll::ordenNueva::insertarServicioRequerimiento(int servicio, int requerimiento);
			void LibreriaAdDll::ordenNueva::llenarLVDetallesOrden(Win::ListView lvDetalles, int large, bool activo, wstring folio);
			void LibreriaAdDll::ordenNueva::updateCantidaDescrOreden(int descr_id, int cantidad);
			void LibreriaAdDll::ordenNueva::updatePrecioDescrOreden(int descr_id, double cantidad);
			int LibreriaAdDll::ordenNueva::sacarCantidad(int id);
			void LibreriaAdDll::ordenNueva::updateCantidadInventario(int cantidad_id, int valor);
			void  LibreriaAdDll::ordenNueva::llenarDDNombreR(Win::DropDownList ddNombre, int large, int pv_id);
			/*void  LibreriaAdDll::ordenNueva::llenarDDNombreR(Win::DropDownList ddNombre, int large, int pv_id);*/
			int LibreriaAdDll::ordenNueva::sacarIDUsuario(int pv, wstring nombre);
			int LibreriaAdDll::ordenNueva::sacarIDrango(int pFinal, int articulo);
			double LibreriaAdDll::ordenNueva::sacarComision(int id);
			void LibreriaAdDll::ordenNueva::insertarArticuloComision(double total, bool exito, int rango, int orden);
			int LibreriaAdDll::ordenNueva::sacarIDrangoSetvicio(int pFinal, int servicio);
			void LibreriaAdDll::ordenNueva::insertarServicioComision(double total, bool exito, int rango, int orden);
			void LibreriaAdDll::ordenNueva::insertarOrdenCompleta(double total, int orden);
			void LibreriaAdDll::ordenNueva::insertarCredito(double total, int orden);
			void LibreriaAdDll::ordenNueva::insertarTotalServicioComision(double total, int rango, int OrdenDesc);
			void LibreriaAdDll::ordenNueva::insertarTotalServicioComision(double total, int articuloComision);


	};
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	void Window_Open(Win::Event& e);
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.style = DS_CENTER | DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU;

	}
};
