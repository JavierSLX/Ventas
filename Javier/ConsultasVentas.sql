

SELECT id, tipo
FROM punto_venta
WHERE activo = true;

SELECT id, tipo
FROM punto_venta
WHERE tipo LIKE 'R%'
AND CHARACTER_LENGTH(tipo) <= 3
AND activo = true
ORDER BY tipo ASC;