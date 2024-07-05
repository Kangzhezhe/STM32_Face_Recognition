#include "flash.h"

#define DATA_32                 ((uint32_t)0x87645321)

/* Exported types -----------------------------------------------------*/
/* Exported constants -------------------------------------------------*/
/* 要擦除内部FLASH的起始地址 */
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_7
/* 要擦除内部FLASH的结束地址 */
#define FLASH_USER_END_ADDR     ADDR_FLASH_SECTOR_7

/**
 * @brief  根据输入的地址给出它所在的sector
 * @param  Address：地址
 * @retval 地址所在的sector
 */
static uint32_t GetSector(uint32_t Address)
{
    uint32_t sector = 0;

    if ((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0)) {
        sector = FLASH_SECTOR_0;
    } else if ((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1)) {
        sector = FLASH_SECTOR_1;
    } else if ((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2)) {
        sector = FLASH_SECTOR_2;
    } else if ((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3)) {
        sector = FLASH_SECTOR_3;
    } else if ((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4)) {
        sector = FLASH_SECTOR_4;
    } else if ((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5)) {
        sector = FLASH_SECTOR_5;
    } else if ((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6)) {
        sector = FLASH_SECTOR_6;
    } else {
        sector = FLASH_SECTOR_7;
    }
    return sector;
}

/**
 * @brief  解锁FLASH以便进行写操作
 * @retval None
 */
void Flash_Unlock(void)
{
    HAL_FLASH_Unlock();
}

/**
 * @brief  锁定FLASH防止数据被篡改
 * @retval None
 */
void Flash_Lock(void)
{
    HAL_FLASH_Lock();
}

/**
 * @brief  擦除指定范围内的FLASH扇区
 * @param  start_addr: 起始地址
 * @param  end_addr: 结束地址
 * @retval 操作状态，0表示成功，-1表示失败
 */
int Flash_Erase(uint32_t start_addr, uint32_t end_addr)
{
    uint32_t FirstSector = 0;
    uint32_t NbOfSectors = 0;
    uint32_t SECTORError = 0;
    static FLASH_EraseInitTypeDef EraseInitStruct;

    FirstSector = GetSector(start_addr);
    NbOfSectors = GetSector(end_addr) - FirstSector + 1;

    EraseInitStruct.Banks = FLASH_BANK_2;
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
    EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
    EraseInitStruct.Sector = FirstSector;
    EraseInitStruct.NbSectors = NbOfSectors;

    if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK) {
        return -1;
    }
    return 0;
}

/**
 * @brief  向指定地址写入数据
 * @param  address: 写入数据的地址
 * @param  data: 要写入的数据
 * @retval 操作状态，0表示成功，-1表示失败
 */
int Flash_WriteByte(uint32_t address, uint32_t* data)
{
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, address, data) == HAL_OK) {
        return 0;
    } else {
        return -1;
    }
}

/**
 * @brief  从指定地址读取数据
 * @param  address: 读取数据的地址
 * @retval 读取的数据
 */
uint32_t Flash_ReadByte(uint32_t address)
{
    return *(volatile uint32_t*)address;
}

void Flash_Read(uint32_t address, uint32_t *data, uint32_t length){
    for (uint32_t i = 0; i < length; i++) {
        data[i] = Flash_ReadByte(address + i * 4);
    }
}

void Flash_Erase_and_Write(uint32_t address, uint32_t *data, uint32_t length){
    Flash_Unlock();

    if (Flash_Erase(address, address + length * 4) != 0)
    {
        Flash_Lock();
        return -1;
    }

    Flash_Write(address, data, length);
    Flash_Lock();
}

void Flash_Write(uint32_t address, uint32_t *data, uint32_t length){
    for (uint32_t i = 0; i < length; i++) {
        Flash_WriteByte(address + i * 4, data+i);
    }
}

/**
 * @brief  InternalFlash_Test,对内部FLASH进行读写测试
 * @param  None
 * @retval None
 */
int InternalFlash_Test(void)
{
    uint32_t Address = FLASH_USER_START_ADDR;
    uint32_t DataToWrite[10];
    uint32_t DataRead[10];
    volatile uint32_t MemoryProgramStatus = 0;

    for (int i = 0; i < 10; i++)
    {
        DataToWrite[i] = DATA_32 + i*2;
    }

    // Flash_Unlock();

    // if (Flash_Erase(Address, Address + 10 * 4) != 0)
    // {
    //     Flash_Lock();
    //     return -1;
    // }

    // Flash_Write(Address, DataToWrite, 10);

    // Flash_Lock();

    // Flash_Erase_and_Write(Address, DataToWrite, 10);
    Flash_Read(Address, DataRead, 10);


    MemoryProgramStatus = 0;
    for (int i = 0; i < 10; i++)
    {
        if (DataRead[i] != DataToWrite[i])
        {
            MemoryProgramStatus++;
        }
    }

    return (MemoryProgramStatus == 0) ? 0 : -1;
}