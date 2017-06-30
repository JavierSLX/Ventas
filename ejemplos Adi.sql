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


#Tabla articulo
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('123456789', 20, true, 1, 23);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('223456789', 10, true, 1, 24);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('224456789', 200, true, 2, 12);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('224466789', 400, true, 2, 15);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('224466889', 800, true, 2, 19);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('924456789', 1000, true, 2, 21);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('984456789', 500, true, 3, 7);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('987456789', 200, true, 3, 1);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('987656789', 1200, true, 3, 5);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('224756789', 50, true, 4, 2);
#De Aqui en adelante
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('724456787', 30, true, 4, 20);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('624556757', 300, true, 5, 10);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('524556757', 700, true, 5, 13);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('524555757', 300, true, 5, 19);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('664566757', 150, true, 6, 3);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('664566756', 250, true, 6, 9);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('674766757', 150, true, 7, 7);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('777766757', 550, true, 7, 17);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('674767757', 650, true, 7, 14);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('874768757', 150, true, 8, 12);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('884768857', 120, true, 8, 16);
#nuevos
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('884768826', 140, true, 6, 16);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('884111234', 290, true, 1, 20);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('886167289', 90, true, 2, 10);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('884768173', 230, true, 4, 14);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('882233227', 220, true, 6, 18);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('267812946', 370, true, 4, 14);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('345621789', 250, true, 8, 25);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('884768826', 120, true, 6, 16);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('863748292', 460, true, 1, 17);
INSERT INTO articulo (codigo, precio, activo, tipoArticulo_id, modelo_id)
VALUES ('884781043', 140, true, 3,21);

INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (15, 7, 8, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 7, 7, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (17, 7, 6, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 8, 2, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (19, 8, 4, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (15, 8, 1, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (22, 8, 3, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (12, 9, 9, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (19, 9, 5, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 9, 3, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (16, 9, 9, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (11, 10, 3, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (19, 10, 9, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (22, 10, 5, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (12, 10, 7, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (11, 10, 3, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (14, 11, 8, 7);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (20, 11, 12, 7);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (15, 11, 11, 7);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 12, 5, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (17, 12, 4, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (20, 12, 10, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (13, 12, 9, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 12, 5, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 13, 13, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 13, 6, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (11, 13, 2, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 14, 8, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (12, 14, 9, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (17, 14, 4, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (20, 15, 6, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (16, 15, 5, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (14, 15, 7, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (13, 16, 6, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (19, 16, 4, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (17, 16, 8, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 16, 5, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 17, 6, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (21, 17, 13, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (17, 17, 11, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (19, 17, 2, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 18, 10, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 18, 11, 7);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (15, 18, 1, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (28, 18, 2, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (14, 19, 3, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (12, 19, 4, 4);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (13, 19, 12, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 19, 2, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (5, 20, 5, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (16, 20, 7, 7);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (13,20 , 3, 5);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 20, 2, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (12, 21, 4, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (15, 21, 8, 3);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (13, 21, 4, 6);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (8, 21, 10, 4);


