#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void setUp(void) { }

void tearDown(void) { }

void    test_list_insert_0(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_insert(&list, strdup("World"), 0, free);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_STRING("World", list->data);
    TEST_ASSERT_NOT_NULL(list->next);
    TEST_ASSERT_EQUAL_STRING("Hello", list->next->data);
    TEST_ASSERT_NULL(list->next->next);

    list_clear(&list, free);
}

void    test_list_insert_1(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_insert(&list, strdup("World"), 1, free);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_STRING("Hello", list->data);
    TEST_ASSERT_NOT_NULL(list->next);
    TEST_ASSERT_EQUAL_STRING("World", list->next->data);
    TEST_ASSERT_NULL(list->next->next);

    list_clear(&list, free);
}

void    test_list_insert_invalid(void)
{
    t_list *list = list_create(strdup("Hello"));
    TEST_ASSERT_EQUAL_INT(0, list_insert(&list, strdup("World"), 2, free));
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_STRING("Hello", list->data);
    TEST_ASSERT_NULL(list->next);

    list_clear(&list, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_insert_0);
    RUN_TEST(test_list_insert_1);
    RUN_TEST(test_list_insert_invalid);
    return UNITY_END();
}