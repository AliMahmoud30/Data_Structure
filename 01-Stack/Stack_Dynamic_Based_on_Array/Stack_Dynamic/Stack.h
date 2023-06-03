
#ifndef STACK_H
#define STACK_H


#include "typedef.h"

typedef struct
{
    void** Stack_Array;
    uint32_t Stack_Max_Size;
    uint32_t Element_Count;
    sint32_t Stack_Top;
}Stack_t;

typedef enum
{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NOT_FULL,
    STACK_NULL_POINTER
}Stack_Status_t;

/***********************************************************************
@Author : Ali Morsy
@Brief  : Create a new Stack Based on dynamic Array
@param  : Stack_Size
@param  : Pointer to Stack_Status_t
@ret    : Pointer to Stack_t which contain Address for Stack Allocated
          or NULL when Stack Stack Not Allocated
***********************************************************************/
Stack_t* Create_Stack(uint32_t Stack_Size, Stack_Status_t* Stack_status);


/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to Destroy stack from dynamic memory
@param  : Reference for Stack to Destroy it
@param  : Pointer to Stack_Status_t
@ret    : NULL when Stack Stack Not Allocated
***********************************************************************/
Stack_t* Stack_Destroy(Stack_t* Stack_Obj, Stack_Status_t* Stack_status);


/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to Push Address of value to stack.
@param  : Reference for Stack to Push Address to it
@param  : Pointer to value which will Push in Stack
@ret    : Stack_Status
***********************************************************************/
Stack_Status_t Stack_Push(Stack_t* Stack_Obj, void* Value);


/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to Pope Value from stack.
@param  : Reference for Stack.
@param  : pointer for Stack_Status
@ret    : void*
***********************************************************************/
void* Stack_Pop(Stack_t* Stack_Obj, Stack_Status_t *Stack_Status);

/***********************************************************************
@Func_name : Stack_Top
@Author    : Ali Morsy
@Brief     : This Function used to Get Top Value in Stack.
@param     : Reference for Stack.
@param     : reference for item to return stack Top in it.
@ret       : pointer for Stack_Status
***********************************************************************/
void* Stack_Top(Stack_t* Stack_Obj, Stack_Status_t* Stack_Status);

/***********************************************************************
@Func_name : Stack_Count
@Author    : Ali Morsy
@Brief     : This Function used to Get Stack Count in Stack.
@param     : Reference for Stack.
@param     : reference for item to return stack Count in it.
@ret       : pointer for Stack_Status
***********************************************************************/
Stack_Status_t Stack_Count(Stack_t* Stack_Obj, uint32_t* item_ptr);



/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to check stack is Full Or not
@param  : Reference for Stack to Destroy it
@ret    : Stack_Status_t
***********************************************************************/
static Stack_Status_t IS_Stack_Full(Stack_t* Stack_Obj);


/***********************************************************************
@Author : Ali Morsy
@Brief  : This Function used to check stack is Empty Or not
@param  : Reference for Stack to Destroy it
@ret    : Stack_Status_t
***********************************************************************/
static Stack_Status_t IS_Stack_Empty(Stack_t* Stack_Obj);

#endif // STACK_H
