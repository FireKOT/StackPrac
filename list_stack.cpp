#include <stdio.h>
#include <malloc.h>
#include <cstring>

#include "list_stack.hpp"


Stack *StackCtor (size_t element_size) {

    if (!element_size) return nullptr;

    Stack *stack        = (Stack*) calloc(1, sizeof(Stack));
    stack->element_size = element_size;
    stack->root         = nullptr;

    return stack;
}

int Push (Stack* stack, void *buf) {

    if (!stack || !buf) {

        return 0;
    }

    elem *new_elem = (elem*) calloc(1, sizeof(elem));
    new_elem->val  = calloc(1, stack->element_size);
    std::memcpy(new_elem->val, buf, stack->element_size);
    new_elem->prev = stack->root;

    stack->root = new_elem;

    return 1;
}

int Top (Stack *stack, void *buf) {

    if (!stack || !buf) {

        return 0;
    }

    std::memcpy(buf, stack->root->val, stack->element_size);

    return 1;
}

int Pop (Stack *stack, void *buf) {

    if (!stack || !buf) {

        return 0;
    }

    std::memcpy(buf, stack->root->val, stack->element_size);
    RootDtor(stack);

    return 1;
}

void RootDtor (Stack *stack) {

    elem *tmp = stack->root->prev;

    free(stack->root);
    stack->root = tmp;
}

void StackDtor (Stack *stack) {

    while (stack->root){

        RootDtor(stack);
    }

    free(stack);
}