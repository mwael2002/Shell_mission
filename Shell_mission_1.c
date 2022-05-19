/************************************Defining Registers addresses********************/
# define System_Clock_RCGCGPIO (*(( volatile unsigned long *)0x400FE608))
# define GPIO_Port_F_Data_Read_Pin_4 (*(( volatile unsigned long *)0x40025040)) 
# define GPIO_Port_F_Data_Write_Pin_1 (*(( volatile unsigned long *)0x40025008)) 
# define GPIO_Port_F_Direction (*(( volatile unsigned long *)0x40025400)) 
# define GPIO_Port_F_Digital_Enable (*(( volatile unsigned long *)0x4002551C))
# define GPIO_Port_F_Pull_Up (*(( volatile unsigned long *)0x40025510 ))
/************************************************************************************/

#define Port_F_Enable_Clock 0x20     
#define GPIO_Port_F_Pin_1 0x02
#define GPIO_Port_F_Pin_4 0x10

# define system_clock_freq  16000000

void delay(unsigned long);

void main(void){
	System_Clock_RCGCGPIO |= Port_F_Enable_Clock; // Enable clock on Port F
	GPIO_Port_F_Digital_Enable |= (GPIO_Port_F_Pin_1+GPIO_Port_F_Pin_4); // Enable pin 1 and pin 4 as Digital Pins
	GPIO_Port_F_Direction |= GPIO_Port_F_Pin_1; // Set Pin 1 as Output pin
	
	GPIO_Port_F_Direction &= (~GPIO_Port_F_Pin_4);       // Set Pin 4 as Input Pin
	GPIO_Port_F_Pull_Up |= GPIO_Port_F_Pin_4;
	
	GPIO_Port_F_Data_Write_Pin_1 &= (~GPIO_Port_F_Pin_1); // Initialize Pin 1 Value with zero (The led is off)
	while(1){
		while(GPIO_Port_F_Data_Read_Pin_4!=0);        // While loop until the the button is pushed
		GPIO_Port_F_Data_Write_Pin_1 ^= GPIO_Port_F_Pin_1; //  toggling the led
		delay(16000000/20);  // 1 second delay (Assuming that one line in the for loop in the delay function takes 20 clock cycle) 
}
}

void delay(unsigned long del){
	for(unsigned long count=0;count<del;count++);
}







