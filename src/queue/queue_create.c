#include "basic-types.h"
#include <stdlib.h>

t_queue *queue_create()
{
    t_queue *queue = malloc(sizeof(t_queue));
    if (queue == NULL)
        return (NULL);

    queue->head = NULL;
    queue->tail = NULL;

    return (queue);
}