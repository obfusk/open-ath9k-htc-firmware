/*************************************************************************/
/*  Copyright (c) 2006 Atheros Communications, Inc., All Rights Reserved */
/*                                                                       */
/*  Module Name : mem_addrs.h                                            */
/*                                                                       */
/*  Abstract                                                             */
/*      This file contains definition of the memory related information. */
/*                                                                       */
/*  NOTES                                                                */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/

#ifndef _MEM_ADDRS_H_
#define _MEM_ADDRS_H_

#define SYS_ROM_BLOCK_SIZE              (24*1024)
#define SYS_ROM_BLOCK_NUM               1
#define SYS_ROM_SIZE                    (SYS_ROM_BLOCK_SIZE*SYS_ROM_BLOCK_NUM)

#define SYS_RAM_BLOCK_SIZE              (40*1024)

#define SYS_RAM_BLOCK_NUM               4
#define SYS_RAM_SZIE                    (SYS_RAM_BLOCK_SIZE*SYS_RAM_BLOCK_NUM)

/* instruction port area */
#define SYS_I_R0M_REGION_0_BASE         0x8e0000
                                        
#define SYS_I_RAM_REGION_0_BASE         0x900000
#define SYS_I_RAM_REGION_1_BASE         (SYS_I_RAM_REGION_0_BASE+SYS_RAM_BLOCK_SIZE)
#define SYS_I_RAM_REGION_2_BASE         (SYS_I_RAM_REGION_1_BASE+SYS_RAM_BLOCK_SIZE)
#define SYS_I_RAM_REGION_3_BASE         (SYS_I_RAM_REGION_2_BASE+SYS_RAM_BLOCK_SIZE)
                                        
/* data port area */                    
#define SYS_D_R0M_REGION_0_BASE         0x4e0000
                                        
#define SYS_D_RAM_REGION_0_BASE         0x500000
#define SYS_D_RAM_REGION_1_BASE         (SYS_D_RAM_REGION_0_BASE+SYS_RAM_BLOCK_SIZE)
#define SYS_D_RAM_REGION_2_BASE         (SYS_D_RAM_REGION_1_BASE+SYS_RAM_BLOCK_SIZE)
#define SYS_D_RAM_REGION_3_BASE         (SYS_D_RAM_REGION_2_BASE+SYS_RAM_BLOCK_SIZE)

/* data and bss section */

#define SYS_D_RAM_DATA_BSS              SYS_D_RAM_REGION_0_BASE
#define SYS_D_RAM_DATA_BSS_SZ           SYS_RAM_BLOCK_SIZE
#define SYS_D_RAM_STACK_SIZE                (2*1024)
#define SYS_D_RAM_USB_DESC_BUFFER       (SYS_D_RAM_DATA_BSS+SYS_RAM_BLOCK_SIZE)

#define SYS_D_RAM_PCIE_DESC_BUFFER      (SYS_D_RAM_REGION_3_BASE)
#define SPI_FLASH_BASE	0x0F000000
#define SPI_FLASH_MAX_ADDR	0x0FFFFFFF
#define SPI_FLASH_MAX_SIZE	0x01000000
/////////////////////////////////////////////////////////////////////////////////////
#define EEPROM_CTRL_BASE                    0x10000000
#define EEPROM_ADDR_BASE                    (EEPROM_CTRL_BASE+0x2000)

#define EEPROM_SIZE                         0x1000  // 4K addressing space, each has 2 bytes, (a half word)
#define EEPROM_START_OFFSET                 0       // THIS SHOULD NOT MODIFY
#define EEPROM_END_OFFSET                   (EEPROM_START_OFFSET+EEPROM_SIZE-1)   // end of the eeprom offset

/////////////////////////////////////////////////////////////////////////////////////
#define EEPROM_USB_DESCRIPTOR_ADDR          ((uint32_t)&_bss_end)  // address at RAM to put descriptor data
#define USB_DESC_START_ADDR                 0x4
#define USB_DESCRIPTOR_ADDR                 USB_DESC_START_ADDR     // eeprom offset to sotre the descriptor data

