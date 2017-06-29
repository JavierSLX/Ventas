DROP DATABASE ventas;
CREATE DATABASE ventas;
USE ventas;

create table punto_venta
(
	id int not null auto_increment primary key,
    tipo varchar(50) not null,
    activo bool not null
);

CREATE TABLE marca 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR (30) NOT NULL,
    activo BOOL NOT NULL
);
CREATE TABLE modelo
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
	nombre VARCHAR (30) NOT NULL,
	activo BOOL NOT NULL,
	marca_id INT UNSIGNED NOT NULL REFERENCES marca.id ON UPDATE CASCADE
);

create table compania
(
	id int not null auto_increment primary key,
    tipo varchar(50) not null,
    activo bool not null
);

create table acceso
(
	id int not null auto_increment primary key,
    tipo varchar(50) not null
);

create table puesto 
(
	id int not null auto_increment primary key,
    tipo varchar(25) not null
);

CREATE TABLE requerimiento
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    tipo VARCHAR (30) NOT NULL,
    activo BOOL NOT NULL
);

CREATE TABLE servicio_venta
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR (30) NOT NULL,
    precio INT UNSIGNED NOT NULL,
    activo BOOL NOT NULL
);

CREATE TABLE ciudad
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR (200) NOT NULL,
    activo BOOL NOT NULL,
	lada_id INT UNSIGNED NOT NULL REFERENCES lada.id ON UPDATE CASCADE
);

CREATE TABLE tipo_articulo
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR (30) NOT NULL,
    activo BOOL NOT NULL
);

CREATE TABLE cliente
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
	nombre VARCHAR (200) NOT NULL,
	direccion VARCHAR (200) NOT NULL,
    telefono VARCHAR (15) NOT NULL,
    email VARCHAR (50) NOT NULL,
	activo BOOL NOT NULL,
    ciudad_id INT UNSIGNED NOT NULL REFERENCES ciudad.id
);

create table permiso
(
	id int not null auto_increment primary key,
    nick varchar(30) not null,
    pwd varchar(30) not null,
    puntoVenta_id int not null references punto_venta.id,
    acceso_id int not null references acceso.id
);

CREATE TABLE clave_cliente 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    numero VARCHAR (10) NOT NULL,
    activo BOOL NOT NULL,
    cliente_id INT UNSIGNED NOT NULL REFERENCES cliente.id,
    puntoVenta_id INT NOT NULL REFERENCES punto_venta.id
); 

create table usuario
(
	id int not null auto_increment primary key,
    nombre varchar(200) not null,
    activo bool not null,
    puesto_id int not null references puesto.id,
    puntoVenta_id int not null references punto_venta.id
); 

CREATE TABLE orden
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    folio VARCHAR (30) NOT NULL,
    fecha DATETIME NOT NULL,
    cliente_id INT UNSIGNED NOT NULL REFERENCES cliente.id,
    puntoVenta_id INT NOT NULL REFERENCES punto_venta.id
);

CREATE TABLE cantidad
  (
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    valor INT UNSIGNED NOT NULL,
    articulo_id INT UNSIGNED NOT NULL REFERENCES articulo.id ON UPDATE CASCADE,
    color_id INT UNSIGNED NOT NULL REFERENCES color.id ON UPDATE CASCADE,
    puntoVenta_id INT NOT NULL REFERENCES punto_venta.id ON UPDATE CASCADE
  );

CREATE TABLE orden_descripcion
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    tipoVentaId INT NOT NULL,
    cantidad INT UNSIGNED NOT NULL,
    precio_sugerido DOUBLE UNSIGNED NOT NULL,
    precio_final DOUBLE UNSIGNED NOT NULL,
    orden_id INT UNSIGNED NOT NULL REFERENCES orden.id,
    requerimiento_id INT  UNSIGNED  NOT NULL REFERENCES requerimiento.id ON UPDATE CASCADE
);

CREATE TABLE orden_completa
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    fecha DATETIME NOT NULL,
    total DOUBLE UNSIGNED NOT NULL,
    estado BOOL NOT NULL,
    orden_id INT UNSIGNED NOT NULL REFERENCES orden.id ON UPDATE CASCADE
);

CREATE TABLE credito(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
	total DOUBLE NOT NULL,
    estado BOOL NOT NULL,
    orden_id INT UNSIGNED NOT NULL REFERENCES orden.id  ON UPDATE CASCADE

);

CREATE TABLE bono_credito(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    cantidad DOUBLE UNSIGNED NOT NULL,
    estado BOOL,
    fecha DATETIME NOT NULL,
    credito_id  INT UNSIGNED NOT NULL REFERENCES credito.id	 ON UPDATE CASCADE
    
);

CREATE TABLE servicio_requerimiento(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    servicioVenta_id INT UNSIGNED NOT NULL REFERENCES servicio_venta.id ON UPDATE CASCADE,
	requerimiento_id INT UNSIGNED NOT NULL REFERENCES requerimiento.id ON UPDATE CASCADE 
);

