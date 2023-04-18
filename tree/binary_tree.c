/**
 * @file binary_search .c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "queue.h"
#include "stack.h"
#include "tree.h"

dsa_err_t btree_insert_node(int32_t data, dlinkedlist_t *root)
{
    DSA_CHECK_ARG(root)
    dlinkedlist_t *temp_node = (dlinkedlist_t *)malloc(sizeof(dlinkedlist_t));
    if (temp_node == NULL)
    {
        return DSA_NO_MEM;
    }
    dlinkedlist_t *current = NULL, *parent = NULL;

    temp_node->data = data;
    temp_node->llink = NULL;
    temp_node->rlink = NULL;

    // if tree is empty
    if (root == NULL)
    {
        root = temp_node;
    }
    else
    {
        current = root;
    }

    //
    while (current != NULL)
    {
        parent = current;
        // goto left of the tree

        if (data < parent->data)
        {
            current = current->llink;
            // inserrt to the left
            if (current == NULL)
            {
                parent->llink = temp_node;
                return DSA_OK;
            }
        }
        else
        {
            current = current->rlink;
            // insert to the right
            if (current == NULL)
            {
                parent->rlink = temp_node;
                return DSA_OK;
            }
        }
    }

    return DSA_OK;
}

dsa_err_t btree_search_node(dlinkedlist_t *root, int32_t data)
{
    DSA_CHECK_ARG(root)
    dsa_err_t ret = DSA_OK;
    dlinkedlist_t *current = root;
    while (current != NULL && current->data != data)
    {
        // goto left
        if (current->data > data)
        {
            current = current->llink;
        }
        // else goto right
        else
        {
            current = current->rlink;
        }
    }
    if (current == NULL)
    {
        ret = DSA_FAIL;
    }

    return ret;
}

// transversal
dsa_err_t btree_pre_transversal(dlinkedlist_t *root)
{
    DSA_CHECK_ARG(root)
    if (root != NULL)
    {
        printf("%d\n", root->data);
        btree_pre_transversal(root->llink);
        btree_pre_transversal(root->rlink);
    }
    return DSA_OK;
}

dsa_err_t btree_inorder_transversal(dlinkedlist_t *root)
{
    DSA_CHECK_ARG(root)
    if (root != NULL)
    {
        btree_inorder_transversal(root->llink);
        printf("%d\n", root->data);
        btree_inorder_transversal(root->llink);
    }
    return DSA_OK;
}

dsa_err_t btree_post_transversal(dlinkedlist_t *root)
{
    DSA_CHECK_ARG(root)
    if (root != NULL)
    {
        btree_post_transversal(root->llink);
        btree_post_transversal(root->llink);
        printf("%d\n", root->data);
    }
    return DSA_OK;
}

dsa_err_t btree_iteri_method_pre_order_transversal(dlinkedlist_t *root, int size)
{
    DSA_CHECK_ARG(root);
    dsa_err_t ret = DSA_OK;
    stack_t st;

    // init stack with max value
    ret = stack_init(&st, size);
    if (ret != DSA_OK)
    {
        return ret;
    }
    dlinkedlist_t *temp = root;
    while (temp != NULL || !(stack_is_empty(&st)))
    {
        if (temp != NULL)
        {
            printf("%d\n", temp->data);
            ret = stack_push(&st, temp);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                return ret;
            }
            temp = temp->llink;
        }
        else
        {
            ret = stack_pop(&st, temp);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                return ret;
            }
            temp = temp->rlink;
        }
    }
    return ret;
}

dsa_err_t btree_iteri_method_inorder_transversal(dlinkedlist_t *root, int size)
{
    DSA_CHECK_ARG(root);
    dsa_err_t ret = DSA_OK;
    stack_t st;

    // init stack with max value
    ret = stack_init(&st, size);
    if (ret != DSA_OK)
    {
        return ret;
    }
    dlinkedlist_t *temp = root;
    while (temp != NULL || !(stack_is_empty(&st)))
    {
        if (temp != NULL)
        {
            ret = stack_push(&st, temp);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                return ret;
            }
            temp = temp->llink;
        }
        else
        {
            ret = stack_pop(&st, temp);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                return ret;
            }
            printf("%d\n", temp->data);
            temp = temp->rlink;
        }
    }
    return ret;
}

dsa_err_t btree_iteri_method_post_order_transversal(dlinkedlist_t *root, int size)
{
    DSA_CHECK_ARG(root);
    dsa_err_t ret = DSA_OK;
    stack_t st;

    // init stack with max value
    ret = stack_init(&st, size);
    if (ret != DSA_OK)
    {
        return ret;
    }
    dlinkedlist_t *temp = root;
    while (temp != NULL || !(stack_is_empty(&st)))
    {
        if (temp != NULL)
        {
            ret = stack_push(&st, temp);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                return ret;
            }
            temp = temp->llink;
        }
        else
        {
            ret = stack_pop(&st, temp);
            if (ret != DSA_OK)
            {
                DSA_CDEBUG_ON_ERR(ret);
                return ret;
            }

            temp = temp->rlink;
            if (temp != NULL)
            {
                printf("%d\n", temp->data);
            }
        }
    }
    return ret;
}

dsa_err_t btree_level_order(dlinkedlist_t *root, uint32_t length)
{
    DSA_CHECK_ARG(root);
    dsa_err_t ret = DSA_OK;
    queue_t q;
    dlinkedlist_t *temp = root;
    uint32_t len = sizeof((uint32_t *)) * length;
    ret = queue_init(&q, len);
    if (ret != DSA_OK)
    {
        return ret;
    }
    printf("%d\n", temp->data);
    ret = queue_enqueue(&q, (uint32_t)temp);
    if (ret != DSA_OK)
    {
        return ret;
    }
    while (!queue_is_empty(&q))
    {
        ret = queue_circular_dequeue(&q, temp);
        if (ret != DSA_OK)
        {
            return ret;
        }

        if (temp->llink)
        {
            printf("%d", temp->llink->data);
            ret = queue_enqueue(&q, (uint32_t)temp);
            if (ret != DSA_OK)
            {
                return ret;
            }
        }
        if (temp->rlink)
        {
            printf("%d", temp->rlink->data);
            ret = queue_enqueue(&q, (uint32_t)temp);
            if (ret != DSA_OK)
            {
                return ret;
            }
        }
    }
    return DSA_OK;
}