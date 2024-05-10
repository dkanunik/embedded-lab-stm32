#ifndef STM_DRIVER_H
#define STM_DRIVER_H

#include <stdint.h>

#define FLASH_DASEADDR     0x08000000U
#define SRAM1_BASEADDR     0x20000000U //112 Kb + 1024 = 114688 -> 1C000 (Hex) -> 0x20000000U + 1C000 = 0x2001C000U
#define SRAM2_BASEADDR     0x2001C000U
#define ROM_BASEARRD       0x1FFF0000U
#define SRAM      		   SRAM1_BASEADDR

#define PERIF_BASEADDR         0x4000 0000
#define APB1PERIPH_BASEADDR    0x4000 0000
#define APB2PERIPH_BASEADDR    0x4001 0000
#define AHB1PERIPH_BASEADDR    0x4002 0000
#define AHB2PERIPH_BASEADDR    0x5000 0000

#define GPIOK_BASEADDR     (AHB1PERIPH_BASEADDR + 0x2800)
#define GPIOJ_BASEADDR     (AHB1PERIPH_BASEADDR + 0x2400)
#define GPIOI_BASEADDR     (AHB1PERIPH_BASEADDR + 0x2000)
#define GPIOH_BASEADDR     (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR     (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOF_BASEADDR     (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR     (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR     (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR     (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR     (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOA_BASEADDR     (AHB1PERIPH_BASEADDR + 0x0000)

#define I2C1_BASEADDR      (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR      (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR      (APB1PERIPH_BASEADDR + 0x5C00)
#define SPI2_BASEADDR      (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR      (APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR    (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR    (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR     (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR     (APB1PERIPH_BASEADDR + 0x5000)

#define SPI1_BASEADDR      (APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR    (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR    (APB2PERIPH_BASEADDR + 0x1400)
#define EXTI_BASEADDR      (APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR    (APB2PERIPH_BASEADDR + 0x3800)

#define RCC_BASEADDR       (AHB1PERIPH_BASEADDR + 0x3800)

typedef struct {
   volatile uint32_t GPIOx_MODER;
   volatile uint32_t GPIOx_OTYPER;
   volatile uint32_t GPIOx_OSPEEDR;
   volatile uint32_t GPIOx_PUPDR;
   volatile uint32_t GPIOx_IDR;
   volatile uint32_t GPIOx_ODR;
   volatile uint32_t GPIOx_BSRR;
   volatile uint32_t GPIOx_LCKR;
   volatile uint32_t GPIOx_AFR[1];
} GPIO_RegDef_t;


typedef struct {
   volatile uint32_t RCC_CR;
   volatile uint32_t RCC_PLLCFGR;
   volatile uint32_t RCC_CFGR;
   volatile uint32_t RCC_CIR;
   volatile uint32_t RCC_AHB1RSTR;
   volatile uint32_t RCC_AHB2RSTR;
   volatile uint32_t RCC_AHB3RSTR;
   volatile uint32_t RCC_APB1RSTR;
   volatile uint32_t RCC_APB2RSTR;
   volatile uint32_t RCC_AHB1ENR;
   volatile uint32_t RCC_AHB2ENR;
   volatile uint32_t RCC_AHB3ENR;
   volatile uint32_t RCC_APB1ENR;
   volatile uint32_t RCC_APB2ENR;
   volatile uint32_t RCC_AHB1LPENR;
   volatile uint32_t RCC_AHB2LPENR;
   volatile uint32_t RCC_AHB3LPENR;
   volatile uint32_t RCC_APB1LPENR;
   volatile uint32_t RCC_APB2LPENR;
   volatile uint32_t RCC_BDCR;
   volatile uint32_t RCC_CSR;
   volatile uint32_t RCC_SSCGR;
   volatile uint32_t RCC_PLLI2SCFGR;
   volatile uint32_t RCC_PLLSAICFGR;
   volatile uint32_t RCC_DCKCFGR;
} RCC_RegDef_t;


#define GPIOA     ((GPIO_RefDef_t*) GPIOA_BASEADDR)
#define GPIOB     ((GPIO_RefDef_t*) GPIOB_BASEADDR)
#define GPIOC     ((GPIO_RefDef_t*) GPIOC_BASEADDR)
#define GPIOD     ((GPIO_RefDef_t*) GPIOD_BASEADDR)
#define GPIOE     ((GPIO_RefDef_t*) GPIOE_BASEADDR)
#define GPIOF     ((GPIO_RefDef_t*) GPIOF_BASEADDR)
#define GPIOG     ((GPIO_RefDef_t*) GPIOG_BASEADDR)
#define GPIOH     ((GPIO_RefDef_t*) GPIOH_BASEADDR)
#define GPIOI     ((GPIO_RefDef_t*) GPIOI_BASEADDR)


#define RCC       ((RCC_RegDef_t*) RCC_BASEADDR)


#define GPIOA_PCLK_EN()   (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()   (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()   (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()   (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()   (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()   (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()   (RCC->AHB1ENR |= (1 << 8))


#define I2C1_PCLK_EN()    (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()    (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()    (RCC->APB1ENR |= (1 << 23))


#define SPI1_PCLK_EN()    (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()    (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()    (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()    (RCC->APB2ENR |= (1 << 13))


#define USART1EN_PCCK_EN()    (RCC->APB2ENR |= (1 << 4)
#define USART2EN_PCCK_EN()    (RCC->APB1ENR |= (1 << 17)
#define USART3EN_PCCK_EN()    (RCC->APB1ENR |= (1 << 18)
#define UART4EN_PCCK_EN()     (RCC->APB1ENR |= (1 << 19)
#define UART5EN_PCCK_EN()     (RCC->APB1ENR |= (1 << 20)
#define USART6EN_PCCK_EN()    (RCC->APB2ENR |= (1 << 5)


#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1 << 14))


#define GPIOA_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 8))

/*
 * To reset GPIOx peripherals
 * */
#define GPIOA_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); } while(0)
#define GPIOI_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); } while(0)

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET

#endif // STM_DRIVER_H
