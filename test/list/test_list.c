#include "list.h"
#include "unity.h"

list_t list = { 0 };
void test_list_create(void)
{
    TEST_ASSERT_EQUAL(DSA_OK, list_create(&list, 10));
    TEST_ASSERT_NOT_NULL(list.data);
    TEST_ASSERT_EQUAL_INT(10, list.size);
    TEST_ASSERT_EQUAL_INT(0, list.cindex);
}

void test_list_append_data(void)
{
    list_create(&list, 10);
    TEST_ASSERT_EQUAL(DSA_OK, list_append_data(&list, 1));
    TEST_ASSERT_EQUAL_INT(1, list.data[0]);
    TEST_ASSERT_EQUAL_INT(1, list.cindex);
}

void test_list_insert_data(void)
{
    list_create(&list, 10);
    list_append_data(&list, 1);
    TEST_ASSERT_EQUAL(DSA_OK, list_insert_data(&list, 2, 0));
    TEST_ASSERT_EQUAL_INT(2, list.data[0]);
}

void test_list_delete_index(void)
{
    list_create(&list, 10);
    list_append_data(&list, 1);
    TEST_ASSERT_EQUAL(DSA_OK, list_delete_index(&list, 0));
    TEST_ASSERT_EQUAL_INT(INT_MIN, list.data[0]);
}

void test_linear_search(void)
{
    uint32_t index;
    list_create(&list, 10);
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    TEST_ASSERT_EQUAL(DSA_OK, linear_search(&list, 2, &index));
    TEST_ASSERT_EQUAL_INT(1, index);
}

void test_binary_search(void)
{
    uint32_t index;
    list_create(&list, 10);
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    TEST_ASSERT_EQUAL(DSA_OK, binary_search(&list, 2, &index));
    TEST_ASSERT_EQUAL_INT(1, index);
}

void test_list_search_data(void)
{
    uint32_t index;
    list_create(&list, 10);
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    TEST_ASSERT_EQUAL(DSA_OK, list_search_data(&list, 2, &index, true));
    TEST_ASSERT_EQUAL_INT(1, index);
    TEST_ASSERT_EQUAL(DSA_OK, list_search_data(&list, 2, &index, false));
    TEST_ASSERT_EQUAL_INT(1, index);
}

void test_list_get(void)
{
    int value;
    list_create(&list, 10);
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    TEST_ASSERT_EQUAL(DSA_OK, list_get(&list, 2, &value));
    TEST_ASSERT_EQUAL_INT(2, value);
}
void test_list_set(void)
{
    list_t list;
    list_create(&list, 5);

    // Test invalid argument
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_set(NULL, 1, 10));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_set(&list, 6, 10));

    // Test valid argument
    TEST_ASSERT_EQUAL(DSA_OK, list_set(&list, 1, 10));
    TEST_ASSERT_EQUAL(10, list.data[0]);
    TEST_ASSERT_EQUAL(DSA_OK, list_set(&list, 3, 20));
    TEST_ASSERT_EQUAL(20, list.data[2]);
}

void test_list_get_max(void)
{
    list_t list;
    list_create(&list, 5);

    // Test invalid argument
    uint32_t max;
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_get_max(NULL, &max));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_get_max(&list, NULL));

    // Test valid argument
    list_append_data(&list, 5);
    list_append_data(&list, 10);
    list_append_data(&list, 3);
    list_append_data(&list, 15);
    list_append_data(&list, 8);
    TEST_ASSERT_EQUAL(DSA_OK, list_get_max(&list, &max));
    TEST_ASSERT_EQUAL(15, max);
}

void test_list_get_min(void)
{
    list_t list;
    list_create(&list, 5);

    // Test invalid argument
    uint32_t min;
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_get_min(NULL, &min));
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_get_min(&list, NULL));

    // Test valid argument
    list_append_data(&list, 5);
    list_append_data(&list, 10);
    list_append_data(&list, 3);
    list_append_data(&list, 15);
    list_append_data(&list, 8);
    TEST_ASSERT_EQUAL(DSA_OK, list_get_min(&list, &min));
    TEST_ASSERT_EQUAL(3, min);
}

