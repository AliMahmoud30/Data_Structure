#include <stdio.h>
#include <stdlib.h>

#include "DS_Stack.h"

DS_Stack_t  my_stack1;
uint16_t value_Poped = ZERO;
int main()
{
    Stack_init(&my_stack1);

    Stack_Push(&my_stack1,50);
    Stack_Push(&my_stack1,505);
    Stack_Push(&my_stack1,100);
    Stack_Push(&my_stack1,60);
    Stack_Push(&my_stack1,30);
    Stack_Push(&my_stack1,10);
    Stack_Push(&my_stack1,10);

    Stack_Display(&my_stack1);

    Stack_Pop(&my_stack1,&value_Poped);
    printf("value Poped = %i\n",value_Poped);
    Stack_Pop(&my_stack1,&value_Poped);
    printf("value Poped = %i\n",value_Poped);
    Stack_Pop(&my_stack1,&value_Poped);
    printf("value Poped = %i\n",value_Poped);
    Stack_Pop(&my_stack1,&value_Poped);
    printf("value Poped = %i\n",value_Poped);
    Stack_Pop(&my_stack1,&value_Poped);
    printf("value Poped = %i\n",value_Poped);
    Stack_Pop(&my_stack1,&value_Poped);
    Stack_Display(&my_stack1);

    return 0;
}
