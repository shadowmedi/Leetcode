#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //思路1：归并
    //定义双指针分别指向两个链表的头节点,取较小的尾插到新节点上
    //1无哨兵位

    if(list1 == NULL)//如果有任意一个链表为空，则返回另一个链表的头节点
        return list2;
    if(list2 == NULL)
        return list1;
    struct ListNode* head,*tail;
    head = tail = NULL;
    while(list1 && list2)//当其中一个链表遍历到空，直接把另外一个链表的剩下部分尾插到新链表
    {
        if(list1->val <= list2->val)
        {
            if(head == NULL)
            {
                head = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;//list1指针向后走
        }
        else
        {
            if(head == NULL)
            {
                head = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;//list2指针向后走
        }
    }
    if(list1 != NULL)//把没遍历完的链表剩下部分尾插到新链表
    {
        tail->next = list1;
    }
    else if(list2 != NULL)
    {
        tail->next = list2;
    }
    return head;
}*/
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //有哨兵位 归并 此时不需要单独判断其中一个链表为空或全为空的情况，也不用判断新链表的头结点是否为空
    //只需尾插
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    head->next = NULL;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            tail = tail->next;//及时更新tail
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    if (list1 != NULL)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }
    //但要free掉head
    struct ListNode* re = head->next;
    free(head);
    return re;

}
