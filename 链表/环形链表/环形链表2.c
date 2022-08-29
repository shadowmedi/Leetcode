#define _CRT_SECURE_NO_WARNINGS
//定义两个指针，fast一次走2步，slow一次走1步，fast在【slow走1圈之内】(slow从进成环口开始)一定能追上slow，因为fast和slow最多间隔b（环节点数）
//slow走一圈，fast走两圈
//在相遇的地方定义一个指针meet，在头节点定义cur，同时走直到cur = meet时，该节点就是成环入口。
//slow走的节点数：a+x
//fast走的节点数：a+kb+x
//a+x = kb
//a = kb - x
//a = (k - 1)b+(b-x)
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