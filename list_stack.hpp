#ifndef _LIST_STACK_H_
#define _LIST_STACK_H_


#include <stdio.h>


struct elem {

    void *val;
    elem *prev;
};

struct Stack {

    size_t element_size;

    elem *root;
};


Stack *StackCtor (size_t element_size);
int    Push      (Stack* stack, void *buf);
int    Top       (Stack *stack, void *buf);
int    Pop       (Stack *stack, void *buf);
void   RootDtor  (Stack *stack);
void   StackDtor (Stack *stack);



#endif