#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"


Stack_t* Stack_1;

int main()
{
    Stack_Status_t Stack_Status=STACK_NOK;
    int x = 20;
    int y = 30;
    float z= 3.14;
    void* retun_val = NULL;

    Stack_1 = Create_Stack(5,&Stack_Status);
    if(Stack_1 != NULL)
    {
        printf("Stack Created Successfully\n");

        Stack_Status = Stack_Push(Stack_1,&x); printf("Stack_Status = %i\n",Stack_Status);
        Stack_Status = Stack_Push(Stack_1,&y); printf("Stack_Status = %i\n",Stack_Status);
        Stack_Status = Stack_Push(Stack_1,&z); printf("Stack_Status = %i\n",Stack_Status);
        Stack_Status = Stack_Push(Stack_1,&z); printf("Stack_Status = %i\n",Stack_Status);
        Stack_Status = Stack_Push(Stack_1,&z); printf("Stack_Status = %i\n",Stack_Status);
        Stack_Status = Stack_Push(Stack_1,&z); printf("Stack_Status = %i\n",Stack_Status);



        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = %0.2f\tStack_Status=%i\n",*((float*)retun_val),Stack_Status );
        retun_val = Stack_Top(Stack_1, &Stack_Status); printf("Stack_Top = %0.2f\tStack_Status=%i\n",*((float*)retun_val),Stack_Status );
        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = %0.2f\tStack_Status=%i\n",*((float*)retun_val),Stack_Status );
        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = %0.2f\tStack_Status=%i\n",*((float*)retun_val),Stack_Status );
        retun_val = Stack_Top(Stack_1, &Stack_Status); printf("Stack_Top = %i\tStack_Status=%i\n",*((uint32_t*)retun_val),Stack_Status );
        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = %i\tStack_Status=%i\n",*((uint32_t*)retun_val),Stack_Status );
        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = %i\tStack_Status=%i\n",*((uint32_t*)retun_val),Stack_Status );
        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = \tStack_Status=%i\n",Stack_Status );
        retun_val = Stack_Pop(Stack_1, &Stack_Status); printf("retun_val = \tStack_Status=%i\n",Stack_Status );





    }
    else
    {
       printf("Error! Cannot Create Stack_1\n");
    }






    Stack_1 = Stack_Destroy(Stack_1,&Stack_Status);
    if(Stack_1 == NULL)
    {
        printf("Stack Destroyed Successfully\n");
    }
    else
    {
       printf("Error! Cannot Destroy Stack_1\n");
    }


    return 0;
}
