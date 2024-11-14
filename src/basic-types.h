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

t_list  *list_last(t_list *list);

int     list_append(t_list **list, t_data data);

int     list_insert(t_list **list, t_data data, int index, void (*destroy)(t_data));

#endif