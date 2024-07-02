#ifndef __usart_H
#define __usart_H

#include "system.h" 


void USART1_Init(u32 bound);

void USART_SendString(const char* str);

void Serial_SendByte(uint8_t Byte);

uint8_t Serial_GetRxFlag(void);

uint8_t Serial_GetRxData(void);








#endif


