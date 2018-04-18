/*
 * Id:        SEMBDef.h
 *
 * Function:  SEM Defines Header File.
 *
 * Generated: Wed Apr 18 09:05:59 2018
 *
 * Coder 5, 3, 0, 1052
 * 
 * This is an automatically generated file. It will be overwritten by the Coder. 
 * 
 * DO NOT EDIT THE FILE! 
 */


#ifndef __SEMBDEF_H
#define __SEMBDEF_H


/*
 * Include SEM Types Header File.
 */
#include "SEMTypes.h"


#if (VS_CODER_GUID != 0X00e767911)
#error The generated file does not match the SEMTypes.h header file.
#endif


/*
 * Number of Identifiers.
 */
#define VS_NOF_ACTION_EXPRESSIONS        0X003  /*   3 */
#define VS_NOF_ACTION_FUNCTIONS          0X003  /*   3 */
#define VS_NOF_EVENT_GROUPS              0X000  /*   0 */
#define VS_NOF_EVENTS                    0X004  /*   4 */
#define VS_NOF_EXTERNAL_VARIABLES        0X000  /*   0 */
#define VS_NOF_GUARD_EXPRESSIONS         0X000  /*   0 */
#define VS_NOF_INSTANCES                 0X001  /*   1 */
#define VS_NOF_INTERNAL_VARIABLES        0X000  /*   0 */
#define VS_NOF_SIGNALS                   0X000  /*   0 */
#define VS_NOF_STATE_MACHINES            0X001  /*   1 */
#define VS_NOF_STATES                    0X003  /*   3 */


/*
 * Signal Queue Size.
 */
#define VS_SIGNAL_QUEUE_SIZE             0X001  /*   1 */


/*
 * Conditional Compilation Definitions.
 */
#define SEM_FUNCEXPHANDLING              0
#define SEM_GUARD_EXPRESSION             0
#define SEM_SIGNAL_DB                    0
#define VS_NOF_SYSTEMS                   1
#define VS_REALLINKMODE                  0
#define VS_RL_USE_EXTKWS                 0
#define VS_USE_HEAP                      0
#define SEM_INQUIRY                      1


/*
 * Conditional Compilation Definitions.
 */
#define SEM_DEDUCT_FUNC                  0
#define SEM_DEDUCT_WITH_VA_LIST          0
#define SEM_SPEED                        0


/*
 * Undefined State.
 */
#define STATE_UNDEFINED                  0X0FF  /* 255 */


/*
 * Undefined Event.
 */
#define EVENT_UNDEFINED                  0X0FF  /* 255 */


/*
 * Undefined Event Group.
 */
#define EVENT_GROUP_UNDEFINED            0X0FF  /* 255 */


/*
 * Event Termination ID.
 */
#define EVENT_TERMINATION_ID             0X0FF  /* 255 */


/*
 * Action Expression Termination ID.
 */
#define ACTION_EXPRESSION_TERMINATION_ID 0X0FF  /* 255 */
#define ACTION_FPT_NAME LightingSystemVSAction


/*
 * Type qualifier macros
 */
#define VS_TQ_RULEBASE                 const 
#define VS_TQ_GUARDEXPRCOL             const 
#define VS_TQ_ACTIONEXPRCOL            const 
#define VS_TQ_CONTEXT                  
#define VS_RL_TQ_DATA                  
#define VS_RL_TQ_PROTOCOL_DATA         
#define VS_RL_TQ_CONST_DATA            


/*
 * Functional expression type definitions
 */
typedef VS_BOOL (* VS_GUARDEXPR_TYPE) (VS_VOID);
typedef VS_VOID (* VS_ACTIONEXPR_TYPE) (VS_VOID);


/*
 * SEM Library Datatype Definition.
 */
typedef struct SEMDATALightingSystem
{
  VS_UINT8                                      Status;
  VS_UINT8                                      State;
  VS_UINT8                                      DIt;
  VS_UINT8                                      nNo;
  VS_UINT8                                      nNeg;
  VS_UINT8                                      nPos;
  VS_UINT8                                      nNxt;
  VS_UINT8                                      nAction;
  SEM_EVENT_TYPE                                EventNo;
  SEM_RULE_INDEX_TYPE                           iRI;
  SEM_RULE_TABLE_INDEX_TYPE                     iFirstR;
  SEM_RULE_TABLE_INDEX_TYPE                     iLastR;
  SEM_INTERNAL_TYPE                             i;
  SEM_STATE_TYPE                                sa;
  VS_UINT8                                      Chg;
  SEM_STATE_TYPE                                CSV[VS_NOF_STATE_MACHINES];
  SEM_STATE_TYPE                                WSV[VS_NOF_STATE_MACHINES];
  VS_UINT8                                      InqAct;
  VS_UINT8                                      IIt;
  VS_UINT8                                      nInqNo;
  VS_UINT8                                      nInqNeg;
  VS_UINT8                                      nInqPos;
  SEM_EVENT_TYPE                                InqEventNo;
  SEM_EVENT_TYPE                                InqCurrentEventNo;
  SEM_EVENT_TYPE                                InqFoundEventNo;
  SEM_RULE_INDEX_TYPE                           iInqRI;
  SEM_RULE_TABLE_INDEX_TYPE                     iInqFirstR;
  SEM_RULE_TABLE_INDEX_TYPE                     iInqLastR;
  SEM_INTERNAL_TYPE                             j;
  SEM_STATE_TYPE                                sb;
} SEMDATALightingSystem;


/*
 * VS System Datatype Definition.
 */
typedef struct
{
  VS_UINT8       SMI[0X003];
  VS_UINT8       RD[0X017];
  VS_UINT8       RI[0X005];
  VS_UINT8       RTI[0X005];
  VS_UCHAR       ENames[0X024];
  VS_UINT8       ENI[0X004];
  VS_UCHAR       SNames[0X040];
  VS_UINT8       SNI[0X003];
  VS_UCHAR       ANames[0X020];
  VS_UINT8       ANI[0X003];
} VSDATALightingSystem;


/*
 * Data External Declaration.
 */
extern VSDATALightingSystem const LightingSystem;

extern SEMDATALightingSystem SEMLightingSystem;


/*
 * Action Functions Header File Name.
 */
#define SEM_FN_ACTION_HEADER           "LightingSystemAction.h"


/*
 * Action Functions Identifier Name.
 */
#define SEM_IN_ACTION                  LightingSystemVSAction


/*
 * Action Expression Collection Macro.
 */
#define VSAction                       LightingSystemVSAction


#endif
