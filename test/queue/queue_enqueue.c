#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_queue_enqueu_null(void)
{
    TEST_ASSERT_EQUAL_INT(0, queue_enqueue(NULL, NULL));
}

void    test_queue_enqueue_one(void)
{
    t_queue *queue = queue_create();
    
    int *data = malloc(sizeof(int));
    *data = 1;
    queue_enqueue(queue, data);

    TEST_ASSERT_EQUAL_INT(1, *(int*)queue->head->data);
    TEST_ASSERT_EQUAL_INT(1, *(int*)queue->tail->data);

    queue_clear(queue, free);
}

void    test_queue_enqueue_two(void)
{
    t_queue *queue = queue_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    queue_enqueue(queue, data1);

    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    queue_enqueue(queue, data2);

    TEST_ASSERT_EQUAL_INT(1, *(int*)queue->head->data);
    TEST_ASSERT_EQUAL_INT(1, *(int*)queue->tail->data);

    queue_clear(queue, free);
}

void    test_queue_enqueue_three(void)
{
    t_queue *queue = queue_create();
    
    int *data1 = malloc(sizeof(int));
    *data1 = 1;
    queue_enqueue(queue, data1);

    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    queue_enqueue(queue, data2);

    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    queue_enqueue(queue, data3);

    TEST_ASSERT_EQUAL_INT(1, *(int*)queue->head->data);
    TEST_ASSERT_EQUAL_INT(2, *(int*)queue->tail->data);

    queue_clear(queue, free);
}

int    main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_queue_enqueu_null);
    RUN_TEST(test_queue_enqueue_one);
    RUN_TEST(test_queue_enqueue_two);
    RUN_TEST(test_queue_enqueue_three);
    return UNITY_END();
}