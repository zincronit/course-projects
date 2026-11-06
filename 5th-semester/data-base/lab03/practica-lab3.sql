SET SERVEROUTPUT ON;
DECLARE 
    value1 NUMBER;
    value2 NUMBER;

BEGIN
    value1 :=20;
    value2 :=30;
    dbms_output.put_line('HOla soy samin \n' || value1);
    dbms_output.put_line(value2);
END;
/
SET SERVEROUTPUT ON;
DECLARE
    precio_original NUMBER(5, 2) := 120.00;
    descuento NUMBER(2,2) := 0.15;
    precio_final NUMBER (5, 2);
BEGIN 
    precio_final := precio_original*(1 - descuento);
    
    dbms_output.put_line('precio original: ' || precio_original);
    dbms_output.put_line('descuento: ' || descuento);
    dbms_output.put_line('precio_final: ' || precio_final);
END;
/

SET SERVEROUTPUT ON;
DECLARE
    nombre GT_SOCIOS.NOMBRES%TYPE;
    ape_paterno GT_SOCIOS.APE_PATERNO%TYPE;
    correo GT_SOCIOS.CORREO%TYPE;
BEGIN
    SELECT 
        nombres,
        ape_paterno,
        correo
    INTO 
        nombre,
        ape_paterno,
        correo
    FROM GT_SOCIOS
    WHERE socio_id IN (1);
    dbms_output.put_line('Socio consultado: ' || nombre || ' ' || ape_paterno);
    dbms_output.put_line('Correo de Contacto: ' || correo);
END;

/


SET SERVEROUTPUT ON;
DECLARE
    porcentaje_aforo CONSTANT NUMBER(5,2) := 0.80;
    nombre gt_sedes.nombre%type;
    aforo_maximo gt_sedes.aforo_maximo%type;
    aforo_permitido NUMBER(5);
BEGIN
    SELECT 
        nombre,
        aforo_maximo
    INTO
        nombre,
        aforo_maximo
    FROM gt_sedes
    WHERE sede_id IN (1);
    
    aforo_permitido := TRUNC(porcentaje_aforo * aforo_maximo);
    dbms_output.put_line(aforo_permitido);

END;
/

--CREATE OR REPLACE FUNCTION DIAS_RESTANTES_MEMBRESIAS(
--    MEMBRESIA_ID GT_MEMBRESIAS.MEMBRESIA_ID%TYPE
--) RETURN NUMBER
--AS 
--    FECHA_FIN GT_MEMBRESIAS.FECHA_FIN%TYPE;
--    DIAS NUMBER(3);
--BEGIN
--    SELECT M.FECHA_FIN
--    INTO FECHA_FIN
--    FROM GT_MEMBRESIAS M
--    WHERE M.MEMBRESIA_ID = MEMBRESIA_ID;
--    
--    DIAS := TRUNC(FECHA_FIN - SYSDATE);
--    
--    IF DIAS < 0 THEN
--        RETURN 0;
--    ELSE
--        RETURN DIAS;
--    END IF;
--EXCEPTION
--    WHEN NO_DATA_FOUND THEN
--        RETURN -1;
--END DIAS_RESTANTES_MEMBRESIAS;
--
--/
--SET SERVEROUTPUT ON;
--
--DECLARE
--    v_id_membresia GT_MEMBRESIAS.MEMBRESIA_ID%TYPE := 1;
--    v_dias_restantes NUMBER;
--BEGIN
--    -- Invocación de la función
--    v_dias_restantes := DIAS_RESTANTES_MEMBRESIAS(v_id_membresia);
--    
--    DBMS_OUTPUT.PUT_LINE('Membresía ID: ' || v_id_membresia);
--    DBMS_OUTPUT.PUT_LINE('Días restantes de vigencia: ' || v_dias_restantes);
--END;




CREATE OR REPLACE FUNCTION DIAS_RESTANTES_MEMBRESIAS(
    p_membresia_id IN GT_MEMBRESIAS.MEMBRESIA_ID%TYPE
) RETURN NUMBER
AS 
    v_fecha_fin GT_MEMBRESIAS.FECHA_FIN%TYPE;
    v_dias NUMBER(3);
BEGIN
    SELECT M.FECHA_FIN
      INTO v_fecha_fin
      FROM GT_MEMBRESIAS M
     WHERE M.MEMBRESIA_ID = p_membresia_id;
    
    v_dias := TRUNC(v_fecha_fin - SYSDATE);
    
    IF v_dias < 0 THEN
        RETURN 0;
    ELSE
        RETURN v_dias;
    END IF;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        RETURN -1;
END DIAS_RESTANTES_MEMBRESIAS;
/

SET SERVEROUTPUT ON;

DECLARE
    v_id_membresia GT_MEMBRESIAS.MEMBRESIA_ID%TYPE := 1;
    v_dias_restantes NUMBER;
BEGIN
    -- Invocación usando el parámetro sin ambigüedad
    v_dias_restantes := DIAS_RESTANTES_MEMBRESIAS(v_id_membresia);
    
    DBMS_OUTPUT.PUT_LINE('Membresía ID: ' || v_id_membresia);
    DBMS_OUTPUT.PUT_LINE('Días restantes de vigencia: ' || v_dias_restantes);
END;
/