void test_list_reverse(void)
{
    list_create(&list, 5);

    // Test invalid argument
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, list_reverse(NULL));

    // Test valid argument
    list_append_data(&list, 5);
    list_append_data(&list, 10);
    list_append_data(&list, 3);
    list_append_data(&list, 15);
    list_append_data(&list, 8);
    TEST_ASSERT_EQUAL(DSA_OK, list_reverse(&list));
    TEST_ASSERT_EQUAL(8, list.data[0]);
    TEST_ASSERT_EQUAL(15, list.data[1]);
    TEST_ASSERT_EQUAL(3, list.data[2]);
    TEST_ASSERT_EQUAL(10, list.data[3]);
    TEST_ASSERT_EQUAL(5, list.data[4]);
}

void test_list_shift_left()
{
    list_create(&list, 5);

    // Test valid argument
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    list_append_data(&list, 4);
    list_append_data(&list, 5);
    TEST_ASSERT_EQUAL(DSA_OK, list_shift(&list, 2, true));
    TEST_ASSERT_EQUAL(3, list.data[0]);
    TEST_ASSERT_EQUAL(4, list.data[1]);
    TEST_ASSERT_EQUAL(5, list.data[2]);
    TEST_ASSERT_EQUAL(0, list.data[3]);
    TEST_ASSERT_EQUAL(0, list.data[4]);
}

void test_list_shift_right()
{
    list_create(&list, 5);

    // Test valid argument
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    list_append_data(&list, 4);
    list_append_data(&list, 5);

    TEST_ASSERT_EQUAL(DSA_OK, list_shift(&list, 2, false));
    TEST_ASSERT_EQUAL(0, list.data[0]);
    TEST_ASSERT_EQUAL(0, list.data[1]);
    TEST_ASSERT_EQUAL(1, list.data[2]);
    TEST_ASSERT_EQUAL(2, list.data[3]);
    TEST_ASSERT_EQUAL(3, list.data[4]);
}

void test_list_rotate_left()
{
    list_create(&list, 5);

    // Test valid argument
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    list_append_data(&list, 4);
    list_append_data(&list, 5);
    TEST_ASSERT_EQUAL(DSA_OK, list_rotate(&list, 2, true));
    TEST_ASSERT_EQUAL(3, list.data[0]);
    TEST_ASSERT_EQUAL(4, list.data[1]);
    TEST_ASSERT_EQUAL(5, list.data[2]);
    TEST_ASSERT_EQUAL(1, list.data[3]);
    TEST_ASSERT_EQUAL(2, list.data[4]);
}

void test_list_rotate_right()
{
    list_create(&list, 5);

    // Test valid argument
    list_append_data(&list, 1);
    list_append_data(&list, 2);
    list_append_data(&list, 3);
    list_append_data(&list, 4);
    list_append_data(&list, 5);
    TEST_ASSERT_EQUAL(DSA_OK, list_rotate(&list, 2, false));
    TEST_ASSERT_EQUAL(4, list.data[0]);
    TEST_ASSERT_EQUAL(5, list.data[1]);
    TEST_ASSERT_EQUAL(1, list.data[2]);
    TEST_ASSERT_EQUAL(2, list.data[3]);
    TEST_ASSERT_EQUAL(3, list.data[4]);
}

void test_run_list_test_cases(void)
{
    // RUN_TEST(test_list_create);
    // RUN_TEST(test_list_append_data);
    // RUN_TEST(test_list_insert_data);
    // RUN_TEST(test_list_delete_index);
    // RUN_TEST(test_linear_search);
    // RUN_TEST(test_binary_search);
    // RUN_TEST(test_list_search_data);
    // RUN_TEST(test_list_get);
    // RUN_TEST(test_list_set);
    // RUN_TEST(test_list_get_max);
    // RUN_TEST(test_list_get_min);
    // RUN_TEST(test_list_reverse);
    // RUN_TEST(test_list_shift_left);
    // RUN_TEST(test_list_shift_right);
    // RUN_TEST(test_list_rotate_left);
    // RUN_TEST(test_list_rotate_right);
    return;
}