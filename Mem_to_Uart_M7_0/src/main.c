/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : S32K3XX
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
#include "Mcal.h"
#include "Lpuart_Uart_Ip.h"
#include "Dma_Ip.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Siul2_Port_Ip.h"
#include "CDD_Rm.h"

volatile int exit_code = 0;

#define UART_LPUART_INTERNAL_CHANNEL  3

#pragma GCC section bss ".mcal_bss_no_cacheable"
uint8_t uart_tx[8] = {0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80};
#pragma GCC section bss

//uint8_t uart_rx[8];

volatile Lpuart_Uart_Ip_StatusType lpuartStatus = LPUART_UART_IP_STATUS_ERROR;
volatile Lpuart_Uart_Ip_StatusType lpuartStatus1 = LPUART_UART_IP_STATUS_ERROR;
uint32_t remainingByte = 0;
uint32_t remainingByte1 = 0;


void Lpuart3_Callback(const uint8 HwInstance, const Lpuart_Uart_Ip_EventType Event, void *UserData)
{

	if(Event==LPUART_UART_IP_EVENT_TX_EMPTY){
		Lpuart_Uart_Ip_SetTxBuffer(UART_LPUART_INTERNAL_CHANNEL, uart_tx, 8);
	}

}

uint32_t i=0;

int main(void)
{

	OsIf_Init(NULL_PTR);

	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	IntCtrl_Ip_Init(&IntCtrlConfig_0);

	Rm_Init(&Rm_Config);

	Dma_Ip_Init(&Dma_Ip_xDmaInitPB);

	Lpuart_Uart_Ip_Init(UART_LPUART_INTERNAL_CHANNEL, &Lpuart_Uart_Ip_xHwConfigPB_3);

	Lpuart_Uart_Ip_AsyncSend(UART_LPUART_INTERNAL_CHANNEL, uart_tx, 8);
   while(1)
    {

       for(uint32 j =0 ;j<0xffffffff;j++);

    }
    return exit_code;
}


