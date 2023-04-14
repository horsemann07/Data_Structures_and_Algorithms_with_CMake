/**
 * @file linkedlist.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 11-01-2023
 */

#include "linkedlist.h"
#include "dsa.h"

dsa_err_t slinkedlist_create(slinkedlist_t *llist, int key)
{
    DSA_CHECK_ARG(llist);

    llist = (slinkedlist_t *)calloc(1, sizeof(slinkedlist_t));
    if (llist == NULL)
    {
        return DSA_NO_MEM;
    }
    llist->data = key;
    return DSA_OK;
}

dsa_err_t slinkedlist_display_data(slinkedlist_t *head)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = head;

    while (current != NULL)
    {
        printf("%d->", current->data);

        current = current->nlink;
    }
    printf("\n");

    return DSA_OK;
}

/**
 * len  1    2    3    4    5    6    7
 * ll:  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
 */
dsa_err_t slinkedlist_length(slinkedlist_t *head, uint32_t *len)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = head;
    (*len) = 0;
    while (current != NULL)
    {
        (*len)++;
        current = current->nlink;
    }
    return DSA_OK;
}

/*
 */
dsa_err_t slinkedlist_insert(slinkedlist_t *head, int key)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = head;

    while (current->nlink != NULL)
    {
        // printf("%d \n", current->data);

        current = current->nlink;
    }
    return (slinkedlist_create(current->nlink, key));
}

/*
 *
 * ll:  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
 */
dsa_err_t slinkedlist_insert_at_pos(slinkedlist_t *head, uint32_t pos, int key)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = head;
    slinkedlist_t *next = NULL;
    int len;
    slinkedlist_length(head, &len);
    DSA_CHECK_ARG(pos <= len && pos > 0);

    for (int start = 0; start < pos - 1 && current != NULL; start++)
    {
        current = current->nlink;
    }
    next = current->nlink;
    slinkedlist_create(current->nlink, key);
    current = current->nlink;
    current->nlink = next;
    return DSA_OK;
}

/*
 *
 * ll:  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
 */
dsa_err_t slinkedlist_delete_node(slinkedlist_t *head, uint32_t pos)
{
    DSA_CHECK_ARG(head);

    int len;
    slinkedlist_length(head, &len);
    if (pos > len || pos == 0)
    {
        return DSA_INVALID_ARG;
    }
    slinkedlist_t *current = head;
    slinkedlist_t *next = NULL;

    if (pos == 1)
    {
        next = current->nlink;
        free(current);
        current = next;
        head = current;
        return DSA_OK;
    }

    for (int i = 0; i < pos - 1 && current != NULL; i++)
    {
        current = current->nlink;
    }
    next = current->nlink->nlink;
    free(current->nlink);
    current->nlink = next;
    return DSA_OK;
}

dsa_err_t slinkedlist_reverse(slinkedlist_t *head)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = NULL, *next = NULL, *prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->nlink;
        current->nlink = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return DSA_OK;
}

dsa_err_t slinkedlist_is_lists_match(slinkedlist_t *head1, slinkedlist_t *head2)
{
    slinkedlist_t *currentHead1 = head1, *currentHead2 = head2;

    while (currentHead1 != NULL && currentHead2 != NULL)
    {
        if (currentHead1->data != currentHead2->data)
        {
            return DSA_FAIL;
        }
        currentHead1 = currentHead1->nlink;
        currentHead2 = currentHead2->nlink;
    }

    if (currentHead1 == NULL && currentHead2 == NULL)
    {
        return DSA_OK;
    }

    return DSA_FAIL;
}

dsa_err_t slinkedlist_merge_sorted_list(
    slinkedlist_t *head1, slinkedlist_t *head2, slinkedlist_t *merge)
{
    DSA_CHECK_ARG(head1 && head2);

    merge = NULL;
    slinkedlist_t *unsortedList1 = head1, *unsortedList2 = head2;

    if (unsortedList1 == NULL)
    {
        merge = unsortedList2;
        return DSA_OK;
    }

    if (unsortedList2 == NULL)
    {
        merge = unsortedList1;
        return DSA_OK;
    }

    if (unsortedList1->data <= unsortedList2->data)
    {
        merge = unsortedList1;
        // moving head 1 to point to next element in the
        // linked list 1 for further comparison
        unsortedList1 = unsortedList1->nlink;
    }
    else
    {
        merge = unsortedList2;
        // moving head 2 to point to next element in the
        // linked list 2 for further comparison
        unsortedList2 = unsortedList2->nlink;
    }
    slinkedlist_t *tempHead = merge;
    while (unsortedList1 != NULL && unsortedList2 != NULL)
    {
        slinkedlist_t *temp = NULL;
        if (unsortedList1->data <= unsortedList2->data)
        {
            temp = unsortedList1;
            unsortedList1 = unsortedList1->nlink;
        }
        else
        {
            temp = unsortedList2;
            unsortedList2 = unsortedList2->nlink;
        }

        tempHead->nlink = temp;
        tempHead = temp;
    }

    if (unsortedList1 == NULL)
    {
        tempHead->nlink = unsortedList2;
    }
    else if (unsortedList2 == NULL)
    {
        tempHead->nlink = unsortedList1;
    }

    return DSA_OK;
}

dsa_err_t slinkedlist_get_node(slinkedlist_t *head, uint32_t pos, int *value)
{
    DSA_CHECK_ARG(head && value);
    slinkedlist_t *current = head;
    int listlen = 0;
    (*value) = 0;
    for (int start = 0; start < pos && current != NULL; start++)
    {
        current = current->nlink;
    }
    (*value) = current->data;
    return DSA_OK;
}

/*
 *ll :    1 -> 3 -> 5 -> 9 -> 5 -> 7 -> 3 -> 0
 */
dsa_err_t slinkedlist_remove_duplicates(slinkedlist_t *head)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = head;
    slinkedlist_t *next = NULL, *prev = NULL;
    slinkedlist_t *duplicate_node = NULL;
    bool flag = false;
    while (current->nlink != NULL)
    {
        duplicate_node = current->nlink;

        while (duplicate_node != NULL && flag == false)
        {
            if (current->data == duplicate_node->data)
            {
                prev = duplicate_node;
                duplicate_node = duplicate_node->nlink;
            }
            else
            {
                flag = true;
            }
        }

        if (flag == true)
        {
            flag = false;
            next = duplicate_node->nlink;
            free(duplicate_node);
            prev->nlink = next;
        }
        current = current->nlink;
    }
    return DSA_OK;
}

dsa_err_t slinkedlist_remove_duplicates_in_sorted_list(slinkedlist_t *head)
{
    DSA_CHECK_ARG(head);
    slinkedlist_t *current = head;
    slinkedlist_t *next_next = current;
    slinkedlist_t *duplicateNode = NULL;

    while (current->nlink != NULL)
    {
        if (current->data == current->nlink->data)
        {
            next_next = current->nlink->nlink;
            current->nlink = next_next;
        }
        else
        {
            current = current->nlink;
        }
    }
    return DSA_OK;
}
