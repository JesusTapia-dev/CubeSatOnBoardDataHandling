#include "tasksobc.h"
#include "state_handler.h"

// Definiciones de las tareas y funciones compartidas
void  measureVoltageCurrent(){
    /*
    brief: Mide el voltaje y la corriente 
    */
    
    battery.voltage_battery=5;
    battery.current_battery=1;
    battery.voltage_status=1;
}
void checkADCS_status(){
    /*
    brief:debe leer alguna magnitud que asegure que
    el sistema ADCS es correcto
    */
    adcs.adcs_antenna_status=1;
    adcs.adcs_detumbling_status=1;
}
