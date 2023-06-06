
#ifndef _STACK_UT_
#define _STACK_UT_
#ifdef __cplusplus
extern "C" {
#endif
void test_stack_init_should_return_ok_when_successful(void);
void test_stack_is_empty_should_return_ok_when_empty(void);
void test_stack_is_empty_should_return_fail_when_not_empty(void);
void test_stack_is_full_should_return_fail_when_not_full(void);
void test_stack_is_full_should_return_ok_when_full(void);
void test_stack_push_should_return_fail_when_full(void);
void test_stack_push_should_increase_top_and_push_item(void);
void test_stack_pop_should_return_fail_when_empty(void);
void test_stack_pop_should_decrease_top_and_pop_item(void);
void test_stack_peek_should_return_fail_when_empty(void);
void test_stack_peek_should_return_top_item(void);
void test_stack_print_data_char(void);
void test_stack_print_data_int(void);
void test_stack_is_parenthes_balance(void);
void run_stack_test_cases(void);
#ifdef __cplusplus
}
#endif
#endif /* _STACK_UT_ */