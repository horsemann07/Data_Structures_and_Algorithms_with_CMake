
#ifndef __SORTING_H__
#define __SORTING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dsa.h"
#include "list.h"

dsa_err_t sorting_bubble_sort(list_t *list, bool ascending);
dsa_err_t sorting_inserting_sort(list_t *list, bool ascending);
dsa_err_t sorting_selection_sort(list_t *list, bool ascendig);

#ifdef __cplusplus
}
#endif
#endif /* __SORTING_H__*/