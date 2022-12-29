/**
 * @file list.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 1.0.1
 * @date 28-12-2022
 */

#include "list.h"

dsa_err_t list_create(list_t *list, int size)
{
    DSA_CHECK_ARG(list);
    list->data = (int *)calloc(size, sizeof(int));
    list->size = size;
    return DSA_OK;
}

dsa_err_t list_display_data(list_t *list)
{
    DSA_CHECK_ARG(list);
    for (int i = 1; i <= list->size; i++)
    {
        printf("%d ", list->data[i - 1]);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    return DSA_OK;
}

dsa_err_t list_get(list_t *list, int index, int *value)
{
    DSA_CHECK_ARG(list && index <= list->size);
    *value = list->data[index - 1];
    return DSA_OK;
}

dsa_err_t list_set(list_t *list, int index, int value)
{
    DSA_CHECK_ARG(list && index <= list->size);
    list->data[index - 1] = value;
    return DSA_OK;
}