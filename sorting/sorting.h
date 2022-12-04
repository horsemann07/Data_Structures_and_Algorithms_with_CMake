
#ifndef __SORTING_H__
#define __SORTING_H__

#include "dsa_config.h"

typedef struct
{
    int32_t *arr_base;
    size_t size;
} list_t;

dsa_err_t sorting_bubble_sort(list_t *list, bool ascending);
dsa_err_t sorting_inserting_sort(list_t *list, bool ascending);
dsa_err_t sorting_selection_sort(list_t *list, bool ascendig);
#endif /* __SORTING_H__*/