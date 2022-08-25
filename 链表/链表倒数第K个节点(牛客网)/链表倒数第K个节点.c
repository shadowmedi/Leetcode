#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    // write code here
    //����˫ָ��fast slow
    //fast����k����֮��slow��fastһ���ߣ�ֱ��fast==NULL,ʹslow��fast���뱣��k
    struct ListNode* fast, * slow;
    fast = slow = pListHead;
    while (k--)//fast��k��
    {
        if (fast == NULL)//���fast��ǰ�ߵ��գ�˵��k > �ڵ���,û�е�����k���ڵ�
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
    //���������ó��ڵ���
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
        int step = num - k;//������k�������ǵ�(�ڵ���-k + 1)�����ӵ�һ���ڵ㿪ʼҪ��(num-k)��
        while (step--)
        {
            cur = cur->next;
        }
        return cur;
    }

}