#include "rpi_gpio.h"


/* GPIO Register set */
volatile unsigned int* gpio;

/* Simple loop variable */
volatile unsigned int tim;



int main(void) __attribute__((naked));
int main(void)
{
	/* Assign the address of the GPIO peripheral (Using ARM Physical Address) */
	gpio = (unsigned int *)GPIO_BASE;

    /* Write 1 to the GPIO47 init nibble in the Function Select 4 GPIO
           peripheral register to enable GPIO47 as an output */
    gpio[LED_GPFSEL] = (1 << LED_GPFBIT);

	while(1)
	{
		for(tim = 0; tim < 500000; tim++);

        /* Set the LED GPIO pin high ( Turn OK LED off for original Pi, and on
                   for plus models )*/
        gpio[LED_GPSET] = (1 << LED_GPIO_BIT);

        for(tim = 0; tim < 500000; tim++);

        /* Set the LED GPIO pin low ( Turn OK LED on for original Pi, and off
                   for plus models )*/
        gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

        for(tim = 0; tim < 100000; tim++);

        gpio[LED_GPSET] = (1 << LED_GPIO_BIT);

        for(tim = 0; tim < 100000; tim++);

        gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

        for(tim = 0; tim < 100000; tim++);

        gpio[LED_GPSET] = (1 << LED_GPIO_BIT);

        for(tim = 0; tim < 100000; tim++);

        gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);
    }

	return 0;
}

void exit(int code)
{
	while(1)
	{

	}
}
