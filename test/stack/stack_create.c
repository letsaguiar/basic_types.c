#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_stack_create(void)
{
    t_stack *stack = stack_create();

    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_NULL(stack->head);

    free(stack);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_stack_create);
    return UNITY_END();
}