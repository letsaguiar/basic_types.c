#include "basic-types.h"
#include <stdlib.h>

t_data  *list_toArray(t_list *list, t_data (*duplicate)(t_data))
{
    if (!list)
        return (NULL);

    int size = list_size(list);
    t_data *array = malloc(sizeof(t_data) * size);
    if (!array)
        return (NULL);

    for (int i = 0; i < size; i++)
    {
        array[i] = duplicate(list->data);
        list = list->next;
    }

    return (array);
}