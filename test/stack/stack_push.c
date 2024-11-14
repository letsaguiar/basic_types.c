#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_stack_push_one(void)
{
    t_stack *stack = stack_create();
    
    int *data = malloc(sizeof(int));
    *data = 1;

    TEST_ASSERT_EQUAL_INT(1, stack_push(stack, data, free));
    TEST_ASSERT_EQUAL_INT(*data, *(int *)stack->head->data);

    stack_clear(stack, free);
}

void    test_stack_push_two(void)
{
    t_stack *stack = stack_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    int *data2 = malloc(sizeof(int));
    *data2 = 2;

    TEST_ASSERT_EQUAL_INT(1, stack_push(stack, data1, free));
    TEST_ASSERT_EQUAL_INT(1, stack_push(stack, data2, free));
    TEST_ASSERT_EQUAL_INT(*data2, *(int *)stack->head->data);

    stack_clear(stack, free);
}

void    test_stack_push_three(void)
{
    t_stack *stack = stack_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    int *data3 = malloc(sizeof(int));
    *data3 = 3;

    TEST_ASSERT_EQUAL_INT(1, stack_push(stack, data1, free));
    TEST_ASSERT_EQUAL_INT(1, stack_push(stack, data2, free));
    TEST_ASSERT_EQUAL_INT(1, stack_push(stack, data3, free));
    TEST_ASSERT_EQUAL_INT(*data3, *(int *)stack->head->data);

    stack_clear(stack, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_stack_push_one);
    RUN_TEST(test_stack_push_two);
    RUN_TEST(test_stack_push_three);
    return UNITY_END();
}