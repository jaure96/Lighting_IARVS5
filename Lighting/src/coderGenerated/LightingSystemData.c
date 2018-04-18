/*
 * Id:        LightingSystemData.c
 *
 * Function:  VS System Data Source File.
 *
 * Generated: Wed Apr 18 09:05:59 2018
 *
 * Coder 5, 3, 0, 1052
 * 
 * This is an automatically generated file. It will be overwritten by the Coder. 
 * 
 * DO NOT EDIT THE FILE! 
 */


/*
 * Include SEM Library Header File.
 */
#include "SEMLibB.h"


#if (VS_CODER_GUID != 0X00e767911)
#error The generated file does not match the SEMTypes.h header file.
#endif


/*
 * Include VS System Data Header File.
 */
#include "LightingSystemData.h"


/*
 * Include VS System Action Expression Pointer Table File.
 */
#include "LightingSystemAction.h"


/*
 * Include Compiler Standard Library Header Files.
 */
#if (SEM_DEDUCT_WITH_VA_LIST)
#include <stdarg.h>
#endif


/*
 * Action Expression Pointer Table.
 */
VS_ACTIONEXPR_TYPE const LightingSystemVSAction[3] = 
{
  Blue_LED_ON,
  LEDs_OFF,
  Red_LED_ON
};
