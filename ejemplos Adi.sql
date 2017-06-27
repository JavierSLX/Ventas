use ventas;


INSERT INTO requerimiento (tipo, activo) VALUES ('Articulo', true);
INSERT INTO requerimiento (tipo, activo) VALUES ('Servicio', true);

INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Reparaciones', 250, true);
INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Liberaciones', 150, true);
INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Planes', 0, true);
INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Targeta amigo fácil', 0, true);
INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Portabilidad', 0, true);
INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Cambios de compañia', 0, true);
INSERT INTO servicio_venta (nombre, precio, activo) VALUES ('Cambio de chip', 70, true);



INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (1,1);
INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (2,1);
INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (3,1);
INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (4,1);
INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (5,1);
INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (6,1);
INSERT INTO servicio_requerimiento (servicioVenta_id, requerimiento_id) VALUES (7,1);



INSERT INTO tipo_articulo (nombre, activo) VALUES ('Chip', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Teléfono', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Audífonos', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Mica', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Pila', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Cargador', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Manos libres', true);
INSERT INTO tipo_articulo (nombre, activo) VALUES ('Memoria SD', true);


INSERT INTO compania (tipo,activo) VALUES ('Telcel', true);
INSERT INTO compania (tipo,activo) VALUES ('Movistar', true);
INSERT INTO compania (tipo,activo) VALUES ('Unefon', true);
INSERT INTO compania (tipo,activo) VALUES ('Isacel', true);



INSERT INTO articulo_compania (compania_id, tipoArticulo_id) VALUES (1,1);
INSERT INTO articulo_compania (compania_id, tipoArticulo_id) VALUES (2,1);
INSERT INTO articulo_compania (compania_id, tipoArticulo_id) VALUES (3,1);
INSERT INTO articulo_compania (compania_id, tipoArticulo_id) VALUES (4,1);


#Tabla marca
INSERT INTO marca (nombre, activo) VALUES ('Sony', true);
INSERT INTO marca (nombre, activo) VALUES ('Apple', true);
INSERT INTO marca (nombre, activo) VALUES ('Samsung', true);
INSERT INTO marca (nombre, activo) VALUES ('Alcatel', true);
INSERT INTO marca (nombre, activo) VALUES ('Lanix', true);
INSERT INTO marca (nombre, activo) VALUES ('Senwa', true);
INSERT INTO marca (nombre, activo) VALUES ('Doppio', true);
INSERT INTO marca (nombre, activo) VALUES ('Azumi', true);
INSERT INTO marca (nombre, activo) VALUES ('LG', true);
INSERT INTO marca (nombre, activo) VALUES ('Motorola', true);
INSERT INTO marca (nombre, activo) VALUES ('Freetel', true);
INSERT INTO marca (nombre, activo) VALUES ('Phone', true);


INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,2);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,3);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,4);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,5);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,6);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,7);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (1,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (2,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (3,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (4,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (5,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (6,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (7,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (8,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (9,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (10,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (11,8);
INSERT INTO articulo_marca (marca_id, TipoArticulo_id) VALUES (12,8);







select * from punto_venta;
SELECT cli.nombre
			FROM punto_venta pv, cliente cli, clave_cliente cc 
			WHERE  pv.id= cc.puntoVenta_id
			AND cli.id = cc.cliente_id
			AND pv.id = 3
			AND cc.numero = '001';
            SELECT id, tipo
								FROM punto_venta
								WHERE activo = true
								ORDER BY tipo ASC;



