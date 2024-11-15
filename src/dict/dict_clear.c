#include "basic-types.h"
#include <stdlib.h>

void    dict_clear(t_dict *dict, void (*destroy)(t_data))
{
    if (!dict)
        return ;

    for (int i = 0; i < dict->capacity; i++)
        if (dict->buckets[i])
        {
            t_list *list = dict->buckets[i];
            while (list)
            {
                t_list *tmp = list;
                list = list->next;

                if (!tmp->data)
                    free(tmp);
                else
                {
                    t_dict_data *data = tmp->data;
                    if (destroy && data->value)
                        destroy(data->value);
                    free((void *)data->key);
                    free(data);
                    free(tmp);
                }
            }
        }

    free(dict->buckets);
    free(dict);
}