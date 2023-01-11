/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

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
// typedef struct s_linkedlist slinkedlist_t;

/**
 * @brief Singly Linked List structure
 *
 */
typedef struct
{
    int data;
    slinkedlist_t *nlink;
} slinkedlist_t;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

/**
 * @brief
 *
 * @param llist
 * @param key
 * @return dsa_err_t
 */
dsa_err_t slinkedlist_create_node(slinkedlist_t *llist, int key);

sa_err_t slinkedlist_display_data(slinkedlist_t *head);

dsa_err_t slinkedlist_length(slinkedlist_t *head, uint32_t *len);

dsa_err_t slinkedlist_insert(slinkedlist_t *head, int key);

dsa_err_t slinkedlist_insert_at_pos(slinkedlist_t *head, uint32_t pos, int key);

dsa_err_t slinkedlist_delete_node(slinkedlist_t *head, uint32_t pos);

dsa_err_t slinkedlist_reverse(slinkedlist_t *head);

dsa_err_t slinkedlist_is_lists_match(slinkedlist_t *head1, slinkedlist_t *head2);

dsa_err_t slinkedlist_merge_sorted_list(
    slinkedlist_t *head1, slinkedlist_t *head2, slinkedlist_t *merge);

sa_err_t slinkedlist_get_node(slinkedlist_t *head, uint32_t pos, int *value);

dsa_err_t slinkedlist_remove_duplicates(slinkedlist_t *head);

dsa_err_t slinkedlist_remove_duplicates_in_sorted_list(slinkedlist_t *head);
#ifdef __cplusplus
}
#endif
