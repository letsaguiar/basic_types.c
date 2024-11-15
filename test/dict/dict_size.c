#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_size_null(void)
{
    TEST_ASSERT_EQUAL_INT(0, dict_size(NULL));
}

void    test_dict_size_empty(void)
{
    t_dict *dict = dict_create();
    TEST_ASSERT_EQUAL_INT(0, dict_size(dict));
    dict_clear(dict, NULL);
}

void    test_dict_size_one(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    dict_set(dict, "key", data);
    TEST_ASSERT_EQUAL_INT(1, dict_size(dict));

    dict_clear(dict, free);
}

void    test_dict_size_two(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;
    int *data2 = malloc(sizeof(int));
    *data2 = 42;

    dict_set(dict, "key", data);
    dict_set(dict, "key2", data2);
    TEST_ASSERT_EQUAL_INT(2, dict_size(dict));

    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_size_null);
    RUN_TEST(test_dict_size_empty);
    RUN_TEST(test_dict_size_one);
    RUN_TEST(test_dict_size_two);
    return UNITY_END();
}