use ventas;

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



INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('YOLANDA CARDOSO',	'5 DE MAYO #9C','466 1260141', 'S/R', TRUE,52);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('GLORIA ROSALES',	'MANUEL DOBLADO #30','411 1068777', 'S/R', TRUE,13);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JUAN MANUEL SANCHEZ',	'CHILPANCINGO ZACATECAS #401',	'411 1068777', 'S/R', TRUE,55);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('DIANA MANCERA',	'HIDALGO',	'411 1242981', 'S/R', TRUE,22);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JUAN RAYA','JUÁREZ #304',	'411 1256075', 'S/R', TRUE,22);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('EDWIN SILVA',	'JUÁREZ #500',	'456 1032318', 'S/R', TRUE,14);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LUIS MARTÍNEZ','	HIDALGO #115', '429 1004872', 'S/R', TRUE,14);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ORALIA RODRÍGUEZ', 'HIDALGO #17',	'429 103 8521', 'S/R', TRUE,20);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARÍA GUADALUPE VARGAS', 'JESUS MARIA MONTAÑO #37', '429 1225620', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JOSÉ LUIS SÁNCHEZ', 'GUANAJUATO #825', '462 1915180', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('VIRGINIA', 'BLVD. ESPERANZA #16', '462 1221611', 'S/R', TRUE,1);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LEONARDO SILVA', 'GUERRERO #113C', '456 1018172', 'S/R', TRUE,1);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MIGUEL NEGRETE', 'LERDO #139', '429 1113156', 'S/R', TRUE,1);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('DULCE MARÍA LÓPEZ', 'ECHEGARAY #205', '429 1033661', 'S/R', TRUE,35);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CECILIA NEGRETE',	'ALDAMA #17', '429 1113160', 'S/R', TRUE,10);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JESÚS CASTRO ', 'PROLONGACIÓN', 'S/R', 'S/R', FALSE,34);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARÍA DOLORES QUIRINO', 'HIDALGO #45', '438 6980263', 'S/R', TRUE,34);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LUIS MERCECES', 'MELCHOR OCAMPO #75A', '429 1112886', 'S/R', TRUE,34);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('GUILLERMO CÁZAREZ', 'HIDALGO #121', '352 1086969', 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('HERNESTINA DOMINGUES', 'AV PADRE HIDALGO  #254', '352 1221012' , 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CLAUDIA AREVALO', 'AV PADRE HIDALGO #252', '352 1112524', 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LUIS MENESES', 'BLVD. LÁZARO CÁRDENAS #194', '352 1200562', 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('FABIAN VARGAS', 'TEHUACAN #802', '462 2224016', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('PEDRO ARREOLA', 'FRANCISCO I. MADERO #332', '462 1089250', 'S/R', TRUE,36);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ARMANDO CHÁVEZ', '5 DE MAYO #546', '474 7415712', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARGARITA GUTIERREZ', '5 DE MAYO #567', '474 7379683', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LUPITA HERNÁNDEZ', '5 DE MAYO #154', '474 41280800', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CRISTOBAL RANGEL', 'GAMES SARIAS #15', '465 9553414', 'S/R', TRUE,32);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ROBERTO SERRANO', 'LUIS MORENO #269', '474 7428829', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('DANIEL ORTEGA', 'AGUSTÍN RIVERA #237', '474 7457911', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('DANIEL PÉREZ', 'ANTONIO GONZALEZ #129', '474 1266936', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARICELA RANGEL', 'JIMÉNEZ #100', '465 1081444', 'S/R', TRUE,38);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('FERNANDO HERNÁNDEZ', '5 DE MAYO #505', '331 1632701', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JOSÉ SALAS', 'JESÚS E. ZAPATA #205', '449 1916771', 'S/R', TRUE,24);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('SERGIO SANTANA', 'AV. JUÁREZ #406', '465 1092648', 'S/R', TRUE,44);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('BLANCA RANGEL', 'ECNEGARAY', '465 1088535', 'S/R', TRUE,44);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARISOL DE LERDO', 'PLUTARCO ELIAS CALLES 17', '449 2737573', 'S/R', TRUE,3);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CRUZ ASARA', 'AV. REVOLUCIÓN #28', '465 1169639', 'S/R', TRUE,3);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ANTONIO FLORES', '16 DE SEP # 10', '465 1166998', 'S/R', TRUE,3);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('PRISCILA CELAYA', 'JULIO CADENA 116', '449 1004639', 'S/R', TRUE,24);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ISRAEL HERNÁNDEZ', 'JUAREZ MERCED #75', '346 1008585', 'S/R', TRUE,66);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JHONATAN GUTIERREZ', '5 DE MAYO #214', '478 1002040', 'S/R', TRUE,6);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JUAN PABLO', 'S/R', 'S/R', 'S/R', FALSE,66);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LEONARDO PÉREZ','S/R','S/R', 'S/R', FALSE,66);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('GERARDO ALMANZA',	'JESUS MONTAÑO #78', '438 1005607', 'S/R', TRUE,8);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ANTONIO MARTÍNEZ', 'NICOLAS BRAVO #45', '438 1214423', 'S/R', TRUE,37);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JAZMIN BORJOQUES', 'M DE LA PIEDRA #103', '438 1145809', 'S/R', TRUE,37);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('SALVADOR PAREDES', 'NIÑOS HEROES #10A', '438 1215333', 'S/R', TRUE,8);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ISRAEL PAREDES', 'NIÑOS HEROES #120', '445 4452176', 'S/R', TRUE,8);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LUIS ALBERTO ALMANZA', 'MONTAÑO #63', '438 3623002', 'S/R', TRUE,8);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JESUS ENRIQUE LÓPEZ', 'FRANCISCO SIERRA #25B', '438 1162512', 'S/R', TRUE,37);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('GUILLERMO HERNÁNDEZ', 'ABASOLO #111B', '438 1001838', 'S/R', TRUE,37);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ANGELICA MADRIS', '5 DE MAYO #38', '438 1143631', 'S/R', TRUE,37);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LUIS HIGAREDA', 'NICOLAS RAVO 45', '438 1034936', 'S/R', TRUE,37);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('URIEL TORRES', '5 DE MAYO', '449 1447773', 'S/R', TRUE,3);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('RAUL', 'FAJA DE ORO 1400', '461 1699233', 'S/R', TRUE,42);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('RIGOBERTO LÓPEZ', 'NO REELECCION #16', '462 2103896', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('EDER PÉREZ', 'MINA #60', '418 1105096', 'S/R', TRUE,43);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CARLOS ÁVILA', 'HIDALGO #406', '466 1073802', 'S/R', TRUE,61);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARÍN PÉREZ','S/R', 'S/R', 'S/R', FALSE,19);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('EDUARDO LÓPEZ', 'ZARAGOZA #23', '466 1160702', 'S/R', TRUE,26);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JUAN CASTRO', 'ABASOLO #1885', '462 111961', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('OMAR CASTRO','S/R','S/R', 'S/R', FALSE,66);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JAVIER ESTRADA', 'LAZARO CARDENAS #8A', '438 1110867', 'S/R', TRUE,8);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CARMEN SILLAS', 'S/R','S/R', 'S/R', TRUE,11);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('SERGIO SANCHEZ', 'S/R','S/R', 'S/R', TRUE,23);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JORGE OMAR DE LA PAZ', 'GUERRERO #15A', '469 6218054', 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ANTONIO LÓPEZ', 'S/R', 'S/R', 'S/R', FALSE,35);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('FYLY HERNÁNDEZ', 'AV. SAN JOAQUÍN #460', '462 1251452', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CESAR ACOSTA', 'S/R', 'S/R', 'S/R', FALSE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JUDITH PAREDES', 'JUAREZ #133', '466 1234573' , 'S/R', TRUE,52);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LEOPOLDO HERNÁNDEZ', 'JOSE TORRES LANDA ESQ.', '461 1194026', 'S/R', TRUE,7);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JAVIER', 'JOSE REYES 301', '465 9558022', 'S/R', TRUE,32);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARTÍN SALAS','S/R','S/R', 'S/R', FALSE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('EDER PÉREZ', 'S/R','S/R', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MAURICIO VERNABE', 'MIGUEL LERDO #91A', '474 7944364', 'S/R', TRUE,28);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('GUILLERMO CASTILLO','BLVD. LAZARO CARDENAS', '352 5618531', 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CARLOS ANTONIO','S/R','S/R', 'S/R', FALSE,43);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('LIBORIO LÓPEZ', 'SEG. PÚBLICA #403', 'S/R', 'S/R', TRUE,44);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('RICARDO BARROSO',	'LAGUNILLA #653', '462 1647833', 'S/R', TRUE,21);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ANGEL MORENO','S/R','S/R', 'S/R', FALSE,43);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('MARCO MENDES', 'BLVD. LAZARO CARDENAS #194', '352 1395887', 'S/R', TRUE,27);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ELVIRA LLANAS', 'JUAN DOMINGUEZ #302', '465 1085701', 'S/R', TRUE,45);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('JAVIER DOMINGUEZ', 'JOSÉ REYES #301', '492 8925035', 'S/R', TRUE,2);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ANA GABRIELA', 'MORELOS #505', '411 1110608' , 'S/R', TRUE,6);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CARLOS LARA', 'ZARAGOZA #1421', '449 3230874', 'S/R', TRUE,3);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ERICK RAMÍREZ', 'BENITO JUÁREZ #57', '466 1151818', 'S/R', TRUE,50);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('CLAUDIA LARA SÁNCHEZ', 'MANUEL DOBLADO #7', '921 1629167', 'S/R', TRUE,66);
INSERT INTO cliente (nombre, direccion, telefono, email, activo, ciudad_id) VALUES 
('ALVARO MOTA', 'TRANSITO #202' , '478 1057186', 'S/R', TRUE,6);


