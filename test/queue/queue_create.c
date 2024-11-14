#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_queue_create(void)
{
    t_queue *queue = queue_create();

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);

    queue_clear(queue, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_queue_create);
    return UNITY_END();
}