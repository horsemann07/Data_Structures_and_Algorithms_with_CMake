

/************************************
 * INCLUDES
 ************************************/
/* queue header */
#include "queue.h"

/* queue unit test header */
#include "queue_ut.h"

/* Single Unity Test Framework */
#include "unity.h"

/************************************
 * GLOBAL FUNCTIONS
 ************************************/

void test_QueueInit(void)
{
    queue_t queue;
    queue_t c_queue;

    TEST_ASSERT_EQUAL_INT(DSA_OK, queue_init(&queue, 10));
    TEST_ASSERT_EQUAL_INT(queue.size, 10);
    TEST_ASSERT_EQUAL_INT(queue.front, -1);
    TEST_ASSERT_EQUAL_INT(queue.rear, -1);

    TEST_ASSERT_EQUAL_INT(DSA_OK, queue_init(&c_queue, 10));
    TEST_ASSERT_EQUAL_INT(c_queue.size, 10);
    TEST_ASSERT_EQUAL_INT(c_queue.front, -1);
    TEST_ASSERT_EQUAL_INT(c_queue.rear, -1);
}