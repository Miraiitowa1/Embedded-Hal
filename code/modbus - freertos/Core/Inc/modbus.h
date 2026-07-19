#ifndef __MODBUS_H__
#define __MODBUS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

	
#define LED1_CMD		(1<<0)
#define LED2_CMD		(1<<1)
#define BEEP_CMD		(1<<2)
#define RELAY_CMD		(1<<3)

// 只读的线圈
// 十路保持寄存器 可读可写的2字节寄存器
extern uint16_t REG_HOLD_BUF[];

extern	uint8_t SlaveAddress; //设备默认地址为1
extern	uint8_t Modify_SlaveAddress_Flag; //修改从机地址的标志位
extern	uint8_t TIM3_Timerout_Flag; //500ms定时器到，刷新各种传感器
	
void Modbus_Init(void);
uint8_t ReadSlaveAddress(uint8_t addr, uint8_t *pdata);
uint8_t WriteSlaveAddress(uint8_t addr, uint8_t data);
void Modbus_Parse(void);
	
#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

