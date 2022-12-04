/**
 * @file sorting.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 09-11-2022
 */
#include "sorting.h"

//#include "list.h"
///< No-temp-var swap operation
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

dsa_err_t sorting_bubble_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->arr_base);

    for (int row = 0; row < list->size; row++)
    {
        for (int col = 0; col < (list->size - 1 - row); col++)
        {
            // descending order
            if ((ascending == false) && (list->arr_base[col] < list->arr_base[col + 1]))
            {
                SWAP(list->arr_base[col], list->arr_base[col + 1]);
            }
            // ascending order
            else if ((ascending == true) && (list->arr_base[col] > list->arr_base[col + 1]))
            {
                SWAP(list->arr_base[col], list->arr_base[col + 1]);
            }
        }
    }

    return DSA_OK;
}

dsa_err_t sorting_inserting_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->arr_base);

    for (int row = 1; row < list->size; row++)
    {
        int32_t removed_item = list->arr_base[row];
        int col = row - 1;

        while ((col > -1) && (list->arr_base[col] > removed_item))
        {
            list->arr_base[col + 1] = list->arr_base[col];
            col--;
        }
        list->arr_base[col + 1] = removed_item;
    }
    return DSA_OK;
}

/**
 * - Select the index and check for min value in array.
 * - If found, then, swap min value with index value.
 */
dsa_err_t sorting_selection_sort(list_t *list, bool ascendig)
{
    DSA_CHECK_ARG(list && list->arr_base);

    int row, col, index;

    for (row = 0; row < list->size - 1; row++)
    {
        col = row;
        index = row;
        for (/* col = index = row*/; col < list->size; col++)
        {
            // descending
            if (!(ascendig) && (list->arr_base[col] < list->arr_base[index]))
            {
                index = col;
            }
            // ascending
            else if ((ascendig) && (list->arr_base[col] > list->arr_base[index]))
            {
                index = col;
            }
            SWAP(list->arr_base[row], list->arr_base[index]);
        }
    }
    return DSA_OK;
}