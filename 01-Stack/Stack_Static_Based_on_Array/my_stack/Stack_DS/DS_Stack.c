/*************************************************/
/** Author : Ali Morsy                           */
/** Date   : 29-4-2023                           */
/** VER    : V1.0                                */
/*************************************************/

#include "DS_Stack.h"


Return_Status_t Stack_init(DS_Stack_t* my_stack)
{
    Return_Status_t Return_Status;

    if(my_stack != NULL)
    {
        my_stack->Stack_Ptr = -1;
        Return_Status = R_OK;
    }
    else
    {
        Return_Status = R_NOK;
    }
    return Return_Status;
}

Return_Status_t Stack_Push(DS_Stack_t* my_stack, uint16_t value)
{
    Return_Status_t Return_Status;

    if ( (my_stack != NULL) && (Stack_Full(my_stack) == STACK_NOTFULL) )
    {
        my_stack->Stack_Ptr++;
        my_stack->Data[my_stack->Stack_Ptr] = value;
        Return_Status = R_OK;
    }
    else
    {
        printf("Error! Stack is Full\n");
        Return_Status = R_NOK;
    }
    return Return_Status;

}
Return_Status_t Stack_Pop(DS_Stack_t* my_stack, uint16_t *value)
{
    Return_Status_t Return_Status;

    if ( (my_stack != NULL) && (Stack_Empty(my_stack) == STACK_NOTFULL) )
    {

        *value = my_stack->Data[my_stack->Stack_Ptr];
        my_stack->Stack_Ptr--;
        Return_Status = R_OK;
    }
    else
    {
        printf("Error! Stack is Empty\n");
        Return_Status = R_NOK;
    }
    return Return_Status;

}

static Stack_Status_t Stack_Empty(DS_Stack_t *my_stack)
{
    Stack_Status_t ret;

    if( my_stack ->Stack_Ptr == -1 )
    {
        ret = STACK_EMPTY;
    }
    else
    {
        ret = STACK_NOTFULL;
    }
    return ret;

}
static Stack_Status_t Stack_Full(DS_Stack_t *my_stack)
{
    Stack_Status_t ret;

    if( my_stack ->Stack_Ptr == (STACK_SIZE-1) )
    {
        ret = STACK_FULL;
    }
    else
    {
        ret = STACK_NOTFULL;
    }
    return ret;

}

Return_Status_t Stack_Display(DS_Stack_t* my_stack)
{
      Return_Status_t Return_Status;

    if( (my_stack == NULL) || (Stack_Empty(my_stack) == STACK_EMPTY) )
    {
        printf("Error! stack is Empty\n");
        Return_Status = R_NOK;
    }
    else
    {
        printf("************ Display Stack **************** \n");
        for(uint16_t i=0; i<= my_stack->Stack_Ptr; i++)
        {
            printf("Stack[%i] = %i\n",i,my_stack->Data[i]);
        }
         Return_Status = R_OK;
    }
    return Return_Status;

}
