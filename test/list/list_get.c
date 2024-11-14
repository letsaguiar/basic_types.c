#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_list_get_null(void)
{
    t_list  *list = NULL;

    TEST_ASSERT_NULL(list_get(list, 0));
}

void    test_list_get_valid(void)
{
    t_list  *list = list_create(strdup("Hello"));

    TEST_ASSERT_EQUAL_STRING("Hello", list_get(list, 0)->data);
    list_clear(&list, free);
}

void    test_list_get_invalid(void)
{
    t_list  *list = list_create(strdup("Hello"));

    TEST_ASSERT_NULL(list_get(list, 1));
    list_clear(&list, free);
}

void    test_list_get_multiple(void)
{
    t_list  *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_append(&list, strdup("!"));

    TEST_ASSERT_EQUAL_STRING("Hello", list_get(list, 0)->data);
    TEST_ASSERT_EQUAL_STRING("World", list_get(list, 1)->data);
    TEST_ASSERT_EQUAL_STRING("!", list_get(list, 2)->data);
    TEST_ASSERT_NULL(list_get(list, 3));
    list_clear(&list, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_get_null);
    RUN_TEST(test_list_get_valid);
    RUN_TEST(test_list_get_invalid);
    RUN_TEST(test_list_get_multiple);
    return (UNITY_END());
}