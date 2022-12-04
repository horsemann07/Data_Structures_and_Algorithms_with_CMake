

#include "stack.h"

// Single Unity Test Framework include
#include "unity.h"

void test_init_stack_should_init_stackBase(void)
{
    //
    stack_t __stack = {0};
    __stack.size = 5;
    TEST_ASSERT_EQUAL_INT(-2, init_stack(NULL));
    TEST_ASSERT_EQUAL_INT(1, init_stack(&__stack));
    TEST_ASSERT_EQUAL_INT(-1, init_stack(&__stack));
    TEST_ASSERT_EQUAL_INT(-1, __stack.top);
    TEST_ASSERT_EQUAL_INT(!NULL, __stack.st_base);
}

void setUp(void)
{
}
void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init_stack_should_init_stackBase(), 8);
    UNITY_END();
}