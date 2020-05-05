/**
  ******************************************************************************
  * @file    font20.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text font20 for STM32xx-EVAL's LCD driver. 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"
#include <avr/pgmspace.h>

// Character bitmaps for Courier New 15pt
const uint8_t Font20_Table[] PROGMEM = 
{
        

	// @640 '0' (14 pixels wide)
	0x00, 0x00, //               
	0x0F, 0x80, //     #####     
	0x1F, 0xC0, //    #######    
	0x18, 0xC0, //    ##   ##    
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x18, 0xC0, //    ##   ##    
	0x1F, 0xC0, //    #######    
	0x0F, 0x80, //     #####     
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @680 '1' (14 pixels wide)
	0x00, 0x00, //               
	0x03, 0x00, //       ##      
	0x1F, 0x00, //    #####      
	0x1F, 0x00, //    #####      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x1F, 0xE0, //    ########   
	0x1F, 0xE0, //    ########   
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @720 '2' (14 pixels wide)
	0x00, 0x00, //               
	0x0F, 0x80, //     #####     
	0x1F, 0xC0, //    #######    
	0x38, 0xE0, //   ###   ###   
	0x30, 0x60, //   ##     ##   
	0x00, 0x60, //          ##   
	0x00, 0xC0, //         ##    
	0x01, 0x80, //        ##     
	0x03, 0x00, //       ##      
	0x06, 0x00, //      ##       
	0x0C, 0x00, //     ##        
	0x18, 0x00, //    ##         
	0x3F, 0xE0, //   #########   
	0x3F, 0xE0, //   #########   
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @760 '3' (14 pixels wide)
	0x00, 0x00, //               
	0x0F, 0x80, //     #####     
	0x3F, 0xC0, //   ########    
	0x30, 0xE0, //   ##    ###   
	0x00, 0x60, //          ##   
	0x00, 0xE0, //         ###   
	0x07, 0xC0, //      #####    
	0x07, 0xC0, //      #####    
	0x00, 0xE0, //         ###   
	0x00, 0x60, //          ##   
	0x00, 0x60, //          ##   
	0x60, 0xE0, //  ##     ###   
	0x7F, 0xC0, //  #########    
	0x3F, 0x80, //   #######     
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @800 '4' (14 pixels wide)
	0x00, 0x00, //               
	0x01, 0xC0, //        ###    
	0x03, 0xC0, //       ####    
	0x03, 0xC0, //       ####    
	0x06, 0xC0, //      ## ##    
	0x0C, 0xC0, //     ##  ##    
	0x0C, 0xC0, //     ##  ##    
	0x18, 0xC0, //    ##   ##    
	0x30, 0xC0, //   ##    ##    
	0x3F, 0xE0, //   #########   
	0x3F, 0xE0, //   #########   
	0x00, 0xC0, //         ##    
	0x03, 0xE0, //       #####   
	0x03, 0xE0, //       #####   
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @840 '5' (14 pixels wide)
	0x00, 0x00, //               
	0x1F, 0xC0, //    #######    
	0x1F, 0xC0, //    #######    
	0x18, 0x00, //    ##         
	0x18, 0x00, //    ##         
	0x1F, 0x80, //    ######     
	0x1F, 0xC0, //    #######    
	0x18, 0xE0, //    ##   ###   
	0x00, 0x60, //          ##   
	0x00, 0x60, //          ##   
	0x00, 0x60, //          ##   
	0x30, 0xE0, //   ##    ###   
	0x3F, 0xC0, //   ########    
	0x1F, 0x80, //    ######     
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @880 '6' (14 pixels wide)
	0x00, 0x00, //               
	0x03, 0xE0, //       #####   
	0x0F, 0xE0, //     #######   
	0x1E, 0x00, //    ####       
	0x18, 0x00, //    ##         
	0x38, 0x00, //   ###         
	0x37, 0x80, //   ## ####     
	0x3F, 0xC0, //   ########    
	0x38, 0xE0, //   ###   ###   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x18, 0xE0, //    ##   ###   
	0x1F, 0xC0, //    #######    
	0x07, 0x80, //      ####     
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @920 '7' (14 pixels wide)
	0x00, 0x00, //               
	0x3F, 0xE0, //   #########   
	0x3F, 0xE0, //   #########   
	0x30, 0x60, //   ##     ##   
	0x00, 0x60, //          ##   
	0x00, 0xC0, //         ##    
	0x00, 0xC0, //         ##    
	0x00, 0xC0, //         ##    
	0x01, 0x80, //        ##     
	0x01, 0x80, //        ##     
	0x01, 0x80, //        ##     
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x03, 0x00, //       ##      
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @960 '8' (14 pixels wide)
	0x00, 0x00, //               
	0x0F, 0x80, //     #####     
	0x1F, 0xC0, //    #######    
	0x38, 0xE0, //   ###   ###   
	0x30, 0x60, //   ##     ##   
	0x38, 0xE0, //   ###   ###   
	0x1F, 0xC0, //    #######    
	0x1F, 0xC0, //    #######    
	0x38, 0xE0, //   ###   ###   
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x38, 0xE0, //   ###   ###   
	0x1F, 0xC0, //    #######    
	0x0F, 0x80, //     #####     
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               

	// @1000 '9' (14 pixels wide)
	0x00, 0x00, //               
	0x0F, 0x00, //     ####      
	0x1F, 0xC0, //    #######    
	0x38, 0xC0, //   ###   ##    
	0x30, 0x60, //   ##     ##   
	0x30, 0x60, //   ##     ##   
	0x38, 0xE0, //   ###   ###   
	0x1F, 0xE0, //    ########   
	0x0F, 0x60, //     #### ##   
	0x00, 0xE0, //         ###   
	0x00, 0xC0, //         ##    
	0x03, 0xC0, //       ####    
	0x3F, 0x80, //   #######     
	0x3E, 0x00, //   #####       
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
	0x00, 0x00, //               
};


sFONT Font20 = {
  Font20_Table,
  14, /* Width */
  20, /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
