#include "basic-types.h"

int dict_hash(t_dict *dict, const char *key)
{
    unsigned long hash = 5381;
    for (int i = 0; key[i]; i++)
        hash = ((hash << 5) + hash) + key[i];

    return hash % dict->capacity;
}