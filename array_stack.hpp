#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_


#include <stdio.h>


struct Stack {

    size_t capacity, size, element_size;

    void *data;
};


Stack *StackCtor      (size_t capacity, size_t element_size);
int    Push           (Stack* stack, void *buf);
void   ResizeUpIfNeed (Stack *stack);
int    Top            (Stack *stack, void *buf);
int    Pop            (Stack *stack, void *buf);
void   StackDtor      (Stack *stack);



#endif