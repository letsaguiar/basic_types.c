#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_remove_null(void)
{
    dict_remove(NULL, "key", NULL);
}

void    test_dict_remove_null_key(void)
{
    t_dict *dict = dict_create();
    dict_remove(dict, NULL, NULL);
    dict_clear(dict, NULL);
}

void    test_dict_remove(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    dict_set(dict, "key", data);
    dict_remove(dict, "key", free);

    TEST_ASSERT_EQUAL_INT(0, dict->size);
    TEST_ASSERT_NULL(dict_get(dict, "key"));

    dict_clear(dict, free);
}

void    test_dict_remove_and_insert(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    dict_set(dict, "key", data);
    dict_remove(dict, "key", free);

    int *data2 = malloc(sizeof(int));
    *data2 = 42;

    dict_set(dict, "key", data2);

    TEST_ASSERT_EQUAL_INT(1, dict->size);
    TEST_ASSERT_EQUAL_INT(42, *(int *)dict_get(dict, "key"));

    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_remove_null);
    RUN_TEST(test_dict_remove_null_key);
    RUN_TEST(test_dict_remove);
    RUN_TEST(test_dict_remove_and_insert);
    return UNITY_END();
}