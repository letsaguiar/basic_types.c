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

#endif