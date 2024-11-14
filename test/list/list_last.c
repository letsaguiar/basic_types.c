#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_list_last_null(void)
{
    t_list  *list = NULL;

    TEST_ASSERT_NULL(list_last(list));
}

void    test_list_last_one(void)
{
    t_list  *list = list_create(strdup("Hello"));

    TEST_ASSERT_EQUAL_STRING("Hello", list_last(list)->data);
    list_clear(&list, free);
}

void    test_list_last_two(void)
{
    t_list  *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));

    TEST_ASSERT_EQUAL_STRING("World", list_last(list)->data);
    list_clear(&list, free);
}

void    test_list_last_three(void)
{
    t_list  *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_append(&list, strdup("!"));

    TEST_ASSERT_EQUAL_STRING("!", list_last(list)->data);
    list_clear(&list, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_last_null);
    RUN_TEST(test_list_last_one);
    RUN_TEST(test_list_last_two);
    RUN_TEST(test_list_last_three);
    return (UNITY_END());
}