CREATE TABLE cantidad_requerimiento(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    cantidad_id int UNSIGNED NOT NULL REFERENCES cantidad.id ON UPDATE CASCADE,
    requerimiento_id INT UNSIGNED NOT NULL REFERENCES requerimiento.id ON UPDATE CASCADE
);

CREATE TABLE precio_cliente
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    precio DOUBLE NOT NULL,
    claveCliente_id INT UNSIGNED NOT NULL REFERENCES clave_cliente.id ON UPDATE CASCADE,
    tipoArticulo_id INT UNSIGNED NOT NULL REFERENCES tipo_articulo.id ON UPDATE CASCADE
);

CREATE TABLE articulo_compania 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    compania_id INT NOT NULL REFERENCES compania.id ON UPDATE CASCADE,
    tipoArticulo_id INT UNSIGNED REFERENCES tipo_articulo.id ON UPDATE CASCADE
);

CREATE TABLE articulo_marca 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    marca_id INT UNSIGNED NOT NULL REFERENCES marca.id ON UPDATE CASCADE,
    tipoArticulo_id INT UNSIGNED REFERENCES tipo_articulo.id ON UPDATE CASCADE
);

CREATE TABLE region
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR (10) NOT NULL,
    activo BOOL NOT NULL
);

CREATE TABLE lada 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    tipo VARCHAR (5) NOT NULL,
    activo BOOL NOT NULL,
    region_id INT UNSIGNED NOT NULL REFERENCES region.id ON UPDATE CASCADE
);

CREATE TABLE venta_lada
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    cantidad INT UNSIGNED NOT NULL,
    orden_id INT UNSIGNED NOT NULL REFERENCES orden.id ON UPDATE CASCADE,
    lada_id INT UNSIGNED NOT NULL REFERENCES lada.id ON UPDATE CASCADE
);

CREATE TABLE rango
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    minimo DOUBLE UNSIGNED NOT NULL,
    maximo DOUBLE UNSIGNED NOT NULL,
    comision DOUBLE UNSIGNED NOT NULL,
    activo BOOL NOT NULL
);

CREATE TABLE articulo_comision
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    total DOUBLE UNSIGNED NOT NULL,
    exito BOOL NOT NULL,
    rango_id INT UNSIGNED NOT NULL REFERENCES rango.id ON UPDATE CASCADE
);

CREATE TABLE servicio_comision
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    total DOUBLE UNSIGNED NOT NULL,
    exito BOOL NOT NULL,
    rango_id INT UNSIGNED NOT NULL REFERENCES rango.id ON UPDATE CASCADE
);

CREATE TABLE totalArticulo_comision 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    total DOUBLE UNSIGNED NOT NULL,
    articuloComision_id INT UNSIGNED NOT NULL REFERENCES articulo_comision.id ON UPDATE CASCADE,
    orden_id INT UNSIGNED NOT NULL REFERENCES orden.id ON UPDATE CASCADE
);

CREATE TABLE totalServicio_comision 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    total DOUBLE UNSIGNED NOT NULL,
    servicioComision_id INT UNSIGNED NOT NULL REFERENCES servicio_comision.id ON UPDATE CASCADE,
    orden_id INT UNSIGNED NOT NULL REFERENCES orden.id ON UPDATE CASCADE
);

CREATE TABLE articulo_rango 
(	
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    articulo_id INT UNSIGNED NOT NULL REFERENCES articulo.id ON UPDATE CASCADE,
    rango_id INT UNSIGNED NOT NULL REFERENCES rango.id ON UPDATE CASCADE,
    requerimiento_id INT UNSIGNED NOT NULL REFERENCES requerimiento.id ON UPDATE CASCADE
);

CREATE TABLE servicio_rango 
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    servicio_id INT UNSIGNED NOT NULL REFERENCES servicio.id ON UPDATE CASCADE,
    rango_id INT UNSIGNED NOT NULL REFERENCES rango.id ON UPDATE CASCADE,
    requerimiento_id INT UNSIGNED NOT NULL REFERENCES requerimiento.id ON UPDATE CASCADE
);
CREATE TABLE color
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR (30) NOT NULL,
    R INT NOT NULL,
    G INT NOT NULL,
    B INT NOT NULL,
    activo BOOL NOT NULL
);
CREATE TABLE articulo
(
	id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
	codigo VARCHAR (20) NOT NULL,
	precio DOUBLE NOT NULL,
	activo BOOL NOT NULL,
	tipoArticulo_id INT UNSIGNED NOT NULL REFERENCES tipo_articulo.id ON UPDATE CASCADE,
	modelo_id INT UNSIGNED NOT NULL REFERENCES modelo.id ON UPDATE CASCADE
);
