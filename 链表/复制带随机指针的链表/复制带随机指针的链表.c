#define _CRT_SECURE_NO_WARNINGS
struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    //�����������п������������Ľڵ�������ԭ�ڵ����
    struct Node* cur = head;
    while (cur != NULL)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;//�������Ľڵ�������ԭ�ڵ����
        struct Node* next = cur->next;
        cur->next = copy;
        cur = next;
    }
    //����������
    cur = head;
    struct Node* copy = head->next;
    while (cur != NULL)
    {
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;//��Ϊ�����ڵ㶼��ԭ�ڵ����һ��
        }
        cur = cur->next->next;
        if (cur != NULL)
            copy = copy->next->next;
    }
    //�ѿ����ڵ������β�嵽��һ������,��ԭԭ����
    cur = head;
    copy = head->next;
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));//���ڱ�λ
    struct Node* tail = newHead;
    newHead->next = NULL;
    newHead->random = NULL;
    while (cur != NULL)
    {
        cur->next = copy->next;//��ԭԭ�ڵ�����ӹ�ϵ
        cur = cur->next;
        tail->next = copy;//copy�ڵ�β�嵽������
        tail = tail->next;
        if (cur)
            copy = cur->next;//������copy��ֵ
    }
    struct Node* re = newHead->next;
    free(newHead);
    return re;
}