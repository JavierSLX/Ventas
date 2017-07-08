##Ventas

### 26-JUN-2017
	- CREACION DE VENTANAS PARA LA NUEVA ORDEN EXISTENTE
	- CREACION DE METODOS PARA LLENAR LOS LIST VIEW

##27-jun-2017
	- Creacion del método para insertar una orden 
	- Implementación del metodo para crear folios
	- Creacion del diseño de la ventana de los detalles de una orden
	- Llenado de los dd del diseño de la paginas
##28-junio-2017
	- Modificacion de elementos simples faltantes de la ventana Orden
	- Ajuste del diseño de la ventana detalles orden.
	- Creacion de metodos para insertar los detalles de una orden
	- Aplicacion de mensajes informativos para ayuda del usuario
	- Desabilitacion de botones en la venta orden para el mejor manejo y evitar algún cambio erroneo del usuario.
##29 -junio-2017
	- llenado de los dropDown(el llenado del tipo de articulo dependera que desea el usuario agregar a la orden que levantara, 
		esto dependera del servico o en su caso el articulo, tambien del punto de venta en donde se realizara la venta.
		Teniendo en cuenta esas restricciones, se procedio al llenado de los modelos, masrcas y colores si es articulo, y si no solo el tipo de servicio se llenara
		el llenado de la marca, modelo y color dependera del tipo de articulo seleccionado y obviamente de la existencia en el inventario).
	- tbxCantidad (La cantidad tiene una restriccion. Si la cantidad a vender es mayor a la cantidad existente en el inventario no se podra realñizar la compra hasta que sea igual 
			o menor a la existente).
##30 - junio - 2017
	- Se detecto un problema con una consulta que no se mostraba en el listView, este problema afecto con el....
	- llenar precio sugerido y precio final (Para llenar estos tbx se utilizaron metodos para sacar los precios de determinado articulo con si determinado cliente
		 ).
	- metodo para insertar una descripcion de la venta
	-Para insertar una orden descripcion se tuvieron en cuenta muchas restricciones, si lo que se registraba era articulo o servicio, si la cantidad era menor o igual a la existente
	tener en cuenta el id del ultimo folio, su precio sugerido, su cantidad su total.
##3-julio-2017
	- A la hora de berificar las inserciones de una orden, se tuvo un conflicto que se visualizo el dia de hoy, no se mostraban los articulos preciamente insertados,
		con ninguno de los metodos ya funcionales entonces se decidio realizar toda la ventana de nuevo, cono cada cosa que se habia echo
##4-julio-2017
	- Se continuo con la creacion de la ventana y el dia de hoy el metodo para que el usuiario vea el articulo agregado a la venta es funcional
##5-julio-2017
	- ya realizadas las insercciones en la tabla orden descripcion, pasamos a descontar de inventario los articulos ventidos, y agregar el movimiento de venta.
	tambien se comenzo a visualizar como se crarian las comisiones el dia de hoy pero solo en teoria
##6-julio-2017
	- Se crearon los metodos para la calcular las comisiones de cada articulo.

##7-julio-2017
	- Las comisiones por orden de cada departamento fueron calculada, y se inserto en las tablas de los totales, para esta parte del proyecto solo se estaran revisando las funcionalidades
		de cada boton y pequeños detalles con la base de datos.