#include "basic-types.h"

int dict_size(t_dict *dict)
{
    if (!dict)
        return 0;

    int size = 0;
    for (int i = 0; i < dict->capacity; i++)
    {
        if (dict->buckets[i])
            size += list_size(dict->buckets[i]) - 1;
    }

    return size;
}