#include "ecu_initialize.h"



lcd_4bit_t lcd_1 = 
{
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = GPIO_PIN1,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    
    
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN2,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic= GPIO_LOW,
    
    
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN3,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic= GPIO_LOW,
    
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN4,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic= GPIO_LOW,
    
    
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN5,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic= GPIO_LOW,
    
    
};






dc_motor_t motor1 = 
{
    .dc_motor[0].dc_motor_port = PORTC_INDEX,
    .dc_motor[0].dc_motor_pin = GPIO_PIN6,
    .dc_motor[0].dc_motor_status = DC_MOTOR_OFF,
    
    .dc_motor[1].dc_motor_port = PORTC_INDEX,
    .dc_motor[1].dc_motor_pin = GPIO_PIN7,
    .dc_motor[1].dc_motor_status = DC_MOTOR_OFF,
    
   
};


dc_motor_t motor2 = 
{
    .dc_motor[0].dc_motor_port = PORTD_INDEX,
    .dc_motor[0].dc_motor_pin = GPIO_PIN0,
    .dc_motor[0].dc_motor_status = DC_MOTOR_OFF,
    
    .dc_motor[1].dc_motor_port = PORTD_INDEX,
    .dc_motor[1].dc_motor_pin = GPIO_PIN1,
    .dc_motor[1].dc_motor_status = DC_MOTOR_OFF,
    
   
};


void ecu_initialize(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = lcd_4bit_initialize(&lcd_1);
   
    ret = dc_motor_initialize(&motor1);
    ret = dc_motor_initialize(&motor2);
    /*Seven Seg*/
  
    
    
}

