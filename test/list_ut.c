
#include "list_ut.h"

#include "dsa.h"
#include "list.h"
#include "unity.h"

void test_ListAPI(void)
{
    list_t list;
    TEST_ASSERT_EQUAL(DSA_OK, list_create(&list, 5));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_create(NULL, 5));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_create(&list, 0));

    TEST_ASSERT_EQUAL(5, list.size);
    list_t elist;
    for (int i = 0; i < 5; i++)
    {
        list.data[i] = i;
        list.cindex = i;
    }
    int max;
    TEST_ASSERT_EQUAL(DSA_OK, list_get_max(&list, &max));
    TEST_ASSERT_EQUAL(4, max);
    TEST_ASSERT_EQUAL(DSA_OK, list_shift(&list, 3, true));
    int data[5] = { 3, 4, 0, 0, 0 };
    elist.data = data;
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(elist.data, list.data, 5, "Checking array after 3 shift");

    TEST_ASSERT_EQUAL(DSA_OK, list_rotate(&list, 2, true));

    // int data2[5] = { 3, 4, 0, 1, 2 };
    // elist.data = data2;
    // TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(elist.data, list.data, 5, "Checking array after 3
    // shift");
    list_display_data(&list);
    return;
}

void test_CreateList(void)
{
    list_t list;
    TEST_ASSERT_EQUAL(DSA_OK, list_create(&list, 5));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_create(NULL, 5));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_create(&list, 0));

    TEST_ASSERT_EQUAL(0, list.cindex);
    TEST_ASSERT_EQUAL(5, list.size);

    int data[5] = { 0 };

    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(
        data, list.data, list.size, "comparing each element in array");

    return;
}

void test_DisplayList(void)
{
}

void test_AppendData(void)
{
}

void test_InsertData(void)
{
}

void test_Delete(void)
{
}

void test_Search(void)
{
}

void test_getIndexValue(void)
{
}

void test_setIndexValue(void)
{
}

void test_MaxAndMin(void)
{
}

void test_Reverse(void)
{
}

void test_Shift(void)
{
}

void test_Rotate(void)
{
}