

#include "stack.h"
#include "stack_ut.h"
// Single Unity Test Framework include
#include "unity.h"

stack_t stack;

void test_StackInit(void)
{
    TEST_ASSERT_EQUAL_INT(DSA_OK, stack_init(&stack, 10));
    TEST_ASSERT_EQUAL_INT(0, stack.top);
    TEST_ASSERT_EQUAL_INT(10, stack.size);

    // stack_t *stack_ptr = NULL;
    // TEST_ASSERT_EQUAL_INT(DSA_INVALID_ARG, stack_init(stack_ptr, 10));
    return;
}

void test_StackPush(void)
{
    int top = stack.top;
    int c = 32;
    TEST_ASSERT_EQUAL(DSA_OK, stack_push(&stack, (void *)&c));
    stack_print_data(&stack, false);
    TEST_ASSERT_EQUAL_INT(top + 1, stack.top);

    // TEST_ASSERT_EQUAL_INT(32, stack.st_base[0]);
}

void test_StackPop(void)
{
    int32_t pop;
    TEST_ASSERT_EQUAL(DSA_OK, stack_pop(&stack, &pop));
    TEST_ASSERT_EQUAL_INT(pop, 32);
    TEST_ASSERT_EQUAL(DSA_OK, stack_pop(&stack, &pop));
}

void test_StackEmpty(void)
{
    TEST_ASSERT_EQUAL_INT(DSA_OK, stack_is_empty(&stack));
}

void test_CheckParenthMatch(void)
{
    const char *exp = "((a+b)*(c-d)-e)";
    TEST_ASSERT_EQUAL_INT(DSA_OK, stack_is_parenthes_balance(exp));
}
