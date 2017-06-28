#pragma once   //_____________________________________________ LibreriaJRDll.h  
#include "resource.h"

class LibreriaJRDll: public Win::Dialog
{
public:
	LibreriaJRDll()
	{
	}
	~LibreriaJRDll()
	{
	}

	//Clase que contiene las inserciones, llenado o cualquier interacción con elementos de Wintempla
	class WintemplaCLS : public Win::Dialog
	{
	public:
		WintemplaCLS()
		{

		}
		//Saca la id oculto en cualquier listview, lo regresa
		int sacarIDOcultoLV(Win::ListView lvTabla);

		//Saca el id oculto de cualquier ddlist
		int sacarIDOcultoDdl(Win::DropDownList ddLista);

		//Saca una cadena en una determinada celda de listview, lo regresa
		wstring sacarTextoLV(Win::ListView lvTabla, int columna);

		//Saca una lista de marcas de un determinado tipo de articulo
		void sacarListaMarcas(Win::DropDownList ddMarca, wstring punto_venta, wstring tipo_articulo, int size);

		//Saca una lista de las cantidad de marcas de cierto tipo de articulo registrado en un determinado departamento
		void sacarListaCantidadMarcas(Win::DropDownList ddCantidad, wstring punto_venta, wstring tipo_articulo, int size);

		//Saca una lista de tipo de articulos que contiene al menos un artículo
		void sacarListaTipoArticulos(Win::DropDownList ddTipo, wstring punto_venta, int size);

		//Saca una lista de las cantidades que contienen cada tipo de articulo en cierto punto_venta
		void sacarListaCantidadTipoArticulos(Win::DropDownList ddCantidad, wstring punto_venta, int size);

		//Saca una lista de los movimientos que se hicieron de los articulos de ciertos puntos de venta
		void sacarListaMovimientos(Win::DropDownList ddTipo, wstring movimiento, wstring punto_venta, Sys::Time inicial, Sys::Time termino, int size);

		//Saca una lista de la cantidad de los movimientos que se hicieron de los articulos de ciertos puntos de venta
		void sacarListaCantidadMovimientos(Win::DropDownList ddCantidad, wstring movimiento, wstring punto_venta, Sys::Time inicial, Sys::Time termino, int size);

		//Saca la cantidad máxima de una lista
		double sacaValorMaximo(Win::DropDownList ddCantidad);

		//Método que llena todos los punto de venta existentes en la base de datos
		void llenarLVPuntoVenta(Win::ListView lvTabla, bool activo, int size);

		//Método que llena todos los punto de venta según una búsqueda
		void llenarLVPuntoVentaBusqueda(Win::ListView lvTabla, wstring texto, bool activo, int size);

		//Método que llena la drop down list con los tipos de punto de venta registrados
		void llenarDdPuntoVenta(Win::DropDownList ddVenta, int size);

		//Método que llena la drop down list con los tipos generales de categorias en la empresa
		void llenarDdColocacion(Win::DropDownList ddColocacion, int size);

		//Método que llena la drop down list con los tipos de artículos registrados en la base de datos
		void llenarDdTipoArticulo(Win::DropDownList ddTipo, int size);

		//Método que llena la drop down list con las ciudades registradas en la base de datos
		void llenarDdCiudad(Win::DropDownList ddCiudad, bool activo, int size);

		//Método que llena la drop down list exclusivamente de rutas registradas en la base de datos
		void llenarDdRutasExclusiva(Win::DropDownList ddRutas, bool activo, int size);

		//Método que llena una gráfica de pastel con los datos correspondientes al inventario
		void llenarPastelInventario(wstring opcion);
	};

	//Clase que contiene cualquier interacción directa con la base de datos
	class SqlCLS : public Win::Dialog
	{
	public:
		SqlCLS()
		{

		}

		//Saca el id de un registro de la tabla punto_venta, en caso de no existir regresa un 0
		int sacarIDPuntoVenta(wstring nombre);

		//Saca el id de un registro de la tabla colocacion, en caso de no existir regresa un 0
		int sacarIDColocacion(int puntoVenta_id);

		//Saca el id de un registro de la tabla colocacion, en caso de no existir regresa un 0
		int sacarIDColocacion(wstring tipo);

		//Saca el id de un registro de la tabla puntoVenta_colocacion, en caso de no existir regresa un 0
		int sacarIDPuntoVentaColocacion(int puntoVenta_id, int colocacion_id);

		//Saca el id de un registro de la tabla ciudad, en caso de no existir regresa un 0
		int sacarIDCiudad(wstring nombre);

		//Saca el id del último registro de la tabla clave_cliente, en caso de no existir regresa un 0
		int sacarUltimoIDClaveCliente(wstring punto_venta);

		//Saca el tipo de un registro de la tabla colocacion
		wstring sacarTipoColocacion(wstring punto_venta);

		//Método que actualiza un registro de la tabla punto_venta dado por su id
		void actualizarPuntoVenta(int categoria_id, wstring nombre);

		//Método que actualiza un estado de un registro de la tabla punto_venta dado por su id
		void actualizarPuntoVenta(int categoria_id, bool estado);

		//Método que actualiza un registro de la tabla puntoVenta_colocacion dado por su id
		void actualizarPuntoVentaColocacion(int puntoVentaColocacion_id, int puntoVenta_id, int colocacion_id);

		//Método que inserta un registro en la tabla punto_venta
		void insertarPuntoVenta(wstring nombre);

		//Método que inserta un registro en la tabla colocacion
		void insertarColocacion(wstring tipo);

		//Método que inserta un registro en la tabla puntoVenta_colocacion
		void insertarPuntoVentaColocacion(int puntoVenta_id, int colocacion_id);

		//Método que inserta un registro en la tabla cliente
		void insertarCliente(wstring nombre, wstring direccion, wstring telefono, wstring email, int ciudad_id);

		//Método que inserta un registro en la tabla ciudad
		void insertarCiudad(wstring nombre, int lada_id);
	};

	//Clase que contiene todo lo referente a color
	class ColorCLS : public Win::Dialog
	{
	public:
		//Método que regreso valores RGB distintos
		void obtenerColor(int index, int *R, int *G, int *B);
	};

	//Clase que contiene cualquier análisis de una cadena
	class StringCLS : public Win::Dialog
	{
	public:
		//Verifica que la posición que se le pasa al método es una letra, regresa TRUE si es así
		bool verificaLetra(wstring cadena, int posicion);

		//Verifica que la posición que se le pasa al método es un número, regresa TRUE si es así
		bool verificaNumero(wstring cadena, int posicion);

		//Verifica si el elemento que se busca existe en la posicion que se le pasa
		bool comparaElemento(wstring cadena, int posicion, char elemento);

		//Verifica si la cadena cumple con el estándar de una estructura de ruta (R1, R1-67, etc)
		bool verificaRuta(wstring cadena);

		//Convierte una cadena a Mayúsculas y regresa el resultado
		wstring convertirAMayusculas(wstring cadena);

		//Convierte una cadena a Mayúsculas y regresa el resultado
		wstring convertirAMinusculas(wstring cadena);

		//Convierte una cadena en la primera letra en mayúscula y las demás en minúsculas
		wstring convertirATextoEstandar(wstring cadena);
	};
private:
	
};
