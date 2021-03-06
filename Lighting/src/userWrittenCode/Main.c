
#include <stdio.h>

#include "..\coderGenerated\SEMLibB.h"
#include "..\coderGenerated\LightingSystemAction.h"
#include "..\coderGenerated\LightingSystemData.h"

#include "eventQueue\simpleEventHandler.h"

#define STRLEN 30

void readFromKeyboardAndAddToQueue(VS_BOOL *e);
void error(VS_BOOL *e);
void displayEventNames();
void displayStateNames();

int main()
{
	/*Parameter used to break the general loop*/
	VS_BOOL breakLoop = 0; 

	/*Completion code variable*/
	unsigned char cc;

	/* Define action expression variable. */
	SEM_ACTION_EXPRESSION_TYPE actionExpressNo;

	/* Define and initialize. In this case the reset event is SE_RESET. */
	SEM_EVENT_TYPE eventNo = SE_RESET;

	/* Initialize the VS System. */
	SEM_Init();

	/* Initialize event queue */
	SEQ_Initialize();

	/*Put the firts event in queue. SE_RESET*/
	if ((cc = SEQ_AddEvent(SE_RESET)) != UCC_OK) {
		error(&breakLoop);
	}

	displayEventNames();	

	while (breakLoop != 1) {

		/*Get next event from queue*/
		if (SEQ_RetrieveEvent(&eventNo) != UCC_QUEUE_EMPTY) {

			/* Deduct the event. */
			if ((cc = SEM_Deduct(eventNo)) != SES_OKAY) {
				error(&breakLoop);
			}

			/* Get resulting action expressions and execute them. */
			while ((cc = SEM_GetOutput(&actionExpressNo)) == SES_FOUND) {
				SEM_Action(actionExpressNo);				
			}							
			if (cc != SES_OKAY) {
				error(&breakLoop);
			}		

			/* Change the next state vector. */
			if ((cc = SEM_NextStateChg()) != SES_OKAY) {
				//error(&breakLoop);
			}

			displayStateNames();

			readFromKeyboardAndAddToQueue(&breakLoop);
		}

	}

    return 0;
}

void readFromKeyboardAndAddToQueue(VS_BOOL *e) {

	unsigned char cc;
	SEM_EVENT_TYPE event;
	VS_INT scan_event;
	
	printf("\nevent:");
	scanf("%i", &scan_event);

	event = (SEM_EVENT_TYPE)scan_event;
	if (event != EVENT_UNDEFINED) {
		if ((cc = SEQ_AddEvent(event)) != UCC_OK) {
			error(e);
		}
	}
	else {
		error(e);
	}
}

void error(VS_BOOL *e) {
	printf("\nERROOOR!");
	*e = (VS_BOOL)1;
}

void displayEventNames() {

	SEM_EVENT_TYPE i;

	for (i = 0u; i < VS_NOF_EVENTS; i++)
	{
		VS_UINT8 e1 = 0u;
		char str[STRLEN];
		
		/* Print event name*/
		e1 = SEM_Name(EVENT_TYPE, i, str, STRLEN);
		if (e1 == 0u) {
			printf("\n%s \t=  %i", &str, i);
		}
	}
	printf("\n\n");
}

void displayStateNames() {

	SEM_STATE_TYPE StateNo = STATE_UNDEFINED;
	SEM_STATE_MACHINE_TYPE i;

	for (i = 0u; i < VS_NOF_STATE_MACHINES; i++) {
		if (SEM_State(i, &StateNo) != SES_FOUND) {
			printf("\nState machine %d is in an undefined state", i);
		}
		else {
			char str[STRLEN];
			VS_UINT8 e = 0u;
			/* Print state machine number and state number. */
			e = SEM_Name(STATE_TYPE, StateNo, str, STRLEN);
			if (e == 0u) {
				printf("\nState machine %d: state %s", i, &str);
			}
			else {
				break;
			}
		}
	}
	printf("\nEnter %i to exit\n", EVENT_UNDEFINED);

}