#Tabla punto_venta
INSERT INTO punto_venta (tipo, activo) VALUES ('R0', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R1', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R2', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R3', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Oficina', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Local Juárez', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Local Zaragoza', true);



INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('001', true,174, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('002', true,175, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('003', true,176, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('004',true,177, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('005',true,178, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('006',true,179, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('007',true,180, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('008',true,181, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('009',true,182, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('010',true,183, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('011',true,184, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('012',true,185, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('013',true,186, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('014',true,187, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('015',true,188, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('016',true,189, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('017',true,190, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('018',true,191, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('019',true,192, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('020',true,193, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('021',true,194, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('022',true,195, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('023',true,196, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('024',true,197, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('025',true,198, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('026',true,199, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('027',true,200, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('028',true,201, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('029',true,204, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('030',true,205, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('031',true,206, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('032',true,207, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('033',true,208, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('034',true,209, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('035',true,210, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('036',true,211, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('037',true,212, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('038',true,213, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('039',true,214, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('040',true,215, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('041',true,216, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('042',true,217, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('043',true,218, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('044',true,219, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('045',true,220, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('046',true,221, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('047',true,222, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('048',true,223, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('049',true,224, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('050',true,225, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('051',true,226, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('052',true,227, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('053',true,228, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('054',true,229, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('055',true,230, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('056',true,231, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('057',true,232, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('058',true,233, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('059',true,234, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('060',true,235, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('061',true,236, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('062',true,237, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('063',true,238, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('064',true,239, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('065',true,240, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('066',true,241, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('067',true,241, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('068',true,242, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('069',true,243, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('070',true,244, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('071',true,245, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('072',true,246, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('073',true,247, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('074',true,248, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('075',true,249, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('076',true,250, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('077',true,256, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('078',true,257, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('079',true,258, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('080',true,259, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('081',true,260, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('082',true,261, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('083',true,262, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('084',true,263, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('085',true,264, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('086',true,265, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('087',true,266, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('088',true,267, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('089',true,269, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('090',true,269, 3);




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



