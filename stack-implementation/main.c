#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main(){
        struct Stack* St = createStack(100);
        printf("%d\n", isEmpty(St));
        printStack(St);
        push(St, 10);
        printStack(St);
        push(St, 20);
        printStack(St);
        int d = pop(St);
        printStack(St);
        return 0;
}


