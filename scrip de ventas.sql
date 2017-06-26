use atc;
-- seleccionar todas las regiones activas
SELECT id,tipo 
FROM region
WHERE activo=true;

-- insertar registro en lada
INSERT INTO lada(tipo,activo,regio_id)VALUES
('466',true,1);

-- seleccionar todas las ladas activas
SELECT la.id,la.tipo,re.nombre
FROM lada la,regio re
WHERE la.region_id=re.id
AND la.activo=true;

-- verifica si la lada ya existe en la base de datos
SELECT tipo
FROM lada
WHERE tipo='466'
and region_id=1;

-- actualiza los datos de una lada
UPDATE lada
SET tipo='466'
WHERE id=1;

-- insertar una nueva region
INSERT INTO region(nombre,activo)VALUES
('Region 5',true);

-- seleccionar todas las regiones activas
SELECT id,nombre
FROM region
WHERE activo=true;

-- actualizar region
UPDATE region
SET nombre='REGION 5'
WHERE id=1;

-- seleccionar todas las ladas activas
SELECT id,tipo
FROM lada
WHERE activo=true;

-- seleccionar todas las ciudades activas
SELECT c.id,c.nombre,la.tipo
FROM ciudad c,lada la
WHERE c.lada_id=la.id
AND c.activo=true;

-- insertar un nuevo registro en ciudad
INSERT INTO ciudad(nombre,activo,lada_id)VALUES
('Celaya',true,1);

-- actualizar un registro en ciudad
UPDATE ciudad
SET nombre='Celaya 2'
WHERE id=1;

-- Verificar que no exista un registro en ciudad antes de insertar
SELECT nombre
FROM ciudad
WHERE nombre='Celaya 2'
and lada_id=1;

-- actualizar los datos de un cliente
UPDATE cliente
SET nombre=´jesus´
direccion=´juarez´,´telefono´=´466´
email=´ta@ho.com´ ativo=TRUE
ciudad_id=2
WHERE id=1;

-- llena el list view con los clientes activos
SELECT cli.id, cli.nombre, cli.direccion, cli.telefono, cli.email, ciu.nombre, cla.numero, pv.tipo
FROM cliente cli, ciudad cui, clave_cliente cla, punto_venta pv
WHERE cli.id=cla.cliente_id
AND cla.puntoVenta_id=pv.id
AND cli.ciudad_id = ciu.id
AND cli.activo=true;

-- llena todas las claves de los clientes
SELECT id, numero
FROM clave_cliente
WHERE activo=TRUE;

-- llena todos los articulos
SELECT id, nombre
FROM tipo_articulo
WHERE activos=true;

-- inseta un nuevo preio cliente
INSERT INTO precio_cliente(precio, claveCliente_id, tipoArticulo_id)
VALUES(´20.00´,1,1);

-- actualiza el precio de cliente
UPDATE precio_cliente
SET precio = ´18.00´
WHERE id=1;

-- muestra todos los precios de articulos por cliene 
SELECT pc.id, cla.numero, cli.nombre, ta.nombre, pc.precio
FROM precio_cliente pc, clave_cliente cla, cliente eli, tipo_ariculo ta
WHERE pc.claveCliente_id=cla.id
AND cla.cliente_id=cli.id
AND pc.tipoArticulo_id=ta.id
AND cli.activo=TRUE
AND ta.activo=TRUE;

-- verifica que el precio no se repita 
SELECT pc.precio
FROM prcio_cliente pc, clave_cliente cla, cliente eli, tipo_articulo ta
WHERE pc.claveCliente_id=cla.id
AND cla.id=1
AND pc.tipoArticulo_id=ta.id
AND ta.id=1
AND pc.precio=´20.00´;

-- muestra todos los servivios ventas activos en un list view
SELECT id, nombre, precio
FROM sevicio_venta
WHERE activo=TRUE;

-- registra un nuevo servicio de venta
INSERT INTO servivio_venta(nombre, precio,activo)
VALUES (´portabilidad´, ´0.00´, TRUE);

-- actualiza un servicio
UPDATE servicio_venta
SET nombre=´porta´,precio = ´50.0´
WHERE id=1;

-- compruba si ya exite un registro para que no lo capture
SELECT nombre
FROM servicio_venta
WHERE nombre=´porta´;

-- llena un list view con los creditos de una cierta orden
SELECT c.id, cl.numero, cli.nombre, o.folio, o.fecha, c.total
FROM credito  c, clave_cliente cl, cliente cli, orden o
WHERE c.orden_id = o.id
AND o.cliente_id = cli.id
AND cl.Cliente_id = cl.id
AND o.folio = ´1234/2017´
-- AND cl.numero = ´R3-001´
AND c.estado = TRUE;

-- inserta un abono credito
INSERT INTO bono_credito(cantidad, credito_id)
VALUES (´200´,1);

-- Actualiza el total de la tabla credito
UPDATE credito 
SET tota = 200
WHERE id=1;

-- Actualiza el campo activo cuando el credito se termina
UPDATE credito
SET activo=FALSE
WHERE id=1;

