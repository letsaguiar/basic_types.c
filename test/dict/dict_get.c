#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_get_null(void)
{
    TEST_ASSERT_NULL(dict_get(NULL, "key"));
}

void    test_dict_get_null_key(void)
{
    t_dict *dict = dict_create();
    TEST_ASSERT_NULL(dict_get(dict, NULL));
    dict_clear(dict, NULL);
}

void    test_dict_get(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    dict_set(dict, "key", data);
    TEST_ASSERT_EQUAL_INT(42, *(int *)dict_get(dict, "key"));

    dict_clear(dict, free);
}

void    test_dict_get_not_found(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    dict_set(dict, "key", data);
    TEST_ASSERT_NULL(dict_get(dict, "not_found"));

    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_get_null);
    RUN_TEST(test_dict_get_null_key);
    RUN_TEST(test_dict_get);
    RUN_TEST(test_dict_get_not_found);
    return UNITY_END();
}