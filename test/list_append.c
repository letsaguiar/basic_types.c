#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void setUp(void) { }

void tearDown(void) { }

void    test_list_append(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));

    TEST_ASSERT_NOT_NULL(list->next);
    TEST_ASSERT_EQUAL_STRING("World", list->next->data);
    TEST_ASSERT_NULL(list->next->next);

    list_destroy(list->next, free);
    list_destroy(list, free);
}

void    test_list_append_two(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_append(&list, strdup("!"));

    TEST_ASSERT_NOT_NULL(list->next);
    TEST_ASSERT_EQUAL_STRING("World", list->next->data);
    TEST_ASSERT_NOT_NULL(list->next->next);
    TEST_ASSERT_EQUAL_STRING("!", list->next->next->data);
    TEST_ASSERT_NULL(list->next->next->next);

    list_destroy(list->next->next, free);
    list_destroy(list->next, free);
    list_destroy(list, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_append);
    RUN_TEST(test_list_append_two);
    return UNITY_END();
}