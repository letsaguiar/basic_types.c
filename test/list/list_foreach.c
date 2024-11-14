#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void    setUp(void) { }

void    tearDown(void) { }

void    test_calls(int check)
{
    static int counter = 0;
    if (check == -1)
        counter++;
    else
    {
        TEST_ASSERT_EQUAL_INT(check, counter);
        counter = 0;
    }
}

void    test_callback(t_data data, int index)
{
    (void)data;
    (void)index;
    test_calls(-1);
}

void    test_list_foreach_null(void)
{
    t_list  *list = NULL;

    list_foreach(list, test_callback);
    test_calls(0);
}

void    test_list_foreach_one(void)
{
    t_list *list = list_create(strdup("Hello"));

    list_foreach(list, test_callback);
    test_calls(1);

    list_clear(&list, free);
}

void    test_list_foreach_two(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));

    list_foreach(list, test_callback);
    test_calls(2);

    list_clear(&list, free);
}

void    test_list_foreach_three(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_append(&list, strdup("!"));

    list_foreach(list, test_callback);
    test_calls(3);

    list_clear(&list, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_foreach_null);
    RUN_TEST(test_list_foreach_one);
    RUN_TEST(test_list_foreach_two);
    RUN_TEST(test_list_foreach_three);
    return (UNITY_END());
}