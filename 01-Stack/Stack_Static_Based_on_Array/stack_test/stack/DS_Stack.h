
#ifndef DS_STACK_H
#define DS_STACK_H

#include "typedef.h"

#define STACK_SIZE          5

typedef struct
{
    uint32_t Stack[STACK_SIZE];
    sint32_t Stack_Ptr;
}Stack_t;

typedef enum
{

    Stack_Empty,
    Stack_Full,
    Stack_NotFull
}Stack_State;

R_result DS_StackInit(Stack_t* my_Stack);
R_result DS_StackPush(Stack_t* my_stack, uint32_t Value);
R_result DS_StackPop(Stack_t* my_stack, uint32_t* R_Value);
R_result DS_StackDisplay(Stack_t* my_stack);

static Stack_State Is_Stack_Full(Stack_t* my_stack);
static Stack_State Is_Stack_Empty(Stack_t* my_stack);


#endif // DS_STACK_H
