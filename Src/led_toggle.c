#include "stm32f446_gpio_driver.h"
#include "stm32f446re.h"

void delayToggle(void) {
	for (uint32_t i = 0; i<5000000; i++) {

	}
}

int main(void) {
	GPIO_Handle_t gpioLed;
	gpioLed.pGPIOx = GPIOA;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MEDIUM;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&gpioLed);

	while(1) {
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delayToggle();
	}

	return 0;
}
