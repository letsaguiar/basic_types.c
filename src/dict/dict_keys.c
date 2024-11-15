#include "basic-types.h"
#include <string.h>
#include <stdlib.h>

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
            list_insert(&keys, strdup(data->key), 0);
            bucket = bucket->next;
        }
    }
    char **result = (char **)list_toArray(keys, (t_data (*)(t_data))strdup);

    list_clear(&keys, free);
    return (result);
}