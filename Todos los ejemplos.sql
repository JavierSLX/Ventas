
USE ventas;
#Tabla punto_venta
INSERT INTO punto_venta (tipo, activo) VALUES ('R0', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R1', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R2', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R3', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Oficina', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Local Juárez', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Local Zaragoza', true);

 
#Tabla cantidad
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 1, 2, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (15, 1, 5, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (11, 1, 3, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (17, 2, 4, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (12, 2, 8, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (16, 2, 7, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (20, 3, 1, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (21, 3, 9, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 3, 10, 1);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (13, 4, 6, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (14, 4, 9, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (16, 4, 10, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (18, 5, 11, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (11, 5, 13, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (19, 5, 8, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (23, 6, 7, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (27, 6, 1, 2);
INSERT INTO cantidad (valor, articulo_id, color_id, puntoVenta_id) VALUES (10, 6, 3, 2);


INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('ABASOLO',TRUE, 14);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('Acambaro',TRUE, 7);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('AGUASCALIENTE',TRUE, 28);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('APASEO EL ALTO',TRUE, 8);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('APASEO EL GRANDE',TRUE, 8);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CALERA',TRUE, 9);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CELAYA',TRUE, 10);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CERANO',TRUE, 11);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CHAMACUARO',TRUE, 7);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('COMONFORT',TRUE, 18);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('LORETO',TRUE, 29);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CORONEO',TRUE, 25);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CORTAZAR',TRUE, 13);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CUERAMARO',TRUE, 14);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('CUPAREO',TRUE, 12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('DOLORES HIDALGO',TRUE, 15);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('EL SABINO',TRUE, 12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('EMPALME ESCOBEDO',TRUE, 18);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('GUANAJUATO',TRUE, 16);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('HUNIMARO',TRUE, 14);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('IRAPUATO',TRUE, 17);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('JARAL DEL PROGRESO',TRUE, 13);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('JERECUARO',TRUE, 25);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('JESUS MARIA',TRUE, 28);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('JUVENTINO ROSAS',TRUE, 18);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('LA MONCADA',TRUE, 18);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('LA PIEDAD',TRUE, 3);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('LAGOS DE MORENO',TRUE, 19);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('MOLINO DE SANTA ANA',TRUE, 17);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('NUEVO CHUPICUARO',TRUE, 7);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('OBRAJUELO',TRUE, 7);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('PABELLON DE ARTEAGA',TRUE, 23);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('PARACUARO',TRUE, 7);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('PASTOR ORTIZ',TRUE, 11);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('PENJAMO',TRUE, 30);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('PUEBLO NUEVO',TRUE, 14);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('PURUANDIRO',TRUE, 11);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('RINCON DE ROMOS',TRUE, 23);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('RINCON DE TAMAYO',TRUE, 10);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('ROMITA',TRUE, 31);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAHUAYO',TRUE, 6);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SALAMANCA',TRUE, 20);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN DIEGO',TRUE, 15);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN FRANCISCO',TRUE, 23);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN JOSE DE GRACIA',TRUE, 32);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN JOSE DE ITURBIDE',TRUE, 14);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN JUAN DE LA VEGA',TRUE, 10);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN JUAN DEL RIO',TRUE, 24);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN LUIS DE LA PAZ',TRUE, 21);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SAN PEDRO DE LOS NARANJOS',TRUE, 21);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SANTA MARIA DEL REFUGIO',TRUE,10);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SANTIAGO MARAVATIO',TRUE,12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SANTO TOMAS',TRUE, 12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SALVATIERRA',TRUE, 12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('SARABIA',TRUE, 13);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('TANGAMANDAPIO',TRUE, 33);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('TANGANCICUARO',TRUE, 34);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('TARANDACUAO',TRUE, 25);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('TARIMORO',TRUE,12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('URIANGATO',TRUE, 27);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('URIREO',TRUE, 12);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('VALLE DE SANTIAGO',TRUE, 26);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('VILLAGRAN',TRUE, 13);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('YURIRIA',TRUE, 27);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('ZACAPU',TRUE, 2);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('S/R',TRUE, 35);
INSERT INTO ciudad(nombre, activo, lada_id)
VALUES('QUERETARO',TRUE, 36);
-- INSERT INTO ciudad(id, nombre, activo, lada_id)
-- VALUES('ZACATECAS',TRUE);

INSERT INTO region(nombre, activo)
VALUES('R5',TRUE);
INSERT INTO region(nombre, activo)
VALUES('R6',TRUE);
INSERT INTO region(nombre, activo)
VALUES('S/R',TRUE);


INSERT INTO lada(tipo, activo, region_id)
VALUES('438', TRUE, 1);
INSERT INTO lada(tipo, activo, region_id)
VALUES('436', TRUE, 1);
INSERT INTO lada(tipo, activo, region_id)
VALUES('352', TRUE, 1);
INSERT INTO lada(tipo, activo, region_id)
VALUES('351', TRUE, 1);
INSERT INTO lada(tipo, activo, region_id)
VALUES('443', TRUE, 1);
INSERT INTO lada(tipo, activo, region_id)
VALUES('353', TRUE, 1);
INSERT INTO lada(tipo, activo, region_id)
VALUES('417', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('413', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('478', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('461', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('438', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('466', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('411', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('429', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('418', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('473', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('462', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('412', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('474', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('464', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('468', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('472', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('465', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('427', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('421', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('456', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('445', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('449', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('496', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('469', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('432', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('381', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('383', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('355', TRUE, 2);
INSERT INTO lada(tipo, activo, region_id)
VALUES('S/R', TRUE, 3);
INSERT INTO lada(tipo, activo, region_id)
VALUES('442', TRUE, 2);


INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(1, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(2, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(3, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(4, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(5, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(6, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(7, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(8, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(9, 1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(10, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(11, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(12, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(13, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(14, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(15, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(16, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(17, 2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(18, 2);

INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(1,1,8);
INSERT INTO precio_cliente(precio, claveCliente_id,articulo_id)
VALUES(2,2,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(3,3,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(4,4,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(5,5,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(6,6,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(7,7,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(8,8,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(9,9,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(10,10,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(11,11,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(12,12,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(13,13,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(14,14,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(15,15,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(16,16,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(17,17,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(18,18,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(19,19,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(20,20,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(21,21,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(22,22,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(23,23,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(24,24,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(25,25,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(26,26,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(27,27,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(28,28,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(29,29,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(30,30,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(31,31,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(32,32,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(33,33,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(34,34,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(35,35,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(36,36,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(37,37,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(38,38,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(39,39,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(40,40,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(41,41,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(42,42,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(43,43,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(44,44,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(45,45,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(46,46,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(47,47,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(48,48,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(49,49,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(50,50,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(51,51,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(52,52,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(53,53,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(54,54,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(55,55,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(56,56,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(57,57,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(58,58,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(59,59,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(60,60,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(61,61,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(62,62,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(63,63,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(64,64,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(65,65,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(66,66,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(67,67,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(68,68,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(69,69,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(70,70,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(71,71,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(72,72,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(73,73,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(74,74,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(75,75,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(76,77,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(77,77,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(78,78,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(79,79,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(80,80,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(81,81,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(82,82,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(83,83,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(84,84,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(85,85,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(86,86,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(87,87,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(88,88,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(89,89,1);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(90,90,2);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(91,91,3);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(92,92,4);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(93,93,5);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(94,94,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(95,95,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(96,96,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(97,97,8);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(98,98,7);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(99,99,6);
INSERT INTO precio_cliente(precio, claveCliente_id, articulo_id)
VALUES(100,100,5);


INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(1,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(2,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(3,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(4,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(5,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(6,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(7,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(8,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(9,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(10,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(11,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(12,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(13,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(14,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(15,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(16,2);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(17,1);
INSERT INTO cantidad_requerimiento(cantidad_id, requerimiento_id)
VALUES(18,2);

#Tabla cliente
#Ruta 0
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GENERAL','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OFICINA','JUÁREZ 212','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LOCAL ZARAGOZA','ZARAGOZA 328','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LOCAL JUÁREZ 212','JUÁREZ 212','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LOCAL JUÁREZ 111','JUÁREZ 111','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ARTURO PACHECO','HIDALGO','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALVINO X','URIREO','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANGEL PRECOMA','SAN JOSÉ ITURBIDE','S/R','S/R',true,46);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ISABEL X','OCAMPO','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ISAAC MEDRANO','SALVATIERRA','S/R','S/R',true,54);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ ESPINOZA','OCAMPO','S/R','S/R',true,54);

#Ruta 1
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FIDEL PAREDES','NIÑOS HERES #5CERANO','438 100 4824','S/R',true,8);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARIA VAZQUEZ','M. DE LA PIEDRA 31, PURUANDIRO','438 101 4951','S/R',true,37);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'NATALIA REYES','MORELOS 98, MOROLEON','445 111 2527','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LEIDY ANAHI','LEANDRO VALLE # 112 URIANGATO','445 122 7606','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FILIBERTO PAREDEZ','J. JESÚS MONTAÑO 12, CERANO','438 111 0088','S/R',true,8);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALFREDO VILLALÓN','URRUTIA 70, URIANGATO,GTO','445 108 4027','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'TOÑO MURILLO','SAN MIGUEL 26, URIANGATO,GTO.','445 104 1444','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSE LUIS MORALES','5 MAYO NO. 8, YURIRIA,GTO.','445 102 8278','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARLOS PLANCARTE','5 MAYO # 1 YURIRIA,GTO.','445 106 4550','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EDUARDO', 'URIANGATO,GTO.', '4454562133','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'YOLANDA OROZCO','12 DE OCT Y ABASOLO, MOROLEON,GTO.','445 111 6593','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALFONSO CHAVEZ','5 DE MAYO, URIANGATO,GTO.','452 127 9903','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARICELA AGUILAR','FERNANDO NUÑES # 5 YURIRIA,GTO.','445 140 6823','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'DELIA CALDERON','HIDALGO # 59 URIANGATO,GTO.','445 102 7918','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OMAR', 'PIPILA # MOROLEON', '4454558781','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ROMAN BARBOZA','PLAZA LLENCISO 25, YURIRIA,GTO.','445 456 3135','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'IMELDA GONZALEZ','AV. JUÁREZ ORIENTE 330, QRO.','427 112 8270','S/R',true,67);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALEJANDRO RAMÍREZ','AV.PUEBLA 408, MOROLEÓN, GTO.','445 131 4137','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ISRAEL LOPEZ','FRANCISCO VILLA 45, SAN JUAN DEL RIO, QRO.','S/R','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GERARDO PEREZ ACOSTA','F. VILLA 31, SAN JUAN DEL RIO, QRO.','427 117 7723','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARLOS GOMES','AV. JUÁREZ 320, SAN JUAN DEL RIO, QRO.','427 124 3617','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ VESERAL','AV. HIDALGO 234, SAN JUAN DEL RIO, QRO.','427 108 1571','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ELIZABETH ACEVEDO','AV JUÁREZ 164, SAN JUAN DEL RÍO, QRO.','427 149 4780','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FLOR SILVESTRE','CLAVELES 165,SAN JUAN DEL RIO, QRO.','427 124 3251','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EDUARDO FEREGRINO','ARTICULO 4, LOCAL 2','427 110 3690','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALEJANDRO VELAZQUEZ','F.VILLA 21, SAN JUAN DEL RIO, QRO.','427 306 7524','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LETICIA LINAREZ','PENSAMIENTO 37, SAN JUAN DEL RIO, QRO.','427 306 0141','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MELANNY', 'RIVAPALACIO #12 SAN JUAN DEL RIO', '4271229119','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MOISES FLORES','20 NOV , SAN JUAN DEL RIO,QRO','427 120 0791','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSE LUIS COLÍN','20 NOV 90 B, SAN JUAN DEL RIO, QRO.','427 108 7027','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EMMA','CERRO GORDO,SAN JUAN DEL RIO, QRO.','427 110 3690','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANGEL TORRES','CAMINO RANCHO DE EN MEDIO, ANDADOR SANTA LUCIA','427 110 3690','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JORGE RUIZ','S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JORGE RODRÍGUEZ MIRANDA','RIVAPALACIO 53, SAN JUAN DEL RÍO, QRO.','442 133 1017','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUAN RUÍZ MORENO','ADOLFO LOPEZ MATEOS 26, SAN JUAN DEL RIO,QRO.','442 155 9198','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' HUGO NIETO','FCO VILLA 64','427 134 5585','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' JESÚS ZAVALA','SANTA MÓNICA 2161, COL. REFORMA, IRAPUATO','462 170 1310','S/R',true,21);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' CARMEN HERNÁNDEZ','16 DE DICIEMBRE NO. 90, COL. JUÁREZ, IRAPUATO','462 173 5854','S/R',true,21);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' DANIEL CALDERÓN','5 DE MAYO 76, VALLE DE SANTIAGO','456 101 2773','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' ALBERTO HIDALGO','CARR. A AMEALCO KM 6','427 159 1210','S/R',true,67);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' DON LUIS','OBREGÓN SUR 199, SALAMANCA ,GTO','464 133 9660','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' ABIGAIL GARCÍA','ANDRÉS DELGADO 214, SALAMANCA','464 601 5740','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' ANDREA MIRANDA','CALLE 5 DE MAYO #408, SALAMANCA,GTO.','464 655 3352','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' JARY','5 DE MAYO 303-B, SALAMANCA, GTO.','464 102 5057','S/R',FALSE,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' ESTHER SALDIVAR','AV. DEL TRABAJO,SALAMANCA,GTO.','464 133 2946','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' RAZO MARCO','VILLA, SALAMANCA,GTO.','464 157 0975','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' MOISES ORNELAS LOERA','VILLAS SALAMANCA 506, SALAMANCA,GTO.','464 645 0354','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' GABY LOPEZ','MERCADO 5 MAYO, SALAMANCA, GTO.','464 167 1344','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' BRENDA GONZALEZ ORTÍZ','CALLE COMUNICACIÓN NORTE 522, SALAMANCA,GTO.','464 105 3554','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' LILIANA PACHECO','MADERO 36, VALTIERRILLA, GTO.','449 1067894','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EDER MARTINEZ', 'DAXIAL # 1624', '4621920351','S/R',true,21);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' RICARDO VALENCIA G.','15 DE MAYO NO. 2, CERRO GORDO, SALAMANCA','464 124 0151','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' CLAUDIA GUTIERREZ','DIEGO MORAN 301,SALAMANCA,GTO.','464 136 1123','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' SANDRA KARINA CASTAÑEDA ARREDONDO','BOULEVARD VILLAS SALAMANCA 176, SALAMANCA,GTO','464 136 6664','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' JUAN CIRILO ARELLANO MEDIA','COMUNICACIÓN NORTE 509, INFONAVIT, SALAMANCA, GTO','464 655 8822','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' LUIS ANGEL','ZARAGOZA 606,VILLAGRAN, GTO','411 108 8008','S/R',true,63);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' RAFAEL VÁZQUEZ','RAYON 581, SAN LUIS DE LA PAZ, GTO','468 103 5129','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' JANET RAMIREZ','RAYON 572, SAN LUIS DE LA PAZ, GTO','468 117 5817','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' SANDRA GUERRERO','	RAYON # 313, SAN LUIS DE LA PAZ, GTO','468 680 2120','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' SAUL GUERRA','	JOSEFA ORTÍZ 36, SAN LUIS DE LA PAZ, GTO','	468 687 3251','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' RAY LEONOR	','RAYON 206, SAN LUIS DE LA PAZ, GTO','468 103 8024','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' URIEL LÓPEZ','COMERCIO 147, CENTRO, MOROLEÓN, GTO.','445 462 2711','S/R',true,64);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' ANA PATRICIA SOLÍS','HIDALGO 133, SAN LUIS DE LA PAZ,GTO','468 687 6358','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' ELVIA VILLANUEVA','GALEANA 349, SAN LUIS DE LA PAZ,GTO','468 106 6117','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' SILVIA LÓPEZ','BRAVO 501, SAN LUIS DE LA PAZ,GTO','468 114 6807','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( ' MARIA DEL CARMEN','ZARAGOZA 110, SAN LUIS DE LA PAZ, GTO.','468 686 9842','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MIGUEL CANO	','YUCATAN #36, DOLORES HIDALGO, GTO.','418 101 1587','S/R',true,16);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ DIAZ','BOULEVARD ADOLFO LOPEZ MATEOS 21 INT 22, CELAYA	','461 133 6148','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'IVAN JARAMILLO','RAYÓN 427, SAN LUIS DE LA PAZ, GTO.','468 100 4577','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUANITA SALINAS	','RAYON 316, SAN LUIS DE LA PAZ, GTO','468 117 2759','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ULISES DURAN','RAYON, SAN LUIS DE LA PAZ, GTO','468 113 7493','S/R',FALSE,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SOLEDAD	','GUERRERO,SAN LUIS DE LA PAZ,GTO','S/R','S/R',FALSE,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ARTURO AGUILERA LEIVA','BRAVO 619, SAN LUIS DE LA PAZ,GTO','468 108 85 37','S/R',true,49);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MAURICIO  CUELLAR CERVANTEZ','JUÁREZ 12, NEUTLA, GTO','412 117 9660','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'IRVIN REYEZ	','PLAZA NUEVA, COMONFORT,GTO.','712 103 6030','S/R',true,10);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SAUL GARCIA ARREDONDO','JUÁREZ ESQ. MORELOS, ROQUE,GTO','461 188 3349','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'AGUSTIN HERRERA MARTÍNEZ','AV. LAS AGUILAS 101, COL AGUILAS, SAN JUAN DEL RIO,QRO.','427 144 7100','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ ALFREDO','AV. UNIVERSIDAD 201, CELAYA','461 127 9792','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANA LAURA MUÑÍZ	','REFORMA AGRARIA 1500, MONTE BLANCO, CELAYA','461 254 3081','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MIGUEL RODRIGUEZ', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUAN JESUS MARTINEZ	','S/R','S/R','S/R',true,16);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ADRIAN CASILLAS','MORELOS, DOLORES HIDALGO, GTO','418 102 0224','S/R',true,16);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUAN MANUEL MARTINEZ', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARLOS MOCTEZUMA', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ ANTONIO RANGEL','CORREGIDORA 12','418 101 0596','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'NESTOR G', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANA PATRICIA SOLIS', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EDGAR OCHOA', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'RODRIGO ZETTER R.','INT. MERCADO TOMASA ESTEBES LOCAL 161','464 653 9773','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARINA SANCHEZ', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JORGE VARGAS LUNA', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANALILIA RODRIGEZ', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'DANIEL OCAMPO', 'AV SAVEDRA # 100 VARLOBENTO SALAMANCA', '4641392803','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUAN CARLOS GUERRERO','HIDALGO 201B,JUVENTINO ROSAS, GTO','412 117 7651','S/R',FALSE,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JORGE MORRIL','HIDALGO 302, JUVENTINO ROSAS, GTO','412 171 7030','S/R',FALSE,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BERENICE CORTEZ	','AV. PEDREGAL 512, MORELIA','443 268 1768','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ENRIQUE CASTILLO','16 DE SEP 104B,JUVENTINO ROSAS, GTO','461 239 6110','S/R',FALSE,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANTONIO GODINEZ','CORREGIDORA 217A, JUVENTINO ROSAS, GTO','412 117 1336','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BERNARDO BUENAVISTA','ISABEL LA CATOLICA 405, JUVENTINO ROSAS, GTO','412 104 8187','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ GUADALUPE MONTENEGRO','CAMINO REAL NO. 4, LA ORDEÑA, SALAMANCA	','464 639 6822','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANDREA DABALOS','BENITO JUÁREZ 2A, ALVARO OBREGÓN','443 131 8444','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LOURDES ZABALA', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARIA DEL CARMEN HERNANDEZ', 'S/R', 'S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARMEN GUERRERO	','HIDALGO 100,JUVENTINO ROSAS, GTO','412 117 2830','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MIGUEL CANO','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GERARDO LÓPEZ', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ARMANDO MONTES', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SANJUAN SOBRAS', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BRENDA GALLARDO GONZÁLEZ','5 DE MAYO SIN N, SALAMANCA, GTO','464 642 3195','S/R',true,42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARINA SANCHEZ', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CHAVA', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GUSTABO', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARIA TERESA MAGAÑA', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GUSTABO LAZARO', 'ALDAMA # 103 SALAMANCA', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OBDULIA', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JASMÍN MALDONADO','VILLAS DEL SECRETO 172, VILLAS DE LOS ARCOS, CELAYA','461 174 9150','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GLORIA ROSALES', 'PLAZA RESTAR MODULO TELCEL', 'S/R','S/R',TRUE , 21);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MAYRA JUAREZ', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARIA TERESA GARCIA RAMIREZ', '18 MARZO # 117 CARDENAS', 'S/R','S/R',TRUE, 42);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OSCAR QUINTANA NÚÑEZ','BLV. HIDALGO 36, SAN JUAN DEL RÍO','551 339 7189','S/R',true,48);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'RICARDO FERREIRA LARA', 'FRAY CERVANDO Y TERESA DEMIER', ' 4612631439','S/R',TRUE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARIA MARTIN MERINO', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ADONAY', 'S/R', 'S/R','S/R',FALSE,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MAYRA DEL SOL MENDOZA','5 DE MAYO NO. 54B, URIANGATO, GTO','445 144 9628','S/R',true,60);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EVELIN', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'TERESA ÁLVAREZ','INSURGENTE 6, PANALES JAMAICA, TARIMORO','S/R','S/R',true,59);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUAN CARRILLO', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FELIX DANIEL', 'S/R', 'S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BERNANDO NÚÑEZ SUÁREZ ','EJIDO DE SANTA ANITA 105, CELAYA, GTO','461 184 7091','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ LUIS','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JAVIER VARGAS','S/R','S/R','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSUE','LUIS DE VELAZCO SANTANAMAYA','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BERENICE BUTANIA SANTOYO','GUADALUPE VICTORIA #18 A','S/R','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'RICARDO GOMEZ','S/R','S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'PATRICIA','S/R','S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ROGELIO','S/R','S/R','S/R',FALSE,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SANDRA SOSA','GRAL NEGRETE 147, ZACAPU,MICH','436 100 3445','S/R',true,65);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SANDRITA SOSA','ZACAPU,MICH','S/R','S/R',true,65);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ERICK SOSA','ZACAPU,MICH','436 112 0992','S/R',true,65);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MIREYA LEON','MORELOS 125 SANTAANA MAYA','4431747068','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'IVAN MARQUEZ','CARR NAL. 10','351 100 0345','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SANTIAGO PRADO','SANTO TOMAS #5,MICH.','351 180 6986','S/R',true,53);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANA KAREN','CARLOS SALAZAR 306, TANGANCICUARO,MICH.','S/R','S/R',true,57);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'S/R','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SALVADOR','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LAURA VEGA VILLANUEVA','MADERO 212,TANGAMANDAPIO,MICH.','3511085250','S/R',true,56);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'PATRICIA SANCHEZ','MADERO # 214','S/R','S/R',true,56);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'DANIEL VALDEZ','MADERO 239','S/R','S/R',true,56);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSÉ ZARAGOZA','HIDALGO #10','3511135251','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSE MANUEL VENEGAS ','INSURGENTES 212, SAHUAYO,MICH','353 120 7089','S/R',true,41);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ENRIQUE MOSQUEDA RAMIREZ','CONSTITUCION # 206 SAHUAYO,MICH','3535351176','S/R',true,41);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FLABIO CASTILLO','MATAMOROS 237','332 346 1380','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GERMAN GEO','S/R','3531154481','S/R',true,41);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'DIEGO CASTAÑEDA','HIDALGO 10, SAHUAYO,MICH','332 107 82209','S/R',true,41);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'HERNAN GEO','ZARAGOZA','3531154481','S/R',true,41);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'S/R','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARIA CARMEN TORRES','MADERO #51','3511454933','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GABY BRISEÑO','HIDALGO #258','3931057438','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SALVADOR','CONSTITUCION','3531017115','S/R',true,41);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'REMEDIOS','CARR. NACIONAL 77','353 123 1838','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BLANCA CECILIA','PORTAL CASTELLANOS','3535397609','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'S/R','S/R','S/R','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LUCILA GARCIA','FRANCISCO Y MADERO','3535359663','S/R',true,66);
#Ruta 2
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


#Ruta 3
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MIREYA PARRALES	','MERCADO HIDALGO,LOCAL #2 ACAMBARO,GTO.','417 100 2354','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALFREDO LOPEZ','16 DE SEPTIEMBRE #870 ACAMBARO','415 106 5437','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ERNESTO TECNO-CELL','AV 1 DE MAYO # 661-A, ACAMBARO GTO','417 110 0083','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ROBERTO MORENO CASTRO','ANDADOR JUAREZ # 431, ACAMBARO GTO','417 107 5700','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MUNDO CELL','MARIANO ABASOLO #34-A ACAMBARO GTO','417 177 6136','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'DALIA OROZCO','HIDALGO  #70 CHAMACUARO GTO','417 113 8340','S/R',true,9);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'NAYELI HIDALGO','HIDALGO #5 OBRAJUALO , ACAMBARO','417 101 5434','S/R',true,31);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LUZ MARIA RODRIGUEZ TREJO','MORELOS #531 ACAMBARO GTO','417 112 9344','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARMEN FIERROS VALIOIS','HIDALGO #127 TARANDA GTO','421 102 7365','S/R',true,58);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LUIS HERNANDEZ','AV. MIGUEL HIDALGO #988 ACAMBARO GTO','417 100 1300','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LILIANA SEX SOHOP','AV GUERRERO # 439 ACAMBARO GTO','417 104 4485','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'DIANA PARRALES','ALDAMA #62 B ACAMBARO GTO','417 117 1097','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SR RAMIRO BELTRAN','AV ZARAGOZA #181 CORONEO GTO','421 472 6091','S/R',true,12);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSE GUADALUPE','JUAREZ #78 JERECUARO','421 105 1671','S/R',true,23);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ELIZABETH PEREZ','	JOSE AGUILAR Y MAYA #56 JERECUARO','421 105 1293','S/R',true,23);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FABIOLA RODRIGUES','GUERRERO # 14B  ACAMBARO','417 104 2223','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'YOSEN GIOVANI CAMACHO','ABASOLO #54 B ACAMBARO','442 471 0407','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANTONIO PEREZ','HEROES DE NACOZARI #646 A ACAMBARO','417 179 4390','S/R',true,2);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EDGAR URIEL RIVERA','20 DE MAYO # 4 NUEVO CHUPICUARO','417 178 9947','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'KARLA MERLO	','PLAZA SAMANO #83 PARACUARO,ACAM	','417 104 3921','S/R',true,33);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MA. SANTOS','QUINTANA ROO LOCAL 5, APASEO EL ALTO','413 101 5472','S/R',true,4);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LETICIA HERNANDEZ','JARDIN CUAUHTEMOC #10, APASEO EL ALTO','442 120 8754','S/R',true,4);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALVARO EZEQUIEL LARA','VENUSTIANO CARRANZA #316, APASEO EL ALTO','442 410 5139','S/R',true,4);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OCTAVIO TINAJERO','PROL. MIGUEL ALEMAN #409 APASEO EL ALTO','413 112 5076','S/R',true,4);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MINERVA ARAZATE	','JUAREZ #610 APASEO EL ALTO','4612279683','S/R',true,4);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GUSTAVO ANAYA','FRANCISCO JAVIER MINA #305, APASEO EL GRANDE','413 102 7118','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'PAOLA ÑAÑES	','GUDALUPE VICTORIA #105,APASEO EL GRANDE','461 231 8563','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARLOS PEREZ','VICENTE RUIZ #105, APASEO EL GRANDE','412 101 8145','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'YOLANDA GUTIERREZ','MARIANO MATAMOROS #200-B APASEO EL GRANDE','413 120 7693','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SR JOSE JULIAN GARCIA ','ALDAMA# 126 B LA VILLITA ,APASEO EL GRANDE','413 100 2594','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARLOS CRUZ ','VENUSTIANO CARRANZA, CEMTRAL DE APASEO EL GRANDE','461 200 6136','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BRAYAN GUERRERO	','PROL. MIGUEL ALEMAN #521 APASEO EL ALTO','413 111 9754','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SR. FERNANDO IBARRA	','GUADALUPE VICTORIA S/N APASEO EL GRANDE	','413 158 2472','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SR. JAVIR LUCERO','NARCIZO MENDOZA,#99 APASEO EL GRANDE  GTO','413 118 2540','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SRA. MARGARITA CARRETO','CALLE ANTONIO PLAZA S/N APASEO EL GRANDE MERCADO','413 123 6533','S/R',true,5);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'RICARDO PARAMO','saltillo #121 col santarita ,celaya gto','461 151 1863','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JANET NARANJO RUIZ','Aguascalientes #166 ,col. Santa rita','461 608 7690','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'BRENDA RAQUEL ','Chetumal #301, clo santa rita, celaya','461 611 4233','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARTHA MEDINA','Puebla #301, col, santa rita','461 109 4698','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SRA, FLOR RODRIGUEZ	','Paulino leon #35 santa maria del refuguio','461 600 7342','S/R',true,51);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'SR JESUS FARMACIA','Camino de las torres #445 col el campanario celaya','461 119 5083','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'VERONICA MEDINA	','ALDAMA # 206, SAN JUAN DE LA VEGA','461 223 1059','S/R',true,47);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JAVIER VARGAS','AV PRESA ALVARO OBREGON _#11 COLONIA BONFIL','461 242 4585','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CESAR TODO PARA TU CELULAR','AV PRESA ALVARO OBREGON _#432 COLONIA BONFIL','461 265 1247','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALI ROJAS','Herrera rocha, #1778 ,CORTAZAR','411 133 1103','S/R',true,13);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ELIZABETH ROJAS GONZALEZ','Fray servando Teresa de mier ,#303 cortazar	','411 125 7196','S/R',true,13);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CECILIO EMICELL','	Del cipreses #12-A , VALLE DE SANTIAGO','456 112 0318','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'FATIMA MIRANDA','Av. Juarez #217, valle de santiago','456 111 2543','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LUIS ARIAS','AV. Benito juarez ,#218 valle de santiago','456 104 3007','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LILIANA  MURILLO ARROYO	','MANUEL DOBLADO ,#15 VALLE DE SANTIAGO','456 101 3554','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARMEN BRITOS','AV MENA #168, A VALLE DE SANTIAGO','456 129 1615','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MASTER CELL	','MANUEL DOBLADO # 25 VALLE DE SANTIAGO','4561023298','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'KARLA MARTINEZ ','AV MENA #168, A VALLE DE SANTIAGO','456 129 1615','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'LUIS ARIAS','AV. Benito juarez ,#218 valle de santiago','456 104 3007','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARICELA GASCA','AV ARTEAGA #13 VALLE DE SANTIAGO','456 110 8024','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'RUBI SIERRA','AV ARTEAGA #13 VALLE DE SANTIAGO','456 651 2459','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'VIRGINIA VARGAS','AV ARTEAGA # 20 VALLE DE SANTIAGO','456 103 1442','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANGEL GARCIA','VICENTE GERRERO #108 JARAL DEL PROGRESO','456 101 9078','S/R',true,22);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JUNCARLOS LEZAMA','AV MENA #210, A VALLE DE SANTIAGO','456 651 8781','S/R',true,62);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'PAOLA ANDRADE TURBO CELL','IGNACIO COMONDORD ,#101 RINCON DE TAMAYO','461 151 7677','S/R',true,39);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ABRAHAM SALGADO	','AV EL SAUZ #223 COL. VALLE DE LOS NARANGOS CELAYA','461 120 9610','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ABIGAIL','AV JUAN JOSE TORRES LANDA #503 , CELAYA GTO','461 615 5177','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ERIK TADEO','ANTONIO PLAZA #106 CELAYA GTO','461 139 2509','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'AMALIA GONZALEZ	','MARIANO JIMENEZ -#561 , CELAYA GT0','461 112 2609','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'AXEL CONTRERAS','FRANCISCO IMADERO #29 EMPALME ESCOBEDO','412 120 4090','S/R',true,18);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'HORTENCIA ROCHA','AV JUAREZ # 242 GUANAJUATO CAPITAL','473 110 9990','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OFELIA CARRILLO RAMIREZ	','AV JUAREZ #236 GUANAJUATO','473 101 2800','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'MARY ','AV JUAREZ # 117 INT 1 GUANAJUATO','473 652 7330','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANA CAMACHO	','AV JUAREZ ,# 182 GUANAJUATO	','473 122 9149','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ALFREDO FERNANDEZ ','AV JUAREZ #178 GUANAJUATO','473 114 0510','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GONZALO GALVAN ','AV JUAREZ #180  GUANAJUATO','473 597 2442','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GERARDO BARCENAS','CALLE ROBLE #108 COL ARROYO VERDE GUANAJUATO','477 272 5271','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CRISTIAN GASCA','MIGUEL HIDALGO #119 JUVENTINO ROSAS	','412 117 3795','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANTONIO GODINEZ	','CORREGUIDORA #216 JUVENTINO ROSAS','412 187 7632','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSE GUADALUPE MARTINEZ	','NETZAHUALCOYOT #205 JUVENTINO','412 118 3572','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JOSE GERRERO','ADOLFO LOPEZ MATEOS LOCAR 36 MERCADO HIDALGO','412 105 3272','S/R',true,66);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'JAZMIN AGUILAR','ZARAGOZA # 114 JUVENTINO ROSAS','412 122 0886','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'OBDULIA RIOS ','MOLINO DE SANTA ANA #11 IRAPUATO','462 132 0665','S/R',true,21);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'VIRGINIA GONZALES','BARRIO NUEVO 32 MEZQUITE  GODO ROMITA','432 102 7333','S/R',true,40);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'EVELIN	','CALLE MORELOS #431 JUVENTINO ROSAS','412 128 0151','S/R',true,25);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ACCESORIOS MICHELL','CARR. JUVENTINO ROSAS GUANAJUATO LA YERBABUENA GTO,23','473 139 2242','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'GUADALUPE MANCERA','EMILIANO ZAPARA ,# 17 LA NORIA ,TARIMORO GTO','461 112 4064','S/R',true,59);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'CARMEN GERRERO ','GERRERO ,#89 CUPAREO SALVATIERRA GUANAJUATO	','466 103 6307','S/R',true,19);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ERICK RAMIREZ ABONCE','JUAREZ ,# 70, SAN PEDRO DE LOS NARANJOS,','466 115 1818','S/R',true,50);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'AURA JUAREZ	','PASEO DE LOS OLIVOS, #1237 CELAYA GTO','461 287 7484','S/R',true,7);
INSERT INTO cliente(nombre,direccion,telefono,email,activo,ciudad_id) VALUES ( 'ANDREA OJEDA JIMENEZ','GENERAL FRANCISCO VILLA ,#23, EL SABINO SALVATIERRA GTO	','461 679 2020','S/R',true,17);


#Tabla clave_cliente
#Ruta 0
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('001',true,1,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('002',true,2,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('003',true,3,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('004',true,4,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('005',true,5,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('006',true,6,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('007',true,7,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('008',true,8,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('009',true,9,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('010',true,10,1);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('011',true,11,1);

#Ruta 1

INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('001',true,12,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('002',true,13,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('003',true,14,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('004',true,15,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('005',true,16,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('006',true,17,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('007',true,18,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('008',true,19,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('009',true,20,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('010',true,21,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('011',true,22,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('012',true,23,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('013',true,24,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('014',true,25,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('015',true,26,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('016',true,27,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('017',true,28,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('018',true,29,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('019',true,30,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('020',true,31,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('021',true,32,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('022',true,33,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('023',true,34,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('024',true,35,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('025',true,36,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('026',true,37,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('027',true,38,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('028',true,39,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('029',true,40,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('030',true,41,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('031',true,42,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('032',true,43,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('033',true,44,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('034',true,45,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('035',true,46,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('036',true,47,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('037',true,48,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('038',true,49,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('039',true,50,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('040',true,51,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('041',true,52,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('042',true,53,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('043',true,54,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('044',true,55,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('045',true,56,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('046',true,57,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('047',true,58,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('048',true,59,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('049',true,60,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('050',true,61,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('051',true,62,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('052',true,63,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('053',true,64,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('054',true,65,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('055',true,66,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('056',true,67,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('057',true,68,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('058',true,69,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('059',true,70,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('060',true,71,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('061',true,72,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('062',true,73,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('063',true,74,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('064',true,75,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('065',true,76,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('066',true,77,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('067',true,78,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('068',true,79,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('069',true,80,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('070',true,81,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('071',true,82,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('072',true,83,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('073',true,84,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('074',true,85,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('075',true,86,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('076',true,87,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('077',true,88,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('078',true,89,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('079',true,90,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('080',true,91,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('081',true,92,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('082',true,93,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('083',true,94,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('084',true,95,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('085',true,96,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('086',true,97,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('087',true,98,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('088',true,99,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('089',true,100,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('090',true,101,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('091',true,102,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('092',true,103,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('093',true,104,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('094',true,105,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('095',true,106,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('096',true,107,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('097',true,108,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('098',true,109,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('099',true,110,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('100',true,111,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('101',true,112,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('102',true,113,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('103',true,114,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('104',true,115,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('105',true,116,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('106',true,117,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('107',true,118,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('108',true,119,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('109',true,120,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('110',true,121,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('111',true,122,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('112',true,123,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('113',true,124,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('114',true,125,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('115',true,126,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('116',true,127,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('117',true,128,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('118',true,129,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('119',true,130,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('120',true,131,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('121',true,132,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('122',true,133,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('123',true,134,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('124',true,135,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('125',true,136,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('126',true,137,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('127',true,138,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('128',true,139,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('129',true,140,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('130',true,141,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('131',true,142,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('132',true,143,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('133',true,144,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('134',true,145,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('135',true,146,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('136',true,147,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('137',true,148,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('138',true,149,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('139',true,150,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('140',true,151,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('141',true,152,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('142',true,153,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('143',true,154,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('144',true,155,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('145',true,156,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('146',true,157,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('147',true,158,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('148',true,159,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('149',true,160,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('150',true,161,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('151',true,162,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('152',true,163,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('153',true,164,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('154',true,165,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('155',true,166,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('156',true,167,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('157',true,168,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('158',true,169,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('159',true,170,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('160',true,171,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('161',true,172,2);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('162',true,173,2);
#Ruta 2
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
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('089',true,268, 3);
INSERT INTO clave_cliente (numero, activo, cliente_id, puntoVenta_id)  VALUES ('090',true,269, 3);




#Ruta 3
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('001',true,270,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('002',true,271,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('003',true,272,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('004',true,273,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('005',true,274,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('006',true,275,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('007',true,276,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('008',true,277,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('009',true,278,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('010',true,279,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('011',true,280,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('012',true,281,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('-013',true,282,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('014',true,283,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('015',true,284,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('016',true,285,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('017',true,286,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('018',true,287,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('019',true,288,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('020',true,289,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('021',true,290,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('022',true,291,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('023',true,292,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('024',true,293,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('025',true,294,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('026',true,295,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('027',true,296,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('028',true,297,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('029',true,298,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('030',true,299,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('031',true,300,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('032',true,301,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('033',true,302,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('034',true,303,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('035',true,304,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('036',true,305,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('037',true,306,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('038',true,307,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('039',true,308,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('040',true,309,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('041',true,310,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('042',true,311,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('043',true,312,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('044',true,313,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('045',true,314,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('046',true,315,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('047',true,316,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('048',true,317,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('049',true,318,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('050',true,319,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('051',true,320,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('052',true,321,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('053',true,322,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('054',true,323,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('055',true,324,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('056',true,325,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('057',true,326,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('058',true,327,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('059',true,328,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('060',true,329,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('061',true,330,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('062',true,331,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('063',true,332,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('064',true,333,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('065',true,334,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('066',true,335,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('067',true,336,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('068',true,337,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('069',true,338,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('070',true,339,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('071',true,340,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('072',true,341,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('073',true,342,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('074',true,343,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('075',true,344,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('076',true,345,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('077',true,346,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('078',true,347,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('079',true,348,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('080',true,349,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('081',true,350,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('082',true,351,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('083',true,352,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('084',true,353,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('085',true,354,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('086',true,355,4);
INSERT INTO clave_cliente(numero,activo,cliente_id,puntoVenta_id)VALUES('087',true,356,4);

INSERT INTO credito (total, estado, orden_id) VALUES (11197, true, 1);
INSERT INTO credito (total, estado, orden_id) VALUES (15770, true, 2);
INSERT INTO credito (total, estado, orden_id) VALUES (13351, true, 3);
INSERT INTO credito (total, estado, orden_id) VALUES (13567, true, 4);
INSERT INTO credito (total, estado, orden_id) VALUES (2600, true, 5);
INSERT INTO credito (total, estado, orden_id) VALUES (13322, true, 6);
INSERT INTO credito (total, estado, orden_id) VALUES (26882, true, 7);
INSERT INTO credito (total, estado, orden_id) VALUES (26163, true, 8);
INSERT INTO credito (total, estado, orden_id) VALUES (15999, true, 9);
INSERT INTO credito (total, estado, orden_id) VALUES (6513, true, 10);
INSERT INTO credito (total, estado, orden_id) VALUES (8905, true, 11);
INSERT INTO credito (total, estado, orden_id) VALUES (10021, true, 12);
INSERT INTO credito (total, estado, orden_id) VALUES (11288, true, 13);
INSERT INTO credito (total, estado, orden_id) VALUES (19865, true, 14);
INSERT INTO credito (total, estado, orden_id) VALUES (25781, true, 15);
INSERT INTO credito (total, estado, orden_id) VALUES (18039, true, 16);
INSERT INTO credito (total, estado, orden_id) VALUES (7710, true, 17);
INSERT INTO credito (total, estado, orden_id) VALUES (2519, true, 18);
INSERT INTO credito (total, estado, orden_id) VALUES (29267, true, 19);
INSERT INTO credito (total, estado, orden_id) VALUES (27349, true, 20);
INSERT INTO credito (total, estado, orden_id) VALUES (3227, true, 21);
INSERT INTO credito (total, estado, orden_id) VALUES (25045, true, 22);
INSERT INTO credito (total, estado, orden_id) VALUES (23861, true, 23);
INSERT INTO credito (total, estado, orden_id) VALUES (14809, true, 24);
INSERT INTO credito (total, estado, orden_id) VALUES (14293, true, 25);
INSERT INTO credito (total, estado, orden_id) VALUES (16789, true, 26);
INSERT INTO credito (total, estado, orden_id) VALUES (6887, true, 27);
INSERT INTO credito (total, estado, orden_id) VALUES (26156, true, 28);
INSERT INTO credito (total, estado, orden_id) VALUES (3550, true, 29);
INSERT INTO credito (total, estado, orden_id) VALUES (3251, true, 30);
INSERT INTO credito (total, estado, orden_id) VALUES (14116, true, 31);
INSERT INTO credito (total, estado, orden_id) VALUES (26863, true, 32);
INSERT INTO credito (total, estado, orden_id) VALUES (3687, true, 33);
INSERT INTO credito (total, estado, orden_id) VALUES (17131, true, 34);
INSERT INTO credito (total, estado, orden_id) VALUES (30282, true, 35);
INSERT INTO credito (total, estado, orden_id) VALUES (27225, true, 36);
INSERT INTO credito (total, estado, orden_id) VALUES (8405, true, 37);
INSERT INTO credito (total, estado, orden_id) VALUES (19930, true, 38);
INSERT INTO credito (total, estado, orden_id) VALUES (31756, true, 39);
INSERT INTO credito (total, estado, orden_id) VALUES (7585, true, 40);
INSERT INTO credito (total, estado, orden_id) VALUES (4247, true, 41);
INSERT INTO credito (total, estado, orden_id) VALUES (23561, true, 42);
INSERT INTO credito (total, estado, orden_id) VALUES (19047, true, 43);
INSERT INTO credito (total, estado, orden_id) VALUES (5150, true, 44);
INSERT INTO credito (total, estado, orden_id) VALUES (9142, true, 45);
INSERT INTO credito (total, estado, orden_id) VALUES (27943, true, 46);
INSERT INTO credito (total, estado, orden_id) VALUES (11479, true, 47);
INSERT INTO credito (total, estado, orden_id) VALUES (19373, true, 48);
INSERT INTO credito (total, estado, orden_id) VALUES (32685, true, 49);
INSERT INTO credito (total, estado, orden_id) VALUES (29590, true, 50);
INSERT INTO credito (total, estado, orden_id) VALUES (25546, true, 51);
INSERT INTO credito (total, estado, orden_id) VALUES (31827, true, 52);
INSERT INTO credito (total, estado, orden_id) VALUES (20604, true, 53);
INSERT INTO credito (total, estado, orden_id) VALUES (12074, true, 54);
INSERT INTO credito (total, estado, orden_id) VALUES (9301, true, 55);
INSERT INTO credito (total, estado, orden_id) VALUES (26915, true, 56);
INSERT INTO credito (total, estado, orden_id) VALUES (26104, true, 57);
INSERT INTO credito (total, estado, orden_id) VALUES (9517, true, 58);
INSERT INTO credito (total, estado, orden_id) VALUES (16422, true, 59);
INSERT INTO credito (total, estado, orden_id) VALUES (14434, true, 60);
INSERT INTO credito (total, estado, orden_id) VALUES (15205, true, 61);
INSERT INTO credito (total, estado, orden_id) VALUES (22950, true, 62);
INSERT INTO credito (total, estado, orden_id) VALUES (2490, true, 63);
INSERT INTO credito (total, estado, orden_id) VALUES (5866, true, 64);
INSERT INTO credito (total, estado, orden_id) VALUES (7494, true, 65);
INSERT INTO credito (total, estado, orden_id) VALUES (11738, true, 66);
INSERT INTO credito (total, estado, orden_id) VALUES (18640, true, 67);
INSERT INTO credito (total, estado, orden_id) VALUES (10956, true, 68);
INSERT INTO credito (total, estado, orden_id) VALUES (24948, true, 69);
INSERT INTO credito (total, estado, orden_id) VALUES (2068, true, 70);
INSERT INTO credito (total, estado, orden_id) VALUES (21277, true, 71);
INSERT INTO credito (total, estado, orden_id) VALUES (6457, true, 72);
INSERT INTO credito (total, estado, orden_id) VALUES (25966, true, 73);
INSERT INTO credito (total, estado, orden_id) VALUES (10402, true, 74);
INSERT INTO credito (total, estado, orden_id) VALUES (7489, true, 75);
INSERT INTO credito (total, estado, orden_id) VALUES (9123, true, 76);
INSERT INTO credito (total, estado, orden_id) VALUES (18160, true, 77);
INSERT INTO credito (total, estado, orden_id) VALUES (20512, true, 78);
INSERT INTO credito (total, estado, orden_id) VALUES (22522, true, 79);
INSERT INTO credito (total, estado, orden_id) VALUES (8223, true, 80);
INSERT INTO credito (total, estado, orden_id) VALUES (2759, true, 81);
INSERT INTO credito (total, estado, orden_id) VALUES (6905, true, 82);
INSERT INTO credito (total, estado, orden_id) VALUES (28055, true, 83);
INSERT INTO credito (total, estado, orden_id) VALUES (20750, true, 84);
INSERT INTO credito (total, estado, orden_id) VALUES (9699, true, 85);
INSERT INTO credito (total, estado, orden_id) VALUES (13866, true, 86);
INSERT INTO credito (total, estado, orden_id) VALUES (29616, true, 87);
INSERT INTO credito (total, estado, orden_id) VALUES (24572, true, 88);
INSERT INTO credito (total, estado, orden_id) VALUES (7342, true, 89);
INSERT INTO credito (total, estado, orden_id) VALUES (20809, true, 90);
INSERT INTO credito (total, estado, orden_id) VALUES (25877, true, 91);
INSERT INTO credito (total, estado, orden_id) VALUES (32712, true, 92);
INSERT INTO credito (total, estado, orden_id) VALUES (11420, true, 93);
INSERT INTO credito (total, estado, orden_id) VALUES (29126, true, 94);
INSERT INTO credito (total, estado, orden_id) VALUES (14340, true, 95);
INSERT INTO credito (total, estado, orden_id) VALUES (31237, true, 96);
INSERT INTO credito (total, estado, orden_id) VALUES (13315, true, 97);
INSERT INTO credito (total, estado, orden_id) VALUES (2930, true, 98);
INSERT INTO credito (total, estado, orden_id) VALUES (9375, true, 99);
INSERT INTO credito (total, estado, orden_id) VALUES (11169, true, 100);
INSERT INTO credito (total, estado, orden_id) VALUES (19502, true, 101);
INSERT INTO credito (total, estado, orden_id) VALUES (573, true, 102);
INSERT INTO credito (total, estado, orden_id) VALUES (12188, true, 103);
INSERT INTO credito (total, estado, orden_id) VALUES (13508, true, 104);
INSERT INTO credito (total, estado, orden_id) VALUES (18861, true, 105);
INSERT INTO credito (total, estado, orden_id) VALUES (31044, true, 106);
INSERT INTO credito (total, estado, orden_id) VALUES (19775, true, 107);
INSERT INTO credito (total, estado, orden_id) VALUES (24571, true, 108);
INSERT INTO credito (total, estado, orden_id) VALUES (5870, true, 109);
INSERT INTO credito (total, estado, orden_id) VALUES (4875, true, 110);
INSERT INTO credito (total, estado, orden_id) VALUES (12421, true, 111);
INSERT INTO credito (total, estado, orden_id) VALUES (1174, true, 112);
INSERT INTO credito (total, estado, orden_id) VALUES (7442, true, 113);
INSERT INTO credito (total, estado, orden_id) VALUES (1798, true, 114);
INSERT INTO credito (total, estado, orden_id) VALUES (6819, true, 115);
INSERT INTO credito (total, estado, orden_id) VALUES (26703, true, 116);
INSERT INTO credito (total, estado, orden_id) VALUES (12025, true, 117);
INSERT INTO credito (total, estado, orden_id) VALUES (12383, true, 118);
INSERT INTO credito (total, estado, orden_id) VALUES (16046, true, 119);
INSERT INTO credito (total, estado, orden_id) VALUES (25644, true, 120);
INSERT INTO credito (total, estado, orden_id) VALUES (10911, true, 121);
INSERT INTO credito (total, estado, orden_id) VALUES (31219, true, 122);
INSERT INTO credito (total, estado, orden_id) VALUES (3484, true, 123);
INSERT INTO credito (total, estado, orden_id) VALUES (20646, true, 124);
INSERT INTO credito (total, estado, orden_id) VALUES (17580, true, 125);
INSERT INTO credito (total, estado, orden_id) VALUES (19358, true, 126);
INSERT INTO credito (total, estado, orden_id) VALUES (32363, true, 127);
INSERT INTO credito (total, estado, orden_id) VALUES (32010, true, 128);
INSERT INTO credito (total, estado, orden_id) VALUES (12870, true, 129);
INSERT INTO credito (total, estado, orden_id) VALUES (23736, true, 130);
INSERT INTO credito (total, estado, orden_id) VALUES (9888, true, 131);
INSERT INTO credito (total, estado, orden_id) VALUES (13856, true, 132);
INSERT INTO credito (total, estado, orden_id) VALUES (9514, true, 133);
INSERT INTO credito (total, estado, orden_id) VALUES (4063, true, 134);
INSERT INTO credito (total, estado, orden_id) VALUES (14067, true, 135);
INSERT INTO credito (total, estado, orden_id) VALUES (8203, true, 136);
INSERT INTO credito (total, estado, orden_id) VALUES (19963, true, 137);
INSERT INTO credito (total, estado, orden_id) VALUES (15351, true, 138);
INSERT INTO credito (total, estado, orden_id) VALUES (12361, true, 139);
INSERT INTO credito (total, estado, orden_id) VALUES (26480, true, 140);
INSERT INTO credito (total, estado, orden_id) VALUES (22745, true, 141);
INSERT INTO credito (total, estado, orden_id) VALUES (1648, true, 142);
INSERT INTO credito (total, estado, orden_id) VALUES (25826, true, 143);
INSERT INTO credito (total, estado, orden_id) VALUES (3546, true, 144);
INSERT INTO credito (total, estado, orden_id) VALUES (6198, true, 145);
INSERT INTO credito (total, estado, orden_id) VALUES (12999, true, 146);
INSERT INTO credito (total, estado, orden_id) VALUES (6612, true, 147);
INSERT INTO credito (total, estado, orden_id) VALUES (21853, true, 148);
INSERT INTO credito (total, estado, orden_id) VALUES (20965, true, 149);
INSERT INTO credito (total, estado, orden_id) VALUES (2896, true, 150);
INSERT INTO credito (total, estado, orden_id) VALUES (23736, true, 151);
INSERT INTO credito (total, estado, orden_id) VALUES (3962, true, 152);
INSERT INTO credito (total, estado, orden_id) VALUES (25204, true, 153);
INSERT INTO credito (total, estado, orden_id) VALUES (18226, true, 154);
INSERT INTO credito (total, estado, orden_id) VALUES (24995, true, 155);
INSERT INTO credito (total, estado, orden_id) VALUES (21315, true, 156);
INSERT INTO credito (total, estado, orden_id) VALUES (10940, true, 157);
INSERT INTO credito (total, estado, orden_id) VALUES (4531, true, 158);
INSERT INTO credito (total, estado, orden_id) VALUES (32088, true, 159);
INSERT INTO credito (total, estado, orden_id) VALUES (24255, true, 160);
INSERT INTO credito (total, estado, orden_id) VALUES (31670, true, 161);
INSERT INTO credito (total, estado, orden_id) VALUES (5814, true, 162);
INSERT INTO credito (total, estado, orden_id) VALUES (4027, true, 163);
INSERT INTO credito (total, estado, orden_id) VALUES (10128, true, 164);
INSERT INTO credito (total, estado, orden_id) VALUES (29841, true, 165);
INSERT INTO credito (total, estado, orden_id) VALUES (14465, true, 166);
INSERT INTO credito (total, estado, orden_id) VALUES (29321, true, 167);
INSERT INTO credito (total, estado, orden_id) VALUES (24275, true, 168);
INSERT INTO credito (total, estado, orden_id) VALUES (1793, true, 169);
INSERT INTO credito (total, estado, orden_id) VALUES (21188, true, 170);
INSERT INTO credito (total, estado, orden_id) VALUES (16455, true, 171);
INSERT INTO credito (total, estado, orden_id) VALUES (27720, true, 172);
INSERT INTO credito (total, estado, orden_id) VALUES (5593, true, 173);
INSERT INTO credito (total, estado, orden_id) VALUES (11991, true, 174);
INSERT INTO credito (total, estado, orden_id) VALUES (1912, true, 175);
INSERT INTO credito (total, estado, orden_id) VALUES (9395, true, 176);
INSERT INTO credito (total, estado, orden_id) VALUES (25052, true, 177);
INSERT INTO credito (total, estado, orden_id) VALUES (3396, true, 178);
INSERT INTO credito (total, estado, orden_id) VALUES (15891, true, 179);
INSERT INTO credito (total, estado, orden_id) VALUES (16258, true, 180);
INSERT INTO credito (total, estado, orden_id) VALUES (14544, true, 181);
INSERT INTO credito (total, estado, orden_id) VALUES (26757, true, 182);
INSERT INTO credito (total, estado, orden_id) VALUES (2356, true, 183);
INSERT INTO credito (total, estado, orden_id) VALUES (20399, true, 184);
INSERT INTO credito (total, estado, orden_id) VALUES (6869, true, 185);
INSERT INTO credito (total, estado, orden_id) VALUES (21775, true, 186);
INSERT INTO credito (total, estado, orden_id) VALUES (11538, true, 187);
INSERT INTO credito (total, estado, orden_id) VALUES (17384, true, 188);
INSERT INTO credito (total, estado, orden_id) VALUES (18933, true, 189);
INSERT INTO credito (total, estado, orden_id) VALUES (8847, true, 190);
INSERT INTO credito (total, estado, orden_id) VALUES (14641, true, 191);
INSERT INTO credito (total, estado, orden_id) VALUES (12782, true, 192);
INSERT INTO credito (total, estado, orden_id) VALUES (30716, true, 193);
INSERT INTO credito (total, estado, orden_id) VALUES (8819, true, 194);
INSERT INTO credito (total, estado, orden_id) VALUES (17625, true, 195);
INSERT INTO credito (total, estado, orden_id) VALUES (28987, true, 196);
INSERT INTO credito (total, estado, orden_id) VALUES (1674, true, 197);
INSERT INTO credito (total, estado, orden_id) VALUES (14252, true, 198);
INSERT INTO credito (total, estado, orden_id) VALUES (20422, true, 199);
INSERT INTO credito (total, estado, orden_id) VALUES (18663, true, 200);
INSERT INTO credito (total, estado, orden_id) VALUES (3430, true, 201);
INSERT INTO credito (total, estado, orden_id) VALUES (5042, true, 202);
INSERT INTO credito (total, estado, orden_id) VALUES (6945, true, 203);
INSERT INTO credito (total, estado, orden_id) VALUES (13516, true, 204);
INSERT INTO credito (total, estado, orden_id) VALUES (6933, true, 205);
INSERT INTO credito (total, estado, orden_id) VALUES (17609, true, 206);
INSERT INTO credito (total, estado, orden_id) VALUES (3759, true, 207);
INSERT INTO credito (total, estado, orden_id) VALUES (1513, true, 208);
INSERT INTO credito (total, estado, orden_id) VALUES (25516, true, 209);
INSERT INTO credito (total, estado, orden_id) VALUES (31108, true, 210);
INSERT INTO credito (total, estado, orden_id) VALUES (32329, true, 211);
INSERT INTO credito (total, estado, orden_id) VALUES (25092, true, 212);
INSERT INTO credito (total, estado, orden_id) VALUES (20962, true, 213);
INSERT INTO credito (total, estado, orden_id) VALUES (7559, true, 214);
INSERT INTO credito (total, estado, orden_id) VALUES (25484, true, 215);
INSERT INTO credito (total, estado, orden_id) VALUES (26259, true, 216);
INSERT INTO credito (total, estado, orden_id) VALUES (11881, true, 217);
INSERT INTO credito (total, estado, orden_id) VALUES (13200, true, 218);
INSERT INTO credito (total, estado, orden_id) VALUES (24529, true, 219);
INSERT INTO credito (total, estado, orden_id) VALUES (29405, true, 220);
INSERT INTO credito (total, estado, orden_id) VALUES (20863, true, 221);
INSERT INTO credito (total, estado, orden_id) VALUES (4281, true, 222);
INSERT INTO credito (total, estado, orden_id) VALUES (6751, true, 223);
INSERT INTO credito (total, estado, orden_id) VALUES (23901, true, 224);
INSERT INTO credito (total, estado, orden_id) VALUES (4800, true, 225);
INSERT INTO credito (total, estado, orden_id) VALUES (23799, true, 226);
INSERT INTO credito (total, estado, orden_id) VALUES (20192, true, 227);
INSERT INTO credito (total, estado, orden_id) VALUES (6247, true, 228);
INSERT INTO credito (total, estado, orden_id) VALUES (27454, true, 229);
INSERT INTO credito (total, estado, orden_id) VALUES (31975, true, 230);
INSERT INTO credito (total, estado, orden_id) VALUES (8210, true, 231);
INSERT INTO credito (total, estado, orden_id) VALUES (2574, true, 232);
INSERT INTO credito (total, estado, orden_id) VALUES (32211, true, 233);
INSERT INTO credito (total, estado, orden_id) VALUES (18634, true, 234);
INSERT INTO credito (total, estado, orden_id) VALUES (703, true, 235);
INSERT INTO credito (total, estado, orden_id) VALUES (6980, true, 236);
INSERT INTO credito (total, estado, orden_id) VALUES (31158, true, 237);
INSERT INTO credito (total, estado, orden_id) VALUES (13517, true, 238);
INSERT INTO credito (total, estado, orden_id) VALUES (21743, true, 239);
INSERT INTO credito (total, estado, orden_id) VALUES (16963, true, 240);
INSERT INTO credito (total, estado, orden_id) VALUES (2893, true, 241);
INSERT INTO credito (total, estado, orden_id) VALUES (20111, true, 242);
INSERT INTO credito (total, estado, orden_id) VALUES (30044, true, 243);
INSERT INTO credito (total, estado, orden_id) VALUES (3116, true, 244);
INSERT INTO credito (total, estado, orden_id) VALUES (20290, true, 245);
INSERT INTO credito (total, estado, orden_id) VALUES (13277, true, 246);
INSERT INTO credito (total, estado, orden_id) VALUES (28454, true, 247);
INSERT INTO credito (total, estado, orden_id) VALUES (27118, true, 248);
INSERT INTO credito (total, estado, orden_id) VALUES (31705, true, 249);
INSERT INTO credito (total, estado, orden_id) VALUES (26304, true, 250);
INSERT INTO credito (total, estado, orden_id) VALUES (3528, true, 251);
INSERT INTO credito (total, estado, orden_id) VALUES (17514, true, 252);
INSERT INTO credito (total, estado, orden_id) VALUES (13441, true, 253);
INSERT INTO credito (total, estado, orden_id) VALUES (8889, true, 254);
INSERT INTO credito (total, estado, orden_id) VALUES (27979, true, 255);
INSERT INTO credito (total, estado, orden_id) VALUES (7125, true, 256);
INSERT INTO credito (total, estado, orden_id) VALUES (15273, true, 257);
INSERT INTO credito (total, estado, orden_id) VALUES (5963, true, 258);
INSERT INTO credito (total, estado, orden_id) VALUES (23226, true, 259);
INSERT INTO credito (total, estado, orden_id) VALUES (13917, true, 260);
INSERT INTO credito (total, estado, orden_id) VALUES (30420, true, 261);
INSERT INTO credito (total, estado, orden_id) VALUES (11194, true, 262);
INSERT INTO credito (total, estado, orden_id) VALUES (6357, true, 263);
INSERT INTO credito (total, estado, orden_id) VALUES (8719, true, 264);
INSERT INTO credito (total, estado, orden_id) VALUES (30960, true, 265);
INSERT INTO credito (total, estado, orden_id) VALUES (12307, true, 266);
INSERT INTO credito (total, estado, orden_id) VALUES (23817, true, 267);
INSERT INTO credito (total, estado, orden_id) VALUES (3576, true, 268);
INSERT INTO credito (total, estado, orden_id) VALUES (1763, true, 269);
INSERT INTO credito (total, estado, orden_id) VALUES (8044, true, 270);
INSERT INTO credito (total, estado, orden_id) VALUES (6304, true, 271);
INSERT INTO credito (total, estado, orden_id) VALUES (16010, true, 272);
INSERT INTO credito (total, estado, orden_id) VALUES (19048, true, 273);
INSERT INTO credito (total, estado, orden_id) VALUES (22381, true, 274);
INSERT INTO credito (total, estado, orden_id) VALUES (25142, true, 275);
INSERT INTO credito (total, estado, orden_id) VALUES (8514, true, 276);
INSERT INTO credito (total, estado, orden_id) VALUES (10009, true, 277);
INSERT INTO credito (total, estado, orden_id) VALUES (26895, true, 278);
INSERT INTO credito (total, estado, orden_id) VALUES (4972, true, 279);
INSERT INTO credito (total, estado, orden_id) VALUES (17288, true, 280);
INSERT INTO credito (total, estado, orden_id) VALUES (26060, true, 281);
INSERT INTO credito (total, estado, orden_id) VALUES (26276, true, 282);
INSERT INTO credito (total, estado, orden_id) VALUES (28384, true, 283);
INSERT INTO credito (total, estado, orden_id) VALUES (12503, true, 284);
INSERT INTO credito (total, estado, orden_id) VALUES (10787, true, 285);
INSERT INTO credito (total, estado, orden_id) VALUES (21272, true, 286);
INSERT INTO credito (total, estado, orden_id) VALUES (25180, true, 287);
INSERT INTO credito (total, estado, orden_id) VALUES (31773, true, 288);
INSERT INTO credito (total, estado, orden_id) VALUES (26207, true, 289);
INSERT INTO credito (total, estado, orden_id) VALUES (5750, true, 290);
INSERT INTO credito (total, estado, orden_id) VALUES (14669, true, 291);
INSERT INTO credito (total, estado, orden_id) VALUES (30821, true, 292);
INSERT INTO credito (total, estado, orden_id) VALUES (16757, true, 293);
INSERT INTO credito (total, estado, orden_id) VALUES (7085, true, 294);
INSERT INTO credito (total, estado, orden_id) VALUES (21367, true, 295);
INSERT INTO credito (total, estado, orden_id) VALUES (25779, true, 296);
INSERT INTO credito (total, estado, orden_id) VALUES (9060, true, 297);
INSERT INTO credito (total, estado, orden_id) VALUES (31637, true, 298);
INSERT INTO credito (total, estado, orden_id) VALUES (13288, true, 299);

INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (600, now(), 30);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (538, now(), 147);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (981, now(), 76);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (274, now(), 249);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (708, now(), 19);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (841, now(), 288);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (730, now(), 195);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (329, now(), 174);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (406, now(), 140);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (4, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (735, now(), 277);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (479, now(), 54);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (3, now(), 55);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (563, now(), 119);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (275, now(), 105);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (505, now(), 173);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (901, now(), 287);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (238, now(), 121);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (818, now(), 48);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (112, now(), 81);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (722, now(), 200);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (328, now(), 20);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (652, now(), 186);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (928, now(), 30);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (387, now(), 8);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (63, now(), 107);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (861, now(), 196);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (658, now(), 261);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (277, now(), 91);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (126, now(), 34);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (148, now(), 1);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (43, now(), 124);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (275, now(), 16);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (107, now(), 278);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (844, now(), 272);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (291, now(), 298);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (434, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (145, now(), 223);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (478, now(), 39);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (375, now(), 168);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (964, now(), 120);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (503, now(), 249);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (885, now(), 56);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (816, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (181, now(), 126);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (167, now(), 153);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (896, now(), 167);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (705, now(), 73);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (689, now(), 265);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (688, now(), 209);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (875, now(), 125);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (148, now(), 129);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (284, now(), 195);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (900, now(), 163);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (439, now(), 228);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (246, now(), 150);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (96, now(), 252);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (955, now(), 247);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (37, now(), 85);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (262, now(), 22);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (459, now(), 118);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (767, now(), 28);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (711, now(), 108);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (426, now(), 31);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (95, now(), 70);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (165, now(), 219);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (328, now(), 87);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (435, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (856, now(), 161);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (610, now(), 184);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (526, now(), 227);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (604, now(), 138);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (729, now(), 64);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (460, now(), 274);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (919, now(), 278);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (263, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (536, now(), 116);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (645, now(), 59);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (921, now(), 104);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (471, now(), 7);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (661, now(), 287);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (668, now(), 55);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (681, now(), 174);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (767, now(), 158);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (182, now(), 209);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (931, now(), 72);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (101, now(), 250);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (842, now(), 287);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (486, now(), 40);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (394, now(), 184);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (658, now(), 236);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (945, now(), 56);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (586, now(), 52);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (394, now(), 91);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (919, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (56, now(), 4);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (539, now(), 224);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (659, now(), 41);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (783, now(), 34);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (481, now(), 55);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (815, now(), 247);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (694, now(), 97);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (355, now(), 43);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (71, now(), 82);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (743, now(), 179);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (380, now(), 77);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (286, now(), 131);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (156, now(), 192);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (2, now(), 178);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (781, now(), 79);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (463, now(), 112);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (492, now(), 118);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (25, now(), 108);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (314, now(), 285);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (778, now(), 90);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (936, now(), 100);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (985, now(), 38);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (836, now(), 134);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (848, now(), 23);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (196, now(), 133);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (788, now(), 39);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (842, now(), 27);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (130, now(), 67);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (537, now(), 8);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (856, now(), 165);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (215, now(), 91);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (378, now(), 28);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (276, now(), 209);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (167, now(), 188);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (146, now(), 0);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (947, now(), 167);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (285, now(), 296);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (373, now(), 132);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (236, now(), 8);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (668, now(), 113);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (681, now(), 15);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (197, now(), 26);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (917, now(), 292);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (352, now(), 120);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (984, now(), 2);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (205, now(), 74);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (280, now(), 104);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (553, now(), 135);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (767, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (765, now(), 132);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (842, now(), 281);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (864, now(), 293);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (703, now(), 208);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (876, now(), 195);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (647, now(), 186);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (39, now(), 239);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (477, now(), 193);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (155, now(), 201);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (613, now(), 135);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (943, now(), 269);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (952, now(), 72);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (551, now(), 149);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (663, now(), 109);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (10, now(), 193);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (46, now(), 168);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (995, now(), 228);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (35, now(), 100);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (939, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (391, now(), 294);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (140, now(), 284);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (229, now(), 212);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (481, now(), 23);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (792, now(), 233);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (900, now(), 111);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (346, now(), 269);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (32, now(), 31);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (618, now(), 42);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (616, now(), 122);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (461, now(), 6);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (303, now(), 166);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (984, now(), 228);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (786, now(), 116);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (157, now(), 206);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (714, now(), 216);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (805, now(), 44);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (191, now(), 39);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (781, now(), 110);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (882, now(), 234);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (395, now(), 90);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (817, now(), 226);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (171, now(), 248);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (273, now(), 190);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (717, now(), 194);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (334, now(), 45);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (713, now(), 176);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (887, now(), 17);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (478, now(), 48);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (48, now(), 55);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (887, now(), 162);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (263, now(), 216);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (192, now(), 74);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (875, now(), 223);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (511, now(), 17);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (194, now(), 236);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (310, now(), 84);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (275, now(), 64);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (552, now(), 274);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (691, now(), 2);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (778, now(), 46);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (91, now(), 154);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (796, now(), 142);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (977, now(), 148);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (912, now(), 262);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (142, now(), 162);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (474, now(), 40);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (25, now(), 5);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (56, now(), 26);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (882, now(), 150);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (268, now(), 112);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (737, now(), 101);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (352, now(), 28);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (624, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (362, now(), 127);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (374, now(), 59);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (280, now(), 38);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (254, now(), 8);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (261, now(), 140);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (927, now(), 165);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (997, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (341, now(), 1);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (877, now(), 256);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (504, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (926, now(), 142);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (723, now(), 186);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (308, now(), 19);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (128, now(), 200);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (58, now(), 165);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (898, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (345, now(), 94);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (10, now(), 188);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (568, now(), 72);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (871, now(), 184);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (301, now(), 219);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (688, now(), 277);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (701, now(), 14);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (203, now(), 28);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (161, now(), 43);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (572, now(), 267);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (890, now(), 221);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (518, now(), 120);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (294, now(), 143);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (813, now(), 211);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (59, now(), 231);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (111, now(), 90);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (884, now(), 179);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (888, now(), 55);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (938, now(), 146);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (973, now(), 214);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (52, now(), 102);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (740, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (250, now(), 224);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (202, now(), 147);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (334, now(), 40);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (164, now(), 298);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (756, now(), 292);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (443, now(), 292);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (995, now(), 263);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (145, now(), 12);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (476, now(), 191);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (961, now(), 56);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (75, now(), 294);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (590, now(), 126);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (477, now(), 87);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (42, now(), 114);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (217, now(), 293);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (699, now(), 293);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (889, now(), 276);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (257, now(), 186);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (971, now(), 32);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (50, now(), 179);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (658, now(), 10);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (49, now(), 230);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (123, now(), 40);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (237, now(), 220);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (685, now(), 4);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (358, now(), 45);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (352, now(), 164);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (838, now(), 106);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (833, now(), 48);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (541, now(), 220);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (213, now(), 140);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (477, now(), 298);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (661, now(), 208);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (575, now(), 88);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (896, now(), 50);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (598, now(), 96);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (455, now(), 295);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (410, now(), 245);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (29, now(), 76);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (800, now(), 87);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (621, now(), 158);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (736, now(), 230);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (553, now(), 292);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (878, now(), 203);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (376, now(), 80);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (846, now(), 55);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (95, now(), 4);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (122, now(), 93);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (627, now(), 290);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (974, now(), 22);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (270, now(), 34);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (6, now(), 142);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (793, now(), 59);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (46, now(), 206);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (937, now(), 121);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (681, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (709, now(), 102);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (902, now(), 135);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (926, now(), 190);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (864, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (31, now(), 123);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (621, now(), 64);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (792, now(), 56);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (978, now(), 103);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (110, now(), 117);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (557, now(), 204);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (661, now(), 172);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (307, now(), 81);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (880, now(), 11);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (155, now(), 166);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (16, now(), 34);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (26, now(), 289);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (932, now(), 14);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (184, now(), 108);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (896, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (475, now(), 23);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (985, now(), 85);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (906, now(), 43);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (639, now(), 77);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (989, now(), 220);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (452, now(), 250);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (108, now(), 242);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (44, now(), 29);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (365, now(), 209);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (646, now(), 186);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (690, now(), 195);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (770, now(), 156);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (42, now(), 244);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (763, now(), 265);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (822, now(), 245);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (991, now(), 17);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (991, now(), 10);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (444, now(), 199);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (494, now(), 40);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (381, now(), 229);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (932, now(), 7);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (21, now(), 140);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (627, now(), 227);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (36, now(), 248);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (644, now(), 262);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (576, now(), 249);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (51, now(), 221);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (414, now(), 134);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (72, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (465, now(), 56);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (344, now(), 265);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (146, now(), 131);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (291, now(), 206);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (408, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (159, now(), 259);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (402, now(), 150);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (413, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (747, now(), 299);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (330, now(), 69);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (660, now(), 182);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (441, now(), 111);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (417, now(), 22);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (86, now(), 290);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (37, now(), 164);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (758, now(), 123);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (327, now(), 49);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (654, now(), 74);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (473, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (857, now(), 203);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (134, now(), 288);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (358, now(), 187);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (493, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (641, now(), 231);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (43, now(), 239);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (113, now(), 102);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (813, now(), 29);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (346, now(), 297);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (934, now(), 295);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (628, now(), 232);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (598, now(), 51);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (107, now(), 251);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (660, now(), 299);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (408, now(), 262);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (957, now(), 256);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (464, now(), 192);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (902, now(), 204);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (996, now(), 2);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (86, now(), 281);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (657, now(), 175);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (583, now(), 165);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (392, now(), 275);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (103, now(), 35);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (625, now(), 64);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (154, now(), 284);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (187, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (770, now(), 213);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (191, now(), 25);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (33, now(), 190);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (246, now(), 106);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (222, now(), 156);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (488, now(), 203);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (15, now(), 219);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (727, now(), 130);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (22, now(), 159);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (563, now(), 142);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (599, now(), 72);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (727, now(), 160);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (705, now(), 256);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (532, now(), 128);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (195, now(), 263);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (493, now(), 202);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (792, now(), 13);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (682, now(), 222);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (574, now(), 71);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (953, now(), 5);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (836, now(), 215);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (905, now(), 166);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (802, now(), 273);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (889, now(), 120);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (13, now(), 110);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (833, now(), 144);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (579, now(), 89);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (967, now(), 112);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (739, now(), 122);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (997, now(), 237);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (593, now(), 70);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (24, now(), 226);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (617, now(), 24);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (316, now(), 159);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (898, now(), 81);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (831, now(), 177);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (702, now(), 103);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (523, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (382, now(), 3);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (32, now(), 207);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (714, now(), 96);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (2, now(), 260);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (802, now(), 202);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (334, now(), 113);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (735, now(), 147);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (938, now(), 246);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (749, now(), 41);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (174, now(), 184);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (837, now(), 132);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (198, now(), 214);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (414, now(), 57);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (633, now(), 256);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (436, now(), 206);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (215, now(), 167);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (364, now(), 104);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (926, now(), 213);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (886, now(), 59);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (205, now(), 80);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (36, now(), 97);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (805, now(), 257);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (90, now(), 54);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (717, now(), 245);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (551, now(), 98);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (86, now(), 7);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (915, now(), 32);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (726, now(), 111);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (785, now(), 293);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (560, now(), 103);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (991, now(), 52);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (219, now(), 285);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (147, now(), 136);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (554, now(), 44);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (465, now(), 119);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (644, now(), 254);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (610, now(), 218);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (109, now(), 293);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (847, now(), 76);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (685, now(), 60);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (142, now(), 135);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (815, now(), 181);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (956, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (669, now(), 272);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (468, now(), 183);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (258, now(), 158);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (31, now(), 248);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (608, now(), 215);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (924, now(), 284);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (115, now(), 229);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (26, now(), 70);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (886, now(), 43);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (108, now(), 35);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (348, now(), 193);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (988, now(), 160);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (330, now(), 188);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (227, now(), 67);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (171, now(), 8);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (775, now(), 257);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (396, now(), 23);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (942, now(), 15);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (897, now(), 253);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (555, now(), 178);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (751, now(), 174);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (375, now(), 263);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (723, now(), 280);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (785, now(), 258);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (563, now(), 274);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (137, now(), 218);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (916, now(), 181);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (601, now(), 230);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (740, now(), 60);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (997, now(), 39);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (409, now(), 13);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (525, now(), 98);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (801, now(), 261);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (944, now(), 99);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (787, now(), 36);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (507, now(), 74);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (150, now(), 215);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (971, now(), 249);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (777, now(), 1);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (367, now(), 266);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (907, now(), 45);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (562, now(), 95);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (348, now(), 296);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (183, now(), 255);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (531, now(), 282);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (437, now(), 26);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (1, now(), 71);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (765, now(), 167);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (149, now(), 150);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (2, now(), 117);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (994, now(), 210);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (473, now(), 241);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (607, now(), 87);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (977, now(), 47);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (589, now(), 76);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (36, now(), 295);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (214, now(), 290);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (574, now(), 256);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (699, now(), 203);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (406, now(), 13);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (223, now(), 24);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (322, now(), 260);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (867, now(), 216);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (232, now(), 285);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (73, now(), 162);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (899, now(), 236);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (261, now(), 232);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (907, now(), 234);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (56, now(), 185);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (376, now(), 219);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (919, now(), 144);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (463, now(), 219);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (380, now(), 147);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (318, now(), 119);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (707, now(), 118);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (45, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (864, now(), 95);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (917, now(), 274);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (375, now(), 226);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (534, now(), 83);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (500, now(), 101);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (444, now(), 157);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (316, now(), 110);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (209, now(), 49);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (963, now(), 68);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (249, now(), 263);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (47, now(), 235);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (729, now(), 261);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (133, now(), 222);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (33, now(), 131);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (323, now(), 277);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (820, now(), 282);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (870, now(), 7);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (510, now(), 222);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (413, now(), 242);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (454, now(), 137);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (189, now(), 274);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (4, now(), 107);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (103, now(), 240);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (884, now(), 163);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (159, now(), 99);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (627, now(), 67);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (397, now(), 259);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (785, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (801, now(), 223);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (912, now(), 1);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (715, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (325, now(), 176);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (257, now(), 76);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (716, now(), 26);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (13, now(), 84);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (648, now(), 72);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (502, now(), 294);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (668, now(), 174);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (14, now(), 70);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (843, now(), 126);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (307, now(), 111);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (103, now(), 278);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (146, now(), 148);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (760, now(), 140);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (777, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (475, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (499, now(), 231);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (789, now(), 72);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (570, now(), 86);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (336, now(), 134);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (959, now(), 96);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (414, now(), 251);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (166, now(), 278);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (315, now(), 143);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (889, now(), 35);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (176, now(), 109);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (905, now(), 276);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (60, now(), 176);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (916, now(), 224);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (654, now(), 242);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (51, now(), 104);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (729, now(), 252);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (507, now(), 297);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (623, now(), 10);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (487, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (33, now(), 185);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (484, now(), 206);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (989, now(), 154);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (669, now(), 107);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (154, now(), 24);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (320, now(), 157);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (608, now(), 185);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (48, now(), 98);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (371, now(), 33);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (316, now(), 158);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (874, now(), 128);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (216, now(), 118);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (243, now(), 221);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (787, now(), 279);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (873, now(), 239);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (521, now(), 151);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (192, now(), 251);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (266, now(), 197);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (720, now(), 69);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (403, now(), 104);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (808, now(), 291);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (43, now(), 10);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (973, now(), 108);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (128, now(), 21);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (932, now(), 118);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (867, now(), 241);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (4, now(), 75);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (161, now(), 31);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (304, now(), 96);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (603, now(), 145);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (691, now(), 218);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (17, now(), 59);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (220, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (971, now(), 270);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (357, now(), 165);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (824, now(), 260);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (534, now(), 212);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (850, now(), 23);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (47, now(), 13);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (441, now(), 24);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (430, now(), 26);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (839, now(), 254);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (966, now(), 142);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (140, now(), 271);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (297, now(), 288);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (436, now(), 251);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (710, now(), 187);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (613, now(), 212);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (318, now(), 17);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (477, now(), 181);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (60, now(), 53);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (452, now(), 34);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (772, now(), 182);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (141, now(), 207);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (14, now(), 245);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (811, now(), 89);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (578, now(), 181);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (186, now(), 25);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (389, now(), 93);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (475, now(), 66);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (325, now(), 277);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (444, now(), 169);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (898, now(), 63);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (855, now(), 78);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (710, now(), 197);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (578, now(), 238);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (166, now(), 58);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (943, now(), 291);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (57, now(), 293);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (837, now(), 200);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (160, now(), 222);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (662, now(), 234);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (343, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (378, now(), 110);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (780, now(), 145);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (853, now(), 279);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (749, now(), 100);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (772, now(), 226);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (398, now(), 105);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (582, now(), 92);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (643, now(), 220);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (816, now(), 169);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (347, now(), 15);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (481, now(), 299);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (646, now(), 129);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (840, now(), 120);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (720, now(), 51);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (250, now(), 248);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (254, now(), 34);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (265, now(), 8);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (280, now(), 53);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (257, now(), 83);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (24, now(), 156);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (13, now(), 171);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (227, now(), 289);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (465, now(), 132);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (853, now(), 98);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (721, now(), 253);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (450, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (618, now(), 294);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (586, now(), 239);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (431, now(), 108);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (28, now(), 205);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (432, now(), 122);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (558, now(), 287);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (982, now(), 249);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (212, now(), 53);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (809, now(), 247);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (559, now(), 242);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (509, now(), 237);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (344, now(), 64);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (778, now(), 236);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (638, now(), 4);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (964, now(), 27);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (500, now(), 45);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (739, now(), 47);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (486, now(), 198);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (947, now(), 24);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (597, now(), 210);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (662, now(), 286);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (296, now(), 264);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (576, now(), 207);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (998, now(), 193);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (156, now(), 213);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (90, now(), 176);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (750, now(), 141);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (46, now(), 160);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (624, now(), 253);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (83, now(), 38);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (736, now(), 180);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (624, now(), 283);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (826, now(), 204);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (905, now(), 274);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (866, now(), 48);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (578, now(), 1);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (693, now(), 170);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (836, now(), 28);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (81, now(), 247);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (6, now(), 198);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (314, now(), 257);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (72, now(), 280);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (974, now(), 294);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (109, now(), 252);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (939, now(), 99);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (231, now(), 226);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (911, now(), 13);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (895, now(), 93);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (929, now(), 43);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (732, now(), 268);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (422, now(), 80);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (299, now(), 90);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (646, now(), 243);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (961, now(), 7);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (208, now(), 85);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (478, now(), 39);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (899, now(), 29);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (290, now(), 229);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (407, now(), 19);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (108, now(), 189);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (259, now(), 125);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (216, now(), 294);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (576, now(), 25);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (488, now(), 35);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (926, now(), 113);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (343, now(), 71);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (758, now(), 203);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (194, now(), 270);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (703, now(), 73);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (856, now(), 121);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (189, now(), 192);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (59, now(), 129);
INSERT INTO bono_credito (cantidad, fecha, credito_id) VALUES (823, now(), 279);

INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100001/2017','2017-06-19',1,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100002/2017','2017-06-19',2,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100003/2017','2017-06-19',3,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100004/2017','2017-06-19',4,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100005/2017','2017-06-19',5,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100006/2017','2017-06-19',6,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100007/2017','2017-06-19',7,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100008/2017','2017-06-19',8,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100009/2017','2017-06-19',9,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100010/2017','2017-06-19',10,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100011/2017','2017-06-19',11,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100012/2017','2017-06-19',12,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100013/2017','2017-06-19',13,1);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100014/2017','2017-06-19',14,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100015/2017','2017-06-19',15,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100016/2017','2017-06-19',16,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100017/2017','2017-06-19',17,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100018/2017','2017-06-19',18,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100019/2017','2017-06-19',19,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100020/2017','2017-06-19',20,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100021/2017','2017-06-19',21,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100022/2017','2017-06-19',22,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100023/2017','2017-06-19',23,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100024/2017','2017-06-19',24,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100025/2017','2017-06-19',25,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100026/2017','2017-06-19',26,2);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100027/2017','2017-06-19',27,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100028/2017','2017-06-19',28,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100029/2017','2017-06-19',29,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100030/2017','2017-06-19',30,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100031/2017','2017-06-19',31,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100032/2017','2017-06-19',32,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100033/2017','2017-06-19',33,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100034/2017','2017-06-19',34,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100035/2017','2017-06-19',35,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100036/2017','2017-06-19',36,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100037/2017','2017-06-19',37,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100038/2017','2017-06-19',38,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100039/2017','2017-06-19',39,3);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100040/2017','2017-06-19',40,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100041/2017','2017-06-19',41,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100042/2017','2017-06-19',42,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100043/2017','2017-06-19',43,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100044/2017','2017-06-19',44,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100045/2017','2017-06-19',45,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100046/2017','2017-06-19',46,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100047/2017','2017-06-19',47,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100048/2017','2017-06-19',48,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100049/2017','2017-06-19',49,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100050/2017','2017-06-19',50,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100051/2017','2017-06-19',51,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100052/2017','2017-06-19',52,4);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100053/2017','2017-06-19',53,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100054/2017','2017-06-19',54,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100055/2017','2017-06-19',55,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100056/2017','2017-06-19',56,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100057/2017','2017-06-19',57,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100058/2017','2017-06-19',58,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100059/2017','2017-06-19',59,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100060/2017','2017-06-19',60,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100061/2017','2017-06-19',61,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100062/2017','2017-06-19',62,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100063/2017','2017-06-19',63,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100064/2017','2017-06-19',64,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100065/2017','2017-06-19',65,5);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100066/2017','2017-06-19',66,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100067/2017','2017-06-19',67,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100068/2017','2017-06-19',68,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100069/2017','2017-06-19',69,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100070/2017','2017-06-19',70,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100071/2017','2017-06-19',71,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100072/2017','2017-06-19',72,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100073/2017','2017-06-19',73,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100074/2017','2017-06-19',74,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100075/2017','2017-06-19',75,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100076/2017','2017-06-19',76,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100077/2017','2017-06-19',77,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100078/2017','2017-06-19',78,6);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100079/2017','2017-06-19',79,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100080/2017','2017-06-19',80,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100081/2017','2017-06-19',81,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100082/2017','2017-06-19',82,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100083/2017','2017-06-19',83,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100084/2017','2017-06-19',84,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100085/2017','2017-06-19',85,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100086/2017','2017-06-19',86,7);
INSERT INTO orden(folio,fecha,cliente_id,puntoVenta_id)VALUES
('100087/2017','2017-06-19',87,7);

-- orden descripcion
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,20,'20.00','20.00',1,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,10,'20.00','20.00',1,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,1,'500.00','500.00',2,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,15,'20.00','20.00',3,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,10,'20.00','20.00',4,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,10,'20.00','20.00',4,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,1,'0.0','0.0',5,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(8,10,'20.00','20.00',6,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(9,30,'20.00','15.00',7,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(10,1,'500.00','500.00',8,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(11,15,'20.00','20.00',9,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(12,1,'200.00','200.00',10,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(13,20,'20.00','20.00',11,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(14,10,'20.00','20.00',12,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(15,50,'20.00','15.00',13,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(16,20,'20.00','20.00',14,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(17,30,'20.00','20.00',14,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(18,50,'20.00','20.00',15,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,50,'20.00','18.00',16,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,1,'500.00','500.00',16,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,20,'20.00','20.00',17,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,20,'20.00','20.00',17,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,1,'500.00','500.00',18,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,30,'20.00','20.00',18,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,20,'20.00','20.00',19,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(8,20,'20.00','20.00',19,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(9,100,'20.00','18.00',20,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(10,10,'300.00','300.00',21,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(11,10,'400.00','400.00',21,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(12,20,'20.00','20.00',21,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(13,20,'20.00','20.00',22,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(14,20,'20.00','20.00',22,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(15,2,'500.00','500.00',23,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(16,30,'20.00','20.00',23,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(17,10,'20.00','20.00',24,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(18,10,'20.00','20.00',24,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,5,'300.00','300.00',25,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,5,'400.00','400.00',25,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,25,'20.00','20.00',26,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,25,'20.00','20.00',26,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,20,'20.00','20.00',27,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,20,'20.00','20.00',27,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,1,'300.00','300.00',27,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(8,30,'20.00','20.00',28,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(9,30,'20.00','20.00',29,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(10,5,'300.00','300.00',30,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(11,20,'20.00','20.00',30,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(12,20,'20.00','20.00',31,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(13,20,'20.00','20.00',32,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(14,10,'20.00','20.00',32,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(15,10,'20.00','20.00',33,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(16,25,'20.00','20.00',34,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(17,10,'20.00','20.00',35,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(18,1,'500.00','500.00',35,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,30,'20.00','20.00',36,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,50,'20.00','15.00',37,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,50,'20.00','18.00',38,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,1,'800.00','800.00',39,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,20,'20.00','20.00',40,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,10,'20.00','20.00',41,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,10,'20.00','20.00',41,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(8,1,'500.00','500.00',42,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(9,20,'20.00','20.00',43,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(10,20,'20.00','20.00',43,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(11,30,'20.00','20.00',44,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(12,10,'20.00','20.00',45,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(13,10,'20.00','20.00',46,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(14,10,'20.00','20.00',46,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(15,1,'300.00','300.00',47,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(16,10,'20.00','20.00',47,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(17,20,'20.00','20.00',48,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(18,20,'20.00','20.00',48,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,10,'20.00','20.00',49,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,20,'20.00','20.00',50,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,30,'20.00','20.00',51,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,20,'20.00','20.00',52,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,20,'20.00','20.00',52,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,1,'500.00','500.00',53,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,5,'300.00','300.00',53,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(8,50,'20.00','18.00',54,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(9,20,'20.00','20.00',55,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(10,20,'20.00','20.00',55,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(11,15,'20.00','20.00',56,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(12,30,'20.00','18.00',56,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(13,5,'500.00','500.00',57,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(14,15,'20.00','20.00',58,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(15,15,'20.00','20.00',58,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(16,30,'20.00','18.00',59,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(17,30,'20.00','18.00',59,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(18,1,'1000.00','1000.00',60,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,20,'20.00','20.00',61,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,20,'20.00','20.00',61,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,10,'20.00','20.00',62,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,10,'20.00','20.00',62,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,1,'800.00','800.00',63,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,20,'20.00','15.00',64,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,10,'20.00','20.00',65,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(8,25,'20.00','20.00',65,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,1,'0.00','0.00',66,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,1,'100.00','100.00',67,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,1,'100.00','100.00',68,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,1,'4000.00','4000.00',69,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,1,'20.00','0.00',69,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,1,'300.00','300.00',70,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,1,'50.00','50.00',71,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,1,'0.00','0.00',72,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,1,'1500.00','1500.00',73,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,1,'20.00','0.00',73,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,1,'50.00','50.00',74,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,1,'100.00','100.00',75,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,1,'300.00','300.00',76,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,1,'100.00','100.00',77,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,1,'100.00','100.00',78,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,1,'4500.00','4500.00',79,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,1,'20.00','0.00',79,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,1,'80.00','80.00',80,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,1,'50.00','50.00',81,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,1,'0.00','0.00',82,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,1,'100.00','100.00',83,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(1,1,'6500.00','6500.00',84,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(2,1,'20.00','0.00',84,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(3,1,'50.00','50.00',85,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(4,1,'50.00','50.00',85,2);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(5,1,'80.00','80.00',86,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(6,1,'2500.00','2500.00',87,1);
INSERT INTO orden_descripcion(tipoVentaId,cantidad,precio_sugerido,precio_final,orden_id,requerimiento_id)VALUES
(7,1,'20.00','0.00',87,1);
-- orden completa
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,1);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','500.00',true,2);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','300.00',true,3);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,4);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','0.00',true,5);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','200.00',true,6);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','450.00',true,7);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','500.00',true,8);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','300.00',true,9);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','200.00',true,10);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,11);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','200.00',true,12);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','750.00',true,13);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1000.00',true,14);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1000.00',true,15);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1400.00',true,16);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,17);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1100.00',true,18);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,19);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1800.00',true,20);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','7400.00',true,21);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,22);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1600.00',true,23);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,24);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','3500.00',true,25);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1000.00',true,26);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1100.00',true,27);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,28);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,29);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1900.00',true,30);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,31);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,32);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','200.00',true,33);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','500.00',true,34);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','700.00',true,35);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,36);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','750.00',true,37);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','900.00',true,38);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,39);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,40);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,41);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','500.00',true,42);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,43);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,44);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','200.00',true,45);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,46);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','500.00',true,47);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,48);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','200.00',true,49);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,50);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,51);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,52);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','2000.00',true,53);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','900.00',true,54);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,55);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','840.00',true,56);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','2500.00',true,57);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','600.00',true,58);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1080.00',true,59);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1000.00',true,60);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,61);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','400.00',true,62);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,63);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','300.00',true,64);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','700.00',true,65);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','0.00',true,66);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,67);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,68);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','4000.00',true,69);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','300.00',true,70);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','50.00',true,71);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','0.00',true,72);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','1500.00',true,73);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','50.00',true,74);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,75);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','300.00',true,76);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,77);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,78);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','4500.00',true,79);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','800.00',true,80);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','50.00',true,81);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','0.00',true,82);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,83);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','6500.00',true,84);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','100.00',true,85);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','80.00',true,86);
INSERT INTO orden_completa(fecha,total,estado,orden_id)VALUES
('2016-06-19','2500.00',true,87);

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