use ventas;

INSERT INTO punto_venta (tipo, activo) VALUES ('R0', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R1', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R2', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('R3', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Oficina', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Local Juárez', true);
INSERT INTO punto_venta (tipo, activo) VALUES ('Local Zaragoza', true);

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

































