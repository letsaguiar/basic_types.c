#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_dict_keys_null(void)
{
    TEST_ASSERT_NULL(dict_keys(NULL));
}

void    test_dict_keys_empty(void)
{
    t_dict *dict = dict_create();
    TEST_ASSERT_NULL(dict_keys(dict));
    dict_clear(dict, NULL);
}

void    test_dict_keys(void)
{
    t_dict *dict = dict_create();
    dict_set(dict, "key1", strdup("value1"));
    dict_set(dict, "key2", strdup("value2"));
    dict_set(dict, "key3", strdup("value3"));

    char **keys = dict_keys(dict);
    TEST_ASSERT_NOT_NULL(keys);
    TEST_ASSERT_EQUAL_STRING("key3", keys[0]);
    TEST_ASSERT_EQUAL_STRING("key2", keys[1]);
    TEST_ASSERT_EQUAL_STRING("key1", keys[2]);
    
    for (int i = 0; i < 3; i++)
        free(keys[i]);
    free(keys);
    dict_clear(dict, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_dict_keys_null);
    RUN_TEST(test_dict_keys_empty);
    RUN_TEST(test_dict_keys);
    return UNITY_END();
}