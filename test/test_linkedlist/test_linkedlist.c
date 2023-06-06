#include "linkedlist.h"
#include "unity.h"

void test_slinkedlist_create(void)
{
    slinkedlist_t llist;
    dsa_err_t result = slinkedlist_create(&llist, 10);
    TEST_ASSERT_EQUAL(DSA_OK, result);
    TEST_ASSERT_EQUAL(10, llist.data);
}

void test_slinkedlist_display_data(void)
{
    slinkedlist_t llist;
    llist.data = 1;
    slinkedlist_t llist2;
    llist2.data = 2;
    slinkedlist_t llist3;
    llist3.data = 3;
    llist.nlink = &llist2;
    llist2.nlink = &llist3;
    llist3.nlink = NULL;
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_display_data(&llist));
}

void test_slinkedlist_length(void)
{
    slinkedlist_t llist;
    llist.data = 1;
    slinkedlist_t llist2;
    llist2.data = 2;
    slinkedlist_t llist3;
    llist3.data = 3;
    llist.nlink = &llist2;
    llist2.nlink = &llist3;
    llist3.nlink = NULL;
    uint32_t len;
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_length(&llist, &len));
    TEST_ASSERT_EQUAL(3, len);
}

void test_slinkedlist_insert(void)
{
    slinkedlist_t llist;
    llist.data = 1;
    slinkedlist_t llist2;
    llist2.data = 2;
    slinkedlist_t llist3;
    llist3.data = 3;
    llist.nlink = &llist2;
    llist2.nlink = &llist3;
    llist3.nlink = NULL;
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_insert(&llist, 4));
    TEST_ASSERT_EQUAL(4, llist3.nlink->data);
}

void test_slinkedlist_insert_at_pos(void)
{
    slinkedlist_t llist;
    llist.data = 1;
    slinkedlist_t llist2;
    llist2.data = 2;
    slinkedlist_t llist3;
    llist3.data = 4;
    llist.nlink = &llist2;
    llist2.nlink = &llist3;
    llist3.nlink = NULL;
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_insert_at_pos(&llist, 3, 3));
    TEST_ASSERT_EQUAL(3, llist2.nlink->data);
}

void test_slinkedlist_delete_node()
{
    // create linked list
    slinkedlist_t *head = NULL;
    slinkedlist_create(&head, 1);
    slinkedlist_insert_end(head, 2);
    slinkedlist_insert_end(head, 3);

    // delete node
    TEST_ASSERT_EQUAL_INT(DSA_OK, slinkedlist_delete_node(head, 2));

    // check length of linked list
    int len;
    slinkedlist_length(head, &len);
    TEST_ASSERT_EQUAL_INT(2, len);

    // delete remaining nodes
    TEST_ASSERT_EQUAL_INT(DSA_OK, slinkedlist_delete_node(head, 1));
    TEST_ASSERT_EQUAL_INT(DSA_OK, slinkedlist_delete_node(head, 1));

    // check length of linked list
    slinkedlist_length(head, &len);
    TEST_ASSERT_EQUAL_INT(0, len);

    // delete non-existent node
    TEST_ASSERT_EQUAL_INT(DSA_INVALID_ARG, slinkedlist_delete_node(head, 1));
}

void test_slinkedlist_reverse()
{
    // create linked list
    slinkedlist_t *head = NULL;
    slinkedlist_create(&head, 1);
    slinkedlist_insert_end(head, 2);
    slinkedlist_insert_end(head, 3);

    // reverse linked list
    TEST_ASSERT_EQUAL_INT(DSA_OK, slinkedlist_reverse(head));

    // check if the linked list is reversed
    TEST_ASSERT_EQUAL_INT(3, head->data);
    TEST_ASSERT_EQUAL_INT(2, head->nlink->data);
    TEST_ASSERT_EQUAL_INT(1, head->nlink->nlink->data);

    // clean up
    slinkedlist_delete_all_nodes(&head);
}

void test_slinkedlist_is_lists_match()
{
    // create linked lists
    slinkedlist_t *head1 = NULL;
    slinkedlist_create(&head1, 1);
    slinkedlist_insert_end(head1, 2);
    slinkedlist_insert_end(head1, 3);

    slinkedlist_t *head2 = NULL;
    slinkedlist_create(&head2, 1);
    slinkedlist_insert_end(head2, 2);
    slinkedlist_insert_end(head2, 3);

    slinkedlist_t *head3 = NULL;
    slinkedlist_create(&head3, 1);
    slinkedlist_insert_end(head3, 2);
    slinkedlist_insert_end(head3, 4);

    // compare linked lists
    TEST_ASSERT_EQUAL_INT(DSA_OK, slinkedlist_is_lists_match(head1, head2));
    TEST_ASSERT_EQUAL_INT(DSA_FAIL, slinkedlist_is_lists_match(head1, head3));

    // clean up
    slinkedlist_delete_all_nodes(&head1);
    slinkedlist_delete_all_nodes(&head2);
    slinkedlist_delete_all_nodes(&head3);
}

