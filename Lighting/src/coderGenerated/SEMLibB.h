/*
 * Id:        SEMLibB.h
 *
 * Function:  Contains definitions needed for API functions.
 *
 * Generated: Wed Apr 18 09:05:59 2018
 *
 * Coder 5, 3, 0, 1052
 * 
 * This is an automatically generated file. It will be overwritten by the Coder. 
 * 
 * DO NOT EDIT THE FILE! 
 */


#ifndef __SEMLIBB_H
#define __SEMLIBB_H


#include <stddef.h>


/* Include SEM Library Definition Header File. */
#include "SEMBDef.h"


#if (VS_CODER_GUID != 0X00e767911)
#error The generated file does not match the SEMTypes.h header file.
#endif


#ifndef NULL
#define NULL ((void *) 0)
#endif


#ifndef VS_TRUE
#define VS_TRUE (1)
#endif


#ifndef VS_FALSE
#define VS_FALSE (0)
#endif


#ifdef SEM_USE_GUARD_TYPE_CAST
#define SEM_GUARD_TYPE_CAST (unsigned char)
#else
#define SEM_GUARD_TYPE_CAST
#endif


#ifdef VS_RUNTIME_INFO
typedef struct
{
  signed char pSignatureVersion[VS_SIGNATURE_VERSION_LENGTH];
  signed char pSignatureContent[VS_SIGNATURE_CONTENT_LENGTH];
} VSRunTimeInfo;
#endif


/*
 * Status code:     SES_OKAY.
 *
 * Explanation:     Function performed successfully.
 *
 * Solution:        None.
 */
#define SES_OKAY              0x00


/*
 * Status code:     SES_FOUND.
 *
 * Explanation:     The called function has returned an identifier index
 *                  number.
 *
 * Solution:        Process the returned identifier index number. If the
 *                  function SEM_GetInput or SEM_GetOutput was called, the
 *                  function can be called again to find more events or
 *                  action expressions.
 */
#define SES_FOUND             0x01


/*
 * Status code:     SES_ACTIVE.
 *
 * Explanation:     The completion code has one of the two expositions:
 *                  1)  A state/event deduction is started, while an event
 *                      inquiry is active. All inquired events have not been
 *                      returned by the function SEM_GetInput.
 *                  2)  An event inquiry is started, while a state/event
 *                      deduction is active. All deduced action expressions 
 *                      have not been returned by the function SEM_GetOutput 
 *                      and the SEM_NextState has not been called in order to 
 *                      complete the state/event deduction.
 *
 * Solution:        The completion code is a warning and perhaps the
 *                  application program should be rewritten. An event inquiry
 *                  and a state/event deduction should not be active at the
 *                  same time.
 */
#define SES_ACTIVE            0x02


/*
 * Error code:      SES_CONTRADICTION.
 *
 * Explanation:     A contradiction has been detected between two states in a
 *                  state machine.
 *
 * Solution:        Check the VS System.
 */
#define SES_CONTRADICTION     0x03


/*
 * Error code:      SES_RANGE_ERR.
 *
 * Explanation:     You are making a reference to an identifier that does not
 *                  exist. Note that the first index number is 0. If the 
 *                  VS System has 4 identifiers of the same type and you use a
 *                  function with the variable parameter = 4, the function 
 *                  will return an SES_RANGE_ERR error. In this case the 
 *                  highest variable index number is 3.
 *
 * Solution:        The application program will check the index parameters 
 *                  with one of the following symbols defined in the SEMBDef.h 
 *                  file:
 *
 *                    VS_NOF_EVENTS
 *                    VS_NOF_STATES
 *                    VS_NOF_ACTION_FUNCTIONS
 *                    VS_NOF_STATE_MACHINES
 */
#define SES_RANGE_ERR         0x04


/*
 * Error code:      SES_TEXT_TOO_LONG.
 *
 * Explanation:     The requested text is longer than the specified maximum
 *                  length.
 *
 * Solution:        Increase the maximum length.
 */
#define SES_TEXT_TOO_LONG     0x05


 /*
 * Error code:      SES_TYPE_ERR.
 *
 * Explanation:     A text function has been called with the wrong identifier
 *                  type or the specified text is not included in the 
 *                  VS System.
 *
 * Solution:        Use the identifier type symbols (EVENT_TYPE, STATE_TYPE
 *                  or ACTION_TYPE) defined in this file and remember
 *                  to include wanted text in the VS System.
 */
