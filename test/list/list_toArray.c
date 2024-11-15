#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_list_toArray_null(void)
{
    TEST_ASSERT_NULL(list_toArray(NULL, NULL));
}

void    test_list_toArray(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));

    char **array = (char **)list_toArray(list, (void *(*)(void *))strdup);
    TEST_ASSERT_NOT_NULL(array);
    TEST_ASSERT_EQUAL_STRING("Hello", array[0]);
    TEST_ASSERT_EQUAL_STRING("World", array[1]);

    free(array[0]);
    free(array[1]);
    free(array);
    list_clear(&list, free);
}

int     main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_toArray_null);
    RUN_TEST(test_list_toArray);
    return UNITY_END();
}