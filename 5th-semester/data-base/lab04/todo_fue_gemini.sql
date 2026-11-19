/* 
son resoluciones echas por gemini
yo no codie nada de esto
*/

SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE sp_imprimir_detalle_rutina (
    p_rutina_id IN GT_RUTINAS.RUTINA_ID%TYPE,
    p_socio_id  IN GT_SOCIOS.SOCIO_ID%TYPE
) IS
    v_nombre_socio  VARCHAR2(160);
    v_fecha_inicio  GT_RUTINAS.FECHA_INICIO_VIGENCIA%TYPE;
    v_estado        VARCHAR2(20);
    v_observaciones GT_EVALUACIONES_FISICAS.OBSERVACIONES%TYPE;
    v_contador      NUMBER := 0;

    CURSOR c_detalle IS
        SELECT e.NOMBRE AS nombre_ejercicio,
               d.DIA_SEMANA,
               d.SERIES,
               d.REPETICIONES
        FROM GT_DETALLES_RUTINA d
        JOIN GT_EJERCICIOS e ON d.EJERCICIO_ID = e.EJERCICIO_ID
        WHERE d.RUTINA_ID = p_rutina_id
        ORDER BY d.DIA_SEMANA, e.NOMBRE;
BEGIN
    SELECT s.NOMBRES || ' ' || s.APE_PATERNO || NVL(' ' || s.APE_MATERNO, ''),
           r.FECHA_INICIO_VIGENCIA,
           CASE r.ESTADO WHEN 'V' THEN 'VIGENTE' WHEN 'H' THEN 'HISTORICA' ELSE r.ESTADO END,
           NVL(ef.OBSERVACIONES, 'Sin evaluacion previa vinculada')
    INTO v_nombre_socio, v_fecha_inicio, v_estado, v_observaciones
    FROM GT_RUTINAS r
    JOIN GT_SOCIOS s ON r.SOCIO_ID = s.SOCIO_ID
    LEFT JOIN GT_EVALUACIONES_FISICAS ef ON r.EVALUACION_ID = ef.EVALUACION_ID
    WHERE r.RUTINA_ID = p_rutina_id
      AND r.SOCIO_ID  = p_socio_id;

    DBMS_OUTPUT.PUT_LINE('Rutina Nro. ' || p_rutina_id);
    DBMS_OUTPUT.PUT_LINE('Socio: ' || v_nombre_socio);
    DBMS_OUTPUT.PUT_LINE('Fecha de inicio de vigencia: ' || TO_CHAR(v_fecha_inicio, 'DD/MM/YYYY HH24:MI:SS'));
    DBMS_OUTPUT.PUT_LINE('Estado de la rutina: ' || v_estado);
    DBMS_OUTPUT.PUT_LINE('Observaciones evaluacion: ' || v_observaciones);
    DBMS_OUTPUT.PUT_LINE('***');

    FOR reg IN c_detalle LOOP
        v_contador := v_contador + 1;
        DBMS_OUTPUT.PUT_LINE('Ejercicio Nro: ' || v_contador);
        DBMS_OUTPUT.PUT_LINE('Nombre del ejercicio: ' || reg.nombre_ejercicio);
        DBMS_OUTPUT.PUT_LINE('Dia de la semana: ' || reg.DIA_SEMANA);
        DBMS_OUTPUT.PUT_LINE('Series: ' || reg.SERIES || ' | Repeticiones: ' || reg.REPETICIONES);
    END LOOP;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No se encontro la rutina ' || p_rutina_id || ' para el socio ' || p_socio_id || '.');
END sp_imprimir_detalle_rutina;
/
SET SERVEROUTPUT ON;
/
-- Caso de prueba (María Rojas tiene RUTINA_ID = 2 y SOCIO_ID = 1):
EXEC sp_imprimir_detalle_rutina(2, 1);
/
/* pregunta 2 */
DECLARE
    v_clase_id      GT_CLASES.CLASE_ID%TYPE := 4;
    v_total         NUMBER := 0;
    v_asistieron    NUMBER := 0;
    v_inasistencias NUMBER := 0;

    CURSOR c_reservas IS
        SELECT r.RESERVA_ID,
               tc.NOMBRE AS tipo_clase,
               p.NOMBRES || ' ' || p.APE_PATERNO AS instructor,
               s.NOMBRES || ' ' || s.APE_PATERNO AS socio,
               r.FECHA_RESERVA,
               r.ASISTIO
        FROM GT_RESERVAS r
        JOIN GT_CLASES c ON r.CLASE_ID = c.CLASE_ID
        JOIN GT_TIPOS_CLASE tc ON c.TIPO_CLASE_ID = tc.TIPO_CLASE_ID
        JOIN GT_PERSONAL p ON c.PERSONAL_INSTRUCTOR_ID = p.PERSONAL_ID
        JOIN GT_SOCIOS s ON r.SOCIO_ID = s.SOCIO_ID
        WHERE r.CLASE_ID = v_clase_id
          AND r.ESTADO <> 'C'
        ORDER BY r.RESERVA_ID;