#define SES_TYPE_ERR          0x06


/*
 * Error code:      SES_EMPTY.
 *
 * Explanation:     No events have been given to the SEM_Deduct function before
 *                  calling this function.
 *
 * Solution:        Call the SEM_Deduct function with an event number.
 */
#define SES_EMPTY             0x07


/*
 * Error code:      SES_BUFFER_OVERFLOW.
 *
 * Explanation:     A destination buffer cannot hold the number of items found.
 *
 * Solution:        Call the function with an extended buffer as destination.
 */
#define SES_BUFFER_OVERFLOW   0x08


/*
 * Error code:      SES_SIGNAL_QUEUE_FULL.
 *
 * Explanation:     Signal queue is full.
 *
 * Solution:        Increase the maximum signal queue size in the VS System or
 *                  via the VS Coder signal queue size option.
 */
#define SES_SIGNAL_QUEUE_FULL 0x09


/*
 * Identifier types, used when getting texts and explanations.
 */
#define EVENT_TYPE  0x01
#define STATE_TYPE  0x02
#define ACTION_TYPE 0x03
#define INPUTTYPE   EVENT_TYPE 
#define STATETYPE   STATE_TYPE
#define OUTPUTTYPE  ACTION_TYPE


/*
 * Used internally in the API
 */
#define STATE_SEM_INITIALIZE  0x00
#define STATE_SEM_SIGNAL      0x01
#define STATE_SEM_PREPARE     0x02
#define STATE_SEM_CONSULT     0x03
#define STATE_SEM_OUTPUT      0x04
#define STATE_SEM_OKAY        0x05


/*
 * Name        :    SEM_InitAll
 *
 * Description :    The function is a wrapper to all initialization 
 *                  functions. The function calls the following functions
 *                  in the listed order (provided the specific function 
 *                  exists): 
 *                    SEM_Init
 *                    SEM_InitExternalVariables
 *                    SEM_InitInternalVariables
 *                    SEM_InitSignalQueue
 *                    SEM_InitInstances
 *
 * Argument    :    None.
 *
 * Return      :    None.
 *
 * Portability :    ANSI-C Compiler.
 */
void SEM_InitAll (void);


/*
 * Name        :    SEM_Init
 *
 * Description :    Before calling any other functions this function must be
 *                  called to initialize the VS System. In addition it is
 *                  possible to call the initialization functions for the 
 *                  signal queue, internal variables and external variables.
 *
 * Argument    :    None.
 *
 * Return      :    None.
 *
 * Portability :    ANSI-C Compiler.
 */
void SEM_Init (void);


