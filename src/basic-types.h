#ifndef BASIC_TYPES_H
# define BASIC_TYPES_H

typedef void* t_data;

typedef struct s_list
{
    t_data          data;
    struct s_list   *next;
} t_list;

t_list  *list_create(t_data data);

void    list_destroy(t_list *list, void (*destroy)(t_data));

int     list_append(t_list **list, t_data data);

int     list_insert(t_list **list, t_data data, int index, void (*destroy)(t_data));

void    list_remove(t_list **list, int index, void (*destroy)(t_data));

t_list  *list_last(t_list *list);

t_list  *list_get(t_list *list, int index);

t_list  *list_indexOf(t_list *list, t_data data, int (*compare)(t_data, t_data));

#endif