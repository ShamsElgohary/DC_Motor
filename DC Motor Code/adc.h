#ifndef ADC_H_
#define ADC_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"


#define INT_SUPPORTED_ADC 0 //If we want our ADC to support INTERRUPTS 0 -> 1
//ALSO ENABLE I-BIT 7TH BIT IN SREG IN MAIN()

/************************************ GLOBAL VARIABLES ***********************************************/

extern volatile uint16 ADC_INT_result;

/************************************ FUNCTION PROTOTYPES ********************************************/

void ADC_init(void); //initialize the ADC driver.


uint16 ADC_readChannel(uint8 channel_num); // Reads analog data and converts to digital from certain channel

#endif
