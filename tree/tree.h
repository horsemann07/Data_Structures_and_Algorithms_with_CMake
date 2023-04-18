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

typedef struct d_linkedlist dlinkedlist_t;

typedef struct d_linkedlist
{
    int32_t data;         /*! current node data*/
    dlinkedlist_t *llink; /*! left child*/
    dlinkedlist_t *rlink; /*! right child*/
} dlinkedlist_t;

#ifdef __cplusplus
}
#endif
