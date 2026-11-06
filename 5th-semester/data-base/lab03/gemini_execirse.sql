-- excersice 1
CREATE OR REPLACE FUNCTION fn_estado_socio
(
    p_nro_documento IN VARCHAR2
)RETURN NUMBER 
IS 
    -- v_estado CHAR;
    v_estado gt_socios.estado%TYPE;
BEGIN 
    SELECT s.estado
    INTO v_estado
    FROM gt_socios s
    WHERE s.nro_documento = p_nro_documento;
    
    IF v_estado = 'A' THEN
        RETURN 1;
    ELSE
        RETURN 0;
    END IF;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        RETURN -1;
END fn_estado_socio;
/
-- excersice 2
SET SERVEROUTPUT ON
DECLARE 
    v_estado NUMBER;
    -- v_nro_documento gt_socios.nro_documento%TYPE := '45123678';
    v_nro_documento VARCHAR2(15) := '45123678';
BEGIN
    v_estado := fn_estado_socio(v_nro_documento);
    IF v_estado = 1 THEN
        dbms_output.put_line(
            'El socion con documento ' 
            || v_nro_documento 
            || 'esta activo');
    ELSIF v_estado = 0 THEN
        dbms_output.put_line(
            'El socion con documento ' 
            || v_nro_documento 
            || 'esta inactivo');
    ELSE 
        dbms_output.put_line ('El socion con documento '
            || v_nro_documento 
            || 'no existe');
    END IF;
END;
/

-- excercise 3

CREATE OR REPLACE FUNCTION fn_categoria_socio
(
    p_socio_id IN NUMBER
) RETURN VARCHAR2
AS 
    v_monto_total NUMBER;
    v_categoria VARCHAR2(20);
--    v_socio_id NUMBER
BEGIN
    SELECT 
        NVL(SUM(pm.precio), 0)
    INTO v_monto_total
    FROM gt_membresias m
    JOIN gt_planes_membresia pm
        ON m.plan_id = pm.plan_id
    WHERE m.socio_id = p_socio_id;
    
    IF v_monto_total >= 1000 THEN
        v_categoria := 'VIP';
    ELSIF v_monto_total >= 300 THEN
        v_categoria := 'REGULAR';
    ELSE
        v_categoria := 'NUEVO';
    END IF;

    RETURN v_categoria;
END fn_categoria_socio;
/
SET SERVEROUTPUT ON;

DECLARE
    v_socio_id   NUMBER := 2;
    v_nombre_completo VARCHAR2(150);
    v_monto_total NUMBER := 0;
    v_categoria  VARCHAR2(20);
BEGIN
    SELECT NOMBRES || ' ' || APE_PATERNO || NVL2(APE_MATERNO, ' ' || APE_MATERNO, '')
    INTO v_nombre_completo
    FROM GT_SOCIOS
    WHERE SOCIO_ID = v_socio_id;

    SELECT NVL(SUM(p.PRECIO), 0)
    INTO v_monto_total
    FROM GT_MEMBRESIAS m
    INNER JOIN GT_PLANES_MEMBRESIA p ON m.PLAN_ID = p.PLAN_ID
    WHERE m.SOCIO_ID = v_socio_id;

    v_categoria := FN_CATEGORIA_SOCIO(v_socio_id);

    DBMS_OUTPUT.PUT_LINE('Socio: ' || v_nombre_completo || 
                         ' | Total Gastado: S/ ' || TO_CHAR(v_monto_total, '9990.00') || 
                         ' | Categoria: ' || v_categoria);
END;
/


-- final excercise

CREATE OR REPLACE FUNCTION fn_asistencia_clase
(
    p_clase_id IN NUMBER
)RETURN NUMBER
AS 
    v_porcentaje_asistencia NUMBER;
    v_estado CHAR;
    v_atendidos NUMBER := 0;
    v_total_reservas NUMBER := 0;
BEGIN
    SELECT c.estado
    INTO v_estado
    FROM gt_clases c
    WHERE c.clase_id = p_clase_id;
    
    IF v_estado != 'R' THEN
        RETURN -2;
    END IF;
    
    SELECT COUNT(*)
    INTO v_total_reservas
    FROM gt_reservas r
    WHERE r.clase_id = p_clase_id;
    
    IF v_total_reservas = 0 THEN
        RETURN -3;        
    END IF;
    
    
    SELECT 
        COUNT (r.socio_id)
    INTO v_atendidos
    FROM gt_reservas r
    WHERE r.clase_id = p_clase_id
    AND r.asistio IN ('S');
        
    v_porcentaje_asistencia := ROUND((v_atendidos/v_total_reservas)*100 ,2);
    
    RETURN v_porcentaje_asistencia;
EXCEPTION 
    WHEN NO_DATA_FOUND THEN
        RETURN -1;
END fn_asistencia_clase;
/
SELECT * FROM gt_reservas;
/
SELECT * FROM gt_clases;
