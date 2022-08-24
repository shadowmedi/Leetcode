#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode* reverseList(struct ListNode* head)
{
    //思路1：用cur遍历原链表，将遍历到的节点头插到新链表，返回新链表的头
    struct ListNode* cur = head;
    head = NULL;
    while(cur != NULL)
    {
        //保存cur->next
        struct ListNode* Next = cur->next;
        //迭代
        cur->next = head;
        head = cur;
        cur = Next;
    }
    return head;
}*/
struct ListNode* reverseList(struct ListNode* head)
{
    //思路2：把指针的方向颠倒,定义pre,cur,next实现迭代交换
    //空链表情况
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