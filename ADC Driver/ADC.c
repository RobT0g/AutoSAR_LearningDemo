#include <ADC.h>

/* Start the group conversion */
void Adc_StartGroupConversion(Adc_GroupType Group){
    if(Group == 1){
        /* Write implementation to start conversion here */
    }
}

/* Function to read ADC Group */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr){
    unsigned int ADCValue;
    if(Group == 1){
        ADCValue = SomeRegister;
        *DataBufferPtr = ADCValue;
        return E_OK;
    }
    return E_NOK;
}
