#define _CRT_SECURE_NO_WARNINGS
struct ListNode* reverse(struct ListNode* pHead)
{
    struct ListNode* cur = pHead;//定义当前指针和前一个指针，遍历到一个节点将该节点箭头方向逆置
    struct ListNode* pre = NULL;
    while (cur != NULL)
    {
        struct ListNode* Next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = Next;
    }
    return pre;
}
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        //快慢指针找到中间节点，逆置从中间节点开始的链表，一一对比前面节点
        struct ListNode* fast, * slow;
        fast = slow = A;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //此时中间节点是slow
        struct ListNode* newHead = reverse(slow);
        //比较两个链表的节点
        struct ListNode* cur = newHead;
        while (cur != NULL)
        {
            if (cur->val != A->val)
                return false;
            else
            {
                cur = cur->next;
                A = A->next;
            }
        }
        return true;
    }
};