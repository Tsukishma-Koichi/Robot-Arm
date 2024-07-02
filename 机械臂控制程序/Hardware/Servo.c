#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "delay.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngle1(float Angle)
{
	PWM_SetCompare1(Angle / 180 * 2000 + 500);
}
void Servo_SetAngle2(float Angle)
{
	PWM_SetCompare2(Angle / 270 * 2000 + 500);
}
void Servo_SetAngle3(float Angle)
{
	PWM_SetCompare3(Angle / 270 * 2000 + 500);
}
void Servo_SetAngle4(float Angle)
{
	PWM_SetCompare4(Angle / 270 * 2000 + 500);
}
void Servo_SetAngle5(float Angle)
{
	PWM_SetCompare5(Angle / 180 * 2000 + 500);
}

float angle142 = 142, angle58 = 58, angle100 = 100, angle228 = 228, angle48 = 48, angle138 = 138, angle130 = 130, angle60 = 60, angle20 = 20, angle45 = 45, angle80 = 80, angle135 = 135, angle0 = 0, angle180 = 180, angle90 = 90, angle120 = 120, angle225 = 225;

void up(void)
{
	Servo_SetAngle3(angle60);
	Delay_ms(1000);
	Servo_SetAngle1(angle120);
	Delay_ms(1000);
	
	
	//Servo_SetAngle1(angle100);
	//Delay_ms(1000);
	//Servo_SetAngle3(angle80);
	//Delay_ms(1000);
	
	
}

void up_b(void)
{
	Servo_SetAngle1(angle130);
	Delay_ms(1000);
	Servo_SetAngle3(angle80);
	Delay_ms(2000);
	
}

void grab(void)
{
	
	Servo_SetAngle2(angle48);
	Delay_ms(500);
	Servo_SetAngle1(angle45);
	Delay_ms(500);
	Servo_SetAngle3(angle80);
	Delay_ms(500);
}

void claw_open_right(void) //D12
{
	Servo_SetAngle3(angle20);
	Delay_ms(500);
	Servo_SetAngle4(angle60);
	Delay_ms(1000);
}

void claw_open_left(void) //D13
{
	Servo_SetAngle3(angle20);
	Delay_ms(500);
	Servo_SetAngle5(angle45);
	Delay_ms(1000);
}

void claw_close(void)
{
	Servo_SetAngle4(angle0);
	Servo_SetAngle5(angle0);
	Delay_ms(1000);
}

void up_right(void)
{
	
	Servo_SetAngle1(angle130);
	Delay_ms(500);
	Servo_SetAngle3(angle90);
	Delay_ms(500);
	Servo_SetAngle2(angle48);
	Delay_ms(500);
}

void up_left(void)
{
	Servo_SetAngle1(angle130);
	Delay_ms(500);
	Servo_SetAngle3(angle80);
	Delay_ms(500);
	Servo_SetAngle2(angle228);
	Delay_ms(500);
}

void down_(void)
{
	Servo_SetAngle1(angle20);
	Delay_ms(500);
	Servo_SetAngle3(angle60);
	Delay_ms(500);
}
 

void down(void)
{
	Servo_SetAngle2(angle142);
	Delay_ms(500);
	Servo_SetAngle1(angle58);
	Delay_ms(500);
	Servo_SetAngle3(angle100);
	Delay_ms(500);
}



/*
	舵机缓慢从angle1转动到angle2
*/
//void Servo_SlowChange(float angle1, float angle2)
//{
//	int i;
//	if(angle1 < angle2)
//	{
//		for(i = angle1;i <= angle2;i=i+2)
//		{
//			Servo_SetAngle1(i);
//			Delay_ms(20);
//		}
//	}
//	else
//	{
//		for(i = angle1;i >= angle2;i=i-2)
//		{
//			Servo_SetAngle(i);
//			Delay_ms(20);			
//		}
//	}
//}
