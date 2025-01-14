#include "basic-types.h"
#include <string.h>
#include <stdlib.h>

static void dict_keys_destroy(t_list *list)
{
    while (list)
    {
        t_list *tmp = list;
        list = list->next;
        free(tmp);
    }
}

char    **dict_keys(t_dict *dict)
{
    if (!dict || !dict->size)
        return (NULL);

    t_list *keys = NULL;
    for (int i = 0; i < dict->capacity; i++)
    {
        t_list *bucket = dict->buckets[i]->next;
        while (bucket)
        {
            t_dict_data *data = bucket->data;
            list_insert(&keys, (char *)data->key, 0);
            bucket = bucket->next;
        }
    }
    char **result = (char **)list_toArray(keys, (t_data (*)(t_data))strdup);

    dict_keys_destroy(keys);
    return (result);
}