#include "unity.h"
// #include <malloc.h>
#include "List.h"

void setUp(void)
{
}

void tearDown(void)
{
}
/*
void test_createListElement_should_create_new_listElement(void)
{
    ListElement *listElement1 = createListElement((void *)5);
    ListElement *listElement2 = createListElement((void *)6);

    listElement1->next = listElement2;

    TEST_ASSERT_EQUAL_PTR((void *)5, listElement1->data);
    TEST_ASSERT_EQUAL_PTR(listElement2, listElement1->next);
    TEST_ASSERT_EQUAL_PTR((void *)6, listElement2->data);
    TEST_ASSERT_EQUAL_PTR(NULL, listElement2->next);

    destroyListElement(listElement1);
}

void test_listNew_should_create_new_list(void)
{
    List *list = listNew();

    TEST_ASSERT_EQUAL(0, list->length);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head->data);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail->data);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);

    listDel(list);
}

void test_isListEmpty_given_empty_list_should_return_0(void)
{
    List *list = listNew();

    TEST_ASSERT_EQUAL(0, list->length);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head->data);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail->data);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);
    TEST_ASSERT_EQUAL(0, isListEmpty(list));

    listDel(list);
}

void test_isListEmpty_given_not_empty_list_should_return_1(void)
{
    List *list = listNew();
    ListElement *listElement = createListElement((void *)5);

    list->head = listElement;

    TEST_ASSERT_EQUAL(0, list->length);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head->data);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail->data);
    // TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);
    TEST_ASSERT_EQUAL_PTR(listElement, list->head);
    TEST_ASSERT_EQUAL_PTR((void *)5, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);
    TEST_ASSERT_EQUAL(1, isListEmpty(list));

    listDel(list);
}

void test_listAddHead_given_10_should_add_10_into_list(void)
{
    List *list = listNew();
    int data = 10;

    listAddHead(list, (void *)data);

    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL((void *)data, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listAddHead_given_10_in_the_list_should_add_20_into_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;

    listAddHead(list, (void *)data1);
    listAddHead(list, (void *)data2);

    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL((void *)data2, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listAddHead_given_10_20_in_the_list_should_add_30_into_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    listAddHead(list, (void *)data1);
    listAddHead(list, (void *)data2);
    listAddHead(list, (void *)data3);

    TEST_ASSERT_EQUAL(3, list->length);
    TEST_ASSERT_EQUAL((void *)data3, list->head->data);
    TEST_ASSERT_EQUAL((void *)data2, list->head->next->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listAddHead_given_10_20_30_in_the_list_should_add_40_into_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    listAddHead(list, (void *)data1);
    listAddHead(list, (void *)data2);
    listAddHead(list, (void *)data3);
    listAddHead(list, (void *)data4);

    TEST_ASSERT_EQUAL(4, list->length);
    TEST_ASSERT_EQUAL((void *)data4, list->head->data);
    TEST_ASSERT_EQUAL((void *)data3, list->head->next->data);
    TEST_ASSERT_EQUAL((void *)data2, list->head->next->next->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next->next->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listRemoveHead_given_empty_list_should_do_nothing(void)
{
    List *list = listNew();

    listRemoveHead(list);

    TEST_ASSERT_EQUAL(0, list->length);
    TEST_ASSERT_EQUAL(NULL, list->head);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);

    listDel(list);
}

void test_listRemoveHead_10_in_the_list_should_remove_10_in_the_list(void)
{
    List *list = listNew();
    int data1 = 10;
    void *result;

    listAddHead(list, (void *)data1);
    result = listRemoveHead(list);

    TEST_ASSERT_EQUAL(data1, (int *)result);
    TEST_ASSERT_EQUAL(0, list->length);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);

    listDel(list);
}

void test_listRemoveHead_given_10_20_in_the_list_should_remove_head_of_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    void *result;

    listAddHead(list, (void *)data1);
    listAddHead(list, (void *)data2);
    result = listRemoveHead(list);

    TEST_ASSERT_EQUAL(data2, (int *)result);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listRemoveHead_given_10_20_30_in_the_list_should_remove_head_of_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    void *result;

    listAddHead(list, (void *)data1);
    listAddHead(list, (void *)data2);
    listAddHead(list, (void *)data3);
    result = listRemoveHead(list);

    TEST_ASSERT_EQUAL(data3, (int *)result);
    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL((void *)data2, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listAddTail_given_10_should_add_10_into_list(void)
{
    List *list = listNew();
    int data1 = 10;

    listAddTail(list, (void *)data1);

    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listAddTail_given_10_in_the_list_should_add_20_into_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;

    listAddTail(list, (void *)data1);
    listAddTail(list, (void *)data2);

    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data2, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listAddTail_given_10_20_in_the_list_should_add_30_into_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    listAddTail(list, (void *)data1);
    listAddTail(list, (void *)data2);
    listAddTail(list, (void *)data3);

    TEST_ASSERT_EQUAL(3, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL((void *)data2, list->head->next->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next->next);
    TEST_ASSERT_EQUAL((void *)data3, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listRemoveTail_given_empty_list_should_do_nothing(void)
{
    List *list = listNew();

    listRemoveTail(list);

    TEST_ASSERT_EQUAL(0, list->length);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);

    listDel(list);
}

void test_listRemoveTail_given_10_in_the_list_should_remove_10_in_the_list(void)
{
    List *list = listNew();
    int data1 = 10;
    void *result;

    listAddTail(list, (void *)data1);
    result = listRemoveTail(list);

    TEST_ASSERT_EQUAL(data1, (int *)result);
    TEST_ASSERT_EQUAL(0, list->length);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail);

    listDel(list);
}

void test_listRemoveTail_given_10_20_in_the_list_should_remove_tail_of_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    void *result;

    listAddTail(list, (void *)data1);
    listAddTail(list, (void *)data2);
    result = listRemoveTail(list);

    TEST_ASSERT_EQUAL(data2, (int *)result);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->head->next);
    TEST_ASSERT_EQUAL((void *)data1, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
}

void test_listRemoveTail_given_10_20_30_in_the_list_should_remove_tail_of_list(void)
{
    List *list = listNew();
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    void *result;

    listAddTail(list, (void *)data1);
    listAddTail(list, (void *)data2);
    listAddTail(list, (void *)data3);
    result = listRemoveTail(list);

    TEST_ASSERT_EQUAL(data3, (int *)result);
    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL((void *)data1, list->head->data);
    TEST_ASSERT_EQUAL_PTR(list->tail, list->head->next);
    TEST_ASSERT_EQUAL((void *)data2, list->tail->data);
    TEST_ASSERT_EQUAL_PTR(NULL, list->tail->next);

    listDel(list);
} */

