#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_set_null(void)
{
    TEST_ASSERT_EQUAL_INT(0, dict_set(NULL, "key", (void *)42));
}

void    test_dict_set_null_key(void)
{
    t_dict *dict = dict_create();
    TEST_ASSERT_EQUAL_INT(0, dict_set(dict, NULL, (void *)42));
    dict_clear(dict, NULL);
}

void    test_dict_set_existing(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    dict_set(dict, "key", data);
    TEST_ASSERT_EQUAL_INT(0, dict_set(dict, "key", data));

    dict_clear(dict, free);
}

void    test_dict_set(void)
{
    t_dict *dict = dict_create();
    int *data = malloc(sizeof(int));
    *data = 42;

    TEST_ASSERT_EQUAL_INT(1, dict_set(dict, "key", data));
    TEST_ASSERT_EQUAL_INT(1, dict->size);
    TEST_ASSERT_EQUAL_INT(42, *(int *)dict_get(dict, "key"));

    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_set_null);
    RUN_TEST(test_dict_set_null_key);
    RUN_TEST(test_dict_set_existing);
    RUN_TEST(test_dict_set);
    return UNITY_END();
}