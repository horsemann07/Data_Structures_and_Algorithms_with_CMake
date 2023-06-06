/**
 * @file list.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 1.0.1
 * @date 28-12-2022
 */

#include "list.h"
#include <limits.h>

dsa_err_t linear_search(list_t *list, int key, uint32_t *index)
{
    DSA_CHECK_ARG(list && index);

    for (int i = 0; i < list->size; i++)
    {
        if (key == list->data[i])
        {
            *index = i;
            return DSA_OK;
        }
    }
    return DSA_FAIL;
}

dsa_err_t binary_search(list_t *list, int key, uint32_t *index)
{
    DSA_CHECK_ARG(list && index);
    size_t low = 0, high = list->size - 1;
    size_t mid = (low + high) / 2;
    while ((high - low) > 1)
    {
        if (list->data[mid] == key)
        {
            *index = mid;
            return DSA_OK;
        }
        else if (key < list->data[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return DSA_FAIL;
}

dsa_err_t list_create(list_t *list, int size)
{
    DSA_CHECK_ARG(list && size > 0);
    list->data = (int *)calloc(size, sizeof(int));
    list->size = size;
    list->cindex = 0;
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

dsa_err_t list_append_data(list_t *list, int data)
{
    DSA_CHECK_ARG(list && list->cindex < list->size);

    list->data[list->cindex++] = data;
    return DSA_OK;
}

dsa_err_t list_insert_data(list_t *list, int data, int index)
{
    DSA_CHECK_ARG(list && index < list->size);
    list->data[index] = data;
    return DSA_OK;
}

dsa_err_t list_delete_index(list_t *list, int index)
{
    DSA_CHECK_ARG(list && index < list->size);
    list->data[index] = INT_MIN;
    return DSA_OK;
}

dsa_err_t list_search_data(list_t *list, int key, uint32_t *index, bool sorted)
{
    if (sorted)
    {
        return (binary_search(list, key, index));
    }
    else
    {
        return (linear_search(list, key, index));
    }
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

dsa_err_t list_get_max(list_t *list, uint32_t *max)
{
    DSA_CHECK_ARG(list && max);
    *max = list->data[0];
    for (int i = 1; i < list->size; i++)
    {
        if (list->data[i] > (*max))
        {
            (*max) = list->data[i];
        }
    }
    return DSA_OK;
}

dsa_err_t list_get_min(list_t *list, uint32_t *min)
{
    DSA_CHECK_ARG(list && min);
    *min = list->data[0];
    for (int i = 1; i < list->size; i++)
    {
        if (list->data[i] < (*min))
        {
            (*min) = list->data[i];
        }
    }
    return DSA_OK;
}

dsa_err_t list_reverse(list_t *list)
{
    DSA_CHECK_ARG(list);
    int start = 0, end = list->size - 1;
    while (start < end)
    {
        SWAP((list->data[start]), (list->data[end]));
        start++;
        end--;
    }
    return DSA_OK;
}

dsa_err_t list_shift(list_t *list, uint32_t rotate, bool left_shift)
{
    DSA_CHECK_ARG(list);
    int sstart; // shift start index
    if (left_shift)
    {
        int start = 0;
        sstart = rotate;
        for (start = 0; sstart < list->size; start++)
        {
            list->data[start] = list->data[sstart++];
        }
        for (; start < list->size; start++)
        {
            list->data[start] = 0;
        }
    }
    else
    {
        int end;
        sstart = end - rotate;
        for (end = (list->cindex); sstart >= 0; end--)
        {
            list->data[end] = list->data[sstart--];
        }
        for (; end >= 0; end--)
        {
            list->data[end] = 0;
        }
    }
    return DSA_OK;
}

dsa_err_t list_rotate(list_t *list, uint32_t rotate, bool left_rotation)
{
    DSA_CHECK_ARG(list);
    int rstart = 0;
    int end;
    int start = 0;
    if (left_rotation)
    {
        while (rstart < rotate)
        {
            int temp = list->data[0];
            for (start = 1; start < list->cindex - 1; start++)
            {
                list->data[start] = list->data[start + 1];
            }
            list->data[list->cindex] = temp;
            rstart++;
        }
    }
    else
    {
        while (rstart < rotate)
        {
            int temp = list->data[list->cindex];
            for (end = list->cindex - 1; end > 0; end--)
            {
                list->data[end] = list->data[end - 1];
            }
            list->data[0] = temp;
            rstart++;
        }
    }
    return DSA_OK;
}