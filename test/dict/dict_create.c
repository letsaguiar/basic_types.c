#include "basic-types.h"
#include <unity.h>
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_create(void)
{
    t_dict *dict = dict_create();

    TEST_ASSERT_NOT_NULL(dict);
    TEST_ASSERT_NOT_NULL(dict->buckets);
    TEST_ASSERT_EQUAL_INT(0, dict->size);
    TEST_ASSERT_EQUAL_INT(DICT_CAPACITY, dict->capacity);

    for (int i = 0; i < DICT_CAPACITY; i++)
        TEST_ASSERT_NOT_NULL(dict->buckets[i]);

    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_create);
    return UNITY_END();
}