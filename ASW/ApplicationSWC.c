#include "Rte_TemControlSWC.h"

void ApplTemperatureControl(){

    float Temperature;

    /* Read data from ECU Abstraction */
    /**
     * Rte_Read_ Standard function suffix to read a value from a port
     * R_Temperature RPort name
     * Temperature Data Prototype being read
     */
    Rte_Read_R_Temperature_Temperature(&Temperature);
    
    /* Control Logic */
    if(Temperature > 50 && Temperature <= 75){
        /* Set the motor at low speed */

        /**
         * Rte_Call_ Standard function suffix for client-server calls
         * R_StartMotor RPort name
         * StartMotor Data prototype of the argument being passed
         */
        Rte_Call_R_StartMotor_StartMotor(25);

    } else if(Temperature > 75){
        /* Set the motor at high speed */

        Rte_Call_R_StartMotor_StartMotor(100);

    }else{
        /* Turn the motor off (Temperature < 25)*/
        Rte_Call_R_StopMotor();
    }
}