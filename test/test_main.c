

#include "list_ut.h"
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

    RUN_TEST(test_ListAPI);
    RUN_TEST(test_CreateList);

    return UNITY_END();
}