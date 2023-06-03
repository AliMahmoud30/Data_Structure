
/*************************************************/
/** Author : Ali Morsy                           */
/** Date   : 29-4-2023                           */
/** VER    : V1.0                                */
/*************************************************/

#ifndef DS_STACK_H
#define DS_STACK_H

#include <stdio.h>
#include <stdlib.h>

#include "typedef.h"

#define STACK_SIZE  5

typedef struct
{
    uint16_t  Data[STACK_SIZE];
    sint16_t  Stack_Ptr;
}DS_Stack_t;


typedef enum
{
    STACK_FULL,
    STACK_EMPTY,
    STACK_NOTFULL
}Stack_Status_t;


Return_Status_t Stack_init(DS_Stack_t* my_stack);
Return_Status_t Stack_Push(DS_Stack_t* my_stack, uint16_t value);
Return_Status_t Stack_Pop(DS_Stack_t* my_stack, uint16_t *value);
Return_Status_t Stack_Display(DS_Stack_t* my_stack);

static Stack_Status_t Stack_Empty(DS_Stack_t *my_stack);
static Stack_Status_t Stack_Full(DS_Stack_t *my_stack);

#endif // DS_STACK_H
