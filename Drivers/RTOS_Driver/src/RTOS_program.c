/*
 * RTOS_program.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Mario Ezzat
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/TIMER/TIMER_interface.h"
#include "../include/SERVICES/RTOS/RTOS_interface.h"
#include "../include/SERVICES/RTOS/RTOS_private.h"
#include "../include/SERVICES/RTOS/RTOS_configuration.h"

/* ARRAY OF STRUCT WITH NUMBER OF TASKS */
RTOS_TCB RTOS_ArrOfTasks[RTOS_MAX_NUMBER_OF_TASKS];

/********************************************************************************/
/*  THIS FUNCTION INITIALIZE TIMER0 CTC MODE & CALL THE SCHEDULER EACH 200(Ms)  */
/********************************************************************************/
void SRTOS_voidInit(void)
{
	/* INIT TIMER0 CTC_MODE */
	MTIMER0_voidInit();
	/* CALL THE SCHEDULER FUNCTION */
	MTIMER0_voidSetCallBackCTC(SRTOS_voidScheduler);
}

/*******************************************************************************/
/*  THIS FUNCTION SET THE ADDRESS OF FUNCTION OF THE TASK NULL FOR FIRST TIME  */
/*******************************************************************************/
void SRTOS_voidInitArryFunctions(void)
{
	u8 local_u8Counter = 0;
	/* SET ALL FUNCTION ADRESSES IN  TASKS TO NULL */
	for(;local_u8Counter>RTOS_MAX_NUMBER_OF_TASKS;local_u8Counter++)
	{
		RTOS_ArrOfTasks[local_u8Counter].ptr = NULL;
	}
}

/****************************************************************/
/*  THIS FUNCTION SET THE DATA OF TASK							*/
/*  (Priority) --> 0..1..2..3....								*/
/* 	(Periodicity) --> 1(ms)..2(ms)...							*/
/* 	(FirtsDelay) --> commonly = Periodicity -1					*/
/*	(PtrToFunc) --> THE ADDRESS OF THE FUNCTION FOR THE TASK	*/
/****************************************************************/
void SRTOS_voidCreatTask(u8 A_u8Periority, u16 A_u8Periodicity, u16 A_u8FirtsDelay, void(*A_PtrToFunc)(void))
{
	/*CHECK PERIORITY < NUM OF TASKS & PtrToFumc IS NOT NULL */
	if((A_u8Periority < RTOS_MAX_NUMBER_OF_TASKS) && (A_PtrToFunc != NULL))
	{
		/** SAVE THE DATA IN TASK_TCB(STRUCT) **/
		/* SAVE FIRST DELAY VALUE */
		RTOS_ArrOfTasks[A_u8Periority].FirstDelay = A_u8FirtsDelay;
		/* SAVE PERIODICITY VALUE */
		RTOS_ArrOfTasks[A_u8Periority].Periodicity = A_u8Periodicity;
		/* SAVE FUNCTION ADDRESS */
		RTOS_ArrOfTasks[A_u8Periority].ptr = A_PtrToFunc;

	}
}

/***************************************************************/
/*  THIS FUNCTION IS REPEATED BY TIMER0 CTC MODE EACH 200(Ms)  */
/***************************************************************/
void SRTOS_voidScheduler(void)
{
	static u8 local_u8Counter = 0;
	local_u8Counter++;
	/* AFTER 1(ms) local_u8Counter = 5 */
	if (local_u8Counter == 5)
	{
		local_u8Counter = 0;
		u8 local_u8TaskCounter = 0;
		for(;local_u8TaskCounter<RTOS_MAX_NUMBER_OF_TASKS;local_u8TaskCounter++)
		{
			/** CHECK THE TASK IS READY **/
			/* IF FIRST DELAY IS ZERO */
			if(RTOS_ArrOfTasks[local_u8TaskCounter].FirstDelay == 0 )
			{
				/* IF THE FUNCTION EXIST */
				if(RTOS_ArrOfTasks[local_u8TaskCounter].ptr != NULL)
				{
					/* CALL THE FUNCTION OF TASK */
					RTOS_ArrOfTasks[local_u8TaskCounter].ptr();
					/* THEN MAKE THE FIRST DELAY(ms) = Periodicity (ms) - 1(ms) */
					RTOS_ArrOfTasks[local_u8TaskCounter].FirstDelay = RTOS_ArrOfTasks[local_u8TaskCounter].Periodicity - 1;
				}
			}
			/* IF THE FIRST DELAY NOT ZARO */
			else
			{
				RTOS_ArrOfTasks[local_u8TaskCounter].FirstDelay--;
			}
		}
	}
}
