#include "basic-types.h"
#include <string.h>
#include <stdlib.h>

t_data  dict_get(t_dict *dict, const char *key)
{
    if (!dict || !key)
        return (NULL);

    int hash = dict_hash(dict, key);
    t_list *bucket = dict->buckets[hash];
    t_list *current = bucket->next;
    while (current)
    {
        t_dict_data *data = current->data;
        if (strcmp(data->key, key) == 0)
            return (data->value);
        current = current->next;
    }
    return (NULL);
}