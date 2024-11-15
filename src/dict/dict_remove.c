#include "basic-types.h"
#include <string.h>
#include <stdlib.h>

static int     dict_remove_check(t_list *list, const char *key)
{
    if (!list)
        return (0);

    t_dict_data *data = list->data;
    return (strcmp(data->key, key) == 0);
}

static void    dict_remove_destroy(t_list *list, void (*destroy)(t_data))
{
    t_dict_data *data = list->data;
    if (destroy && data->value)
        destroy(data->value);
    free((void *)data->key);
    free(data);
    free(list);
}

void           dict_remove(t_dict *dict, const char *key, void (*destroy)(t_data))
{
    if (!dict || !key)
        return ;

    int index = dict_hash(dict, key);
    t_list *bucket = dict->buckets[index];
    while (bucket)
    {
        t_list *next = bucket->next;
        if (dict_remove_check(next, key))
        {
            bucket->next = next->next;
            dict_remove_destroy(next, destroy);
            dict->size -= 1;
            break;
        }
    }
}