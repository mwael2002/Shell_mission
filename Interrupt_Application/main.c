/*
 * main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: mwael
 */
#include"D:/C/STD.Types.h"
#define F_CPU 8000000
#include"Timer_0_ov_interface.h"
#include"LCD_interface.h"
U8 time;
void main(void){
	time=60;
	U8 prev=time;
	LCD_init();
	LCD_write_no(time,0,0);
	Timer_ov_init(time);
	callback(time_value);

while(1){
if(time<prev){
	prev--;
	LCD_clear();
LCD_write_no(time,0,0);
}
}
}

