#pragma once   //_____________________________________________ LibreriaAngelDll.h  
#include "resource.h"

class LibreriaAngelDll: public Win::Dialog
{
public:
	LibreriaAngelDll()
	{
	}
	~LibreriaAngelDll()
	{
	}

	//clase para la manipulación de operaciones con tipo de articulos
	class tipoArticuloCLS:public Win::Dialog
	{
	public:
		tipoArticuloCLS()
		{

		}
		~tipoArticuloCLS()
		{

		}
		wstring LibreriaAngelDll::tipoArticuloCLS::sacarTipoArticuloSiExiste(wstring marca);
		void LibreriaAngelDll::tipoArticuloCLS::insertarTipoArticulo(wstring nombreArticulo,bool articuloActivo);
		void LibreriaAngelDll::tipoArticuloCLS::actualizarTipoArticulo(int id,wstring nombreArticulo, bool articuloActivo);
		int LibreriaAngelDll::tipoArticuloCLS::obtenerIdOculto(Win::ListView lvTiposArticulos);
		wstring LibreriaAngelDll::tipoArticuloCLS::obtenerTextoListView(Win::ListView lvTiposArticulos, int columna);
		void LibreriaAngelDll::tipoArticuloCLS::cambiarEstadoTipoArticulo(int id, wstring nombreArticulo, bool articuloActivo);
		void LibreriaAngelDll::tipoArticuloCLS::mostrarTiposArticulosExistentes(wstring encabezado,Win::ListView lvTipoArticulo, int longuitud,bool activo);
	};

	//clase para la generación de reportes
	class reportesCLS:public Win::Dialog
	{
	public:
		reportesCLS()
		{

		}
		~reportesCLS()
		{

		}
		void LibreriaAngelDll::reportesCLS::llenarColocacion(Win::DropDownList ddColocacion, int longuitud);
		void LibreriaAngelDll::reportesCLS::llenarPuntoVenta(int id,Win::DropDownList ddDepartamento, int longuitud);
		int LibreriaAngelDll::reportesCLS::obtenerIdOculto(Win::DropDownList ddInformacion);
		void LibreriaAngelDll::reportesCLS::llenarReporteGeneral(Win::ListView lvReporte, int longuitud,int id_punto_venta,bool activo);
		void LibreriaAngelDll::reportesCLS::llenarTipoArticulo(Win::DropDownList ddTipoArticulo, int longuitud);
		void LibreriaAngelDll::reportesCLS::llenarMarca(Win::DropDownList ddMarca, int longuitud);
		void LibreriaAngelDll::reportesCLS::llenarArticulo(Win::DropDownList ddMarca, int longuitud);
		void LibreriaAngelDll::reportesCLS::llenarTipoMovimiento(Win::DropDownList ddTipoMovimiento, int longuitud);
		void LibreriaAngelDll::reportesCLS::llenarReporteTipoArticulo(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_tipoArticulo,bool activo);
		void LibreriaAngelDll::reportesCLS::llenarReporteMarca(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_Marca, bool activo);
		void LibreriaAngelDll::reportesCLS::llenarReporteModelo(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_Modelo, bool activo);
		void LibreriaAngelDll::reportesCLS::llenarReporteMovimiento(Win::ListView lvReporte, int longuitud, int id_punto_venta,int id_tipo_movimiento, Sys::Time inicial, Sys::Time termino, bool activo);
		void LibreriaAngelDll::reportesCLS::llenarReporteMovimientoConColor(Win::ListView lvReporte, int longuitud, int id_punto_venta, int id_tipo_movimiento, Sys::Time inicial, Sys::Time termino, bool activo);
		wstring LibreriaAngelDll::reportesCLS::obtenerNombreUsuario(int usuarioId);
	};

	//clase para insertar un logo
	class Logo :public Win::IPrint
	{
	public:
		Logo(wstring direccion, int size);
		CG::Pen _pen;
		CG::Metafile _metafile;
		void Print(CG::Gdi &gdi, Win::PrintInfo pi);


	private:
		int sizeVP;

	};
	class servicioVentaCLS :public Win::Dialog
	{
	public:
		void LibreriaAngelDll::servicioVentaCLS::mostrarServiciosExistentes(Win::ListView lvServicio, int longuitud, bool activo);
		wstring LibreriaAngelDll::servicioVentaCLS::sacarServicioSiExiste(wstring tipoArticulo);
		void LibreriaAngelDll::servicioVentaCLS::insertarServicio(wstring servicio, int precio, bool servicioActivo);
		void LibreriaAngelDll::servicioVentaCLS::actualizarServicio(int id, wstring servicio, int precio, bool servicioActivo);
		void LibreriaAngelDll::servicioVentaCLS::cambiarEstadoServicio(int idServicio, bool servicioActivo);
	private:
	};
	class rangoCLS :public Win::Dialog
	{
	public:
		void LibreriaAngelDll::rangoCLS::mostrarRangoExistente(Win::ListView lvRango, int longuitud, bool activo);
		wstring LibreriaAngelDll::rangoCLS::sacarRangoSiExiste(double minimo, double maximo, double comision);
		void LibreriaAngelDll::rangoCLS::insertaRango(double minimo, double maximo, double comision, bool rangoActivo);
		void LibreriaAngelDll::rangoCLS::actualizarRango(int id, double minimo, double maximo, double comision, bool servicioActivo);
		void LibreriaAngelDll::rangoCLS::cambiarEstadoRango(int idRango, bool rangoActivo);
	private:
	};
	class reporteVentasCLS :public Win::Dialog
	{
	public:
		void LibreriaAngelDll::reporteVentasCLS::llenarDepartamento(Win::DropDownList ddColocacion, int longuitud);
		void LibreriaAngelDll::reporteVentasCLS::llenarRegion(Win::DropDownList ddRegion, int longuitud);
		void LibreriaAngelDll::reporteVentasCLS::llenarRequerimiento(Win::DropDownList ddRequerimiento, int longuitud);
		void LibreriaAngelDll::reporteVentasCLS::llenarCiudad(Win::DropDownList ddCiudad, int longuitud);
		void LibreriaAngelDll::reporteVentasCLS::llenarCiudad(Win::DropDownList ddCiudad, int regionId, int longuitud);
		void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasGeneral(Win::ListView lvReporte, int idRequerimiento,int longuitud, Sys::Time inicial, Sys::Time termino,bool activo);
		void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasDepartamento(Win::ListView lvReporte, int idPuntoVenta, int idRegion, int idCiudad,int idRequerimiento, int longuitud, bool activo);
		void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasCiudad(Win::ListView lvReporte, int idRegion, int idCiudad, int idRequerimiento, int longuitud, bool activo);
		void LibreriaAngelDll::reporteVentasCLS::llenarReporteVentasOrdenCompra(Win::ListView lvReporte, wstring folio, int longuitud, bool activo);
	private:
	};
private:
	
};
