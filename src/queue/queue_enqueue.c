#include "basic-types.h"
#include <stdlib.h>

int queue_enqueue(t_queue *queue, t_data data)
{
    if (!queue || !list_append(&queue->tail, data))
        return (0);

    if (queue->head == NULL)
        queue->head = queue->tail;
    if (list_size(queue->tail) > 1)
        queue->tail = queue->tail->next;

    return (1);
}