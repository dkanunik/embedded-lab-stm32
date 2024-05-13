#include <stm32f446_gpio_driver.h>

void GPIO_Init(GPIO_Handle_t *pGPIOHangle){
	uint32_t temp = 0;

	// 1. configure the mode of gpio pin
	if (pGPIOHangle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) {
		temp = (pGPIOHangle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHangle->pGPIOx->GPIOx_MODER &= ~(0x3 << pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHangle->pGPIOx->GPIOx_MODER |= temp;
	} else {

	}

	temp = 0;

	// 2. configure the speed
	temp = (pGPIOHangle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHangle->pGPIOx->GPIOx_OSPEEDR &= ~(0x3 << pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHangle->pGPIOx->GPIOx_OSPEEDR |= temp;

	temp = 0;

	// 3. configure the pupd settings
	temp = (pGPIOHangle->GPIO_PinConfig.GPIO_PinPuPdControl	<< (2 * pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHangle->pGPIOx->GPIOx_PUPDR &= ~(0x3 << pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHangle->pGPIOx->GPIOx_PUPDR |= temp;

	temp = 0;

	// 4. configure the optype
	temp = pGPIOHangle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber;
	pGPIOHangle->pGPIOx->GPIOx_OTYPER &= ~(0x1 << pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHangle->pGPIOx->GPIOx_OTYPER |= temp;

	temp = 0;

	// 5. configure the alt functionality
	if (pGPIOHangle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTFN) {
		uint8_t temp1, temp2;
		temp1 = pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHangle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHangle->pGPIOx->GPIOx_AFR[temp1] |= (pGPIOHangle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}

}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) {
	if (pGPIOx == GPIOA) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOB) {
		GPIOB_REG_RESET();
	} else if (pGPIOx == GPIOC) {
		GPIOC_REG_RESET();
	} else if (pGPIOx == GPIOD) {
		GPIOD_REG_RESET();
	} else if (pGPIOx == GPIOE) {
		GPIOE_REG_RESET();
	} else if (pGPIOx == GPIOF) {
		GPIOF_REG_RESET();
	} else if (pGPIOx == GPIOG) {
		GPIOG_REG_RESET();
	} else if (pGPIOx == GPIOH) {
		GPIOH_REG_RESET();
	} else if (pGPIOx == GPIOI) {
		GPIOI_REG_RESET();
	}
}

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t enORdis) {
	if (enORdis == ENABLE) {
		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_EN();
		} else if (pGPIOx == GPIOB) {
			GPIOB_PCLK_EN();
		} else if (pGPIOx == GPIOC) {
			GPIOC_PCLK_EN();
		} else if (pGPIOx == GPIOD) {
			GPIOD_PCLK_EN();
		} else if (pGPIOx == GPIOE) {
			GPIOE_PCLK_EN();
		} else if (pGPIOx == GPIOF) {
			GPIOF_PCLK_EN();
		} else if (pGPIOx == GPIOG) {
			GPIOG_PCLK_EN();
		} else if (pGPIOx == GPIOH) {
			GPIOH_PCLK_EN();
		} else if (pGPIOx == GPIOI) {
			GPIOI_PCLK_EN();
		}
	} else {
		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_DI();
		} else if (pGPIOx == GPIOB) {
			GPIOB_PCLK_DI();
		} else if (pGPIOx == GPIOC) {
			GPIOC_PCLK_DI();
		} else if (pGPIOx == GPIOD) {
			GPIOD_PCLK_DI();
		} else if (pGPIOx == GPIOE) {
			GPIOE_PCLK_DI();
		} else if (pGPIOx == GPIOF) {
			GPIOF_PCLK_DI();
		} else if (pGPIOx == GPIOG) {
			GPIOG_PCLK_DI();
		} else if (pGPIOx == GPIOH) {
			GPIOH_PCLK_DI();
		} else if (pGPIOx == GPIOI) {
			GPIOI_PCLK_DI();
		}
	}
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){
	uint8_t value;
	value = (uint8_t)((pGPIOx->GPIOx_IDR >> pinNumber) & 0x00000001);
	return value;
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = (uint16_t)pGPIOx->GPIOx_IDR;
	return value;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value){
	if (value == GPIO_PIN_SET) {
		pGPIOx->GPIOx_ODR |= (1 << pinNumber);
	} else {
		pGPIOx->GPIOx_ODR &= ~(1 << pinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value){
	pGPIOx->GPIOx_ODR = value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){
	pGPIOx->GPIOx_ODR ^= (1 << pinNumber);
}

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t enORdis){}
void GPIO_Handling(int8_t PinNumber){}
