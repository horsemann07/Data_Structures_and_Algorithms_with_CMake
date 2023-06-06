

#ifndef QUEUE_UT_H
#define QUEUE_UT_H
#ifdef __cplusplus
extern "C" {
#endif

void test_queue_init(void);
void test_queue_enqueue(void);
void test_queue_dequeue(void);
void test_queue_get_front_data(void);
void test_queue_get_rear_data(void);
void test_queue_is_full(void);
void test_queue_is_empty_empty_queue(void);
void test_queue_is_empty_non_empty_queue(void);
void test_queue_is_empty_invalid_arg(void);
void test_queue_circular_init(void);
void test_queue_circular_enqueue(void);
void run_queue_test_cases(void);
#ifdef __cplusplus
}
#endif

#endif /* QUEUE_UT_H*/
