SELECT * FROM GT_PERSONAL ;
//
SELECT * FROM GT_PERSONAL 
WHERE CORREO IN ('carlos.mendoza@gymtotal.pe');

//
SELECT ROWNUM AS POSICION ,TIPO_DOCUMENTO , NOMBRES , APE_PATERNO FROM GT_PERSONAL 
WHERE CORREO IN ('carlos.mendoza@gymtotal.pe');

//
SELECT * FROM GT_PERSONAL ;
//
SELECT * FROM GT_SOCIOS;
//
SELECT SOCIO_ID,
       NOMBRES,
       TELEFONO,
       CORREO 
FROM GT_SOCIOS
    WHERE TIPO_DOCUMENTO = 'D' ;


//


SELECT * FROM GT_CONGELAMIENTOS;
//
SELECT * FROM GT_MEMBRESIAS;
//
SELECT * FROM GT_MEMBRESIAS
WHERE DIAS_CONGELADOS > 0;
//
SELECT * FROM GT_PLANES_MEMBRESIA;
//
SELECT * FROM GT_PERSONAL_ROLES;
//
SELECT 
    p.personal_id,
    p.nombres || ' ' || p.ape_paterno AS entrenador,
    r.nombre AS rol_desempenado
FROM GT_PERSONAL p
JOIN GT_PERSONAL_ROLES pr ON p.personal_id = pr.personal_id
JOIN GT_ROLES r ON pr.rol_id = r.rol_id
WHERE pr.estado = 'A';
//
SELECT * FROM GT_SEDES;
--
CREATE OR REPLACE VIEW VW_RESUMEN_SEDES_FINANCIERO AS
SELECT 
    s.sede_id,
    s.nombre AS sede_nombre,
    SUM(p.precio) AS total_recaudado,
    COUNT(DISTINCT m.socio_id) AS total_socios,
    AVG(p.precio) AS precio_promedio_plan
FROM GT_SEDES s
JOIN GT_MEMBRESIAS m ON s.sede_id = m.sede_id
JOIN GT_PLANES_MEMBRESIA p ON m.plan_id = p.plan_id
WHERE m.estado = 'A'
GROUP BY s.sede_id, s.nombre
WITH READ ONLY;

SELECT * FROM VW_RESUMEN_SEDES_FINANCIERO;



--
--
--

SELECT 
    socio_id,
    tipo_documento,
    nro_documento,
    nombres,
    ape_paterno,
    ape_materno,
    telefono
FROM GT_SOCIOS
    WHERE tipo_documento IN 'D' AND
          estado IN 'A'
    ORDER BY ape_paterno ASC;

-- hello 

SELECT 
    ejercicio_id,
    nombre,
    grupo_muscular
FROM GT_EJERCICIOS
    WHERE 
    grupo_muscular IN ('Pecho', 'Espalda','Piernas') AND
    nombre LIKE '%ba%';
--

SELECT * FROM GT_PERSONAL;

--

SELECT
    nombres || ' ' || ape_paterno || ' ' || ape_materno AS nombre_completo,
    NVL(correo , 'SIN CORREO') AS correo_electronico
FROM GT_PERSONAL;
--
--
SELECT 
    membresia_id,
    socio_id,
    fecha_inicio,
    fecha_fin,
    TRUNC(MONTHS_BETWEEN(fecha_fin, fecha_inicio)) AS meses_duracion
FROM GT_MEMBRESIAS;
--

SELECT
    c.clase_id,
    t.nombre AS nombre_tipo_clase,
    s.nombre AS nombre_sede,
    c.fecha_clase,
    c.cupo_maximo
FROM GT_CLASES c
JOIN GT_TIPOS_CLASE t ON c.tipo_clase_id = t.tipo_clase_id
JOIN GT_SEDES s ON c.sede_id = s.sede_id
ORDER BY c.fecha_clase DESC;

SELECT 
    s.sede_id,
    s.nombre AS nombre_sede,
    pm.plan_id,
    pm.nombre AS nombre_plan_membresia
FROM GT_SEDES s
LEFT JOIN GT_MEMBRESIAS m ON s.sede_id = m.sede_id
LEFT JOIN GT_PLANES_MEMBRESIA pm ON pm.plan_id = m.pLan_id;


-- problema 7
SELECT 
    socio_id,
    COUNT(reserva_id) AS total_reservas
FROM GT_RESERVAS
GROUP BY socio_id
HAVING COUNT(reserva_id) >= 2
ORDER BY total_reservas DESC;


SELECT * FROM GT_EVALUACiONES_FISICAS;

SELECT * FROM GT_SOCIOS;


SELECT
    TO_CHAR(fecha_evaluacion, 'YYYY') AS anio_evaluacion,
    e.socio_id,
    AVG(e.peso) AS peso,
    AVG(e.talla) AS talla,
    MAX(e.porcentaje_grasa) AS porc_grasa
FROM GT_EVALUACIONES_FISICAS e
GROUP BY e.fecha_evaluacion, e.socio_id
ORDER BY e.fecha_evaluacion DESC , e.socio_id ASC;


-- problema 9 

SELECT
    plan_id,
    nombre,
    dias_vigencia,
    precio
FROM GT_PLANES_MEMBRESIA
WHERE precio > (
    SELECT
        AVG(precio)
    FROM GT_PLANES_MEMBRESIA
)
ORDER BY precio DESC;

-- problema 10

SELECT
    s.socio_id,
    s.nombres,
    s.ape_paterno,
    s.ape_materno
FROM GT_SOCIOS s
JOIN GT_MEMBRESIAS m
    ON s.socio_id = m.socio_id
JOIN GT_SEDES se
     ON m.sede_id = se.sede_id
WHERE (se.hora_apertura < TO_DATE('06:00' , 'HH24:MI'))
ORDER BY s.socio_id DESC;
-- otra forma

SELECT 
    socio_id, 
    nombres, 
    ape_paterno, 
    ape_materno
FROM GT_SOCIOS
WHERE socio_id IN (
    SELECT socio_id 
    FROM GT_MEMBRESIAS 
    WHERE sede_id IN (
        SELECT sede_id 
        FROM GT_SEDES 
        WHERE TO_CHAR(hora_apertura, 'HH24:MI') < '06:00'
    )
)
ORDER BY socio_id DESC;

-- pregunta 11

SELECT correo FROM GT_SOCIOS WHERE correo IS NOT NULL
UNION
SELECT correo FROM GT_PERSONAL WHERE correo IS NOT NULL;








