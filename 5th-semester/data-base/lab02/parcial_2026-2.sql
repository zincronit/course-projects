-- Pregunta 3.a del parcial 2026-2

CREATE VIEW vista_sedes AS
SELECT 
    s.sede_id,
    s.nombre AS sede,
    SUM(planes_m.precio) AS monto 
FROM GT_SEDES s
JOIN GT_MEMBRESIAS m
    ON s.sede_id = m.sede_id
JOIN GT_PLANES_MEMBRESIA planes_m
    ON m.plan_id = planes_m.plan_id
WHERE TO_CHAR(m.fecha_inicio, 'yyyy') = '2026'
GROUP BY
    s.sede_id,
    s.nombre;
--    
SELECT * FROM VISTA_SEDES;

--
SELECT 
    sede_id,
    sede,
    'S/.' || TO_CHAR(monto, 'FM9,999') AS monto_total
FROM VISTA_SEDES
WHERE monto > (
    SELECT AVG(monto)
    FROM VISTA_SEDES
);    
--
DROP VIEW vista_sedes;


-- pregunta 3b del parcial 2026-2

SELECT 
    sede.nombre AS nombre_sede,
    tipo_clase.nombre AS tipo_clase,
    COUNT(DISTINCT clase.clase_id) as clases_realizadas,
    COUNT(reserva.socio_id) as total_asistentes,
    ROUND(AVG(clase.cupo_maximo),1) AS cupo_promedio,
    TO_CHAR(
    COUNT(reserva.socio_id)/(COUNT(DISTINCT clase.clase_id)
            *AVG(clase.cupo_maximo))*100, '99.0'
            ) || '%'  AS porcentaje_ocupacion
FROM GT_SEDES sede
JOIN GT_CLASES clase
    ON sede.sede_id = clase.sede_id
JOIN GT_TIPOS_CLASE tipo_clase
    ON clase.tipo_clase_id = tipo_clase.tipo_clase_id
JOIN GT_RESERVAS reserva
    ON clase.clase_id = reserva.clase_id
WHERE reserva.estado = 'R'
    AND reserva.asistio = 'S'
GROUP BY 
    sede.nombre,
    tipo_clase.nombre
ORDER BY 
    tipo_clase.nombre;
    
    
SELECT * FROM GT_RESERVAS;
