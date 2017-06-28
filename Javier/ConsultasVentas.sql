

SELECT id, tipo
FROM punto_venta
WHERE activo = true;

SELECT id, tipo
FROM punto_venta
WHERE tipo LIKE 'R%'
AND CHARACTER_LENGTH(tipo) <= 3
AND activo = true
ORDER BY tipo ASC;

cc.numero\
		from clave_cliente cc, punto_venta pv\
		where cc.puntoVenta_id = pv.id\
		and pv.tipo = '%s'\
		order by cc.numero desc limit 1;