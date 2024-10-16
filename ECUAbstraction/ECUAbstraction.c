#include "Rte_TempHBridgeSWC.h"

void ReadTemperature_Function(){
    //This is the main function of the Temperature Runnable. It is meant to trigger the ADC conversion and get a read of the current Temperature Value
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

    
}