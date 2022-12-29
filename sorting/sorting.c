/**
 * @file sorting.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 09-11-2022
 */
#include "sorting.h"

/// No-temp-var swap operation
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

dsa_err_t sorting_bubble_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->data);

    for (int row = 0; row < list->size; row++)
    {
        for (int col = 0; col < (list->size - 1 - row); col++)
        {
            // descending order
            if ((ascending == false) && (list->data[col] < list->data[col + 1]))
            {
                SWAP(list->data[col], list->data[col + 1]);
            }
            // ascending order
            else if ((ascending == true) && (list->data[col] > list->data[col + 1]))
            {
                SWAP(list->data[col], list->data[col + 1]);
            }
        }
    }

    return DSA_OK;
}

dsa_err_t sorting_inserting_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->data);

    for (int row = 1; row < list->size; row++)
    {
        int32_t removed_item = list->data[row];
        int col = row - 1;

        while ((col > -1) && (list->data[col] > removed_item))
        {
            list->data[col + 1] = list->data[col];
            col--;
        }
        list->data[col + 1] = removed_item;
    }
    return DSA_OK;
}

/**
 * - Select the index and check for min value in array.
 * - If found, then, swap min value with index value.
 */
dsa_err_t sorting_selection_sort(list_t *list, bool ascendig)
{
    DSA_CHECK_ARG(list && list->data);

    int row, col, index;

    for (row = 0; row < list->size - 1; row++)
    {
        col = row;
        index = row;
        for (/* col = index = row*/; col < list->size; col++)
        {
            // descending
            if (!(ascendig) && (list->data[col] < list->data[index]))
            {
                index = col;
            }
            // ascending
            else if ((ascendig) && (list->data[col] > list->data[index]))
            {
                index = col;
            }
            SWAP(list->data[row], list->data[index]);
        }
    }
    return DSA_OK;
}