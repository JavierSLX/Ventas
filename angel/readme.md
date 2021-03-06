<h1>Proyecto Ventas</h1>
<h3>Actividades Ángel</h3>

<P style="text-align:justify;">Al iniciar el Proyecto de Inventario,   se segmentan en ramas los elementos, comprendidos en el sistema.
Determinadas con el fin de ser desarrolladas por José Ángel Campos Alejo, siendo de la siguiente manera:</P>

* Servicio-Venta: Insertar nuevo, editar, eliminar y restaurar.
* Rango: Insertar nuevo, editar, eliminar y restaurar.
* Reportes.

----------

<h5>26/06/2017</h5>
Actividades realizadas durante el día 26 de Junio del 2017:

* Creación de la clase <code>servicioVentaCLS</code> la cual se utilizará para llamar los métodos necesarios para los servicios de la empresa.
* Creación del dialogo <code>ServicioDlg</code>, permite visualizar los servicios activos que tiene la empresa, agregar un nuevo servicio y actualizar un servicio.
* Método que permite mostrar los servicios activos.
* Método que permite insertar un nuevo servicio.
* Método que permite actualizar la información de un servicio.
* Método que valida si un servicio ya existe en la base de datos.
* Validación que no se capturen campos nulos en la base de datos.
* Programación del evento doble <code>click</code> en la <code>ListView</code><code> lvServicio</code> para mostrar los datos del servicio seleccionado en el formulario.
* Creación del dialogo <code>EliminarRestaurarDlg</code>, dialogo que sirve para mostrar los servicios activos e inactivos según la opción que desee el usuario y eliminarlos o restaurarlos dependiendo de sus necesidades.
* Método que controla el contenido de un <code>ListView</code> dependiendo de  la <code>tab</code> seleccionada.
* Método que actualiza el estado del campo de activo dentro de la tabla <code>servicio_venta</code>.
* Programación del botón eliminar, el cual cambia el estado del campo de activo dentro de la tabla <code>servicio_venta</code> a <code>false</code>.
* Programación del botón restaurar, el cual cambia el estado del campo de activo dentro de la tabla <code>servicio_venta</code> a <code>true</code>.
* Creación de la clase <code>rangoCLS</code>,clase que sirve para los movimientos que son necesarios para los rangos de comisiones.

----------

<h5>27/06/2017</h5>
Actividades realizadas durante el día 27 de Junio del 2017:

* Creación del dialogo <code>rangoDlg</code>, este dialogo nos permite visualizar los rangos activos, agregar un nuevo rango y actualizar sus datos.
* Método para insertar un nuevo rango.
* Método para mostrar los rangos activos existentes.
* Método para actualizar la información de un rango.
* Validación para que no se capturen campos nulos en la base de datos
* Validación para que no se capturen rangos repetidos en la base datos.
* Creación del dialogo <code>eliminarRestaurarDlg</code>, este dialogo nos permite eliminar y restaurar rangos.
* Método para cambiar el estado del rango ya sea true o false según la necesidad del usuario.
* Programación del evento <code>selchange</code> del <code>tab</code> para mostrar en un ListView los rangos activos e inactivos según sean sus necesidades.
* Validación para que si no hay ningún elemento seleccionado del <code>ListView</code> no se elimine ni se restaure.
* Creación de la clase <code>reporteVentasCLS</code>, clase que aloja los métodos necesario para generar los reportes de ventas.
* Creación del dialogo <code>reportesVentaDlg</code>, dialogo que permite visualizar los reportes de ventas según las necesidades del usuario.
* Método que muestra los departamentos en un <code>DropDownList</code>.
* Método que muestra las regiones en un <code>DropDownList</code>.
* Método que muestra las ciudades en un <code>DropDownList</code> dependiendo de la opción seleccionada en el <code>DropDownList</code> de regiones.
* Método que muestra los requerimientos en un <code>DropDownList</code>.

----------

<h5>28/06/2017</h5>
Actividades realizadas durante el día 28 de Junio del 2017:

* Re diseño de la tabla orden_descripcion.
* Creación del método generación del reporte general.
* Creación del método generación del reporte por departamento.

----------

<h5>29/06/2017</h5>
Actividades realizadas durante el día 29 de Junio del 2017:

* Programación del evento `selchange` en los `DropDownList` del dialogo reportesDlg para cambiar los parámetros del reporte.
* Adecuación del método para la generación del reporte por departamento y general.
* Creación del método para reporte de ventas por orden de compra.
* Programación del evento textchange del `TextBox` de orden de compra para generar el reporte de ventas por orden.

----------

<h5>30/06/2017</h5>
Actividades realizadas durante el día 30 de Junio del 2017:

* Reporte de ventas generales con filtro por fechas, se agregaron los campos de modelo y marca en caso de artículo.
* Unificación de los script de la base de datos para el proyecto.
* Reporte de ventas por departamento con filtro por fechas, se agregaron los campos de modelo y marca en caso de artículo.
* Reporte de ventas por orden de compra al cual se le agregaron los campos de modelo y marca en caso de artículo.

----------

<h5>01/07/2017</h5>
Actividades realizadas durante el día 01 de Julio del 2017:

* Pruebas de humo del funcionamiento del sistema, las cuales arrojaron funcionamiento positivo.
* Reporte de ventas por ciudad con filtro de fechas, se agregaron los campos de modelo y marca en caso de artículo.
* Cambio en el diseño de los encabezados (título y tamaño) del `ListView` del reporte de ventas.
* Se incluyo la carpeta logoAtc, la cual contiene el logotipo de la empresa necesario para la impresión de los reportes.
* Creación del formato para imprimir reportes.
* Programación del botón para imprimir el reporte de ventas.

