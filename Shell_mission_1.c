/************************************Defining Registers addresses********************/
# define SYSCTL_RCGCGPIO_R (*(( volatile unsigned long *)0x400FE608))
# define GPIO_PORTF_Data_Read_Pin_4 (*(( volatile unsigned long *)0x40025040)) 
# define GPIO_PORTF_Data_Write_Pin_1 (*(( volatile unsigned long *)0x40025008)) 
# define GPIO_PORTF_DIR_R (*(( volatile unsigned long *)0x40025400)) 
# define GPIO_PORTF_DEN_R (*(( volatile unsigned long *)0x4002551C))
# define GPIO_PORTF_PUR_R (*(( volatile unsigned long *)0x40025510 ))
/************************************************************************************/

#define PORTF_Enable_CLK 0x20     
#define GPIO_PORTF_Pin_1 0x02
#define GPIO_PORTF_Pin_4 0x10


void main(void){
	SYSCTL_RCGCGPIO_R |= PORTF_Enable_CLK; // Enable clock on Port F
	GPIO_PORTF_DEN_R |= (GPIO_PORTF_Pin_1+GPIO_PORTF_Pin_4); // Enable pin 1 and pin 4 as Digital Pins
	GPIO_PORTF_DIR_R |= GPIO_PORTF_Pin_1 // Set Pin 1 as Output pin
	
	GPIO_PORTF_DIR_R &= (~GPIO_PORTF_Pin_4);            // Set Pin 4 as Input Pin
	GPIO_PORTF_PUR_R |= GPIO_PORTF_Pin_4;            // Enable pull up resistor to Pin 4
	
	GPIO_PORTF_Data_Write_Pin_1  &= (~GPIO_PORTF_Pin_1); // Initialize Pin 1 Value with zero (The led is off)
	while(1){
		if(GPIO_PORTF_Data_Read_Pin_4==0){           // if the button is pushed  
		while(GPIO_PORTF_Data_Read_Pin_4==0);        // Wait untill the button is released to toggle the led one time only         
		GPIO_PORTF_Data_Write_Pin_1 ^= GPIO_PORTF_Pin_1; //  toggling the led
		
}
	}
}









