#include "basic-types.h"
#include <stdlib.h>

t_data  queue_dequeue(t_queue *queue)
{
    if (!queue || !queue->head)
        return (NULL);

    t_list *head = queue->head;
    t_data data = head->data;
    queue->head = head->next;

    if (!queue->head)
        queue->tail = NULL;
    
    free(head);
    return (data);
}