-- Muestra los abono en un list view
SELECT c.id, cl.numero, cli.nombre, o.folio, o.fecha, c.total, bc.cantidad, bc.fecha
FROM credito  c, clave_cliente cl, cliente cli, orden o, bono_credito bc
WHERE c.orden_id = o.id
AND o.cliente_id = cli.id
AND cl.Cliente_id = cli.id
AND bc.credito_id = c.id
AND o.folio = 1
AND c.estado = TRUE;

-- Inserta un nuevo rango
INSERT INTO(minimo, maximo, comision_activo)
VALUES(5,50,50,TRUE);

-- lena un list view con los rangos activos
SELECT id, minimo, maximo, comision
FROM rango
WHERE activo = TRUE;

-- Verfifica que no exita un rango
SELECT id
FROM rango
WHERE minimo = 5
AND minimo = 10
AND comision = 50;

-- Inserta en la tabla orden
INSERT INTO(folio, fecha , cliente_id, puntoVenta_id)
VALUES(´123/1192´,NOW(),1,1);

-- inserta en la oden descripcion
INSERT INTO order_descripcion(cantidad, precio_sugerido, precio_final, orden_id, requerimiento_id)
VALUES(20,200,200,1,1);

-- inserta en la orden_completa
INSERT INTO orden_completa(fecha, total, estado, order_id)
VALUES(NOW(), 300, TRUE,1);

-- para opener el precio sugerido por articulo
SELECT precio
FROM articulo
WHERE tipoArticulo_id=1
AND modelo_id=1;

-- muestra los detalles de una orden
SELECT o.id, ta.nombre, ma.nombre, mo.nombre, co.nombre, od.cantidad, od.precio_sugerido, od.precio_final, o.fecha
 FROM orden o, punto_venta pv, requerimiento r, tipo_articulo ta,
 marca ma, modelo mo, color co, cantidad ca, orden_descripcio od, cantidad_requerimiento canr, articulo art
 WHERE od.orden_id=o.id
 AND r.id=od.requerimiento_id
 AND canr.requerimiento_id=r.id
 AND canr.cantidad_id=ca.id
 AND ca.color_id=co.id
 AND ca.articulo_id=art.id
 AND a.tipoArt_id=ta.id
 AND o.puntoVenta_id=pv.id
 AND a.modelo_id=mo.id
 AND mo.marca_id=ma.id
 AND o.folio='';
 #el codigo de arriba y abajo es el corazon de reportes, graficas y busquedas
 
 -- saca todos los servicios de una orden en especifico
 SELECT o.id, sv.nombre, od.cantidad, od.precio_sugerido, od.precio_final, o.fecha
 FROM orden o, servicio_venta sv, orden_descripcion od, requerimiento r, servicio_requerimiento sr
 WHERE o.id =od.orden_id
 AND od.requerimiento_id=r.id
 AND sr.requerimiento_id=r.id
 AND sr.servivio_venta_id=sv.id
 AND o.folio='';
 
 -- muestra en un list view las comisiones por una orden de compra
 SELECT o.id,CAST('texto-',cc.numero),pv.tipo,ta.nombre,tac.total,o.fecha
 FROM orden o,cliente c,punto_venta pv,tipo_articulo ta,totalArticulo_comision tac,cantidad ca,articulo a,
 cantidad_requerimiento cr,requerimiento r,clave_cliente cc,orden_descripcion od
 WHERE o.cliente_id=c.id
 AND o.puntoVenta_id=pv.id
 AND od.orden_id=o.id
 AND od.requerimiento_id=r.id
 AND cr.requerimiento_id=r.id
 AND cr.cantidad_id=c.id
 AND ca.articulo_id=a.id
 AND a.tipoArticulo_id=ta.id
 AND cc.cliente_id=c.id
 AND tac.orden_id=o.id
 AND o.folio='%s'
 UNION
 SELECT o.id,CAST('texto-',cc.numero),pv.tipo,sv.nombre,tsc.total,o.fecha
 FROM orden o,cliente c,punto_venta pv,servicio_requerimiento sr,servicio_venta sv,totalServicio_comision,
 orden_descripcion od,requerimiento r,clave_cliente cc
 WHERE o.cliente_id=c.id
 AND o.puntoVenta_id=pv.id
 AND od.orden_id=o.id
 AND od.requerimiento_id=r.id
 AND sr.requerimiento_id=r.id
 AND sr.servicio_venta_id=sv.id
 AND cc.cliente_id=c.id
 AND tsc.orden_id=o.id
 AND o.folio='%s';
 
 -- actualiza una orden descripcion
 UPDATE orden_descripcion 
 SET cantidad=2,
 precio_final=50
 WHERE id=1;
 
 -- busqueda de clientes por clave
 SELECT c.id,c.nombre,cc.numero,pv.id
 FROM cliente c,clave_cliente cc,punto_venta pv
 WHERE cc.cliente_id=c.id
 AND cc.puntoVenta_id=pv.id
 AND cc.numero='%s'
 AND c.activo=true;
 
 -- busqueda de ordenes por punto de venta
 SELECT o.id,o.folio,o.fecha,pv.tipo,cc.numero
 FROM orden o,punto_venta pv,cliente c,clave_cliente cc
 WHERE o.puntoVenta_id=pv.id
 AND o.cliente_id=c.id
 AND cc.cliente_id=c.id
 AND pv.tipo='%s';
 
 