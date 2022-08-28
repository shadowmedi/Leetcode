#define _CRT_SECURE_NO_WARNINGS
/*bool hasCycle(struct ListNode* head)
{
    //�������ָ�룬��ָ��һ��������(����һ����3����?)����ָ��һ����һ��
    //���ɻ�����ָ���ߵ��ɻ����ֵĵ�һ���ڵ��У���ָ���ߵ����ɻ����ֵ�һ��
    //����ָ���ߵ��ɻ����ֵĵ�һ���ڵ��У���ָ����ߵ������ĳһ���ڵ���
    //������ڳɻ�������ָ��ֻ���ڻ����ǻ�����������ָ�������
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
    //һ����3��
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