#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "Servo.h"
#include "system.h"
#include "usart.h"
#include "SysTick.h"

uint16_t AD0, AD1, AD2;

uint8_t RxData;

// ���Դ���
int main(void)
{
    uint8_t received_data;
//ʮ�� �� ���� ��	
    Servo_Init();
    USART1_Init(9600);  // ����ʹ��9600��Ϊ������
		
		while(1)
    {
		
        // ����Ƿ������ݽ���
			  /*
        if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
        {
            received_data = USART_ReceiveData(USART1);  // ��ȡ���յ�������

            // ֱ�ӽ����յ������ݷ��ͻ�ȥ
            USART_SendData(USART1, (uint16_t)received_data);
            while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        }
			*/
			
			
			
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			Serial_SendByte(RxData);
			if(RxData == 's')
			{
				claw_close();
				Delay_ms(1000);
				up();
				Delay_ms(500);
				down();
			}
			if(RxData == 'L')
			{
				up_left();
				Delay_ms(20);
				down_();
				Delay_ms(500);
				claw_open_left();
				Delay_ms(1000);
				claw_close();
				Delay_ms(500);
				up();
				Delay_ms(1000);
				down();
			}
			if(RxData == 'R')
			{
				up_right();
				Delay_ms(20);
				down_();
				Delay_ms(500);
				claw_open_right();
				Delay_ms(1000);
				claw_close();
				up();
				Delay_ms(1000);
				down();
			}
			if(RxData == 'l')
			{
				up_left();
				Delay_ms(20);
				down_();
				Delay_ms(500);
				claw_open_right();
				Delay_ms(1000);
				claw_close();
				up();
				Delay_ms(1000);
				down();
			}
			if(RxData == 'r')
			{
				up_right();
				Delay_ms(20);
				down_();
				Delay_ms(500);
				claw_open_left();
				Delay_ms(1000);
				claw_close();
				up();
				Delay_ms(1000);
				down();
			}
			if(RxData == 't')
			{
				up();
			}
		}
		

		Delay_ms(20);
		 
				
    }
		/*
    while (1)
    {
				Servo_SetAngle1(servo1);  // ������յ� '1'�����ô˺���
        // ����Ƿ������ݽ���
        if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
        {
            received_data = USART_ReceiveData(USART1);  // ��ȡ���յ�������

            // ֱ�ӽ����յ������ݷ��ͻ�ȥ
            USART_SendData(USART1, (uint16_t)received_data);
            while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

            // �����յ��������Ƿ�Ϊ�ַ� '1'
            if (received_data == '1')
            {
                Servo_SetAngle1(servo1);  // ������յ� '1'�����ô˺���
									
            }
        }

        Delay_ms(20);
    }
		*/
}

// ���Դ���2
/*
int main(void)
{
    uint8_t received_data;
    servo0 = 0;    // ���磬��ʼ��Ϊ0��
    servo1 = 90;   // ��ʼ��Ϊ90��
    servo2 = 180;  // ��ʼ��Ϊ180��

    OLED_Init();
    AD_Init();
    Servo_Init();
    USART1_Init(9600);  // ����ʹ��9600��Ϊ������

    while (1)
    {
        // ����Ƿ������ݽ���
        if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
        {
            received_data = USART_ReceiveData(USART1);  // ��ȡ���յ�������

            // ֱ�ӽ����յ������ݷ��ͻ�ȥ
            USART_SendData(USART1, (uint16_t)received_data);
            while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

            // ���ݽ��յ������ݵ�����Ӧ���ŷ����ƺ���
            switch (received_data)
            {
                case '1':
                    Servo_SetAngle1(servo0);  // ������յ� '1'
                    USART_SendString("Done\n");
                    break;
                case '2':
                    Servo_SetAngle2(servo1);  // ������յ� '2'
                    USART_SendString("Done\n");
                    break;
                case '3':
                    Servo_SetAngle3(servo2);  // ������յ� '3'
                    USART_SendString("Done\n");
                    break;
                default:
                    // ���Դ���ƥ���κ��Ѷ�����������
                    break;
            }
        }

        Delay_ms(20);
    }
}
*/

			
			

