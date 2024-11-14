#include "basic-types.h"
#include <stdlib.h>

t_data  stack_peek(t_stack *stack)
{
    if (!stack || !stack->head)
        return (NULL);

    return (stack->head->data);
}