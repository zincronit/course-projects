-- Es un test que me hizo gemini en base
-- al caso de Gym Total que se dio en el parcial

--pregunta 1

SELECT 
    socios.socio_id,
    socios.nombres || ' ' ||
    socios.ape_paterno || ' ' ||
    NVL (socios.ape_materno,'') AS nombre_completo ,
    sedes.nombre AS nombre_sede,
    SUM(detalles_rutina.series*detalles_rutina.repeticiones)
        AS total_repeticiones
FROM GT_SOCIOS socios
JOIN GT_MEMBRESIAS membresias
    ON socios.socio_id = membresias.socio_id    
JOIN GT_SEDES sedes
    ON membresias.sede_id = sedes.sede_id
JOIN GT_RUTINAS rutinas
    ON socios.socio_id = rutinas.socio_id
JOIN GT_DETALLES_RUTINA detalles_rutina
    ON rutinas.rutina_id = detalles_rutina.rutina_id
WHERE rutinas.estado = 'V' 
    AND membresias.estado = 'V'
GROUP BY
    socios.socio_id,
    socios.ape_paterno, 
    socios.ape_materno, 
    socios.nombres,
    sedes.nombre
HAVING 
    SUM(detalles_rutina.series*detalles_rutina.repeticiones) > (
        SELECT 
            AVG(detalles_rutina.series*detalles_rutina.repeticiones)
        FROM GT_DETALLES_RUTINA detalles_rutina
        JOIN GT_RUTINAS rutinas
            ON detalles_rutina.rutina_id = rutinas.rutina_id
        WHERE rutinas.estado = 'V'
    )
ORDER BY
    SUM(detalles_rutina.repeticiones) DESC,
    socios.ape_paterno ASC;    

--
SELECT * FROM GT_DETALLES_RUTINA;
SELECT * FROM GT_RUTINAS;
SELECT * FROM GT_MEMBRESIAS;


SELECT * FROM gt_planes_membresia;

UPDATE gt_planes_membresia 
SET PRECIO = PRECIO*1.05 
WHERE ESTADO = 'A';

SELECT * FROM GT_EJERCICIOS;

SELECT 
    r.RUTINA_ID,
    s.SOCIO_ID,
    s.NOMBRES || ' ' || s.APE_PATERNO || NVL2(s.APE_MATERNO, ' ' || s.APE_MATERNO, '') AS NOMBRE_COMPLETO_SOCIO,
    dr.DIA_SEMANA,
    e.NOMBRE AS EJERCICIO,
    dr.SERIES,
    dr.REPETICIONES
FROM GT_RUTINAS r
INNER JOIN GT_SOCIOS s ON r.SOCIO_ID = s.SOCIO_ID
INNER JOIN GT_DETALLES_RUTINA dr ON r.RUTINA_ID = dr.RUTINA_ID
INNER JOIN GT_EJERCICIOS e ON dr.EJERCICIO_ID = e.EJERCICIO_ID
WHERE r.ESTADO = 'V'
  AND r.RUTINA_ID IN (
      SELECT dr_sub.RUTINA_ID 
      FROM GT_DETALLES_RUTINA dr_sub 
      WHERE dr_sub.EJERCICIO_ID = 1
  )
ORDER BY s.APE_PATERNO ASC, dr.DIA_SEMANA ASC;

SELECT 
    c.CLASE_ID,
    tc.NOMBRE AS TIPO_CLASE,
    sd.NOMBRE AS SEDE,
    c.CUPO_MAXIMO,
    COUNT(r.RESERVA_ID) AS TOTAL_INSCRITOS,
    ROUND(COUNT(r.RESERVA_ID) / c.CUPO_MAXIMO, 2) AS RATIO_OCUPACION
FROM GT_CLASES c
INNER JOIN GT_TIPOS_CLASE tc ON c.TIPO_CLASE_ID = tc.TIPO_CLASE_ID
INNER JOIN GT_SEDES sd ON c.SEDE_ID = sd.SEDE_ID
LEFT JOIN GT_RESERVAS r ON c.CLASE_ID = r.CLASE_ID 
WHERE c.FECHA_CLASE BETWEEN TO_DATE('2026-08-01', 'YYYY-MM-DD') 
                        AND TO_DATE('2026-08-31', 'YYYY-MM-DD')
  AND c.ESTADO IN ('P', 'R')
  AND r.ESTADO = 'R'
GROUP BY c.CLASE_ID, tc.NOMBRE, sd.NOMBRE, c.CUPO_MAXIMO
ORDER BY RATIO_OCUPACION DESC;




--
--
DROP VIEW VISTA_SEDES;




