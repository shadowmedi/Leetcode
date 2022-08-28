#define _CRT_SECURE_NO_WARNINGS
struct ListNode* reverse(struct ListNode* pHead)
{
    struct ListNode* cur = pHead;//���嵱ǰָ���ǰһ��ָ�룬������һ���ڵ㽫�ýڵ��ͷ��������
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
        //����ָ���ҵ��м�ڵ㣬���ô��м�ڵ㿪ʼ������һһ�Ա�ǰ��ڵ�
        struct ListNode* fast, * slow;
        fast = slow = A;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //��ʱ�м�ڵ���slow
        struct ListNode* newHead = reverse(slow);
        //�Ƚ���������Ľڵ�
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