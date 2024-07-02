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

// 测试代码
int main(void)
{
    uint8_t received_data;
//十字 右 环岛 左	
    Servo_Init();
    USART1_Init(9600);  // 假设使用9600作为波特率
		
		while(1)
    {
		
        // 检查是否有数据接收
			  /*
        if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
        {
            received_data = USART_ReceiveData(USART1);  // 读取接收到的数据

            // 直接将接收到的数据发送回去
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
				Servo_SetAngle1(servo1);  // 如果接收到 '1'，调用此函数
        // 检查是否有数据接收
        if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
        {
            received_data = USART_ReceiveData(USART1);  // 读取接收到的数据

            // 直接将接收到的数据发送回去
            USART_SendData(USART1, (uint16_t)received_data);
            while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

            // 检查接收到的数据是否为字符 '1'
            if (received_data == '1')
            {
                Servo_SetAngle1(servo1);  // 如果接收到 '1'，调用此函数
									
            }
        }

        Delay_ms(20);
    }
		*/
}

// 测试代码2
/*
int main(void)
{
    uint8_t received_data;
    servo0 = 0;    // 例如，初始化为0度
    servo1 = 90;   // 初始化为90度
    servo2 = 180;  // 初始化为180度

    OLED_Init();
    AD_Init();
    Servo_Init();
    USART1_Init(9600);  // 假设使用9600作为波特率

    while (1)
    {
        // 检查是否有数据接收
        if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
        {
            received_data = USART_ReceiveData(USART1);  // 读取接收到的数据

            // 直接将接收到的数据发送回去
            USART_SendData(USART1, (uint16_t)received_data);
            while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

            // 根据接收到的数据调用相应的伺服控制函数
            switch (received_data)
            {
                case '1':
                    Servo_SetAngle1(servo0);  // 如果接收到 '1'
                    USART_SendString("Done\n");
                    break;
                case '2':
                    Servo_SetAngle2(servo1);  // 如果接收到 '2'
                    USART_SendString("Done\n");
                    break;
                case '3':
                    Servo_SetAngle3(servo2);  // 如果接收到 '3'
                    USART_SendString("Done\n");
                    break;
                default:
                    // 可以处理不匹配任何已定义命令的情况
                    break;
            }
        }

        Delay_ms(20);
    }
}
*/

			
			

