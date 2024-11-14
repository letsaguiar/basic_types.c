#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_list_size_null(void)
{
    t_list  *list = NULL;

    TEST_ASSERT_EQUAL_INT(0, list_size(list));
}

void    test_list_size_one(void)
{
    t_list  *list = list_create(strdup("Hello"));

    TEST_ASSERT_EQUAL_INT(1, list_size(list));
    list_clear(&list, free);
}

void    test_list_size_two(void)
{
    t_list  *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));

    TEST_ASSERT_EQUAL_INT(2, list_size(list));
    list_clear(&list, free);
}

void    test_list_size_three(void)
{
    t_list  *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_append(&list, strdup("!"));

    TEST_ASSERT_EQUAL_INT(3, list_size(list));
    list_clear(&list, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_size_null);
    RUN_TEST(test_list_size_one);
    RUN_TEST(test_list_size_two);
    RUN_TEST(test_list_size_three);
    return (UNITY_END());
}