/*
 * Name        :    SEM_Deduct
 *
 * Description :    The function prepares the reception of action expressions,
 *                  that can be deduced on the basis of the given event, the
 *                  internal current state vector and the rules in the 
 *                  VS System.
 *                  All action expressions are deduced by continuously calling 
 *                  the function SEM_GetOutput or one call to the
 *                  SEM_GetOutputAll function.
 *                  Before calling the SEM_Deduct function again, the
 *                  SEM_NextState or SEM_NextStateChg must be called to
 *                  enter the new states, if any.
 *                  The function will be auto generated by the VS Coder during
 *                  code generation if double buffering and/or event 
 *                  parameters are present.
 *
 * Argument    :    EventNo:
 *                    Event number to be processed.
 *
 *                  Variable number of arguments:
 *                    Used if at least one event has a parameter. 
 *                    The function call must include one argument for each 
 *                    type name declared in the parameter list for each event. 
 *    
 *                    This sample declaration is for an event with three 
 *                    parameters:
 *
 *                      EventName (VS_UINT8 par1, VS_CHAR par2, VS_LONG par3)
 *
 *                    How to call the SEM_Deduct function for the event 
 *                    EventName:
 *
 *                      SEM_Deduct (EventName, par1, par2, par3);
 *
 * Return      :    Completion code:
 *
 *                    SES_ACTIVE:
 *                      The function SEM_Inquiry has been called. All inquired
 *                      events have not been returned by the function
 *                      SEM_GetInput or SEM_GetInputAll. The state/event
 *                      deduction is okay, but the user should not call the
 *                      function SEM_GetInput before the functions
 *                      SEM_NextState or SEM_NextStateChg and SEM_Inquiry have
 *                      been called.
 *
 *                    SES_RANGE_ERR:
 *                      Event is out of range.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
#if (SEM_DEDUCT_WITH_VA_LIST)
unsigned char SEM_Deduct (SEM_EVENT_TYPE EventNo, ...);
#else
unsigned char SEM_Deduct (SEM_EVENT_TYPE EventNo);
#endif


/*
 * Name        :    SEM_GetOutput
 *
 * Description :    The function finds an action expression, if any such one
 *                  has been deduced on the basis of the event given to the 
 *                  function
 *                  SEM_Deduct, the internal current state vector and the
 *                  rules in the VS System.
 *                  All action expressions are found by continuous calls to 
 *                  the SEM_GetOutput function.
 *                  When the SEM_GetOutput returna the completion code
 *                  SES_OKAY, all action expressions have been found.
 *                  Use SEM_Action or SEM_TableAction to call the action
 *                  expression functions.
 *
 * Argument    :    ActionNo:
 *                    Pointer to store the deduced action expression.
 *
 * Return      :    Completion code:
 *
 *                    SES_CONTRADICTION:
 *                      Contradiction detected, the VS System is not 
 *                      consistent. Check the VS System. 
 *                      You will also get this error code here if you forget
 *                      to call SEM_Init function.
 *
 *                    SES_EMPTY:
 *                      No event has been given to the SEM_Deduct function, i.e.
 *                      SEM_Deduct has not been called before calling the
 *                      SEM_GetOutput function.
 *
 *                    SES_FOUND:
 *                      An action expression has been found. The user can 
 *                      continue to call the SEM_GetOutput in order to have 
 *                      more action expressions found.
 *
 *                    SES_SIGNAL_QUEUE_FULL:
 *                      The signal queue is full. Increase the signal queue 
 *                      size in the VS System.
 *                      Calling the SEM_InitSignalQueue function can reset the 
 *                      signal queue.
 *
 *                    SES_OKAY:
 *                      Success. All action expressions have been found.
 *                      The user can now call the SEM_NextState or
 *                      SEM_NextStateChg function to change state.
 *                      If SEM_Deduct is called with the same event and
 *                      SEM_NextState and SEM_NextStateChg is not called, all
 *                      action expresssions can be found again by calling 
 *                      SEM_GetOutput or SEM_GetOutputAll.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_GetOutput (SEM_ACTION_EXPRESSION_TYPE *ActionNo);


/*
 * Name        :    SEM_GetOutputAll
 *
 * Description :    The function finds all action expression(s), if any such 
 *                  ones have been deduced on basis of the given event to the 
 *                  function SEM_Deduct, the internal current state vector and 
 *                  the rules in the VS System.
 *                  SEM_GetOutputAll returns the completion code SES_OKAY if
 *                  all action expressions have been found successfully.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    ActionVector:
 *                    Pointer to array to store the deduced action 
 *                    expression(s).
 *
 *                  MaxSize:
 *                    Specifies the maximum length of the action vector
 *                    including the definition 
 *                    ACTION_EXPRESSION_TERMINATION_ID.
 *
 * Return      :    Completion code:
 *
 *                    SES_BUFFER_OVERFLOW:
 *                      The specified MaxSize is too small. The actions 
 *                      expressions vector array is not valid.
 *
 *                    SES_CONTRADICTION:
 *                      Contradiction detected, the VS System is not 
 *                      consistent. Check the VS System.
 *                      You will also get this error code here if you forget
 *                      to call SEM_Init.
 *
 *                    SES_EMPTY:
 *                      No event has been given to the SEM_Deduct function,
 *                      i.e. SEM_Deduct has not been called before calling the
 *                      SEM_GetOutputAll function.
 *
 *                    SES_OKAY:
 *                      Success. All action expressions have been found.
 *                      The user can now call the SEM_NextState or
 *                      SEM_NextStateChg function to change state.
 *                      If SEM_Deduct is called with the same event and
 *                      SEM_NextState and SEM_NextStateChg are not called, all
 *                      action expressions can be found again by calling 
 *                      SEM_GetOutput or SEM_GetOutputAll.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_GetOutputAll (SEM_ACTION_EXPRESSION_TYPE *ActionVector, SEM_ACTION_EXPRESSION_TYPE MaxSize);


/*
 * Name        :    SEM_NextStateChg
 *
 * Description :    The function will update the internal current state 
 *                  vector, if any states can be found on the basis of the 
 *                  given event to the function SEM_Deduct, the internal 
 *                  current state vector and the rules in the VS System.
 *                  The returned completion code will tell if the internal
 *                  state vector was updated with a new value or not. This
 *                  feature could be used to determine if the SEM_Inquiry
 *                  function needs to be called.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    None.
 *
 * Return      :    Completion code:
 *
 *                    SES_CONTRADICTION:
 *                      Contradiction detected, the VS System is not
 *                      consistent. Check the VS System.
 *                      Your will also get this error code here if you
 *                      forget to call SEM_Init.
 *
 *                    SES_EMPTY:
 *                      No event has been given to the SEM_Deduct function,
 *                      i.e. SEM_Deduct has not been called before calling the
 *                      SEM_NextStateChg function.
 *
 *                    SES_FOUND:
 *                      Success. The internal state vector was updated to a 
 *                      new value.
 *
 *                    SES_OKAY:
 *                      Success. The internal state vector was updated to the 
 *                      same value as before.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_NextStateChg (void);


/*
 * Name        :    SEM_Inquiry
 *
 * Description :    The function prepares for the finding the events that can 
 *                  be used to perform transactions from the current state. 
 *                  All events are found by continuous calls to the function 
 *                  SEM_GetInput or one call to SEM_GetInputAll.
 *                  As the function will inquire events on the basis of
 *                  the internal current state vector, a state transition
 *                  should be finished, i.e the previously called function
 *                  should be SEM_Init, SEM_NextState or SEM_NextStateChg.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    None.
 *
 * Return      :    Completion code:
 *
 *                    SES_ACTIVE:
 *                      A state transition has not been completed. The user
 *                      should not call the function SEM_GetInput because
 *                      wrong events could be inquired. The function
 *                      SEM_NextState or SEM_NextStateChg is called to finish
 *                      running transactions.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_Inquiry (void);


/*
 * Name        :    SEM_GetInput
 *
 * Description :    The function is used to find events that can be used to 
 *                  perform state/event transitions and/or to derive action
 *                  expressions from the current state. All events are found
 *                  by continuous calls to this function.
 *                  Because the function will inquire events on the basis of
 *                  the internal current state vector, a state/event deduction
 *                  should not be running.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    EventNo:
 *                    Pointer to store the inquired event number.
 *
 *                  EventList:
 *                    Pointer to an array that holds the event numbers that 
 *                    can be inquired. The EventList must be terminated with
 *                    definition EVENT_TERMINATION_ID.
 *                    If the pointer is NULL, then all events can be inquired.
 *
 * Return      :    Completion code:
 *
 *                    SES_FOUND:
 *                      An event has been found.
 *                      The user should continue to call the SEM_GetInput, 
 *                      since more events may be found.
 *
 *                    SES_RANGE_ERR:
 *                      Event number from the EventList is out of range.
 *
 *                    SES_OKAY:
 *                      Success. No more events can be found.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_GetInput (SEM_EVENT_TYPE *EventNo, SEM_EVENT_TYPE *EventList);


/*
 * Name        :    SEM_GetInputAll 
 *
 * Description :    The function is used to find all events that can be used 
 *                  to perform state/event transitions and/or to derive 
 *                  action expressions from the current state. All events are 
 *                  found by one call to this function.
 *                  Because the function will inquire events on the basis of
 *                  the internal current state vector, a state/event deduction
 *                  should not be running.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    EventVector:
 *                    Pointer to array where to store the inquired events.
 *                    The array is terminated with definition 
 *                    EVENT_TERMINATION_ID on success.
 *
 *                  EventList:
 *                    Pointer to an array, which holds the event numbers that, 
 *                    can be inquired. The EventList must be terminated with
 *                    definition EVENT_TERMINATION_ID.
 *                    If the pointer is NULL, then all events can be inquired.
 *
 *                  MaxSize:
 *                    Specifies the maximum length of the event vector 
 *                    including the definition EVENT_TERMINATION_ID.
 *
 * Return      :    Completion code:
 *
 *                    SES_BUFFER_OVERFLOW:
 *                      The specified MaxSize is too small. The inquired 
 *                      events list is not valid.
 *
 *                    SES_RANGE_ERR:
 *                      Event number from the EventList is out of range.
 *
 *                    SES_OKAY:
 *                      Success. All events have been found.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_GetInputAll (SEM_EVENT_TYPE *EventVector, SEM_EVENT_TYPE *EventList, SEM_EVENT_TYPE MaxSize);


/*
 * Name        :    SEM_Name
 *
 * Description :    The function gets the ASCII name of the specified 
 *                  identifier.
 *                  The function can only be used (and compiled) if the 
 *                  VS System contains at least one type of names.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    IdentType:
 *                    Must contain the identifier type of the identifier 
 *                    number, which can be EVENT_TYPE, STATE_TYPE or 
 *                    ACTION_TYPE.
 *
 *                  IdentNo:
 *                    Must contain the index number of an identifier.
 *
 *                  Text:
 *                    Must be a pointer to a text string. If the function
 *                    terminates successfully, the text string contains the
 *                    name of the specified identifier.
 *
 *                  MaxSize:
 *                    Specifies the maximum length of the text including the
 *                    NULL termination character.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      Identifier number is out of range.
 *
 *                    SES_TEXT_TOO_LONG:
 *                      The text length exceeds than MaxSize.
 *
 *                    SES_TYPE_ERR:
 *                      The identifier type is not correct. Remember to 
 *                      include the wanted text in the VS System and specify 
 *                      the correct identifier type when calling this 
 *                      function.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_Name (unsigned char IdentType, SEM_EXPLANATION_TYPE IdentNo, char *Text, unsigned short MaxSize);


/*
 * Name        :    SEM_NameAbs 
 *
 * Description :    The function gets a pointer to the ASCII name of the 
 *                  specified identifier. 
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    IdentType:
 *                    Must contain the identifier type of the identifier 
 *                    number. It can be EVENT_TYPE, STATE_TYPE or 
 *                    ACTION_TYPE.
 *
 *                  IdentNo:
 *                    Must contain the index number of an identifier.
 *
 *                  Text:
 *                    Must be an address of a pointer to a text string. If the
 *                    function terminates successfully, the text pointer 
 *                    contains the address of the name of the specified
 *                    identifier.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      Identifier number is out of range.
 *
 *                    SES_TYPE_ERR:
 *                      The identifier type is not correct. Remember to 
 *                      include the wanted text in the VS System and specify 
 *                      the correct identifier type when calling this 
 *                      function.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_NameAbs (unsigned char IdentType, SEM_EXPLANATION_TYPE IdentNo, char VS_TQ_RULEBASE **Text);


/*
 * Name        :    SEM_Expl
 *
 * Description :    The function gets the ASCII explanation of the specified 
 *                  identifier.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    IdentType:
 *                    Must contain the identifier type of the identifier 
 *                    number. It can be EVENT_TYPE, STATE_TYPE or 
 *                    ACTION_TYPE.
 *
 *                  IdentNo:
 *                    Must contain the index number of an identifier.
 *
 *                  Text:
 *                    Must be a pointer to a text string. If the function
 *                    terminates successfully, the text string contains the
 *                    name of the specified identifier.
 *
 *                  MaxSize:
 *                    Specifies the maximum length of the text including the
 *                    NULL termination character.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      Identifier number is out of range.
 *
 *                    SES_TEXT_TOO_LONG:
 *                      The text length exceeds than MaxSize.
 *
 *                    SES_TYPE_ERR:
 *                      The identifier type is not correct. Remember to 
 *                      include wanted text in the VS System and specify 
 *                      the correct identifier type when calling this 
 *                       function.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_Expl (unsigned char IdentType, SEM_EXPLANATION_TYPE IdentNo, char *Text, unsigned short MaxSize);


/*
 * Name        :    SEM_ExplAbs
 *
 * Description :    The funciton gets the absolute address of an ASCII 
 *                  explanation of the specified identifier.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    IdentType:
 *                    Must contain the identifier type of the identifier 
 *                    number. It can be EVENT_TYPE, STATE_TYPE or 
 *                    ACTION_TYPE.
 *
 *                  IdentNo:
 *                    Must contain the index number of an identifier.
 *
 *                  Text:
 *                    Must be a pointer to a char pointer. If the function
 *                    terminates successfully, the pointer contains the 
 *                    absolute address of the name of the specified identifier.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      Identifier number is out of range.
 *
 *                    SES_TYPE_ERR:
 *                      The identifier type is not correct. Remember to 
 *                      include the wanted text in the VS System and specify 
 *                      the correct identifier type when calling this
 *                      function.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_ExplAbs (unsigned char IdentType, SEM_EXPLANATION_TYPE IdentNo, char VS_TQ_RULEBASE **Text);


/*
 * Name        :    SEM_State
 *
 * Description :    The function will return the current state of the
 *                  specified state machine.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    StateMachineNo:
 *                    State machine number.
 *
 *                  StateNo:
 *                    Pointer to store the current state of the specified 
 *                    state machine.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      State machine index is out of range.
 *
 *                    SES_FOUND:
 *                      Success. State number index found.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_State (SEM_STATE_MACHINE_TYPE StateMachineNo, SEM_STATE_TYPE *StateNo);


/*
 * Name        :    SEM_StateAll
 *
 * Description :    The function will return the current state of all the
 *                  state machines.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    StateVector:
 *                    Pointer to the array to store the current state vector.
 *
 *                  MaxSize:
 *                    Specifies the length of the destination array.
 *                    Must be equal to or longer than the number of state 
 *                    machines.
 *
 * Return      :    Completion code:
 *
 *                    SES_BUFFER_OVERFLOW:
 *                      The specified maxsize is insufficient. The state 
 *                      vector is not valid.
 *
 *                    SES_FOUND:
 *                      Success. All state number indexes found.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_StateAll (SEM_STATE_TYPE *StateVector, SEM_STATE_MACHINE_TYPE MaxSize);


/*
 * Name        :    SEM_Machine 
 *
 * Description :    The function will return the state machine index of the
 *                  specified state.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    StateNo:
 *                    State index number.
 *
 *                  StateMachineNo:
 *                    Pointer to store the found state machine index number of
 *                    the specified state.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      State index is out of range.
 *
 *                    SES_FOUND:
 *                      Success. State machine index number found.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_Machine (SEM_STATE_TYPE StateNo, SEM_STATE_MACHINE_TYPE *StateMachineNo);


/*
 * Name        :    SEM_ForceState
 *
 * Description :    The function is used to force the internal state vector
 *                  into the specified state.
 *                  The function is useful if the user wants to reestablish
 *                  the internal state vector after a power failure of the
 *                  target system. Before calling this function the first
 *                  time after a power down, the SEM_Init function should be
 *                  called to initialize the other internal variables of the
 *                  VS System.
 *                  The state vector established by calls to SEM_ForceState
 *                  should be stored in EEPROM before power down.
 *                  The function must be enabled by its VS Coder option.
 *
 * Argument    :    StateNo:
 *                    State index number.
 *
 * Return      :    Completion code:
 *
 *                    SES_RANGE_ERR:
 *                      State index is out of range.
 *
 *                    SES_OKAY:
 *                      Success.
 *
 * Portability :    ANSI-C Compiler.
 */
unsigned char SEM_ForceState (SEM_STATE_TYPE StateNo);


/*
 * Name        :    SEM_Action 
 *
 * Description :    The macro will call an action expression function by using 
 *                  the VSAction function pointer table.
 *
 * Argument    :    ActionNo:
 *                    Action expression index number.
 * 
 * Return      :    None.
 *
 * Portability :    ANSI-C Compiler.
 */
#define SEM_Action(ActionNo) ((*VSAction[(ActionNo)])())


/*
 * Name        :    SEM_TableAction 
 *
 * Description :    The macro will call an action expression function by using 
 *                  the specified function pointer table.
 *
 * Argument    :    Table:
 *                    Function pointer table.
 *
 *                  ActionNo:
 *                    Action expression index number.
 *
 * Return      :    None.
 *
 * Portability :    ANSI-C Compiler.
 */
#define SEM_TableAction(Table, ActionNo) ((*((Table))[(ActionNo)])())


#endif
