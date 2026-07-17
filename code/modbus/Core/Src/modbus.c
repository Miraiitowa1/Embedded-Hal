#include "modbus.h"
#include "stdio.h"
#include "stm32f1xx_hal.h"
#include "i2c.h"
#include "mb.h"

uint8_t SlaveAddress = 1; //设备默认地址为1

/**
  * @brief  从EEPROM中读取从机地址
  * @param  addr : EEPROM的存储地址
  *		   	pdata : 读回来的数据
  * @retval SET RESET
  */
uint8_t ReadSlaveAddress(uint8_t addr, uint8_t *pdata)
{
	HAL_I2C_Mem_Read(&hi2c1, AT24C02_ADDRESS_READ, addr,I2C_MEMADD_SIZE_8BIT,pdata, 1, 1000);
	if(*pdata == 0)	//如果读出的数据为0，0不能作为从机地址，地址手动加1
	{
		*pdata = 1;
	}
	return SET;
}

/**
  * @brief  写设备的从机地址到EEPROM
  * @param  addr : EEPROM的存储地址
  *		   	pdata : 要写入的数据
  * @retval SET RESET
  */
uint8_t WriteSlaveAddress(uint8_t addr, uint8_t data)
{
	HAL_I2C_Mem_Write(&hi2c1, AT24C02_ADDRESS_WRITE,addr,I2C_MEMADD_SIZE_8BIT,&data,1, 1000);
	return SET;
}

void Modbus_Init(void)
{
	//程序执行后，会自动从EEPROM读取设备的地址
	ReadSlaveAddress(0, &SlaveAddress);
	printf("SlaveAddress %x\n",SlaveAddress);
	eMBInit(MB_RTU, SlaveAddress, 0, 115200, MB_PAR_NONE); // 初始化modbus为RTU方式， 波特率115200， 无校验
	eMBEnable();
}
