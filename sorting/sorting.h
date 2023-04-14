
#ifndef __SORTING_H__
#define __SORTING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dsa.h"
#include "list.h"

/**
 * @brief
 *
 * @param list
 * @param ascending
 * @return dsa_err_t
 */
dsa_err_t sorting_bubble_sort(list_t *list, bool ascending);

/**
 * @brief
 *
 * @param list
 * @param ascending
 * @return dsa_err_t
 */
dsa_err_t sorting_inserting_sort(list_t *list, bool ascending);

/**
 * @brief
 *
 * @param list
 * @param ascending
 * @return dsa_err_t
 */
dsa_err_t sorting_selection_sort(list_t *list, bool ascending);

/**
 * @brief
 *
 * @param list
 * @param ascending
 * @return dsa_err_t
 */
dsa_err_t sorting_quick_sort(list_t *list, bool ascending);

/**
 * @brief 
 * 
 * @param list 
 * @param ascending 
 * @return dsa_err_t 
 */
dsa_err_t sorting_merge_sort(list_t *list, bool ascending);

/**
 * @brief 
 * 
 * @param list 
 * @return dsa_err_t 
 */
dsa_err_t sorting_counting_sort(list_t *list);

/**
 * @brief 
 * 
 * @param list 
 * @return dsa_err_t 
 */
dsa_err_t sorting_bin_sort(list_t *list);

/**
 * @brief 
 * 
 * @param list 
 * @return dsa_err_t 
 */
dsa_err_t sorting_shell_sort(list_t *list);

#ifdef __cplusplus
}
#endif
#endif /* __SORTING_H__*/