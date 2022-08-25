#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //˼·1���鲢
    //����˫ָ��ֱ�ָ�����������ͷ�ڵ�,ȡ��С��β�嵽�½ڵ���
    //1���ڱ�λ

    if(list1 == NULL)//���������һ������Ϊ�գ��򷵻���һ�������ͷ�ڵ�
        return list2;
    if(list2 == NULL)
        return list1;
    struct ListNode* head,*tail;
    head = tail = NULL;
    while(list1 && list2)//������һ������������գ�ֱ�Ӱ�����һ�������ʣ�²���β�嵽������
    {
        if(list1->val <= list2->val)
        {
            if(head == NULL)
            {
                head = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;//list1ָ�������
        }
        else
        {
            if(head == NULL)
            {
                head = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;//list2ָ�������
        }
    }
    if(list1 != NULL)//��û�����������ʣ�²���β�嵽������
    {
        tail->next = list1;
    }
    else if(list2 != NULL)
    {
        tail->next = list2;
    }
    return head;
}*/
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //���ڱ�λ �鲢 ��ʱ����Ҫ�����ж�����һ������Ϊ�ջ�ȫΪ�յ������Ҳ�����ж��������ͷ����Ƿ�Ϊ��
    //ֻ��β��
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    head->next = NULL;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            tail = tail->next;//��ʱ����tail
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    if (list1 != NULL)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }
    //��Ҫfree��head
    struct ListNode* re = head->next;
    free(head);
    return re;

}
