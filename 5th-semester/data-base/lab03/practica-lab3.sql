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