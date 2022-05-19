/****************The Application is Counting down time and displaying it on LCD***********/

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

while(1){
  time_value();
  if((time<prev)&&(time>=0){
	prev--;
	LCD_clear();
LCD_write_no(time,0,0);
}
  
}
  
}


