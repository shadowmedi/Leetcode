#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode* reverseList(struct ListNode* head)
{
    //˼·1����cur����ԭ�������������Ľڵ�ͷ�嵽�����������������ͷ
    struct ListNode* cur = head;
    head = NULL;
    while(cur != NULL)
    {
        //����cur->next
        struct ListNode* Next = cur->next;
        //����
        cur->next = head;
        head = cur;
        cur = Next;
    }
    return head;
}*/
struct ListNode* reverseList(struct ListNode* head)
{
    //˼·2����ָ��ķ���ߵ�,����pre,cur,nextʵ�ֵ�������
    //���������
    if (head == NULL)
        return NULL;
    struct ListNode* pre, * cur, * next;
    pre = NULL;
    cur = head;
    next = cur->next;
    while (cur != NULL)
    {
        cur->next = pre;
        pre = cur;
        cur = next;
        if (cur != NULL)
            next = cur->next;
    }
    return pre;

}