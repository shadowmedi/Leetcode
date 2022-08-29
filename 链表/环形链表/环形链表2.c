#define _CRT_SECURE_NO_WARNINGS
//��������ָ�룬fastһ����2����slowһ����1����fast�ڡ�slow��1Ȧ֮�ڡ�(slow�ӽ��ɻ��ڿ�ʼ)һ����׷��slow����Ϊfast��slow�����b�����ڵ�����
//slow��һȦ��fast����Ȧ
//�������ĵط�����һ��ָ��meet����ͷ�ڵ㶨��cur��ͬʱ��ֱ��cur = meetʱ���ýڵ���ǳɻ���ڡ�
//slow�ߵĽڵ�����a+x
//fast�ߵĽڵ�����a+kb+x
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