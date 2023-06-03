
#include <stdlib.h>
#include "Stack.h"



/***********************************************************************
@Author : Ali Morsy
@Brief  : Create a new Stack Based on dynamic Array
@param  : Stack_Size
@param  : Pointer to Stack_Status_t
@ret    : Pointer to Stack_t which contain Address for Stack Allocated
          or NULL when Stack Stack Not Allocated
***********************************************************************/
Stack_t* Create_Stack(uint32_t Stack_Size, Stack_Status_t* Stack_Status)
{
    Stack_t* my_stack = NULL;

    if(Stack_Status == NULL)
    {
        my_stack = NULL;
        *Stack_Status = STACK_NULL_POINTER;
    }
    else
    {
       my_stack = (Stack_t*)malloc(sizeof(Stack_t));
       if(!my_stack)
       {
           *Stack_Status = STACK_NOK;
            my_stack = NULL;
       }
       else
       {
          my_stack->Stack_Max_Size = Stack_Size;
          my_stack->Element_Count  = 0         ;
          my_stack->Stack_Top      = -1        ;
          my_stack->Stack_Array    = (void**)calloc(my_stack->Stack_Max_Size,sizeof(void*));
          if(!my_stack)
          {
              free(my_stack);
              *Stack_Status = STACK_NOK;
              my_stack = NULL;
          }
          else
          {
             *Stack_Status = STACK_OK;
          }
       }

    }
    return my_stack;
}

/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to Destroy stack from dynamic memory
@param  : Reference for Stack to Destroy it
@param  : Pointer to Stack_Status_t
@ret    : NULL when Stack Stack Not Allocated
***********************************************************************/
Stack_t* Stack_Destroy(Stack_t* Stack_Obj, Stack_Status_t* Stack_status)
{

    if( (Stack_Obj == NULL) || (Stack_status == NULL) )
    {
        *Stack_status = STACK_NULL_POINTER;
    }
    else
    {
        free(Stack_Obj->Stack_Array);
        free(Stack_Obj);
        *Stack_status = STACK_OK;
    }
    return NULL;
}

/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to Push Address of value to stack.
@param  : Reference for Stack to Push Address to it
@param  : Pointer to value which will Push in Stack
@ret    : Stack_Status
***********************************************************************/
Stack_Status_t Stack_Push(Stack_t* Stack_Obj, void* Value)
{
    Stack_Status_t Stack_Status = STACK_NOK;

    if( (Stack_Obj == NULL) || (Value == NULL) )
    {
        Stack_Status = STACK_NULL_POINTER;
    }
    else
    {
       if( IS_Stack_Full(Stack_Obj) == STACK_NOT_FULL)
       {
           Stack_Obj->Element_Count++;
           Stack_Obj->Stack_Top++;
           Stack_Obj->Stack_Array[Stack_Obj->Stack_Top] = Value;
           Stack_Status = STACK_OK;
       }
       else
       {
           Stack_Status = STACK_FULL;
       }
    }
    return Stack_Status;
}


/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to Pope Value from stack.
@param  : Reference for Stack to Destroy it
@param  : pointer for Stack_Status
@ret    : void*
***********************************************************************/
void* Stack_Pop(Stack_t* Stack_Obj, Stack_Status_t *Stack_Status)
{
    void* Stack_ptr = NULL;

    if( (Stack_Obj == NULL) || (Stack_Status == NULL) )
    {
        *Stack_Status = STACK_NULL_POINTER;
        Stack_ptr=NULL;
    }
    else
    {
       if( IS_Stack_Empty(Stack_Obj) != STACK_EMPTY)
       {
           Stack_ptr = Stack_Obj->Stack_Array[Stack_Obj->Stack_Top];
           (Stack_Obj->Stack_Top)--;
           (Stack_Obj->Element_Count)--;
           *Stack_Status = STACK_OK;
       }
       else
       {
           *Stack_Status = STACK_EMPTY;
           Stack_ptr = NULL;
       }
    }
    return Stack_ptr;

}

/***********************************************************************
@Func_name : Stack_Top
@Author    : Ali Morsy
@Brief     : This Function used to Get Top Value in Stack.
@param     : Reference for Stack.
@param     : reference for item to return stack Top in it.
@ret       : pointer for Stack_Status
***********************************************************************/
void* Stack_Top(Stack_t* Stack_Obj, Stack_Status_t* Stack_Status)
{
    void* Stack_ptr = NULL;
    if( (Stack_Obj == NULL) || (Stack_Status == NULL) )
    {
        *Stack_Status = STACK_NULL_POINTER;
         Stack_ptr=NULL;
    }
    else
    {
       if( IS_Stack_Empty(Stack_Obj) != STACK_EMPTY)
       {
           Stack_ptr = Stack_Obj->Stack_Array[Stack_Obj->Stack_Top];
           *Stack_Status = STACK_OK;
       }
       else
       {
           *Stack_Status = STACK_EMPTY;
           Stack_ptr = NULL;
       }
    }
    return Stack_ptr;

}

/***********************************************************************
@Func_name : Stack_Count
@Author    : Ali Morsy
@Brief     : This Function used to Get Stack Count in Stack.
@param     : Reference for Stack.
@param     : reference for item to return stack Count in it.
@ret       : pointer for Stack_Status
***********************************************************************/
Stack_Status_t Stack_Count(Stack_t* Stack_Obj, uint32_t* item_ptr)
{
    Stack_Status_t Stack_Status = STACK_NOK;
    if((Stack_Obj == NULL) || (item_ptr == NULL) )
    {
        Stack_Status = STACK_NULL_POINTER;
    }
    else
    {
        *item_ptr = Stack_Obj->Element_Count;
         Stack_Status = STACK_OK;
    }
    return Stack_Status;
}

/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to check stack is Full Or not
@param  : Reference for Stack to Destroy it
@ret    : Stack_Status_t
***********************************************************************/
static Stack_Status_t IS_Stack_Full(Stack_t* Stack_Obj)
{
    Stack_Status_t Stack_status = STACK_NOK;
    if( (Stack_Obj->Element_Count) == (Stack_Obj-> Stack_Max_Size) )
    {
        Stack_status = STACK_FULL;
    }
    else
    {
         Stack_status = STACK_NOT_FULL;
    }

    return Stack_status;
}

/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to check stack is Empty Or not
@param  : Reference for Stack to Destroy it
@ret    : Stack_Status_t
***********************************************************************/
static Stack_Status_t IS_Stack_Empty(Stack_t* Stack_Obj)
{
     Stack_Status_t Stack_status = STACK_NOK;
    if( (Stack_Obj->Stack_Top) == -1)
    {
        Stack_status = STACK_EMPTY;
    }
    else
    {
         Stack_status = STACK_NOT_FULL;
    }

    return Stack_status;
}
