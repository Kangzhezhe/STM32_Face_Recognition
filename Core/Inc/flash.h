#ifndef __FLASH_H
#define __FLASH_H

#include "main.h"  
#include "stm32h7xx_hal_flash.h"
/* Base address of the Flash sectors */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08100000) /* Base address
                                 of Sector 0, 16 Kbytes   */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08120000) /* Base address
                                 of Sector 1, 16 Kbytes   */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08140000) /* Base address
                                 of Sector 2, 16 Kbytes   */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08160000) /* Base address
                                 of Sector 3, 16 Kbytes   */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08180000) /* Base address
                                 of Sector 4, 64 Kbytes   */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x081A0000) /* Base address
                                 of Sector 5, 128 Kbytes  */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x081C0000) /* Base address
                                 of Sector 6, 128 Kbytes  */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x081E0000) /* Base address
                                 of Sector 7, 128 Kbytes  */

int InternalFlash_Test(void);
void Flash_Erase_and_Write(uint32_t address, uint32_t *data, uint32_t length);
void Flash_Read(uint32_t address, uint32_t *data, uint32_t length);

#endif