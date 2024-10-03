/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef DMA_IP_MULTICORE_H_
#define DMA_IP_MULTICORE_H_

/**
*   @file    Dma_Ip_Multicore.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver header file.
*   @details 
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_MULTICORE_VENDOR_ID                       43
#define DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_MULTICORE_SW_MAJOR_VERSION                3
#define DMA_IP_MULTICORE_SW_MINOR_VERSION                0
#define DMA_IP_MULTICORE_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip.h file are of the same vendor */
#if (DMA_IP_MULTICORE_VENDOR_ID != DMA_IP_VENDOR_ID)
    #error "Dma_Ip_Multicore.h and Dma_Ip.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip.h file are of the same Autosar version */
#if ((DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION != DMA_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Multicore.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip.h file are of the same Software version */
#if ((DMA_IP_MULTICORE_SW_MAJOR_VERSION != DMA_IP_SW_MAJOR_VERSION) || \
     (DMA_IP_MULTICORE_SW_MINOR_VERSION != DMA_IP_SW_MINOR_VERSION) || \
     (DMA_IP_MULTICORE_SW_PATCH_VERSION != DMA_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Multicore.h and Dma_Ip.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

const Dma_Ip_InitType * Dma_Ip_GetInitPtr(void);

Dma_Ip_ReturnType Dma_Ip_ValidateMultiCoreInit(void);
Dma_Ip_ReturnType Dma_Ip_ValidateMultiCoreChannelCall(uint32 ChannelNumber);
Dma_Ip_ReturnType Dma_Ip_ValidateMultiCoreInstanceCall(uint32 InstanceNumber);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef DMA_IP_MULTICORE_H_ */
