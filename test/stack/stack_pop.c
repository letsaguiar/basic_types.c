#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_stack_pop_null(void)
{
    t_stack *stack = stack_create();

    TEST_ASSERT_NULL(stack_pop(stack));

    stack_clear(stack, free);
}

void    test_stack_pop_one(void)
{
    t_stack *stack = stack_create();
    
    int *data = malloc(sizeof(int));
    *data = 1;
    stack_push(stack, data);

    int *pop = stack_pop(stack);

    TEST_ASSERT_EQUAL_INT(*data, *pop);
    TEST_ASSERT_NULL(stack->head);

    free(pop);
    stack_clear(stack, free);
}

void    test_stack_pop_two(void)
{
    t_stack *stack = stack_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    stack_push(stack, data1);

    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    stack_push(stack, data2);

    int *pop = stack_pop(stack);

    TEST_ASSERT_EQUAL_INT(*data2, *pop);
    TEST_ASSERT_EQUAL_INT(*data1, *(int *)stack->head->data);

    free(pop);
    stack_clear(stack, free);
}

void    test_stack_pop_three(void)
{
    t_stack *stack = stack_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    stack_push(stack, data1);
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    stack_push(stack, data2);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    stack_push(stack, data3);

    int *pop = stack_pop(stack);

    TEST_ASSERT_EQUAL_INT(*data3, *pop);
    TEST_ASSERT_EQUAL_INT(*data2, *(int *)stack->head->data);

    free(pop);
    stack_clear(stack, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_stack_pop_null);
    RUN_TEST(test_stack_pop_one);
    RUN_TEST(test_stack_pop_two);
    RUN_TEST(test_stack_pop_three);
    return UNITY_END();
}