#define USB_DESC_IN_EEPROM_SIZE             2                       // indicate eeprom is exist in eeprom
#define USB_DEVICE_DESCRIPTOR_SIZE          16                      // Device Descriptor
#define USB_STRING00_DESCRIPTOR_SIZE        6                       // 16 half word
#define USB_STRING10_DESCRIPTOR_SIZE        12                      // Manufacture data
#define USB_STRING20_DESCRIPTOR_SIZE        16                      // Product/Company data
#define USB_STRING30_DESCRIPTOR_SIZE        8                       // Serial Number

#define USB_DEVICE_PID_SIZE                 1                       // PID SIZE, 1 halfword offset
#define USB_DEVICE_VID_SIZE                 1                       // VID SIZE, 1 halfword offset
    
#define USB_DESC_IN_EEPROM_FLAG_OFFSET      USB_DESCRIPTOR_ADDR
#define USB_DEVICE_DESCRIPTOR_OFFSET        (USB_DESC_IN_EEPROM_FLAG_OFFSET+USB_DESC_IN_EEPROM_SIZE)
#define USB_STRING00_DESCRIPTOR_OFFSET      (USB_DEVICE_DESCRIPTOR_OFFSET+USB_DEVICE_DESCRIPTOR_SIZE)
#define USB_STRING10_DESCRIPTOR_OFFSET      (USB_STRING00_DESCRIPTOR_OFFSET+USB_STRING00_DESCRIPTOR_SIZE)
#define USB_STRING20_DESCRIPTOR_OFFSET      (USB_STRING10_DESCRIPTOR_OFFSET+USB_STRING10_DESCRIPTOR_SIZE)
#define USB_STRING30_DESCRIPTOR_OFFSET      (USB_STRING20_DESCRIPTOR_OFFSET+USB_STRING20_DESCRIPTOR_SIZE)

#define USB_DEVICE_VID_OFFSET               (USB_DEVICE_DESCRIPTOR_OFFSET+4)
#define USB_DEVICE_PID_OFFSET               (USB_DEVICE_VID_OFFSET+USB_DEVICE_VID_SIZE)

#define USB_DESC_IN_EEPROM_FLAG_ADDR        EEPROM_USB_DESCRIPTOR_ADDR
#define USB_DEVICE_DESCRIPTOR_ADDR          (USB_DESC_IN_EEPROM_FLAG_ADDR+(USB_DESC_IN_EEPROM_SIZE*2))
#define USB_STRING00_DESCRIPTOR_ADDR        (USB_DEVICE_DESCRIPTOR_ADDR+(USB_DEVICE_DESCRIPTOR_SIZE*2))
#define USB_STRING10_DESCRIPTOR_ADDR        (USB_STRING00_DESCRIPTOR_ADDR+(USB_STRING00_DESCRIPTOR_SIZE*2))
#define USB_STRING20_DESCRIPTOR_ADDR        (USB_STRING10_DESCRIPTOR_ADDR+(USB_STRING10_DESCRIPTOR_SIZE*2))
#define USB_STRING30_DESCRIPTOR_ADDR        (USB_STRING20_DESCRIPTOR_ADDR+(USB_STRING20_DESCRIPTOR_SIZE*2))

#define USB_DEVICE_VID_ADDR                 (USB_DEVICE_DESCRIPTOR_ADDR+4)
#define USB_DEVICE_PID_ADDR                 (USB_DEVICE_VID_ADDR+USB_DEVICE_VID_SIZE)

#define USB_DESC_IN_EEP_PATTERN             0x41544852  //ATHR

/****************************** patch in eeprom *****************************************/
#define ROM_PATCH_EEPROM_SIZE			2 			// 4 bytes

#define ROM_PATCH_EEPROM_OFFSET         0x3E
#define ROM_PATCH_BUF_ADDR              SYS_D_RAM_REGION_3_BASE

#endif /* _MEM_ADDRS_H_ */