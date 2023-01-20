
#include "stack_ut.h"
#include "list_ut.h"
#include "unity.h"

void setUp(void)
{
    UNITY_BEGIN();
}
void tearDown(void)
{
    UNITY_END();
}

int main(void)
{
    RUN_TEST(test_StackInit);
    RUN_TEST(test_StackEmpty);
    RUN_TEST(test_StackPush);
    RUN_TEST(test_StackPop);
    return 0;
}