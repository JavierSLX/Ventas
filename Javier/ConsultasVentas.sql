

SELECT *
FROM clave_cliente;

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