void test_slinkedlist_merge_sorted_list(void)
{
    // create and populate the first linked list
    slinkedlist_t *list1 = NULL;
    slinkedlist_create(&list1, 5);
    slinkedlist_insert_node_at_end(list1, 10);
    slinkedlist_insert_node_at_end(list1, 15);
    slinkedlist_insert_node_at_end(list1, 25);
    slinkedlist_insert_node_at_end(list1, 30);

    // create and populate the second linked list
    slinkedlist_t *list2 = NULL;
    slinkedlist_create(&list2, 1);
    slinkedlist_insert_node_at_end(list2, 20);
    slinkedlist_insert_node_at_end(list2, 22);
    slinkedlist_insert_node_at_end(list2, 23);
    slinkedlist_insert_node_at_end(list2, 24);

    // create the merged linked list and merge the two sorted lists
    slinkedlist_t *merged_list = NULL;
    slinkedlist_merge_sorted_list(list1, list2, &merged_list);

    // create the expected linked list and populate it with the merged data
    slinkedlist_t *expected_list = NULL;
    slinkedlist_create(&expected_list, 1);
    slinkedlist_insert_node_at_end(expected_list, 5);
    slinkedlist_insert_node_at_end(expected_list, 10);
    slinkedlist_insert_node_at_end(expected_list, 15);
    slinkedlist_insert_node_at_end(expected_list, 20);
    slinkedlist_insert_node_at_end(expected_list, 22);
    slinkedlist_insert_node_at_end(expected_list, 23);
    slinkedlist_insert_node_at_end(expected_list, 24);
    slinkedlist_insert_node_at_end(expected_list, 25);
    slinkedlist_insert_node_at_end(expected_list, 30);

    // check if the merged list matches the expected list
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(DSA_OK, slinkedlist_is_lists_match(merged_list, expected_list),
        "merged list is not as expected");

    // clean up the memory used by the linked lists
    slinkedlist_delete(&list1);
    slinkedlist_delete(&list2);
    slinkedlist_delete(&merged_list);
    slinkedlist_delete(&expected_list);
}

void test_slinkedlist_get_node()
{
    // Create linked list with values 1, 3, 5, 9, 5, 7, 3, 0
    slinkedlist_t *head = NULL;
    slinkedlist_create(&head, 1);
    slinkedlist_append(head, 3);
    slinkedlist_append(head, 5);
    slinkedlist_append(head, 9);
    slinkedlist_append(head, 5);
    slinkedlist_append(head, 7);
    slinkedlist_append(head, 3);
    slinkedlist_append(head, 0);
    int value;
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_get_node(head, 0, &value));
    TEST_ASSERT_EQUAL(1, value);
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_get_node(head, 4, &value));
    TEST_ASSERT_EQUAL(5, value);
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_get_node(head, 7, &value));
    TEST_ASSERT_EQUAL(0, value);
    TEST_ASSERT_EQUAL(DSA_INVALID_ARG, slinkedlist_get_node(NULL, 2, &value));
}

void test_slinkedlist_remove_duplicates()
{
    // Create linked list with values 1, 3, 5, 9, 5, 7, 3, 0
    slinkedlist_t *head = NULL;
    slinkedlist_create(&head, 1);
    slinkedlist_append(head, 3);
    slinkedlist_append(head, 5);
    slinkedlist_append(head, 9);
    slinkedlist_append(head, 5);
    slinkedlist_append(head, 7);
    slinkedlist_append(head, 3);
    slinkedlist_append(head, 0);
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_remove_duplicates(head));
    // Expected linked list with values 1, 3, 5, 9, 7, 0
    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(3, head->nlink->data);
    TEST_ASSERT_EQUAL(5, head->nlink->nlink->data);
    TEST_ASSERT_EQUAL(9, head->nlink->nlink->nlink->data);
    TEST_ASSERT_EQUAL(7, head->nlink->nlink->nlink->nlink->data);
    TEST_ASSERT_EQUAL(0, head->nlink->nlink->nlink->nlink->nlink->data);
}

void test_slinkedlist_remove_duplicates_in_sorted_list(void)
{
    // Create linked list with values 1, 3, 5, 9, 5, 7, 3, 0
    slinkedlist_t *head = NULL;
    slinkedlist_create(&head, 1);
    slinkedlist_append(head, 3);
    slinkedlist_append(head, 5);
    slinkedlist_append(head, 9);
    slinkedlist_append(head, 5);
    slinkedlist_append(head, 7);
    slinkedlist_append(head, 3);
    slinkedlist_append(head, 0);

    // Remove duplicates;
    TEST_ASSERT_EQUAL(DSA_OK, slinkedlist_remove_duplicates(head));

    // Check if duplicates are removed
    TEST_ASSERT_EQUAL_INT(0, head->data);
    TEST_ASSERT_EQUAL_INT(1, head->nlink->data);
    TEST_ASSERT_EQUAL_INT(3, head->nlink->nlink->data);
    TEST_ASSERT_EQUAL_INT(5, head->nlink->nlink->nlink->data);
    TEST_ASSERT_EQUAL_INT(7, head->nlink->nlink->nlink->nlink->data);
    TEST_ASSERT_EQUAL_INT(9, head->nlink->nlink->nlink->nlink->nlink->data);
    TEST_ASSERT_NULL(head->nlink->nlink->nlink->nlink->nlink->nlink);
}

void run_linkedlist_test_case(void)
{
    RUN_TEST(test_slinkedlist_create);
    RUN_TEST(test_slinkedlist_display_data);
    RUN_TEST(test_slinkedlist_length);
    RUN_TEST(test_slinkedlist_insert);
    RUN_TEST(test_slinkedlist_insert_at_pos);
    RUN_TEST(test_slinkedlist_delete_node);
    RUN_TEST(test_slinkedlist_reverse);
    RUN_TEST(test_slinkedlist_is_lists_match);
    RUN_TEST(test_slinkedlist_merge_sorted_list);
    RUN_TEST(test_slinkedlist_get_node);
    RUN_TEST(test_slinkedlist_remove_duplicates);
    RUN_TEST(test_slinkedlist_remove_duplicates_in_sorted_list);
}
