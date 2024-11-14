#include "basic-types.h"
#include <stdlib.h>

t_list  *list_create(t_data data)
{
    t_list *list = (t_list *) malloc(sizeof(t_list));
    if (!list)
        return (NULL);

    list->data = data;
    list->next = NULL;
    return (list);
}