/*
 * Id:        LightingSystemAction.h
 *
 * Function:  VS System Action Expression Pointer Table Header File.
 *
 * Generated: Wed Apr 18 09:05:59 2018
 *
 * Coder 5, 3, 0, 1052
 * 
 * This is an automatically generated file. It will be overwritten by the Coder. 
 * 
 * DO NOT EDIT THE FILE! 
 */


#ifndef __LIGHTINGSYSTEMACTION_H
#define __LIGHTINGSYSTEMACTION_H


/*
 * Include SEM Defines Header File.
 */
#include "SEMBDef.h"


#if (VS_CODER_GUID != 0X00e767911)
#error The generated file does not match the SEMTypes.h header file.
#endif


/*
 * Action Function Prototypes.
 */
extern VS_VOID Blue_LED_ON (VS_VOID);
extern VS_VOID LEDs_OFF (VS_VOID);
extern VS_VOID Red_LED_ON (VS_VOID);


/*
 * Action Expression Pointer Table.
 */
extern VS_ACTIONEXPR_TYPE const LightingSystemVSAction[3];


#endif
