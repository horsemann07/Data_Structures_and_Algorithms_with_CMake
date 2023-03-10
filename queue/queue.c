/**
 * @file queue.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-04
 *
 * @copyright Copyright (c) 2023
 *
 */
/************************************
 * INCLUDES
 ************************************/
#include "queue.h"

/************************************
 * GLOBAL FUNCTIONS
 ************************************/

dsa_err_t queue_init(queue_t *queue, int32_t size)
{
    DSA_CHECK_ARG(queue);
    queue->data = (int32_t)malloc(sizeof(int32_t) * size);
    if (!queue->data)
    {
        return DSA_NO_MEM;
    }
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    return DSA_OK;
}
dsa_err_t queue_enqueue(queue_t *queue, int32_t data)
{
    DSA_CHECK_ARG(queue);
    if (queue->rear == queue->size - 1)
    {
        return DSA_FAIL; // full queue
    }

    queue->data[++(queue->rear)] = data;
    return DSA_OK;
}

dsa_err_t queue_dequeue(queue_t *queue, int32_t *data)
{
    DSA_CHECK_ARG(queue);
    if (queue->rear == queue->front)
    {
        return DSA_FAIL; // empty queue
    }

    *data = queue->data[++(queue->front)];
    return DSA_OK;
}

dsa_err_t queue_get_front_data(queue_t *queue, int32_t *f_data)
{
    DSA_CHECK_ARG(queue);
    if ((queue->rear == queue->front) || (queue->front == -1))
    {
        return DSA_FAIL; // empty queue
    }

    *f_data = queue->data[queue->front];
    return DSA_OK;
}

dsa_err_t queue_get_rear_data(queue_t *queue, int32_t *r_data)
{
    DSA_CHECK_ARG(queue);
    if (queue->rear == -1)
    {
        return DSA_FAIL; // empty queue
    }

    *r_data = queue->data[queue->rear];
    return DSA_OK;
}

dsa_err_t queue_is_full(queue_t *queue)
{
    DSA_CHECK_ARG(queue);
    (queue->rear == (queue->size - 1)) ? DSA_OK : DSA_FAIL;
}

dsa_err_t queue_is_empty(queue_t *queue)
{
    DSA_CHECK_ARG(queue);
    ((queue->front == -1) || (queue->front == queue->rear)) ? DSA_OK : DSA_FAIL;
}
