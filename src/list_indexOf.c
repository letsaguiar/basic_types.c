#include "basic-types.h"
#include <stdlib.h>

t_list  *list_indexOf(t_list *list, t_data data, int (*compare)(t_data, t_data))
{
    for (int i = 0; list; i++)
    {
        if (compare(list->data, data) == 0)
            return (list);
        list = list->next;
    }

    return (NULL);
}