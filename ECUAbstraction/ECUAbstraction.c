#include "Rte_TempHBridgeSWC.h"

void ReadTemperature_Function(){
    /* This is the main function of the Temperature Runnable. It is meant to trigger the ADC conversion and get a read of the current Temperature Value */
    uint16 ADCResult;
    float PinVoltage, Temperature;

    /* Trigger the conversion and read the value */
    Adc_StartGroupConversion(1);
    Adc_ReadGroup(1, &ADCResult);

    /* Convert the ADC value (0-1024) to real world Voltage Value (0V-2.5V)*/
    /* The reference voltage is completely dependent on the HW Component being used, so this assumes that the max read temperature is on 2.5V*/
    PinVoltage = (2.5/1024)*ADC_Result;

    /* This conversion to the actual temperature value is also dependent on the HW and is tipically done on the application, so this is only an example */
    Temperature = PinVoltage*100;

    /* After the temperature is calculated, it is set on the provider port via the RTE function */
    /**
     * Rte_Write_ is standard for all port write operations
     * P_Temperature_ is the port in which the write is being done
     * Temperature is the variable prototype being updated (specified on the interface which in this case is I_Temperature)
     */
    Rte_Write_P_Temperature_Temperature(Temperature);
}

void StartMotor_Function(uint8 FanSpeed){
    /* This is the main function of the runnable StartMotor. It is responsible for making the motor run at certain speeds */
    if(FanSpeed < 50){ 
        /* Runs the motor to run at half speed */
        Dio_WriteChannel(10, STD_HIGH);
        Dio_WriteChannel(11, STD_LOW);
    } else{
        /* Run at full speed */
        Dio_WriteChannel(10, STD_HIGH);
        Dio_WriteChannel(11, STD_HIGH);
    }
}

void StopMotor_Function(){
    /* This is the main function of the runnable StopMotor. It is make the motor stop */
    Dio_WriteChannel(10, STD_LOW);
    Dio_WriteChannel(11, STD_LOW);
}