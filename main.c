
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "xc.h"

#include "adc.h"

typedef enum {
    AN1 = 1, 
    AN2 = 2,
    AN3 = 3,
    AN4 = 4
} Analog;

int main ( void )
{
    uint16_t rawSignal1,rawSignal2, rawSignal3,rawSignal4;
    Init_Analog_Channels(); //ADC Initialization
    
    while(1)
    {
         rawSignal1 = ADC_ReadData( SENSOR1 );    //sensor 1
         rawSignal2 = ADC_ReadData( SENSOR2 );    //sensor 2
         rawSignal3 = ADC_ReadData( SENSOR3 );    //sensor 3
         rawSignal4 = ADC_ReadData( SENSOR4 );    //sensor 4
    }
}
