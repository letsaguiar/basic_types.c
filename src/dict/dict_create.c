#include "basic-types.h"
#include <stdlib.h>

t_dict  *dict_create()
{
    t_dict *dict = malloc(sizeof(t_dict));
    if (!dict)
        return (NULL);

    dict->size = 0;
    dict->capacity = DICT_CAPACITY;

    dict->buckets = malloc(DICT_CAPACITY * sizeof(t_list *));
    if (!dict->buckets)
    {
        free(dict);
        return (NULL);
    }

    t_list *tmp;
    for (int i = 0; i < dict->capacity; i++)
    {
        tmp = list_create(NULL);
        if (!tmp)
        {
            dict_clear(dict, NULL);
            return (NULL);
        }

        dict->buckets[i] = tmp;
    }

    return (dict);
}