#define _CRT_SECURE_NO_WARNINGS
/*bool hasCycle(struct ListNode* head)
{
    //�������ָ�룬��ָ��һ��������(����һ����3����?)����ָ��һ����һ��
    //���ɻ�����ָ���ߵ��ɻ����ֵĵ�һ���ڵ��У���ָ���ߵ����ɻ����ֵ�һ��
    //����ָ���ߵ��ɻ����ֵĵ�һ���ڵ��У���ָ����ߵ������ĳһ���ڵ���
    //����fast��slow�ľ���ΪN��fastһ����2����slowһ����1����ÿ��һ��N--����N =0ʱ��fast��slow����
    struct ListNode* fast = head, * slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        //�����ɻ���ż�����ڵ� slow�ҵ��м�ڵ�ʱ��fast��ΪNULL
        //�������ڵ� slow�ҵ��м�ڵ�ʱ��fast->next��ΪNULL
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}*/
bool hasCycle(struct ListNode* head)
{
    //һ����3��������ǳɻ����ֽڵ���Ϊa���ɻ����ֽڵ���Ϊb,��slow�ߵ��ɻ����ֵ����ʱ��fast��slowǰ��ľ���Ϊ(2a-kb) [kΪ����Ȧ��]
    //fast����slow�����[(k+1)b-2a]
    //N = (k+1)b - 2a
    //����N������С2����NΪż��N���0
    //��Ϊ������b��Ϊ����
    //N���-1����N����Ϊb-1(��Ϊż��)
    //���Կ���1����3��
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}