/**
 * @file sorting.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 09-11-2022
 */
#include "sorting.h"
#include "linkedlist.h"

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

static void merge(list_t *list, int left, int mid, int right, bool ascending)
{
    int k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *arr = list->data;
    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays
    // back into arr[l..r]
    int i = 0;
    int j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (ascending)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        else
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    }

    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements
    // of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

dsa_err_t merge_sort(list_t *list, uint32_t l, uint32_t r, bool ascending)
{
    if (l < r)
    {
        // Same as (l+r)/2 but avoids
        // overflow for large l & h
        int m = l + (r - l) / 2;
        merge_sort(list, l, m, ascending);
        merge_sort(list, m + 1, r, ascending);
        merge(list, l, m, r, ascending);
    }
    return DSA_OK;
}

dsa_err_t sorting_merge_sort(list_t *list, bool ascending)
{
    DSA_CHECK_ARG(list && list->data);
    return merge_sort(list, 0, list->size, ascending);
}

dsa_err_t sorting_counting_sort(list_t *list)
{
    DSA_CHECK_ARG(list);
    dsa_err_t ret = DSA_OK;
    uint32_t max = 0;

    // get max value in array.
    ret = list_get_max(list, &(max));
    if (ret != DSA_OK)
    {
        return ret;
    }

    uint32_t count[max];
    for (size_t i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    // start the count of each element
    for (size_t i = 0; i < list->size; i++)
    {
        count[list->data[i]]++;
    }

    // start cumulative count
    for (size_t i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // find the sorted index of element
    uint32_t sortA[list->size];
    for (size_t i = list->size - 1; i >= 0; i--)
    {
        uint32_t index = count[list->data[i]] - 1;
        sortA[index] = list->data[i];
        count[list->data[i]]--;
    }

    // copy sorted element into original
    for (size_t i = 0; i < count; i++)
    {
        list->data[i] = sortA[i];
    }
    return DSA_OK;
}

dsa_err_t sorting_bin_sort(list_t *list)
{
    uint32_t max = 0, i = 0, j = 0;
    dsa_err_t ret = list_get_max(list, &(max));

    if (ret != DSA_OK)
    {
        return ret;
    }
    slinkedlist_t **bins = NULL;
    bins = (slinkedlist_t **)malloc(sizeof(int32_t *) * max);
    if (!bins)
    {
        return DSA_NO_MEM;
    }

    for (i = 0; i < max; i++)
    {
        bins[i] = NULL;
    }

    // insert the array data
    for (i = 0; i < list->size; i++)
    {
        ret = slinkedlist_create(bins[list->data[i]], list->data[i]);
        if (ret != DSA_OK)
        {
            DSA_CDEBUG_ON_ERR(ret);
            return ret;
        }
    }
    i = 0, j = 0;
    while (i < (max + 1))
    {
        while (bins[i] != NULL)
        {
            ret = slinkedlist_get_node(bins[i], j, &list->data[j]);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                // return ret;
                break;
            }
            j++;
        }
        i++;
    }
}

dsa_err_t sorting_shell_sort(list_t *list)
{
    DSA_CHECK_ARG(list && list->data);

    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = list->size / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < list->size; i += 1)
        {
            int temp = list->data[i];
            int j;
            for (j = i; j >= interval && list->data[j - interval] > temp; j -= interval)
            {
                list->data[j] = list->data[j - interval];
            }
            list->data[j] = temp;
        }
    }
    return DSA_OK;
}

#include <stdio.h>
int main()
{
    /*Array Size Declaration*/
    int size1, size2, size3;
    printf("\nEnter the size for the first array: ");
    scanf("%d", &size1);
    printf("\nEnter the size for the second array: ");
    scanf("%d", &size2);

    size3 = size1 + size2;
    printf("\nEnter the elements in a sorted manner:");

    /*Array Declaration*/
    int array1[size1], array2[size2], array3[size3];
    /*Array Initialized*/
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &array1[i]);
        array3[i] = array1[i];
    }
    int k = size1;
    printf("\nEnter the elements in a sorted manner:");
    /*Array Initialized*/
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &array2[i]);
        array3[k] = array2[i];
        k++;
    }
    printf("\nmerged array of first and second:\n");
    for (int i = 0; i < size3; i++)
        /*Printing the merged array*/
        printf("%d ", array3[i]);

    printf("\nsorted array in descending order\n");
    /*Sorting Array*/
    for (int i = 0; i < size3; i++)
    {
        int temp;
        for (int j = i + 1; j < size3; j++)
        {
            if (array3[i] < array3[j])
            {
                temp = array3[i];
                array3[i] = array3[j];
                array3[j] = temp;
            }
        }
    }
    /*Printing the sorted Array*/
    for (int i = 0; i < size3; i++)
    {
        printf(" %d ", array3[i]);
    }
    return 0;
}