#include <stdio.h>
#include <malloc.h>
#include <cstring>

#include "array_stack.hpp"


Stack *StackCtor (size_t capacity, size_t element_size) {

    if (!element_size) return nullptr;

    if (!capacity) capacity = 1;

    Stack *stack = (Stack*) calloc(1, sizeof(Stack));

    stack->capacity     = capacity;
    stack->size         = 0;
    stack->element_size = element_size;

    stack->data = calloc(capacity, element_size);

    return stack;
}

int Push (Stack* stack, void *buf) {

    if (!stack || !buf || stack->capacity < stack->size) {

        return 0;
    }

    ResizeUpIfNeed(stack);

    std::memcpy((char*) stack->data + stack->size * stack->element_size, buf, stack->element_size);
    stack->size++;

    return 1;
}

void ResizeUpIfNeed (Stack *stack) {

    if (!stack) return;

    if (stack->capacity == stack->size) {

        stack->data = realloc(stack->data, 2 * stack->capacity * stack->element_size);
        stack->capacity *= 2;
    }
}

int Top (Stack *stack, void *buf) {

    if (!stack || !buf || !stack->size) {

        return 0;
    }

    std::memcpy(buf, (char*) stack->data + (stack->size - 1) * stack->element_size, stack->element_size);

    return 1;
}

int Pop (Stack *stack, void *buf) {

    if (!stack || !buf || !stack->size) {

        return 0;
    }

    std::memcpy(buf, (char*) stack->data + (stack->size - 1) * stack->element_size, stack->element_size);
    stack->size--;

    return 1;
}

void StackDtor (Stack *stack) {

    free(stack->data);
    free(stack);
}