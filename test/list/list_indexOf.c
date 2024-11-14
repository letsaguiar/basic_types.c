#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_list_indexOf_0(void)
{
    t_list  *list = list_create(strdup("Hello"));
    t_list  *found = list_indexOf(list, "Hello", (int (*)(void *, void *))strcmp);

    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_STRING("Hello", found->data);

    list_clear(&list, free);
}

void    test_list_indexOf_1(void)
{
    t_list  *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    t_list  *found = list_indexOf(list, "World", (int (*)(void *, void *))strcmp);


    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_STRING("World", found->data);
    
    list_clear(&list, free);
}

void    test_list_indexOf_invalid(void)
{
    t_list  *list = list_create(strdup("Hello"));
    t_list  *found = list_indexOf(list, "World", (int (*)(void *, void *))strcmp);

    TEST_ASSERT_NULL(found);

    list_clear(&list, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_indexOf_0);
    RUN_TEST(test_list_indexOf_1);
    RUN_TEST(test_list_indexOf_invalid);
    return UNITY_END();
}