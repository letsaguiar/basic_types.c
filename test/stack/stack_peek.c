#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_stack_peek_null(void)
{
    t_stack *stack = stack_create();

    TEST_ASSERT_NULL(stack_peek(stack));

    stack_clear(stack, free);
}

void    test_stack_peek_one(void)
{
    t_stack *stack = stack_create();
    
    int *data = malloc(sizeof(int));
    *data = 1;

    stack_push(stack, data);

    TEST_ASSERT_EQUAL_INT(*data, *(int *)stack_peek(stack));

    stack_clear(stack, free);
}

void    test_stack_peek_two(void)
{
    t_stack *stack = stack_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    int *data2 = malloc(sizeof(int));
    *data2 = 2;

    stack_push(stack, data1);
    stack_push(stack, data2);

    TEST_ASSERT_EQUAL_INT(*data2, *(int *)stack_peek(stack));

    stack_clear(stack, free);
}

void    test_stack_peek_three(void)
{
    t_stack *stack = stack_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    int *data3 = malloc(sizeof(int));
    *data3 = 3;

    stack_push(stack, data1);
    stack_push(stack, data2);
    stack_push(stack, data3);

    TEST_ASSERT_EQUAL_INT(*data3, *(int *)stack_peek(stack));

    stack_clear(stack, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_stack_peek_null);
    RUN_TEST(test_stack_peek_one);
    RUN_TEST(test_stack_peek_two);
    RUN_TEST(test_stack_peek_three);
    return UNITY_END();
}