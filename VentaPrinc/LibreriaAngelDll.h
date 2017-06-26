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

	//clase para la manipulaci�n de operaciones con tipo de articulos
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

	//clase para la generaci�n de reportes
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
private:
	
};