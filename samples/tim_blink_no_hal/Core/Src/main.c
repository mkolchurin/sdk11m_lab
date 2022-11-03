#include "main.h"
#include "stdint.h"

/* registers map: */
// NVIC
#define NVIC_REG 0xe000e100
// RCC
#define RCC 0x40023800
#define RCC_AHB1ENR_OFFSET 0x30
#define RCC_APB1ENR_OFFSET 0x40
// PWR
#define PWR 0x40007000
#define PWR_CR_OFFSET 0x0

// GPIO
#define GPIO_PORT_D 0x40020C00
#define GPIO_ODR_OFFSET 0x14
#define GPIO_MODER_OFFSET 0x0

//TIM2
#define TIM2_REG 0x40000000
#define TIM_SR_OFFSET 0x10
#define TIM_CNT_OFFSET 0x24
#define TIM_ARR_OFFSET 0x2c
#define TIM_PSC_OFFSET 0x28
#define TIM_DIER_OFFSET 0x0c
#define TIM_CR1_OFFSET 0x00
/* end registers map */


/* basic bit ops */
/* 
you can choose macro
SET_BIT((RCC + RCC_AHB1ENR_OFFSET), (1 << 3));
or 
*(uint32_t*)(RCC + RCC_AHB1ENR_OFFSET) = (1 << 3)
 */
#define SET_BIT(REG, BIT) ((*(uint32_t*)REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((*(uint32_t*)REG) &= ~(BIT))
#define READ_BIT(REG, BIT) ((*(uint32_t*)REG) & (BIT))
#define CLEAR_REG(REG) ((*(uint32_t*)REG) = (0x0))
#define WRITE_REG(REG, VAL) ((*(uint32_t*)REG) = (VAL))
#define READ_REG(REG) ((*(uint32_t*)REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))


// Interrupt handler of timer "TIM2";
// function name given in the startup_stm32f427xx.s
void TIM2_IRQHandler(void)
{
    // clear interrupt flags
    *(uint32_t*)(TIM2_REG+TIM_SR_OFFSET) = 0;
    // toggle GPIOD_13
    *(uint32_t*)(GPIO_PORT_D + GPIO_ODR_OFFSET) ^= (1 << 13);
}

int main(void)
{
    // enable power interface clock
    SET_BIT((RCC + RCC_APB1ENR_OFFSET), (1 << 28));
    
    // select power mode: PWR scale 1
    SET_BIT((PWR + PWR_CR_OFFSET), (0b11 << 14));

    // enable GPIOD clock 
    SET_BIT((RCC + RCC_AHB1ENR_OFFSET), (1 << 3));
    // установка пина 13 в блока GPIOD режим gpio output mode
    *(uint32_t*)(GPIO_PORT_D + GPIO_MODER_OFFSET) |= (1 << 26);

    // enable TIM2 clock
    SET_BIT((RCC + RCC_APB1ENR_OFFSET), 1);

    // enable TIM2_IRQ
    *(uint32_t*)NVIC_REG |= 1 << 28;
    
    // set counter value to zero (CNT register)
    *(uint32_t*)(TIM2_REG+TIM_CNT_OFFSET) = 0;
    // set auto reload value (if CNT == ARR -> CNT = 0 (resetting counter and generate UPDATE event))
    *(uint32_t*)(TIM2_REG+TIM_ARR_OFFSET) = 0xfff;
    // counter prescaler
    *(uint32_t*)(TIM2_REG+TIM_PSC_OFFSET) = 800;
    // enable interrupt by UPDATE event
    *(uint32_t*)(TIM2_REG+TIM_DIER_OFFSET) = 0x1;
    // clear interrupt flags
    *(uint32_t*)(TIM2_REG+TIM_SR_OFFSET) = 0x0;
    // start count (set CR1->CEN to 1)
    *(uint32_t*)(TIM2_REG+TIM_CR1_OFFSET) = 0x1;

    while (1) {
    }
}

void Error_Handler(void)
{
    while (1) {
    }
}