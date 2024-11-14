#include "basic-types.h"
#include "unity.h"
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_queue_dequeue_null(void)
{
    TEST_ASSERT_NULL(queue_dequeue(NULL));
}

void    test_queue_dequeue_empty(void)
{
    t_queue *queue = queue_create();

    TEST_ASSERT_NULL(queue_dequeue(queue));

    queue_clear(queue, free);
}

void    test_queue_dequeue_one(void)
{
    t_queue *queue = queue_create();

    t_data  data = (t_data)malloc(sizeof(int));
    *(int *)data = 42;
    queue_enqueue(queue, data);

    int *dequeue = (int *)queue_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(42, *dequeue);
    
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);

    free(dequeue);
    queue_clear(queue, free);
}

void    test_queue_dequeue_two(void)
{
    t_queue *queue = queue_create();

    t_data  data1 = (t_data)malloc(sizeof(int));
    *(int *)data1 = 42;
    queue_enqueue(queue, data1);

    t_data  data2 = (t_data)malloc(sizeof(int));
    *(int *)data2 = 24;
    queue_enqueue(queue, data2);

    int *dequeue1 = (int *)queue_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(42, *dequeue1);

    TEST_ASSERT_EQUAL_INT(24, *(int *)queue->head->data);
    TEST_ASSERT_EQUAL_INT(24, *(int *)queue->tail->data);

    free(dequeue1);
    queue_clear(queue, free);
}

void    test_queue_dequeue_three(void)
{
    t_queue *queue = queue_create();

    t_data  data1 = (t_data)malloc(sizeof(int));
    *(int *)data1 = 42;
    queue_enqueue(queue, data1);

    t_data  data2 = (t_data)malloc(sizeof(int));
    *(int *)data2 = 24;
    queue_enqueue(queue, data2);

    t_data  data3 = (t_data)malloc(sizeof(int));
    *(int *)data3 = 12;
    queue_enqueue(queue, data3);

    int *dequeue1 = (int *)queue_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(42, *dequeue1);

    int *dequeue2 = (int *)queue_dequeue(queue);
    TEST_ASSERT_EQUAL_INT(24, *dequeue2);

    TEST_ASSERT_EQUAL_INT(12, *(int *)queue->head->data);
    TEST_ASSERT_EQUAL_INT(12, *(int *)queue->tail->data);

    free(dequeue1);
    free(dequeue2);
    queue_clear(queue, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_queue_dequeue_null);
    RUN_TEST(test_queue_dequeue_empty);
    RUN_TEST(test_queue_dequeue_one);
    RUN_TEST(test_queue_dequeue_two);
    RUN_TEST(test_queue_dequeue_three);
    return UNITY_END();
}
