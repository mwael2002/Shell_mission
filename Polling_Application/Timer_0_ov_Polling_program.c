/*
 * Timer_0_ov_program.c
 *
 *  Created on: Oct 22, 2021
 *      Author: mwael
 */
#include"STD.Types.h"
#include"bit_calc.h"
#include"Timer_0_ov_private.h"
#include"Timer_0_ov_interface.h"

U16 TCNT0_register_value;
U16 restart_count;

extern U8 time;

void Timer_ov_init(U16 time_milliseconds){
    time_calculate(time_milliseconds);
	TCNT0 =TCNT0_register_value;
	TCCR0 = 0b00000010;
	//prescaler=8
	//Normal mode
	
}
void time_calculate(U16 time_millisecond){
    F32 count;
    count=(1000000.0*time_millisecond/256*1000);
    restart_count=count;
    TCNT0_register_value=(256*(1-(count-restart_count)));
    restart_count++;
}

void time_value(void){
	static U16 count=0;
	
	while(get_bit(TIFR,0)!=1); //polling on flag
	set_bit(TIFR,1);           //Clearing the flag
	count++;
	
	if(count==restart_count){
		time--;
		count=0;
		TCNT0=TCNT0_register_value;
	}
	}
