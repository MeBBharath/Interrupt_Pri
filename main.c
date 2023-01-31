#include <stdint.h>
#define TIMER 28
#define I2C 32
uint32_t *pIPR=(uint32_t)0xE00E400;
uint32_t *pISER=(uint32_t)0xE00E100;
uint32_t *pISPR=(uint32_t)0xE00E200;
void config(uint32_t irq_no,uint32_t pri_val)
{
	uint32_t iprx= irq_no/4;
	uint32_t *pipr= pIPR+iprx;

	uint32_t pos= (irq_no%4)*8;

	*ipr&=~((oxFF) << pos);
	*ipr|=((pr_val) << pos);
}
int main(void)
{
    /* Loop forever */
	config(TIMER,0x80);
	config(I2C,0x80);

	*pISPR|=(1<<TIMER);

	*pISER |=(1<<TIMER);
	*pISER |=(1<<I2C);
	for(;;);
}
void TIM2_IRQHandler(void)
{
	printf("in Timer");

}
void I2C1_EV_IRQHandler(void)
{
	printf("in Timer");

}
