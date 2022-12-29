/**
 * @file dsa_main.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-11-2022
 *
 *
 */

#include "dsa_config.h"
#include "list.h"
#include "linkedlist.h"
#include "graph.h"
#include "tree.h"
#include "queue.h"
#include "stack.h"
#include "sorting.h"
#include "stringg.h"

// #include "unity.h"
// #if defined(LINKEDLIST)
// #include "linkedlist.h"
// #define listlist_main main

// #elif defined(LIST)
// #include "list.h"
// #define list_main main

// #elif defined(QUEUE)
// #include "queue.h"
// #define queue_main main

// #elif defined(STACK)
// #include "stack.h"
// #define stack_main main

// #elif defined(STRING_ALG)
// #include "string_alg.h"
// #define strng_alg main

// #else
// /* do nothing */
// #endif

int main()
{
    printf("testing the dsa..\n");

    dsa_err_t ret = DSA_OK;
    list_t list;
    if (list_create(&list, 10) != DSA_OK)
    {
        printf("failed to create list\n");
    }
    else
    {
        printf("list created.\n");
    }

    for (int i = 0; i < list.size; i++)
    {
        list.data[i] = rand() % 10;
    }
    list_display_data(&list);

    return 0;
}