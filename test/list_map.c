#include "basic-types.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void    setUp(void) { }

void    tearDown(void) { }

t_data  test_callback(t_data data, int index)
{
    (void)index;

    char *str = strdup(data);
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);

    return (str);
}

void    test_list_map_null(void)
{
    t_list  *list = NULL;

    TEST_ASSERT_NULL(list_map(list, NULL));
}

void    test_list_map_one(void)
{
    t_list *list = list_create(strdup("Hello"));
    t_list *map = list_map(list, test_callback);

    TEST_ASSERT_EQUAL_STRING("HELLO", map->data);

    list_clear(&list, free);
    list_clear(&map, free);
}

void    test_list_map_two(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    t_list *map = list_map(list, test_callback);

    TEST_ASSERT_EQUAL_STRING("HELLO", map->data);
    TEST_ASSERT_EQUAL_STRING("WORLD", map->next->data);

    list_clear(&list, free);
    list_clear(&map, free);
}

void    test_list_map_three(void)
{
    t_list *list = list_create(strdup("Hello"));
    list_append(&list, strdup("World"));
    list_append(&list, strdup("!"));
    t_list *map = list_map(list, test_callback);

    TEST_ASSERT_EQUAL_STRING("HELLO", map->data);
    TEST_ASSERT_EQUAL_STRING("WORLD", map->next->data);
    TEST_ASSERT_EQUAL_STRING("!", map->next->next->data);

    list_clear(&list, free);
    list_clear(&map, free);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_map_null);
    RUN_TEST(test_list_map_one);
    RUN_TEST(test_list_map_two);
    RUN_TEST(test_list_map_three);
    return (UNITY_END());
}