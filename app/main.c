//#include "stm32f4xx_hal.h"
#include "main.h"
#include "Task.h"
#include "stm32f4xx_hal_gpio.h"
#include "Time.h"
#include "LED.h"
#include "Button.h"
#include "ButtonSM.h"
#include "LedSM.h"

void testFunc(void);
void taskSwitch(void);

int dummy(int value)
{
	return value * 10;
}

int main(void)
{
	LedData ledData;
	ButtonData buttonData;

	initUserButton();
	CLK_EN();
	configureLED(LED3, PORTG);
	configureLED(LED4, PORTG);
	configureLED(LED5, PORTB);
	configureLED(LED6, PORTC);
	buttonInitData(&buttonData);
	ledInitData(&ledData);

	initSysTick();
  
	initTcb();
	//testFunc();
	taskSwitch();

    while(1)
    {
    	//updateTime();
    	//buttonSM(&buttonData);
    	//ledSM(&ledData);
    }
}

void initSysTick()
{
	if(SysTick_Config(SystemCoreClock / 1000))
	{
		//Capture error
		while(1);
	}
}
