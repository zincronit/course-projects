SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE sp_check_member_status 
(
    p_socio_id IN gt_socios.socio_id%TYPE
)
    
AS 
    v_first_name gt_socios.nombres%TYPE;
    v_last_name gt_socios.ape_paterno%TYPE;
    v_estatus gt_socios.estado%TYPE;
BEGIN
    SELECT 
        s.nombres,
        s.ape_paterno,
        s.estado
    INTO
        v_first_name,
        v_last_name,
        v_estatus
    FROM gt_socios s
    WHERE s.socio_id = p_socio_id;
    
    IF  v_estatus <> 'A' THEN 
        dbms_output.put_line('Access granted ' || v_first_name || ' ' || v_last_name);
    ELSIF v_estatus <> 'I' THEN 
        dbms_output.put_line('Access denied ' || v_first_name || ' ' || v_last_name);
    ELSE
        dbms_output.put_line('Unkown status form members. ');
    END IF;

EXCEPTION
    WHEN no_data_found THEN
        dbms_output.put_line('Error: Memeber ID ' || p_socio_id || ' does not exits');
END sp_check_member_status ;
/
SET SERVEROUTPUT ON;
EXEC sp_check_member_status(7);  
/

CREATE OR REPLACE PROCEDURE sp_calculate_plan_discount
(
    p_plan_id IN gt_planes_membresia.plan_id%TYPE,
    p_discount IN NUMBER,
    p_final_price OUT NUMBER
)
AS 
    v_price gt_planes_membresia.precio%TYPE;
    v_estatus gt_planes_membresia.estado%TYPE;
    ex_invalid_discount EXCEPTION;
    ex_inactive_plan EXCEPTION;
BEGIN     
    IF p_discount > 50 OR p_discount < 0 or p_discount IS NULL THEN
        RAISE ex_invalid_discount;
    END IF;
    
    SELECT 
        p.precio,
        p.estado
    INTO 
        v_price,
        v_estatus
    FROM gt_planes_membresia p
    WHERE p.plan_id = p_plan_id;
    
    IF v_estatus = 'I' THEN 
        RAISE ex_inactive_plan;
    END IF;
    
    p_final_price := v_price - (v_price * (p_discount / 100));
    
EXCEPTION
    WHEN no_data_found THEN
        p_final_price := NULL;
        dbms_output.put_line('Error: Plan ID not found.');
    WHEN ex_invalid_discount THEN
        p_final_price := NULL;
        dbms_output.put_line('Error: Discount must be between 0 and 50%.');
    WHEN ex_inactive_plan THEN
        p_final_price := NULL;
        dbms_output.put_line('Error: The selected plan is inactive.');
END sp_calculate_plan_discount;
/       
DECLARE
    v_result NUMBER;
BEGIN
    sp_calculate_plan_discount(4, 10, v_result);
    DBMS_OUTPUT.PUT_LINE('Final price: ' || NVL(TO_CHAR(v_result), 'N/A'));
    
    sp_calculate_plan_discount(5, 10, v_result);
END;
/

/* pregurnta de cursores */

CREATE OR REPLACE PROCEDURE sp_list_branch_classes
(
    p_sede_id IN gt_clases.sede_id%TYPE
)
IS
    CURSOR c_classes(cp_branch_id gt_sedes.sede_id%TYPE)
    IS  
    SELECT
        c.clase_id,
        tc.nombre AS class_name,
        c.fecha_clase,
        c.cupo_maximo
    FROM gt_clases c
    JOIN 
        gt_tipos_clase tc
        ON 
            c.tipo_clase_id = tc.tipo_clase_id
    WHERE c.estado = 'P'
        AND c.sede_id = cp_branch_id
    ORDER BY c.fecha_clase;
    
    r_class c_classes%ROWTYPE;
BEGIN
    OPEN c_classes(p_sede_id);
    LOOP
        FETCH c_classes INTO r_class;
        EXIT WHEN c_classes%NOTFOUND;
        dbms_output.put_line(
            'Class #' || r_class.CLASE_ID || ' - ' || r_class.class_name ||
            ' | Date: ' || TO_CHAR(r_class.FECHA_CLASE, 'YYYY-MM-DD') ||
            ' | Max Capacity: ' || r_class.CUPO_MAXIMO
            );
        END LOOP;
        
    IF c_classes%ROWCOUNT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('No scheduled classes found for branch ' || p_sede_id);
    ELSE
        DBMS_OUTPUT.PUT_LINE('Total scheduled classes: ' || c_classes%ROWCOUNT);
    END IF;

    CLOSE c_classes;
    
END sp_list_branch_classes;
/
SET SERVEROUTPUT ON;
EXEC sp_list_branch_classes(1);
/


SELECT * FROM gt_socios;
/
SELECT * FROM gt_clases;
/
SELECT * FROM gt_reservas;
/* the same thing but in spanish */
/
CREATE OR REPLACE PROCEDURE sp_auditar_inasistencias_mes
(
    p_anio IN VARCHAR2
)
IS 
    CURSOR c_socios IS
        SELECT 
            socio_id,
            nombres,
            ape_paterno
        FROM gt_socios
        WHERE estado = 'A';
        
    v_nro_inasistencias NUMBER;
BEGIN 
    FOR r_socio IN c_socios LOOP
        BEGIN
            SELECT
                COUNT(r.socio_id)
            INTO v_nro_inasistencias
            FROM gt_reservas r
            JOIN gt_clases c 
                ON r.clase_id = c.clase_id
            WHERE r.socio_id = r_socio.socio_id
                AND r.asistio = 'N'
                AND c.estado = 'R'
                AND TO_CHAR(c.fecha_clase, 'YYYY-MM') = p_anio;
                
            IF v_nro_inasistencias >= 3 THEN
                dbms_output.put_line('alera penalidad');
            END IF;
        EXCEPTION 
            WHEN OTHERS THEN
                dbms_output.put_line('manteca');
        END;
    END LOOP;
END sp_auditar_inasistencias_mes;
/
SET SERVEROUTPUT ON;
EXEC sp_auditar_inasistencias_mes('2026-08');
            




    

