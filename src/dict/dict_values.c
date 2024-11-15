#include "basic-types.h"
#include <stdlib.h>

static void dict_values_destroy(t_list *list)
{
    while (list)
    {
        t_list *tmp = list;
        list = list->next;
        free(tmp);
    }
}

t_data  *dict_values(t_dict *dict, t_data (*duplicate)(t_data))
{
    if (!dict || !dict->size)
        return (NULL);

    t_list *values = NULL;
    for (int i = 0; i < dict->capacity; i++)
    {
        t_list *bucket = dict->buckets[i]->next;
        while (bucket)
        {
            t_dict_data *data = bucket->data;
            list_insert(&values, data->value, 0);
            bucket = bucket->next;
        }
    }
    t_data *result = list_toArray(values, duplicate);

    dict_values_destroy(values);
    return (result);
}