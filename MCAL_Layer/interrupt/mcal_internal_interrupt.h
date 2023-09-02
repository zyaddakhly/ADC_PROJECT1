#ifndef _MCAL_INTERNAL_INTERRUPT_H_
#define _MCAL_INTERNAL_INTERRUPT_H_

/*Section : Include*/
#include "mcal_interrupt_config.h"

/*Section : Macro Defination*/
#if ADC_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the ADC interrupt */
#define ADC_InterruptDisable()     (PIE1bits.ADIE = 0)
/*Enable the ADC intrrupt */
#define ADC_InterruptEnable()      ( PIE1bits.ADIE= 1)
/*Clear flag bit for ADC */
#define ADC_InterruptFlagClear()   (PIR1bits.ADIF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make ADC HIGH Priority*/
#define ADC_HighPrioritySet()       (IPR1bits.ADIP = 1)
/*Make ADC Low Priority*/
#define ADC_LowPrioritySet()        (IPR1bits.ADIP  = 0)




#endif


#endif
#endif