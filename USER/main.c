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
	// n��5.625��
	u8 n = 0;
	// ͣ��x,y,z��0.1��
	u8 x = 0, y = 0, z = 0;
	u8 i = 0;
	delay_init(); //��ʱ������ʼ��
	LED_Init();	  //��ʼ����LED���ӵ�Ӳ���ӿ�
	BEEP_Init();  //��ʼ���������˿�
	EXTIX_Init(); // ��ʼ���ⲿ�ж����� 
	Step_Motor_GPIO_Init(); // ���������ʼ��
	
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
		if(1 == mode) // ҡͷģʽ ��˳n��5.625�� ͣ��x��0.1�� ��n��5.625�� ͣ��x��0.1�룩 ��0.2x��
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
		else if(2 == mode) // תȦģʽ1 ��˳1Ȧ��ͣ��y��0.1�룩 ��0.1y��
		{
			motor_circle(64, 0, 2);
			for(i = 0; i < y; i++)
			{
				delay_ms(100);
			}
		}
		else if(3 == mode) // תȦģʽ2 ����1Ȧ��ͣ��z��0.1�룩 ��0.1z��
		{
			motor_circle(64, 1, 2);
			for(i = 0; i < z; i++)
			{
				delay_ms(100);
			}
		}
		else if(4 == mode) // �Զ���ģʽ �������޸Ĵ��룩 ��3.5��
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
		else // ������ģʽ ��0.5��
		{
			delay_ms(500);
		}
		
		LED0 = !LED0;
	}
}
