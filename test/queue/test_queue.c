#include "queue.h"
#include "unity.h"
#include <stdio.h>

void test_queue_init(void)
{
    queue_t q;
    TEST_ASSERT_EQUAL(DSA_OK, queue_init(&q, 5));
    TEST_ASSERT_NOT_NULL(q.data);
    TEST_ASSERT_EQUAL(5, q.size);
    TEST_ASSERT_EQUAL(-1, q.front);
    TEST_ASSERT_EQUAL(-1, q.rear);
    free(q.data);
}

void test_queue_enqueue(void)
{
    queue_t q;
    int i;

    TEST_ASSERT_EQUAL(DSA_OK, queue_init(&q, 5));

    for (i = 1; i <= 5; i++)
    {
        TEST_ASSERT_EQUAL(DSA_OK, queue_enqueue(&q, i));
    }

    TEST_ASSERT_EQUAL(DSA_FAIL, queue_enqueue(&q, 6));

    free(q.data);
}

void test_queue_dequeue(void)
{
    queue_t q;
    int i, data;

    TEST_ASSERT_EQUAL(DSA_OK, queue_init(&q, 5));

    for (i = 1; i <= 5; i++)
    {
        TEST_ASSERT_EQUAL(DSA_OK, queue_enqueue(&q, i));
    }

    for (i = 1; i <= 5; i++)
    {
        TEST_ASSERT_EQUAL(DSA_OK, queue_dequeue(&q, &data));
        TEST_ASSERT_EQUAL(i, data);
    }

    TEST_ASSERT_EQUAL(DSA_FAIL, queue_dequeue(&q, &data));

    free(q.data);
}

void test_queue_get_front_data(void)
{
    queue_t q;
    int i, data;

    TEST_ASSERT_EQUAL(DSA_OK, queue_init(&q, 5));

    for (i = 1; i <= 5; i++)
    {
        TEST_ASSERT_EQUAL(DSA_OK, queue_enqueue(&q, i));
    }

    TEST_ASSERT_EQUAL(DSA_OK, queue_get_front_data(&q, &data));
    TEST_ASSERT_EQUAL(1, data);

    TEST_ASSERT_EQUAL(DSA_OK, queue_dequeue(&q, &data));

    TEST_ASSERT_EQUAL(DSA_OK, queue_get_front_data(&q, &data));
    TEST_ASSERT_EQUAL(2, data);

    free(q.data);
}

void test_queue_get_rear_data(void)
{
    queue_t q;
    int i, data;

    TEST_ASSERT_EQUAL(DSA_OK, queue_init(&q, 5));

    for (i = 1; i <= 5; i++)
    {
        TEST_ASSERT_EQUAL(DSA_OK, queue_enqueue(&q, i));
    }

    TEST_ASSERT_EQUAL(DSA_OK, queue_get_rear_data(&q, &data));
    TEST_ASSERT_EQUAL(5, data);

    TEST_ASSERT_EQUAL(DSA_OK, queue_dequeue(&q, &data));

    TEST_ASSERT_EQUAL(DSA_OK, queue_get_rear_data(&q, &data));
    TEST_ASSERT_EQUAL(5, data);

    free(q.data);
}

void test_queue_is_full(void)
{
    queue_t q;
    int i;

    TEST_ASSERT_EQUAL(DSA_OK, queue_init(&q, 5));

    for (i = 1; i <= 5; i++)
    {
        TEST_ASSERT_EQUAL(DSA_OK, queue_enqueue(&q, i));
    }

    TEST_ASSERT_EQUAL(DSA_OK, queue_is_full(&q));

    TEST_ASSERT_EQUAL(DSA_OK, queue_dequeue(&q, &i));

    TEST_ASSERT_EQUAL(DSA_FAIL, queue_is_full(&q));

    free(q.data);
}

void test_queue_is_empty_empty_queue(void)
{
    queue_t queue;
    queue_init(&queue, 5);
    TEST_ASSERT_EQUAL(DSA_OK, queue_is_empty(&queue));
}

void test_queue_is_empty_non_empty_queue(void)
{
    queue_t queue;
    queue_init(&queue, 5);
    queue_enqueue(&queue, 1);
    TEST_ASSERT_EQUAL(DSA_FAIL, queue_is_empty(&queue));
}

void test_queue_is_empty_invalid_arg(void)
{
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, queue_is_empty(NULL));
}

/*****************CIRCULAR QUEUE**********************/

void test_queue_circular_init(void)
{
    queue_t queue;
    dsa_err_t result = queue_circular_init(&queue, 5);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    TEST_ASSERT_NOT_NULL(queue.data);
    TEST_ASSERT_EQUAL_INT(5, queue.size);
    TEST_ASSERT_EQUAL_INT(-1, queue.front);
    TEST_ASSERT_EQUAL_INT(-1, queue.rear);
}

void test_queue_circular_enqueue(void)
{
    queue_t queue;
    dsa_err_t result = queue_circular_init(&queue, 3);
    TEST_ASSERT_EQUAL(DSA_OK, result);

    // Enqueue first element
    result = queue_circular_enqueue(&queue, 1);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    TEST_ASSERT_EQUAL_INT(0, queue.front);
    TEST_ASSERT_EQUAL_INT(0, queue.rear);
    TEST_ASSERT_EQUAL_INT(1, queue.data[0]);

    // Enqueue second element
    result = queue_circular_enqueue(&queue, 2);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    TEST_ASSERT_EQUAL_INT(0, queue.front);
    TEST_ASSERT_EQUAL_INT(1, queue.rear);
    TEST_ASSERT_EQUAL_INT(1, queue.data[0]);
    TEST_ASSERT_EQUAL_INT(2, queue.data[1]);

    // Enqueue third element
    result = queue_circular_enqueue(&queue, 3);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    TEST_ASSERT_EQUAL_INT(0, queue.front);
    TEST_ASSERT_EQUAL_INT(2, queue.rear);
    TEST_ASSERT_EQUAL_INT(1, queue.data[0]);
    TEST_ASSERT_EQUAL_INT(2, queue.data[1]);
    TEST_ASSERT_EQUAL_INT(3, queue.data[2]);

    // Queue is full, cannot enqueue fourth element
    result = queue_circular_enqueue(&queue, 4);
    TEST_ASSERT_EQUAL(DSA_FAIL, result);
    TEST_ASSERT_EQUAL_INT(0, queue.front);
    TEST_ASSERT_EQUAL_INT(2, queue.rear);
    TEST_ASSERT_EQUAL_INT(1, queue.data[0]);
    TEST_ASSERT_EQUAL_INT(2, queue.data[1]);
    TEST_ASSERT_EQUAL_INT(3, queue.data[2]);
}

// void run_queue_test_cases(void)
// {
//     RUN_TEST(test_queue_init);
//     RUN_TEST(test_queue_enqueue);
//     RUN_TEST(test_queue_dequeue);
//     RUN_TEST(test_queue_get_front_data);
//     RUN_TEST(test_queue_get_rear_data);
//     RUN_TEST(test_queue_is_full);
//     RUN_TEST(test_queue_is_empty_empty_queue);
//     RUN_TEST(test_queue_is_empty_non_empty_queue);
//     RUN_TEST(test_queue_is_empty_invalid_arg);
//     RUN_TEST(test_queue_circular_init);
//     RUN_TEST(test_queue_circular_enqueue);
// }