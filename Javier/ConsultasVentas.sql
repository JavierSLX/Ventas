

SELECT *
FROM orden;

SELECT id, tipo
FROM punto_venta
WHERE tipo LIKE 'R%'
AND CHARACTER_LENGTH(tipo) <= 3
AND activo = true
ORDER BY tipo ASC;

SELECT cc.id, CONCAT('R0-', cc.numero), c.nombre, c.direccion, c.telefono, cd.nombre
FROM clave_cliente cc, cliente c, punto_venta pv, ciudad cd
WHERE cc.cliente_id = c.id
AND  pv.id = cc.puntoVenta_id
AND c.ciudad_id = cd.id
AND c.activo = true
AND pv.tipo = 'R0';

SELECT c.email
FROM cliente c, clave_cliente cc
WHERE cc.cliente_id = c.id
AND cc.id = 19;

SELECT cc.id, CONCAT('R1-', cc.numero), c.nombre, c.direccion, c.telefono, cd.nombre
FROM clave_cliente cc, cliente c, punto_venta pv, ciudad cd
WHERE cc.cliente_id = c.id
AND  pv.id = cc.puntoVenta_id
AND c.ciudad_id = cd.id
AND c.activo = true
AND pv.tipo = 'R1';

SELECT od.id, o.folio, ta.nombre, ma.nombre, mo.nombre, co.nombre, od.cantidad, od.precio_sugerido, od.precio_final,
	od.precio_final * od.cantidad, o.fecha
FROM orden o, orden_descripcion od, tipo_articulo ta, marca ma, modelo mo, color co, cantidad ca, articulo a, 
	requerimiento re, cantidad_requerimiento cr
WHERE od.orden_id = o.id
AND od.requerimiento_id = re.id
AND cr.requerimiento_id = re.id
AND cr.cantidad_id = ca.id
AND ca.articulo_id = a.id
AND a.tipoArticulo_id = ta.id
AND a.modelo_id = mo.id
AND mo.marca_id = ma.id
AND ca.color_id = co.id
AND od.tipoVentaId = a.id
AND o.folio = '100003/2017'
UNION
SELECT od.id, o.folio, sv.nombre, 'N/A', 'N/A', 'N/A', od.cantidad, od.precio_sugerido, od.precio_final,
	od.precio_final * od.cantidad, o.fecha
FROM orden_descripcion od, orden o, servicio_venta sv, servicio_requerimiento sr, requerimiento re
WHERE o.id = od.orden_id
AND od.requerimiento_id = re.id
AND sr.requerimiento_id = re.id
AND sr.servicioVenta_id = sv.id
AND od.tipoVentaId = sv.id
AND o.folio = '100003/2017';