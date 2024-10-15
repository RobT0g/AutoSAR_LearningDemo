/* MCAL for DIO Drivers */
/* Function API to read a channel */
#include <DIO.h>

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
    /* Assume channel 10 is mapped to p2.0 */
    /* Note: The standard calls for more specific development such as error handling, null pointer handling and such */
    Dio_LevelType ReadVal;
    if(ChannelId == 10){
        /* This should contain the access to the registers of said pin */
        ReadVal = P2IN & BIT0;
        /* P2IN is the register being accessed for the pin value */
        /* BIT0 is 0b1 which is 1 on the least significant bit */
        /* Check the value of the register and return */
        if(ReadVal == 0x00){
            return (STD_LOW);   /* Read pin is LOW */
        } else {
            return (STD_HIGH);  /* Read pin is HIGH */
        }
    }
    /* Continue for other pins */
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level){
    /* Assume channel 10 is mapped to p2.0 */
    /* Note: The standard calls for more specific development such as error handling, null pointer handling and such */
    if(ChannelId == 10){
        if(Level == STD_LOW){
            P2OUT &= ~BIT0;     /* Set the value of the pin as LOW */
        }else {
            P2OUT |= BIT0;      /* Set the value of the pin as HIGH */
        }
    }
}
