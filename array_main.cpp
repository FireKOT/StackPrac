#include <stdio.h>
#include <time.h>
#include <cstdlib>

#include "array_stack.hpp"

void StartTestOne   (int attempts_c);
void TestOne        (Stack *stack);
void StartTestTwo   (int attempts_c);
void TestTwo        (Stack *stack);
void StartTestThree (int attempts_c);
void TestThree      (Stack *stack);


int main () {

    int attempts = 10;

    StartTestOne  (attempts);
    StartTestTwo  (attempts);
    StartTestThree(attempts);
    
    return 0;
}

void StartTestOne (int attempts_c) {

    double sum_time = 0;

    FILE *output = fopen("tests.txt", "a");

    fprintf(output, "Test One:\n\n");

    fprintf(output, "Attempts:\n");
    for (int i = 0; i < attempts_c; i++) {

        Stack *stack = StackCtor(1, sizeof(int));

        clock_t t_start = clock();
        TestOne(stack);
        clock_t t_end = clock();

        StackDtor(stack);

        double cur_time = 1000.0 * (t_end - t_start) / CLOCKS_PER_SEC;
        sum_time += cur_time;

        fprintf(output, "%3d: %3lg ms\n", i+1, cur_time);
    }

    fprintf(output, "\nAvearage time: %lg ms\n\n\n", sum_time / attempts_c);

    fclose(output);
}

void TestOne (Stack *stack) {

    int size = 1000000;

    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < size; j++) {

            Push(stack, &i);
        }

        for (int j = 0; j < size / 2; j++) {
            
            int buf = 0;
            Pop(stack, &buf);
        }

        for (int j = 0; j < size / 4; j++) {

            Push(stack, &i);
        }

        size /= 2;
    }
}

void StartTestTwo (int attempts_c) {

    double sum_time = 0;

    FILE *output = fopen("tests.txt", "a");

    fprintf(output, "Test Two:\n\n");

    fprintf(output, "Attempts:\n");
    for (int i = 0; i < attempts_c; i++) {

        Stack *stack = StackCtor(1, sizeof(int));

        clock_t t_start = clock();
        TestTwo(stack);
        clock_t t_end = clock();

        StackDtor(stack);

        double cur_time = 1000.0 * (t_end - t_start) / CLOCKS_PER_SEC;
        sum_time += cur_time;

        fprintf(output, "%3d: %3lg ms\n", i+1, cur_time);
    }

    fprintf(output, "\nAvearage time: %lg ms\n\n\n", sum_time / attempts_c);

    fclose(output);
}

void TestTwo (Stack *stack) {

    int size = 1000000;

    for (int i = 0; i < size; i++) {

        Push(stack, &i);
    }

    for (int i = 0; i < size; i++) {
        
        int buf = 0;
        Pop(stack, &buf);
    }

    TestOne(stack);

    for (int i = 0; i < size; i++) {

        Push(stack, &i);
    }

    for (int i = 0; i < size; i++) {

        int buf = 0;
        Pop(stack, &buf);
    }
}

void StartTestThree (int attempts_c) {

    double sum_time = 0;

    FILE *output = fopen("tests.txt", "a");

    fprintf(output, "Test Three:\n\n");

    fprintf(output, "Attempts:\n");
    for (int i = 0; i < attempts_c; i++) {

        Stack *stack = StackCtor(10e6, sizeof(int));

        for (int j = 0; j < 10e6; j++) {

            Push(stack, &i);
        }

        clock_t t_start = clock();
        TestThree(stack);
        clock_t t_end = clock();

        StackDtor(stack);

        double cur_time = 1000.0 * (t_end - t_start) / CLOCKS_PER_SEC;
        sum_time += cur_time;

        fprintf(output, "%3d: %3lg ms\n", i+1, cur_time);
    }

    fprintf(output, "\nAvearage time: %lg ms\n\n\n", sum_time / attempts_c);

    fclose(output);
}

void TestThree (Stack *stack) {

    for (int i = 0; i < 10e6; i++) {

        if (rand() % 2) {

            Push(stack, &i);
        }
        else {

            int a = 0;
            Pop(stack, &a);
        }
    }
}