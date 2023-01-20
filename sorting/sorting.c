/**
 * @file sorting.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 09-11-2022
 */
#include "sorting.h"

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

/*
 * - Select the index and check for min value in array.
 * - If found, then, swap min value with index value.
 */
dsa_err_t sorting_selection_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->data);

    int row, col, index;

    for (row = 0; row < list->size - 1; row++)
    {
        col = row;
        index = row;
        for (; col < list->size; col++)
        {
            // descending
            if (!(ascending) && (list->data[col] < list->data[index]))
            {
                index = col;
            }
            // ascending
            else if ((ascending) && (list->data[col] > list->data[index]))
            {
                index = col;
            }
            SWAP(list->data[row], list->data[index]);
        }
    }
    return DSA_OK;
}

// array, size
// pivot = arr[0];
// iterate until low < high
// high swap with pivot value
// retun index

// array, size
// untill single element
// pivot index = partition
// qsort ( array, pivot)
// qsort ( &array[pivot+1], count - (pivot+1) )

static int32_t partition(int32_t *list, int32_t size, bool ascending)
{
    DSA_CHECK_ARG(list);

    int32_t pivot = 0;
    int32_t low = 1, high = size - 1;
    while (low < high)
    {
        if (ascending)
        {
            if (list[low] > list[high])
            {
                SWAP(list[low], list[high]);
            }
        }
        else
        {
            if (list[low] < list[high])
            {
                SWAP(list[low], list[high]);
            }
        }

        low++;
        high--;
    }
    SWAP(list[pivot], list[high]);
    return high;
}

static dsa_err_t quick_sort(int32_t *list, uint32_t size, bool ascending)
{
    dsa_err_t ret = DSA_OK;
    if (size > 1)
    {
        int32_t pvt_idx = partition(list, size, ascending);
        ret = quick_sort(list, pvt_idx, ascending);
        if (ret != DSA_OK)
        {
            return ret;
        }

        ret = quick_sort(&list[pvt_idx + 1], size - pvt_idx, ascending);
        if (ret != DSA_OK)
        {
            return ret;
        }
    }
    return ret;
}

dsa_err_t sorting_quick_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->data);
    return quick_sort(list->data, list->size, ascending);
}