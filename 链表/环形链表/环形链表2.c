#define _CRT_SECURE_NO_WARNINGS
struct ListNode* detectCycle(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode* fast = head, * slow = head;
    int flag = 0;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        struct ListNode* cur = head;
        struct ListNode* meet = fast;
        while (cur != meet)
        {
            cur = cur->next;
            meet = meet->next;
        }
        return cur;
    }
    return NULL;


}