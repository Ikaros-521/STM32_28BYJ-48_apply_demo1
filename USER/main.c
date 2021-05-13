#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "step.h"
#include "exti.h"

//IN4: PB6  d
//IN3: PB5  c
//IN2: PB4  b
//IN1: PB3  a

int main(void)
{
	// n个5.625度
	u8 n = 0;
	// 停顿x,y,z个0.1秒
	u8 x = 0, y = 0, z = 0;
	u8 i = 0;
	delay_init(); //延时函数初始化
	LED_Init();	  //初始化与LED连接的硬件接口
	BEEP_Init();  //初始化蜂鸣器端口
	EXTIX_Init(); // 初始化外部中断输入 
	Step_Motor_GPIO_Init(); // 步进电机初始化
	
	LED0 = 0;
	BEEP = 0;
	
	// 24 * 5.625 = 135
	n = 24; 
	// 0.2 * 10 = 2
	x = 10;
	// 0.1 * 5 = 0.5
	y = 5;
	// 0.1 * 0 = 0
	z = 0;
	
	while (1)
	{
		if(1 == mode) // 摇头模式 （顺n个5.625度 停顿x个0.1秒 逆n个5.625度 停顿x个0.1秒） 共0.2x秒
		{
			motor_circle(n, 0, 2);
			for(i = 0; i < x; i++)
			{
				delay_ms(100);
			}
			motor_circle(n, 1, 2);
			for(i = 0; i < x; i++)
			{
				delay_ms(100);
			}
		}
		else if(2 == mode) // 转圈模式1 （顺1圈，停顿y个0.1秒） 共0.1y秒
		{
			motor_circle(64, 0, 2);
			for(i = 0; i < y; i++)
			{
				delay_ms(100);
			}
		}
		else if(3 == mode) // 转圈模式2 （逆1圈，停顿z个0.1秒） 共0.1z秒
		{
			motor_circle(64, 1, 2);
			for(i = 0; i < z; i++)
			{
				delay_ms(100);
			}
		}
		else if(4 == mode) // 自定义模式 （自行修改代码） 共3.5秒
		{
			motor_circle(1, 0, 2);
			delay_ms(500);
			motor_circle(2, 0, 2);
			delay_ms(500);
			motor_circle(4, 0, 2);
			delay_ms(500);
			motor_circle(8, 0, 2);
			delay_ms(500);
			motor_circle(16, 0, 2);
			delay_ms(500);
			motor_circle(32, 0, 2);
			delay_ms(500);
			motor_circle(64, 0, 2);
			delay_ms(500);
		}
		else // 不工作模式 共0.5秒
		{
			delay_ms(500);
		}
		
		LED0 = !LED0;
	}
}
