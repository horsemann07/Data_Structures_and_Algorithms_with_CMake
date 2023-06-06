
#include "list_ut.h"
#include "queue_ut.h"
#include "stack_ut.h"
#include "unity.h"

void setUp(void)
{
}
void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    // test queue functionality.
    RUN_TEST(test_queue_init);
    RUN_TEST(test_queue_enqueue);
    RUN_TEST(test_queue_dequeue);
    RUN_TEST(test_queue_get_front_data);
    RUN_TEST(test_queue_get_rear_data);
    RUN_TEST(test_queue_is_full);
    RUN_TEST(test_queue_is_empty_empty_queue);
    RUN_TEST(test_queue_is_empty_non_empty_queue);
    RUN_TEST(test_queue_is_empty_invalid_arg);
    RUN_TEST(test_queue_circular_init);
    RUN_TEST(test_queue_circular_enqueue);

    // test stack functionality.
    RUN_TEST(test_stack_init_should_return_ok_when_successful);
    RUN_TEST(test_stack_is_empty_should_return_ok_when_empty);
    RUN_TEST(test_stack_is_empty_should_return_fail_when_not_empty);
    RUN_TEST(test_stack_is_full_should_return_fail_when_not_full);
    RUN_TEST(test_stack_is_full_should_return_ok_when_full);
    RUN_TEST(test_stack_push_should_return_fail_when_full);
    RUN_TEST(test_stack_push_should_increase_top_and_push_item);
    RUN_TEST(test_stack_pop_should_return_fail_when_empty);
    RUN_TEST(test_stack_pop_should_decrease_top_and_pop_item);
    RUN_TEST(test_stack_peek_should_return_fail_when_empty);
    RUN_TEST(test_stack_peek_should_return_top_item);
    RUN_TEST(test_stack_print_data_char);
    RUN_TEST(test_stack_print_data_int);
    RUN_TEST(test_stack_is_parenthes_balance);

    // test stringg functionality
    // RUN_TEST(test_stringg_get_length);
    // RUN_TEST(test_stringg_copy);
    // RUN_TEST(test_stringg_compare);
    // RUN_TEST(test_stringg_concat);
    // RUN_TEST(test_stringg_max_occurance);
    // RUN_TEST(test_stringg_reverse);
    // RUN_TEST(test_stringg_count_word);
    // RUN_TEST(test_stringg_count_alpha_and_num);
    // RUN_TEST(test_stringg_count_vow_and_cons);
    // RUN_TEST(test_stringg_get_longest_sub_str_in_strs);
    UNITY_END();
    return 0;
}