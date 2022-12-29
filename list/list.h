/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

#ifndef _LIST_H_
#define _LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/
#include "dsa.h"
/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/
typedef struct
{
    int size;
    int *data;
    uint32_t cindex;
} list_t;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

dsa_err_t list_create(list_t *list, int size);

dsa_err_t list_display_data(list_t *list);

dsa_err_t list_append_data(list_t *list, int data);

dsa_err_t list_insert_data(list_t *list, int data, int index);

dsa_err_t list_delete_index(list_t *list, int index);

dsa_err_t list_search_data(list_t *list, int key, uint32_t *index, bool sorted);

dsa_err_t list_get(list_t *list, int index, int *value);

dsa_err_t list_set(list_t *list, int index, int value);

dsa_err_t list_get_max(list_t *list, uint32_t *max);

dsa_err_t list_get_min(list_t *list, uint32_t *min);

dsa_err_t list_reverse(list_t *list);

dsa_err_t list_shift(list_t *list, list_t *shifted_list, bool left_shift);

dsa_err_t list_rotate(list_t *list, list_t *rotated_list, bool *left_rotation);

#ifdef __cplusplus
}
#endif

#endif /* _LIST_H_ */
