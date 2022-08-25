#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    // write code here
    //定义双指针fast slow
    //fast先走k步，之后slow与fast一起走，直到fast==NULL,使slow和fast距离保持k
    struct ListNode* fast, * slow;
    fast = slow = pListHead;
    while (k--)//fast走k步
    {
        if (fast == NULL)//如果fast提前走到空，说明k > 节点数,没有倒数第k个节点
            return NULL;
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;

}*/
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    //遍历链表，得出节点数
    int num = 0;
    struct ListNode* cur = pListHead;
    while (cur != NULL)
    {
        num++;
        cur = cur->next;
    }
    if (num < k)
        return NULL;
    else
    {
        cur = pListHead;
        int step = num - k;//倒数第k个，就是第(节点数-k + 1)个，从第一个节点开始要走(num-k)步
        while (step--)
        {
            cur = cur->next;
        }
        return cur;
    }

}