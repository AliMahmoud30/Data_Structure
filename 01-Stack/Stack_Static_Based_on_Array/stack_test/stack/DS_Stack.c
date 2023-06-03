
#include "DS_Stack.h"

#include <stdio.h>
#include <stdlib.h>


R_result DS_StackInit(Stack_t* my_Stack)
{
    R_result ret;

    if(my_Stack != NULL)
    {
        my_Stack->Stack_Ptr = -1;
        ret = R_OK;
    }
    else
    {
        ret = R_NOK;
    }
    return ret;
}

R_result DS_StackPush(Stack_t* my_stack, uint32_t Value)
{
    R_result ret;

    if( (my_stack != NULL) && (Is_Stack_Full(my_stack) == Stack_NotFull) )
    {
        my_stack->Stack_Ptr++;
        my_stack->Stack[my_stack->Stack_Ptr] = Value;
        ret = R_OK;
    }
    else
    {
        ret = R_NOK;
    }
    return ret;
}

R_result DS_StackPop(Stack_t* my_stack, uint32_t* R_Value)
{
    R_result ret;
    if( (my_stack != NULL) && (Is_Stack_Empty(my_stack) != Stack_Empty) )
    {
        *R_Value = my_stack->Stack[my_stack->Stack_Ptr];
        my_stack->Stack_Ptr--;
        ret = R_OK;
    }
    else
    {
        ret = R_NOK;
    }
    return ret;
}

R_result DS_StackDisplay(Stack_t* my_stack)
{
    if(Is_Stack_Empty(my_stack) !=Stack_Empty)
    {
        for(uint32_t i=0; i<= my_stack->Stack_Ptr; i++)
        {
            printf("Stack[%i] = %i\n",i,my_stack->Stack[i]);
        }
        return R_OK;
    }
    else
    {

        printf("Stack is Empty!\n");
    }
}

static Stack_State Is_Stack_Full(Stack_t* my_stack)
{
    Stack_State ret;
    if(my_stack->Stack_Ptr == STACK_SIZE-1)
    {
        ret = Stack_Full;
    }
    else
    {
        ret = Stack_NotFull;
    }
    return ret;
}

static Stack_State Is_Stack_Empty(Stack_t* my_stack)
{
    Stack_State ret;
    if(my_stack->Stack_Ptr == -1)
    {
        ret = Stack_Empty;
    }
    else
    {
        ret = Stack_NotFull;
    }
    return ret;
}

