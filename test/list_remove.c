#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_list_remove_0(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_remove(&list, 0, free);

    TEST_ASSERT_NULL(list);
}

void    test_list_remove_1(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_remove(&list, 1, free);

    TEST_ASSERT_EQUAL_STRING("Hello", list->data);
    TEST_ASSERT_NULL(list->next);

    list_destroy(list, free);
}

void    test_list_remove_invalid(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_remove(&list, 1, free);

    TEST_ASSERT_EQUAL_STRING("Hello", list->data);
    TEST_ASSERT_NULL(list->next);

    list_destroy(list, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_remove_0);
    RUN_TEST(test_list_remove_1);
    RUN_TEST(test_list_remove_invalid);
    return UNITY_END();
}