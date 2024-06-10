
#ifndef _LIST_UT_
#define _LIST_UT_
#ifdef __cplusplus
extern "C" {
#endif

#include "list.h"  // Include header for list implementation

// Function prototypes for test cases
void test_list_create(void);
void test_list_append_data(void);
void test_list_insert_data(void);
void test_list_delete_index(void);
void test_linear_search(void);
void test_binary_search(void);
void test_list_search_data(void);
void test_list_get(void);
void test_list_set(void);
void test_list_get_max(void);
void test_list_get_min(void);
void test_list_reverse(void);
void test_list_shift_left(void);
void test_list_shift_right(void);
void test_list_rotate_left(void);
void test_list_rotate_right(void);

#ifdef __cplusplus
}
#endif
#endif /* _LIST_UT_ */