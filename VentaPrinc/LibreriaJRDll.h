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

	//Clase que contiene las inserciones, llenado o cualquier interacci�n con elementos de Wintempla
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

		//Saca una lista de tipo de articulos que contiene al menos un art�culo
		void sacarListaTipoArticulos(Win::DropDownList ddTipo, wstring punto_venta, int size);

		//Saca una lista de las cantidades que contienen cada tipo de articulo en cierto punto_venta
		void sacarListaCantidadTipoArticulos(Win::DropDownList ddCantidad, wstring punto_venta, int size);

		//Saca una lista de los movimientos que se hicieron de los articulos de ciertos puntos de venta
		void sacarListaMovimientos(Win::DropDownList ddTipo, wstring movimiento, wstring punto_venta, Sys::Time inicial, Sys::Time termino, int size);

		//Saca una lista de la cantidad de los movimientos que se hicieron de los articulos de ciertos puntos de venta
		void sacarListaCantidadMovimientos(Win::DropDownList ddCantidad, wstring movimiento, wstring punto_venta, Sys::Time inicial, Sys::Time termino, int size);

		//Saca la cantidad m�xima de una lista
		double sacaValorMaximo(Win::DropDownList ddCantidad);

		//M�todo que llena todos los punto de venta existentes en la base de datos
		void llenarLVPuntoVenta(Win::ListView lvTabla, bool activo, int size);

		//M�todo que llena todos los punto de venta seg�n una b�squeda
		void llenarLVPuntoVentaBusqueda(Win::ListView lvTabla, wstring texto, bool activo, int size);

		//M�todo que llena todos los clientes de un determinado punto de venta
		void llenarLVClientes(Win::ListView lvTabla, wstring punto_venta, bool activoCliente, bool activoClaveCliente, int size);

		//M�todo que llena todas las claves de cliente de un determinado punto de venta
		void llevarLVClaveClientes(Win::ListView lvTabla, wstring punto_venta, bool activo, int size);

		//M�todo que llena todos los art�culos faltantes de registrar un precio_cliente
		void llenarLVFaltantesPrecioCliente(Win::ListView lvTabla, wstring punto_venta, wstring numero, int size);

		//M�todo que llena los art�culos registrados de precio_cliente
		void llenarLVPrecioCliente(Win::ListView lvTabla, wstring punto_venta, wstring numero, int size);

		//M�todo que llena la drop down list con los tipos de punto de venta registrados
		void llenarDdPuntoVenta(Win::DropDownList ddVenta, int size);

		//M�todo que llena la drop down list con los tipos generales de categorias en la empresa
		void llenarDdColocacion(Win::DropDownList ddColocacion, int size);

		//M�todo que llena la drop down list con los tipos de art�culos registrados en la base de datos
		void llenarDdTipoArticulo(Win::DropDownList ddTipo, int size);

		//M�todo que llena las marcas de un determinado tipo de articulo
		void llenarDdMarca(Win::DropDownList ddMarca, wstring tipoArticulo, int size);

		//M�todo que llena las marcas de un determinado tipo de articulo
		void llenarDdModelo(Win::DropDownList ddModelo, wstring marca, int size);

		//M�todo que llena la drop down list con las ciudades registradas en la base de datos
		void llenarDdCiudad(Win::DropDownList ddCiudad, bool activo, int size);

		//M�todo que llena la drop down list exclusivamente de rutas registradas en la base de datos
		void llenarDdRutasExclusiva(Win::DropDownList ddRutas, bool activo, int size);

		//M�todo que llena una gr�fica de pastel con los datos correspondientes al inventario
		void llenarPastelInventario(wstring opcion);
	};

	//Clase que contiene cualquier interacci�n directa con la base de datos
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

		//Saca el id de un registro de la tabla cliente, en caso de no existir regresa un 0
		int sacarIDCliente(wstring nombre);

		//Saca el id de un registro de la tabla clave_cliente, en caso de no existir regresa un 0
		int sacarIDClaveCliente(int cliente_id, int puntoVenta_id);

		//Saca el id de un registro de la tabla clave_cliente, en caso de no existir regresa un 0
		int sacarIDClaveCliente(wstring numero, int puntoVenta_id);

		//Saca el id de un registro de la tabla precio_cliente, en caso de no existir regresa un 0
		int sacarIDPrecioCliente(int claveCliente_id, int articulo_id);

		//Saca el id del �ltimo registro de la tabla clave_cliente, en caso de no existir regresa un 0
		int sacarUltimoIDClaveCliente(wstring punto_venta);

		//Saca el precio de un articulo determinado de la tabla precio_cliente
		double sacarPrecioArticuloCliente(int claveCliente_id, int articulo_id);

		//Saca el tipo de un registro de la tabla colocacion
		wstring sacarTipoColocacion(wstring punto_venta);

		//Saca el email de un cliente determinado dado por su clave_cliente
		wstring sacarEmailCliente(int claveCliente_id);

		//Saca el nombre de un cliente determinado por su clave_cliente
		wstring sacarNombreCliente(int claveCliente_id);

		//M�todo que actualiza un registro de la tabla punto_venta dado por su id
		void actualizarPuntoVenta(int categoria_id, wstring nombre);

		//M�todo que actualiza un estado de un registro de la tabla punto_venta dado por su id
		void actualizarPuntoVenta(int categoria_id, bool estado);

		//M�todo que actualiza un registro de la tabla puntoVenta_colocacion dado por su id
		void actualizarPuntoVentaColocacion(int puntoVentaColocacion_id, int puntoVenta_id, int colocacion_id);

		//M�todo que actualiza el estado de un registro de la tabla clave_cliente
		void actualizarEstadoClaveCliente(int claveCliente_id, bool estado);

		//M�todo que actualiza los datos de un registro de la tabla cliente
		void actualizarCliente(int cliente_id, wstring nombre, wstring direccion, wstring telefono, wstring email, int ciudad_id);

		//M�todo que actualiza los datos de un registro de la tabla precio_cliente
		void actualizarPrecioCliente(int precioCliente_id, double precio);

		//M�todo que inserta un registro en la tabla punto_venta
		void insertarPuntoVenta(wstring nombre);

		//M�todo que inserta un registro en la tabla colocacion
		void insertarColocacion(wstring tipo);

		//M�todo que inserta un registro en la tabla puntoVenta_colocacion
		void insertarPuntoVentaColocacion(int puntoVenta_id, int colocacion_id);

		//M�todo que inserta un registro en la tabla cliente
		void insertarCliente(wstring nombre, wstring direccion, wstring telefono, wstring email, int ciudad_id);

		//M�todo que inserta un registro en la tabla ciudad
		void insertarCiudad(wstring nombre, int lada_id);

		//M�todo que inserta un registro en la tabla clave_cliente
		void insertarClaveCliente(wstring numero, int cliente_id, int puntoVenta_id);

		//M�todo que inserta un registro en la tabla precio_cliente
		void insertarPrecioCliente(double precio, int claveCliente, int articulo_id);
	};

	//Clase que contiene todo lo referente a color
	class ColorCLS : public Win::Dialog
	{
	public:
		//M�todo que regreso valores RGB distintos
		void obtenerColor(int index, int *R, int *G, int *B);
	};

	//Clase que contiene cualquier an�lisis de una cadena
	class StringCLS : public Win::Dialog
	{
	public:
		//Verifica que la posici�n que se le pasa al m�todo es una letra, regresa TRUE si es as�
		bool verificaLetra(wstring cadena, int posicion);

		//Verifica que la posici�n que se le pasa al m�todo es un n�mero, regresa TRUE si es as�
		bool verificaNumero(wstring cadena, int posicion);

		//Verifica si el elemento que se busca existe en la posicion que se le pasa
		bool comparaElemento(wstring cadena, int posicion, char elemento);

		//Verifica si la cadena cumple con el est�ndar de una estructura de ruta (R1, R1-67, etc)
		bool verificaRuta(wstring cadena);

		//Convierte una cadena a May�sculas y regresa el resultado
		wstring convertirAMayusculas(wstring cadena);

		//Convierte una cadena a May�sculas y regresa el resultado
		wstring convertirAMinusculas(wstring cadena);

		//Convierte una cadena en la primera letra en may�scula y las dem�s en min�sculas
		wstring convertirATextoEstandar(wstring cadena);

		//Saca la parte num�rica del identificador
		int sacarIdentificadorNumerico(wstring cadena, char simbolo);
	};
private:
	
};
