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

dsa_err_t queue_circular_init(queue_t *queue, int32_t size)
{
    return (queue_init(queue, size));
}

dsa_err_t queue_ciruclar_rear(queue_t *queue, int32_t *rear)
{
    DSA_CHECK_ARG(queue);
    *rear = (queue->rear + 1) % queue->size;
    return DSA_OK;
}
dsa_err_t queue_circular_front(queue_t *queue, int32_t *front)
{
    DSA_CHECK_ARG(queue);
    *front = (queue->front + 1) % queue->size;
    return DSA_OK;
}

dsa_err_t queue_circular_enqueue(queue_t *queue, int32_t data)
{
    dsa_err_t ret = DSA_OK;
    int32_t rear;
    ret = queue_ciruclar_rear(queue, &rear);
    if (ret != DSA_OK)
    {
        return ret;
    }
    if (rear == queue->front)
    {
        return DSA_FAIL; // queue full
    }

    queue->rear = rear;
    queue->data[++(queue->rear)] = data;

    return DSA_OK;
}

dsa_err_t queue_circular_dequeue(queue_t *queue, int32_t *data)
{
    dsa_err_t ret = DSA_OK;
    int32_t front;
    ret = queue_ciruclar_front(queue, &front);
    if (ret != DSA_OK)
    {
        return ret;
    }
    if (front == queue->rear)
    {
        return DSA_FAIL; // queue empty
    }

    queue->front = front;
    *data = queue->data[++(queue->front)];

    return DSA_OK;
}