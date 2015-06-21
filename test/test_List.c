#include "unity.h"
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
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->data);

	listDel(list);
}

void test_listAdd_given_length_and_data_should_add_data_into_list(void)
{
	List *list = listNew(5);
    int data = 5;

    listAdd(list, (void *)data);

    TEST_ASSERT_EQUAL(5, list->length);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL_PTR((void *)data, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->data);

	listDel(list);
}