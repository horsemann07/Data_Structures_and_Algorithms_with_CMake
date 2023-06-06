#include "stack.h"
#include "unity.h"

void test_stack_init_should_return_ok_when_successful(void)
{
    stack_t stack;
    dsa_err_t result = stack_init(&stack, 10);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    free(stack.st_base);
}

void test_stack_is_empty_should_return_ok_when_empty(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    dsa_err_t result = stack_is_empty(&stack);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    free(stack.st_base);
}

void test_stack_is_empty_should_return_fail_when_not_empty(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    stack_push(&stack, (void *)"a");
    dsa_err_t result = stack_is_empty(&stack);
    TEST_ASSERT_EQUAL(DSA_FAIL, result);
    free(stack.st_base);
}

void test_stack_is_full_should_return_fail_when_not_full(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    stack_push(&stack, (void *)"a");
    dsa_err_t result = stack_is_full(&stack);
    TEST_ASSERT_EQUAL(DSA_FAIL, result);
    free(stack.st_base);
}

void test_stack_is_full_should_return_ok_when_full(void)
{
    stack_t stack;
    stack_init(&stack, 1);
    stack_push(&stack, (void *)"a");
    dsa_err_t result = stack_is_full(&stack);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    free(stack.st_base);
}

void test_stack_push_should_return_fail_when_full(void)
{
    stack_t stack;
    stack_init(&stack, 1);
    stack_push(&stack, (void *)"a");
    dsa_err_t result = stack_push(&stack, (void *)"b");
    TEST_ASSERT_EQUAL(DSA_FAIL, result);
    free(stack.st_base);
}

void test_stack_push_should_increase_top_and_push_item(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    stack_push(&stack, (void *)"a");
    TEST_ASSERT_EQUAL(1, stack.top);
    free(stack.st_base);
}

void test_stack_pop_should_return_fail_when_empty(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    dsa_err_t result = stack_pop(&stack, (void *)"a");
    TEST_ASSERT_EQUAL(DSA_FAIL, result);
    free(stack.st_base);
}

void test_stack_pop_should_decrease_top_and_pop_item(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    stack_push(&stack, (void *)"a");
    char item;
    stack_pop(&stack, (void *)&item);
    TEST_ASSERT_EQUAL(0, stack.top);
    TEST_ASSERT_EQUAL('a', item);
    free(stack.st_base);
}

void test_stack_peek_should_return_fail_when_empty(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    dsa_err_t result = stack_peek(&stack, (void *)"a");
    TEST_ASSERT_EQUAL(DSA_FAIL, result);
    free(stack.st_base);
}

void test_stack_peek_should_return_top_item(void)
{
    stack_t stack;
    stack_init(&stack, 10);
    stack_push(&stack, (void *)"a");
    char item;
    stack_peek(&stack, (void *)&item);
    TEST_ASSERT_EQUAL('a', item);
    free(stack.st_base);
}

void test_stack_print_data_char(void)
{
    stack_t stack;
    char data[] = "Hello, world!";
    stack_init(&stack, sizeof(data));
    stack_push(&stack, data);
    stack_print_data(&stack, true);
}

void test_stack_print_data_int(void)
{
    stack_t stack;
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    stack_init(&stack, sizeof(data));
    stack_push(&stack, data);
    stack_print_data(&stack, false);
}

void test_stack_is_parenthes_balance(void)
{
    TEST_ASSERT_EQUAL(DSA_OK, stack_is_parenthes_balance("(a+b)*(c+d)"));
    TEST_ASSERT_EQUAL(DSA_OK, stack_is_parenthes_balance("{[()]}"));
    TEST_ASSERT_EQUAL(DSA_FAIL, stack_is_parenthes_balance("((a+b)*(c+d)"));
    TEST_ASSERT_EQUAL(DSA_FAIL, stack_is_parenthes_balance("{[()]}]"));
}

// void run_stack_test_cases(void)
// {
//     RUN_TEST(test_stack_init_should_return_ok_when_successful);
//     RUN_TEST(test_stack_is_empty_should_return_ok_when_empty);
//     RUN_TEST(test_stack_is_empty_should_return_fail_when_not_empty);
//     RUN_TEST(test_stack_is_full_should_return_fail_when_not_full);
//     RUN_TEST(test_stack_is_full_should_return_ok_when_full);
//     RUN_TEST(test_stack_push_should_return_fail_when_full);
//     RUN_TEST(test_stack_push_should_increase_top_and_push_item);
//     RUN_TEST(test_stack_pop_should_return_fail_when_empty);
//     RUN_TEST(test_stack_pop_should_decrease_top_and_pop_item);
//     RUN_TEST(test_stack_peek_should_return_fail_when_empty);
//     RUN_TEST(test_stack_peek_should_return_top_item);
//     RUN_TEST(test_stack_print_data_char);
//     RUN_TEST(test_stack_print_data_int);
//     RUN_TEST(test_stack_is_parenthes_balance);
// }