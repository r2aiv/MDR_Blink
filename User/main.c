#include "MDR32Fx.h"
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_rst_clk.h"
#include "MDR32F9Qx_port.h"

PORT_InitTypeDef GPIOC;

void HardFault_Handler(void)
{
	while(1);
}

void Delay()
{
	for(int i=0;i<65535;i++)
		for(int j=0;j<=65535;j++);
}

int main()
{
	GPIOC.PORT_Pin=PORT_Pin_2;
	GPIOC.PORT_MODE=PORT_MODE_DIGITAL;
	GPIOC.PORT_FUNC=PORT_FUNC_PORT;	
	GPIOC.PORT_OE=PORT_OE_OUT;
	GPIOC.PORT_SPEED=PORT_SPEED_SLOW;	
	
	PORT_Init(MDR_PORTC,&GPIOC);	
	
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC,ENABLE);
	
		
	while(1)
	{
		PORT_SetBits(MDR_PORTC,PORT_Pin_2);
		Delay();
		PORT_ResetBits(MDR_PORTC,PORT_Pin_2);
		Delay();		
	}	
}
