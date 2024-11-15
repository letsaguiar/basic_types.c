#ifndef BASIC_TYPES_H
# define BASIC_TYPES_H

# define _POSIX_C_SOURCE 200809L

typedef void* t_data;

typedef struct s_list
{
    t_data          data;
    struct s_list   *next;
} t_list;

t_list  *list_create(t_data data);

void    list_destroy(t_list *list, void (*destroy)(t_data));

int     list_append(t_list **list, t_data data);

int     list_insert(t_list **list, t_data data, int index);

void    list_remove(t_list **list, int index, void (*destroy)(t_data));

void    list_clear(t_list **list, void (*destroy)(t_data));

t_list  *list_last(t_list *list);

t_list  *list_get(t_list *list, int index);

t_list  *list_indexOf(t_list *list, t_data data, int (*compare)(t_data, t_data));

int     list_size(t_list *list);

void    list_foreach(t_list *list, void (*f)(t_data, int));

t_list  *list_map(t_list *list, t_data (*f)(t_data, int));

t_data  *list_toArray(t_list *list, t_data (*duplicate)(t_data));

typedef struct s_stack
{
    t_list  *head;
} t_stack;

t_stack *stack_create();

void    stack_clear(t_stack *stack, void (*destroy)(t_data));

int     stack_push(t_stack *stack, t_data data);

t_data  stack_pop(t_stack *stack);

t_data  stack_peek(t_stack *stack);

int     stack_size(t_stack *stack);

typedef struct s_queue
{
    t_list  *head;
    t_list  *tail;
} t_queue;

t_queue *queue_create();

void    queue_clear(t_queue *queue, void (*destroy)(t_data));

int     queue_enqueue(t_queue *queue, t_data data);

t_data  queue_dequeue(t_queue *queue);

t_data  queue_peek(t_queue *queue);

int     queue_size(t_queue *queue);

# define DICT_CAPACITY 13

typedef struct s_dict
{
    t_list **buckets;
    int    size;
    int    capacity;
} t_dict;

typedef struct s_dict_data
{
    const char *key;
    t_data     value;
} t_dict_data;

int    dict_hash(t_dict *dict, const char *key);

t_dict *dict_create();

void    dict_clear(t_dict *dict, void (*destroy)(t_data));

int     dict_set(t_dict *dict, const char *key, t_data value);

t_data  dict_get(t_dict *dict, const char *key);

void    dict_remove(t_dict *dict, const char *key, void (*destroy)(t_data));

int     dict_size(t_dict *dict);

char    **dict_keys(t_dict *dict);

t_data  *dict_values(t_dict *dict, t_data (*duplicate)(t_data));

#endif