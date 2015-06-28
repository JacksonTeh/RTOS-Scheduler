#include "unity.h"
#include <malloc.h>
#include "List.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_listNew_given_length_should_create_new_list(void)
{
	List *list = listNew(5);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail);

	listDel(list);
}

void test_listAddHead_given_length_and_data_should_add_data_into_list(void)
{
	List *list = listNew(5);
    int data = 10;

    listAddHead(list, (void *)data);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listAddHead_given_length_and_data_10_in_the_list_should_add_data_into_list(void)
{
	List *list = listNew(5);
    int data1 = 10;
    int data2 = 20;

    list->head->data = (void *)data1;
    list->tail->data = (void *)data1;

    listAddHead(list, (void *)data2);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data2, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listAddHead_given_length_and_data_10_20_in_the_list_should_add_data_into_list(void)
{
	List *list = listNew(5);
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    list->head->data = (void *)data2;
    list->tail->data = (void *)data1;
    list->head->next = list->tail;

    listAddHead(list, (void *)data3);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data3, list->head->data);
    TEST_ASSERT_EQUAL((void *)data2, list->head->next->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listAddHead_given_length_and_data_10_20_30_in_the_list_should_add_data_into_list(void)
{
	List *list = listNew(5);
    ListElement *listElement = createListElement();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    list->head->data = (void *)data3;
    listElement->data = (void *)data2;
    list->tail->data = (void *)data1;
    list->head->next = listElement;
    listElement->next = list->tail;

    listAddHead(list, (void *)data4);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data4, list->head->data);
    TEST_ASSERT_EQUAL((void *)data3, list->head->next->data);
    TEST_ASSERT_EQUAL((void *)data2, list->head->next->next->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next->next->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listRemoveHead_given_length_and_data_10_in_the_list_should_remove_head_of_list(void)
{
	List *list = listNew(5);
    int data1 = 10;

    list->head->data = (void *)data1;
    list->tail->data = (void *)data1;

    listRemoveHead(list);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL(NULL, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL(NULL, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listRemoveHead_given_length_and_data_10_20_in_the_list_should_remove_head_of_list(void)
{
	List *list = listNew(5);
    int data1 = 10;
    int data2 = 20;

    list->head->data = (void *)data2;
    list->tail->data = (void *)data1;
    list->head->next = list->tail;

    listRemoveHead(list);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listRemoveHead_given_length_and_data_10_20_30_in_the_list_should_remove_head_of_list(void)
{
	List *list = listNew(5);
    ListElement *listElement = createListElement();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    list->head->data = (void *)data3;
    listElement->data = (void *)data2;
    list->tail->data = (void *)data1;
    list->head->next = listElement;
    listElement->next = list->tail;

    listRemoveHead(list);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data2, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listAddTail_given_length_and_data_should_add_data_into_list(void)
{
	List *list = listNew(5);
    int data = 10;

    listAddTail(list, (void *)data);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listAddTail_given_length_and_data_10_in_the_list_should_add_data_into_list(void)
{
	List *list = listNew(5);
    int data1 = 10;
    int data2 = 20;

    list->head->data = (void *)data1;
    list->tail->data = (void *)data1;

    listAddTail(list, (void *)data2);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data2, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listAddTail_given_length_and_data_10_20_30_in_the_list_should_add_data_into_list(void)
{
	List *list = listNew(5);
    ListElement *listElement = createListElement();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    list->head->data = (void *)data1;
    listElement->data = (void *)data2;
    list->tail->data = (void *)data3;
    list->head->next = listElement;
    listElement->next = list->tail;

    listAddTail(list, (void *)data4);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL((void *)data2, list->head->next->data);
    TEST_ASSERT_EQUAL((void *)data3, list->head->next->next->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next->next->next);
    TEST_ASSERT_EQUAL((void *)data4, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listRemoveTail_given_length_and_data_10_in_the_list_should_remove_head_of_list(void)
{
	List *list = listNew(5);
    int data1 = 10;

    list->head->data = (void *)data1;
    list->tail->data = (void *)data1;

    listRemoveTail(list);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL(NULL, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL(NULL, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listRemoveTail_given_length_and_data_10_20_in_the_list_should_remove_head_of_list(void)
{
	List *list = listNew(5);
    int data1 = 10;
    int data2 = 20;

    list->head->data = (void *)data1;
    list->tail->data = (void *)data1;
    list->head->next = list->tail;

    listRemoveTail(list);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}

void test_listRemoveTail_given_length_and_data_10_20_30_in_the_list_should_remove_head_of_list(void)
{
	List *list = listNew(5);
    ListElement *listElement = createListElement();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    list->head->data = (void *)data1;
    listElement->data = (void *)data2;
    list->tail->data = (void *)data3;
    list->head->next = listElement;
    listElement->next = list->tail;

    listRemoveTail(list);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data2, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

	listDel(list);
}