void test_listInit_should_initialize_the_list(void)
{
    List list;

    listInit(&list);

    TEST_ASSERT_NULL(list.head);
    TEST_ASSERT_NULL(list.tail);
    TEST_ASSERT_EQUAL(0, list.length);
}

void test_listElementInit_should_initialize_the_listElement(void)
{
    ListElement listElement;

    listElementInit(&listElement, (void *)5);

    TEST_ASSERT_NULL(listElement.next);
    TEST_ASSERT_EQUAL((void *)5, listElement.data);
}

void test_isListEmpty_given_empty_list_should_return_0(void)
{
    List list;

    listInit(&list);

    TEST_ASSERT_NULL(list.head);
    TEST_ASSERT_NULL(list.tail);
    TEST_ASSERT_EQUAL(0, list.length);
    TEST_ASSERT_EQUAL(0, isListEmpty(&list));
}

void test_isListEmpty_given_not_empty_list_should_return_1(void)
{
    List list;
    ListElement head;

    listInit(&list);
    listElementInit(&head, (void *)5);
    list.head = &head;

    TEST_ASSERT_NULL(list.tail);
    TEST_ASSERT_EQUAL_PTR(&head, list.head);
    TEST_ASSERT_NULL((list.head)->next);
    TEST_ASSERT_EQUAL((void *)5, (list.head)->data);
    TEST_ASSERT_EQUAL(0, list.length);
    TEST_ASSERT_EQUAL(1, isListEmpty(&list));
}

void test_listAddTail_given_list_with_no_element_should_add_another_list_element_into_the_list(void)
{
    List list;
    ListElement head;

    listInit(&list);
    listElementInit(&head, (void *)5);
    listAddTail(&list, (void *)&head);

    TEST_ASSERT_NOT_NULL(list.head);
    TEST_ASSERT_NOT_NULL(list.tail);
    TEST_ASSERT_EQUAL_PTR(&head, list.head);
    TEST_ASSERT_NULL((list.head)->next);
    TEST_ASSERT_EQUAL((void *)5, (list.head)->data);
    TEST_ASSERT_NULL((list.tail)->next);
    TEST_ASSERT_EQUAL_PTR(&head, list.tail);
    TEST_ASSERT_EQUAL((void *)5, (list.tail)->data);
    TEST_ASSERT_EQUAL(1, list.length);
}

void test_listAddTail_given_list_with_one_element_should_add_another_list_element_into_the_list(void)
{
    List list;
    ListElement head, tail;

    listInit(&list);
    listElementInit(&head, (void *)5);
    listElementInit(&tail, (void *)6);
    listAddTail(&list, (void *)&head);
    listAddTail(&list, (void *)&tail);

    TEST_ASSERT_NOT_NULL(list.head);
    TEST_ASSERT_NOT_NULL(list.tail);
    TEST_ASSERT_EQUAL_PTR(list.tail, (list.head)->next);
    TEST_ASSERT_EQUAL_PTR(&head, list.head);
    TEST_ASSERT_EQUAL((void *)5, (list.head)->data);
    TEST_ASSERT_NULL((list.tail)->next);
    TEST_ASSERT_EQUAL_PTR(&tail, list.tail);
    TEST_ASSERT_EQUAL((void *)6, (list.tail)->data);
    TEST_ASSERT_EQUAL(2, list.length);
}

void test_listRemoveHead_given_list_with_2_element_should_remove_list_element_from_head_of_the_list(void)
{
    List list;
    ListElement head, tail;

    listInit(&list);
    listElementInit(&head, (void *)5);
    listElementInit(&tail, (void *)6);
    listAddTail(&list, (void *)&head);
    listAddTail(&list, (void *)&tail);
    listRemoveHead(&list);

    TEST_ASSERT_NOT_NULL(list.head);
    TEST_ASSERT_NOT_NULL(list.tail);
    TEST_ASSERT_NULL((list.head)->next);
    TEST_ASSERT_EQUAL_PTR(&tail, list.head);
    TEST_ASSERT_EQUAL((void *)6, (list.head)->data);
    TEST_ASSERT_NULL((list.tail)->next);
    TEST_ASSERT_EQUAL_PTR(&tail, list.tail);
    TEST_ASSERT_EQUAL((void *)6, (list.tail)->data);
    TEST_ASSERT_EQUAL(1, list.length);
}
