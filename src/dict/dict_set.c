#include "basic-types.h"
#include <string.h>
#include <stdlib.h>

int dict_set(t_dict *dict, const char *key, t_data value)
{
    if (!dict || !key || dict_get(dict, key))
        return (0);
    
    int hash = dict_hash(dict, key);
    t_list *bucket = dict->buckets[hash];
    t_dict_data *data = malloc(sizeof(t_dict_data));
    if (!data)
        return (0);
    data->key = strdup(key);
    data->value = value;
    if (!list_append(&bucket, data))
    {
        free(data);
        return (0);
    }
    dict->size += 1;
    return (1);
}