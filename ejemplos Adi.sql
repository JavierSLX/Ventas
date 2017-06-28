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


#Tabla color
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Rojo', 255, 0, 0, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Verde', 0, 255, 0, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Azul', 0, 0, 255, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Blanco', 255, 255, 255, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Negro', 0, 0, 0, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Amarillo', 255, 255, 0, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Rosa', 255, 192, 203, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Morado', 138, 43, 226, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Café', 165, 42, 42, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Plateado', 192, 192, 192, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Gris', 128, 128, 128, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Naranja', 255, 140, 0, true);
INSERT INTO color (nombre, R, G, B, activo) VALUES ('Dorado', 255, 215, 0, true);

#Tabla modelo
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Xperia', true, 1);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Estándar', true, 1);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Iphone', true, 2);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('J3', true, 3);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Galaxy S3 Mini', true, 3);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Prime', true, 3);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Core 3', true, 3);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('5010', true, 4);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('4013', true, 4);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('4005', true, 4);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Pixie 3', true, 4);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('4027', true, 4);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Estándar', true, 5);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Estándar', true, 6);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('F1810', true, 7);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('L2Z', true, 8);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('G3', true, 9);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Q10', true, 9);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Q7', true, 9);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('G4', true, 10);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('G3', true, 10);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Estándar', true, 11);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Telcel', true, 12);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Movistar', true, 12);
INSERT INTO modelo (nombre, activo, marca_id) VALUES ('Unefon', true, 11);




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