----------

<h5>03/07/2017</h5>
Actividades realizadas durante el día 03 de Julio del 2017:

* Pruebas de humo del funcionamiento del sistema, las cuales arrojaron funcionamiento positivo.
* Se agregaron detalles a la visualización del reporte de ventas.
* Cambio del orden de tabulación del dialogo `rangoDlg`.
* Cambio del orden de tabulación del dialogo `ServicioDlg`.
* Programación del focus dentro del formulario dependiendo del tipo de reporte seleccionado.
* Pruebas de humo con usuario para verificar el funcionamiento del software.
* Cambios en los mensajes de error en las ventas de `ServicioDlg` y `rangoDlg`.

----------

<h5>04/07/2017</h5>
Actividades realizadas durante el día 04 de Julio del 2017:

* Pruebas de humo del funcionamiento del sistema, las cuales arrojaron funcionamiento positivo.
* Se agregaron creo el dialogo `RangosDlg` para administrar los rangos por artículo.

----------

<h5>05/07/2017</h5>
Actividades realizadas durante el día 05 de Julio del 2017:

* Creación del método para mostrar los servicios y artículos con rango asignado.
* Creación del método para mostrar los servicios y artículos sin rango asignado.
* Creación del método para asignar un rango a un artículo.
* Creación del método para asignar un rango a un servicio.
* Creación del método para editar un rango de un servicio.
* Creación del método para editar un rango de un artículo.
* Se agregó la opción Resumen, en la que se muestra el resumen por artículo y servicio de cada departamento.
* Creación del método para mostrar el resumen del reporte de venta dependiendo del departamento y del rango de fechas.

----------

<h5>06/07/2017</h5>
Actividades realizadas durante el día 06 de Julio del 2017:

* Pruebas de humo del funcionamiento del proyecto.
* Creación de ejemplos para probar los reportes de ventas.

----------

<h5>07/07/2017</h5>
Actividades realizadas durante el día 07 de Julio del 2017:

* Pruebas de humo del funcionamiento del proyecto, se encontraron problemas en la presentación de los rangos y servicios.
* Corrección de la presentación de los rangos en la ventana `asignarRangoDlg`.
* Validación al insertar un servicio existente.

----------

<h5>08/07/2017</h5>
Actividades realizadas durante el día 08 de Julio del 2017:

* Pruebas de humo del funcionamiento del proyecto, se desarrollaron de manera eficiente.
* Capacitación al personal de inventario sobre el uso del mismo.
* Creación como equipo de la base de datos `pruebasmarquesada` en el servidor para verificar las operaciones de las ventanas del proyecto **Ventas**.

<h5>09/07/2017</h5>
Actividades realizadas durante el día 09 de julio del 2017:

* Creación de ejemplos en la base de datos `pruebasmarquesada` en el servidor.
* Pruebas de humo del funcionamiento del sistema.
* Actividades en conjunto con la compañera Fabiola:
	* Creación del método para actualizar la cantidad del artículo cuando el usuario edite la orden descripción.
	* Creación del método para actualizar el total de `artículo_comisión` cuando el usuario edite la orden descripción.
	* Creación del método para actualizar el del `servicio_comisión` cuando el usuario edite la orden descripción.

----------

<h5>10/07/2017</h5>
Actividades realizadas durante el día 10 de Julio del 2017:

* Pruebas de humo del funcionamiento del sistema.
* Actividades realizadas en conjunto con la compañera Fabiola:
	* Creación del método para asignar el rango a un artículo.
	* Creación del método para asignar el rango a un servicio.
	* Creación del bloque de código que calcule el total del `artículo_comisión` cuando el usuario edite la cantidad o se le asigne un nuevo rango.
	* Creación del bloque de código que calcule el total del `totalartículo_comisión` cuando el usuario edite la cantidad o se le asigne un nuevo rango.
	* Creación del bloque de código que calcule el total del `servicio_comisión` cuando el usuario edite la cantidad o se le asigne un nuevo rango.
	* Creación del bloque de código que calcule el total del `totalservicio_comisión` cuando el usuario edite la cantidad o se le asigne un nuevo rango.
	* Creación de ejemplos de artículo y cantidades en cada punto de venta en la base de datos `pruebasmarquesada` para verificar el funcionamiento del software.
	* Corrida del sistema en un equipo en el cual se manipularon las operaciones del sistema, al mismo tiempo en otro equipo se verifico que las operaciones se reflejaran de manera correcta en la base de datos.

----------

<h5>11/07/2017</h5>
Actividades realizadas durante el día 11 de Julio del 2017:

* Corrida del sistema en un equipo en el cual se manipularon las operaciones del sistema, al mismo tiempo en otro equipo se verifico que las operaciones se reflejaran de manera correcta en la base de datos, las pruebas arrojaron las siguientes necesidades:
	* Reducir el tamaño de los Headers del reporte de ventas.
	* Ocultar los elementos del rango de fecha cuando el usuario elija reporte por orden de compra.
	* Crear un botón para agregar un nuevo rango en la ventana `RangosDlg`.
	* Bloquear que el usuario pueda editar la información del rango actual cuando seleccione la opción editar rango.
* Se cambio el tamaño de los Headers del reporte de ventas de manera que en la impresión se visualicen se manera adecuada.
* Se ocultaron los elementos del rango de fecha cuando el usuario elija la opción reporte por orden de compra debido a que en esa opción no tienen funcionalidad.
* Se creo el botón `btAgregarNuevoRango` en el dialogo `RangosDlg` el cual abre el dialogo que permite crear un nuevo rango.
* Se bloquearon los elementos del rango actual asignado a un artículo o servicio cuando el usuario selecciona editar.