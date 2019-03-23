
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "adc.h"

#define PIN_ANALOG      1
#define PIN_DIGITAL     0

#define PIN_INPUT       1
#define PIN_OUTPUT      0

uint16_t ADC_ReadData(ADC_CHANNEL channel)
{
    switch(channel)
    {
        case ADC_CHANNEL_5:
            break;

        case ADC_CHANNEL_4:
            break ;
            
        case ADC_CHANNEL_3:
            break;
            
        case ADC_CHANNEL_2:
            break;
            
        case ADC_CHANNEL_1:
            break;
            
        case ADC_CHANNEL_21:
            break;
            
        case ADC_CHANNEL_12:
            break;
            
        case ADC_CHANNEL_13:
            break;

        default:
            return 0xFFFF;
    }

    AD1CHS = channel ;
  
    AD1CON1bits.MODE12 = 1; //12 bit mode

    // Get an ADC sample
    AD1CON1bits.SAMP = 1;           //Start sampling
    msDelay(10);

    AD1CON1bits.SAMP = 0;           //Start sampling
    msDelay(10);

    while(!AD1CON1bits.DONE);       //Wait for conversion to complete

    return ADC1BUF0;
}

bool ADC_ChannelEnable(ADC_CHANNEL channel)
{
    switch(channel)
    {
        case ADC_CHANNEL_5:
            ANSBbits.ANSB5 = PIN_ANALOG ;

        case ADC_CHANNEL_4:
            ANSBbits.ANSB4 = PIN_ANALOG ;
            return true ;
            
        case ADC_CHANNEL_3:
            ANSBbits.ANSB3 = PIN_ANALOG ;
            return true;

        case ADC_CHANNEL_2:
            ANSBbits.ANSB2 = PIN_ANALOG ;
            return true;
            
        case ADC_CHANNEL_1:
            ANSBbits.ANSB1 = PIN_ANALOG ;
            return true;
            
        case ADC_CHANNEL_21:
            ANSEbits.ANSE9 = PIN_ANALOG ;
            return true;
            
        case ADC_CHANNEL_12:
            ANSBbits.ANSB12 = PIN_ANALOG; //CHANNEL 12 => 41 
            return true;
            
        case ADC_CHANNEL_13:
            ANSBbits.ANSB13 = PIN_ANALOG;   //CHANNEL 13 => 42 
            return true;
            
        default:
            return false;
    }
    
    return false;
}

void Init_Analog_Channels(void)
{
    ADC_SetConfiguration();
}

void ADC_SetConfiguration()
{
    AD1CON2bits.PVCFG = 0x0 ;
    AD1CON3bits.ADCS = 0xFF ;
    AD1CON1bits.SSRC = 0x0;
    AD1CON3bits.SAMC = 0b10000;
    AD1CON1bits.FORM = 0b00;
    AD1CON2bits.SMPI = 0x0;
    AD1CON1bits.ADON = 1;
}

void Init_Sensors(void)
{
    //SENSOR 1 => pin 22
    ADC_ChannelEnable( SENSOR1 );
    //SENSOR 2 => pin 23
    ADC_ChannelEnable( SENSOR2 );
    //SENSOR 3 => pin 24
    ADC_ChannelEnable( SENSOR3 );
    //SENSOR 4 => Pin 19
    ADC_ChannelEnable( SENSOR4 );
    //SENSOR 5 => Pin 20 
    ADC_ChannelEnable( SENSOR5 );
    //BOOM_ANGLE => PIN 41
    ADC_ChannelEnable( BOOM_ANGLE );
    //LOAD_HEIGHT => PIN 42
    ADC_ChannelEnable(LOAD_HEIGHT);
    
}


long Map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#define SCALE 1200L
void msDelay(unsigned int ms)
{
    unsigned long i;
    for(i=(unsigned long)(ms)*SCALE; i>0; i-=1)
        Nop();
}
