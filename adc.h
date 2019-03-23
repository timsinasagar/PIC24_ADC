
#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include <stdbool.h>

#define SENSOR1 ADC_CHANNEL_3
#define SENSOR2 ADC_CHANNEL_2
#define SENSOR3 ADC_CHANNEL_1
#define SENSOR4 ADC_CHANNEL_21
#define SENSOR5 ADC_CHANNEL_5

#define BOOM_ANGLE ADC_CHANNEL_12
#define LOAD_HEIGHT ADC_CHANNEL_13

typedef enum
{
    ADC_CHANNEL_5 = 5,
    ADC_CHANNEL_4 = 4,
    ADC_CHANNEL_3 = 3,
    ADC_CHANNEL_2 = 2,
    ADC_CHANNEL_1 = 1,
    ADC_CHANNEL_21 = 21,
    ADC_CHANNEL_12 = 12,
    ADC_CHANNEL_13 = 13
} ADC_CHANNEL;

uint8_t ADC_ReadPercentage(ADC_CHANNEL channel);

uint16_t ADC_ReadData(ADC_CHANNEL channel);

void ADC_SetConfiguration(void);

bool ADC_ChannelEnable(ADC_CHANNEL channel);

void Init_Analog_Channels(void);

void Init_Sensors(void);

long Map(long x, long in_min, long in_max, long out_min, long out_max);

void msDelay(unsigned int ms);

#endif  //ADC_H
