/* 
 * File:   application.c
 * Author: zyadi
 *
 * Created on August 18, 2023, 8:01 AM
 */

/*---------------------------Section Include-----------------------------------------------*/
#include "application.h"
#include "MCAL_Layer/ADC/hal_adc.h"

/*---------------------------Function Declaration -----------------------------------------------*/
void ADC_Func(void);
void application_init(void);


/*--------------------------- Global Variable -----------------------------------------------*/

Std_ReturnType ret = E_NOT_OK;
adc_result_t result1 = 0;
adc_result_t result2 = 0;
adc_result_t result3 = 0;
adc_result_t result4 = 0;
uint8 ADC_RQ = 0;
adc_conf_t _adc =
{.ADC_INterruptHandler = ADC_Func,
 .acquisition_time = ADC_12_TAD,
 .adc_channel = ADC_CHANNEL_AN0,
 .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DEV_16,
 .result_format = ADC_RESULT_RIGHT,
 .voltage_referenc = ADC_VOLTAGE_REFERENCE_DISABLE,
 .priority =  INTERRUPT_HIGH_PRIORITY ,

};

uint8 str1[6];
uint8 str2[6];
uint8 str3[6];
uint8 str4[6];


int main() {
    
    application_init();
    ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"ADC Test");
    __delay_ms(2000);
    ret = lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"POS0 : ");
    ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"POS1 : ");
    ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"POS2 : ");
    ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"POS3 : ");
  
    while(1)
    {
        if(ADC_RQ == 0)
        {
            ret = ADC_GetConversion_Interrupt(&_adc,ADC_CHANNEL_AN0);
        }
        else if(ADC_RQ == 1)
        {
            ret = ADC_GetConversion_Interrupt(&_adc,ADC_CHANNEL_AN1);
        }
        else if(ADC_RQ == 2)
        {
            ret = ADC_GetConversion_Interrupt(&_adc,ADC_CHANNEL_AN2);
        }
        else if(ADC_RQ == 3)
        {
            ret = ADC_GetConversion_Interrupt(&_adc,ADC_CHANNEL_AN3);
        }
        else
        {
        }
        ret = convert_short_to_str(result1, str1);
        ret = convert_short_to_str(result2, str2);
        ret = convert_short_to_str(result3, str3);
        ret = convert_short_to_str(result4, str4);
            
           
        ret = lcd_4bit_send_string_pos(&lcd_1,1,7,str1);
        ret = lcd_4bit_send_string_pos(&lcd_1,2,7,str2);
        ret = lcd_4bit_send_string_pos(&lcd_1,3,7,str3);
        ret = lcd_4bit_send_string_pos(&lcd_1,4,7,str4);


    }


    return 0;
}

void ADC_Func(void)
{

    
        if(ADC_RQ == 0)
        {
            ret = ADC_GetConversionResult(&_adc,&result1);
       
            ADC_RQ ++;
        }
        else if(ADC_RQ == 1)
        {
            ret = ADC_GetConversionResult(&_adc,&result2);
            ADC_RQ ++;

        }
        else if(ADC_RQ == 2)
        {
            ret = ADC_GetConversionResult(&_adc,&result3);
            ADC_RQ ++;
        }
        else if(ADC_RQ == 3)
        {
            ret = ADC_GetConversionResult(&_adc,&result4);
            ADC_RQ = 0;

        }
        else
        {
        }
}

void application_init(void)
{
    Std_ReturnType ret = E_OK;
    ecu_initialize();
    ret = ADC_Init(&_adc);


}