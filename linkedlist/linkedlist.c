

#include "dsa.h"
#include "linkedlist.h"

dsa_err_t linkedlist_create(linkedlist_t *llist, int key)
{
    DSA_CHECK_ARG(llist);

    llist = (linkedlist_t *)calloc(1, sizeof(linkedlist_t));
    if (llist == NULL)
    {
        return DSA_NO_MEM;
    }
    llist->data = key;
    return DSA_OK;
}

dsa_err_t linkedlist_display(linkedlist_t *head)
{
    DSA_CHECK_ARG(head);
    linkedlist_t *temp = head;

    while (temp != NULL)
    {
        printf("%d \n", temp->data);

        temp = temp->nlink;
    }

    return DSA_OK;
}

dsa_err_t linkedlist_length(linkedlist_t *head, int *len)
{
    DSA_CHECK_ARG(head);
    linkedlist_t *temp = head;
    (*len) = 0;
    while (temp != NULL)
    {
        (*len)++;
        temp = temp->nlink;
    }
    return DSA_OK;
}

dsa_err_t linkedlist_insert(linkedlist_t *head, int key)
{
    DSA_CHECK_ARG(head);
    linkedlist_t *temp = head;

    while (temp->nlink != NULL)
    {
        printf("%d \n", temp->data);

        temp = temp->nlink;
    }
    return (linkedlist_create(&(temp->nlink), key));
}
// 1 2 3 4 5
dsa_err_t linkedlist_insert_at_pos(linkedlist_t *head, uint32_t pos, int key)
{
    DSA_CHECK_ARG(head);
    linkedlist_t *temp = head;
    linkedlist_t *next = NULL;
    int len;
    linkedlist_length(head, &len);
    DSA_CHECK_ARG(pos <= len);

    for (int start = 0; start < pos - 1; start++)
    {
        temp = temp->nlink;
    }
    next = temp->nlink->nlink;
    linkedlist_create(&(temp->nlink), key);
    temp = temp->nlink;
    temp->nlink = next;
    return DSA_OK;
}