BEGIN
    FOR reg IN c_reservas LOOP
        v_total := v_total + 1;
        DBMS_OUTPUT.PUT_LINE('Asistente Nro: ' || v_total);
        DBMS_OUTPUT.PUT_LINE('Clase: ' || reg.tipo_clase || ' | Instructor: ' || reg.instructor);
        DBMS_OUTPUT.PUT_LINE('Socio: ' || reg.socio);
        DBMS_OUTPUT.PUT_LINE('Fecha de reserva: ' || TO_CHAR(reg.FECHA_RESERVA, 'DD/MM/YYYY HH24:MI:SS'));

        IF reg.ASISTIO = 'S' THEN
            v_asistieron := v_asistieron + 1;
            DBMS_OUTPUT.PUT_LINE('Estado de asistencia: ASISTIO');
        ELSIF reg.ASISTIO = 'N' THEN
            v_inasistencias := v_inasistencias + 1;
            DBMS_OUTPUT.PUT_LINE('Estado de asistencia: INASISTENCIA');
        ELSE
            DBMS_OUTPUT.PUT_LINE('Estado de asistencia: PENDIENTE');
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('---');
    DBMS_OUTPUT.PUT_LINE('Existen ' || v_asistieron || ' socios que asistieron de un total de ' || v_total || ' reservas.');
    DBMS_OUTPUT.PUT_LINE('Existen ' || v_inasistencias || ' inasistencias de un total de ' || v_total || ' reservas.');
END;
/

CREATE OR REPLACE PROCEDURE sp_cancelar_membresia (
    p_membresia_id IN GT_MEMBRESIAS.MEMBRESIA_ID%TYPE
) IS
    v_estado            GT_MEMBRESIAS.ESTADO%TYPE;
    v_motivo_fin        GT_MEMBRESIAS.MOTIVO_FIN%TYPE;
    v_congelamientos    NUMBER;

    e_ya_finalizada     EXCEPTION;
    e_esta_congelada    EXCEPTION;
BEGIN
    SELECT ESTADO, MOTIVO_FIN
    INTO v_estado, v_motivo_fin
    FROM GT_MEMBRESIAS
    WHERE MEMBRESIA_ID = p_membresia_id;

    IF v_estado = 'F' THEN
        RAISE e_ya_finalizada;
    END IF;

    SELECT COUNT(*)
    INTO v_congelamientos
    FROM GT_CONGELAMIENTOS
    WHERE MEMBRESIA_ID = p_membresia_id
      AND FECHA_FIN >= TO_DATE('2026-08-08', 'YYYY-MM-DD'); -- Referencia operativa del DML

    IF v_estado = 'G' OR v_congelamientos > 0 THEN
        RAISE e_esta_congelada;
    END IF;

    UPDATE GT_MEMBRESIAS
    SET ESTADO     = 'F',
        MOTIVO_FIN = 'C',
        FECHA_FIN  = TRUNC(SYSDATE)
    WHERE MEMBRESIA_ID = p_membresia_id;

    COMMIT;
    DBMS_OUTPUT.PUT_LINE('La membresia ' || p_membresia_id || ' fue cancelada correctamente.');

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('La membresia ' || p_membresia_id || ' no existe.');
    WHEN e_ya_finalizada THEN
        DBMS_OUTPUT.PUT_LINE('No se puede cancelar la membresia ' || p_membresia_id || ' porque su estado ya es FINALIZADA.');
    WHEN e_esta_congelada THEN
        DBMS_OUTPUT.PUT_LINE('No se puede cancelar la membresia ' || p_membresia_id || ' porque se encuentra CONGELADA.');
END sp_cancelar_membresia;
/

EXEC sp_cancelar_membresia(5);
/