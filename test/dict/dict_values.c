#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_values_null(void)
{
    TEST_ASSERT_NULL(dict_values(NULL, NULL));
}

void    test_dict_values_empty(void)
{
    t_dict *dict = dict_create();
    TEST_ASSERT_NULL(dict_values(dict, NULL));
    dict_clear(dict, NULL);
}

void    test_dict_values(void)
{
    t_dict *dict = dict_create();
    dict_set(dict, "key1", strdup("value1"));
    dict_set(dict, "key2", strdup("value2"));
    dict_set(dict, "key3", strdup("value3"));

    t_data *values = dict_values(dict, (void *(*)(t_data))strdup);
    TEST_ASSERT_NOT_NULL(values);
    TEST_ASSERT_EQUAL_STRING("value3", values[0]);

    free(values[0]);
    free(values[1]);
    free(values[2]);
    free(values);
    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_values_null);
    RUN_TEST(test_dict_values_empty);
    RUN_TEST(test_dict_values);
    return UNITY_END();
}