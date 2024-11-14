#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void setUp(void) { }

void tearDown(void) { }

void    test_list_create(void)
{
    t_list *list = list_create(strdup("Hello World"));

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_STRING("Hello World", list->data);
    TEST_ASSERT_NULL(list->next);

    list_destroy(list, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_create);
    return UNITY_END();
}