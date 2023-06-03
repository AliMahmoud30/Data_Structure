#include <stdio.h>
#include <stdlib.h>


#include "DS_Stack.h"

Stack_t  my_stack_1;


int main()
{
    R_result Stack_ret;
    uint32_t val;

    Stack_ret = DS_StackInit(&my_stack_1);
    if(Stack_ret == R_OK)
    {
        printf("my_stack_1 Initialized Successfully... \n");
    }
    else
    {
        printf("Can not Initialize my_stack_1 ... \n");

    }

    DS_StackPush(&my_stack_1,10);
    DS_StackPush(&my_stack_1,20);
    DS_StackPush(&my_stack_1,30);
    DS_StackPush(&my_stack_1,30);
    DS_StackPush(&my_stack_1,30);
    DS_StackPush(&my_stack_1,30);
    DS_StackPush(&my_stack_1,30);

    DS_StackDisplay(&my_stack_1);


    DS_StackPop(&my_stack_1,&val);
    printf("pop val = %i\n",val);

    DS_StackDisplay(&my_stack_1);

    DS_StackPop(&my_stack_1,&val);
    printf("pop val = %i\n",val);

    DS_StackDisplay(&my_stack_1);

    DS_StackPop(&my_stack_1,&val);
    printf("pop val = %i\n",val);

    DS_StackDisplay(&my_stack_1);

    return 0;
}
