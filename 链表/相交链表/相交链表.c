#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    //����1���������һ���ڵ���ͬ�����ж��Ƿ�2�����ཻ
    //�������������ֱ������������Ľڵ���
    //�ڵ����������ָ�룬��ͷ��ʼ���߲�ಽ��ʹ�������������ָ�����һ����ӵĽڵ������ͬ
    //Ȼ��ͬʱ�ߣ�ֱ������ָ��ָ��Ľڵ�(��ַ)��ͬ
    if(headA == NULL|| headB == NULL)
        return NULL;
    struct ListNode* cur1 = headA;  //cur1����a����
    struct ListNode* cur2 = headB;  //cur2����b����
    int num1,num2;
    num1 = num2 = 1;
    //num1��¼a����ڵ�����num2��¼b����ڵ���
    //���ཻ���������һ���ڵ�ĵ�ַһ������ͬ
    while(cur1->next != NULL)
    {
        num1++;
        cur1 = cur1->next;
    }
    //��ʱcur1ָ��a����β�ڵ�
    while(cur2->next != NULL)
    {
        num2++;
        cur2 = cur2->next;
    }
    //��ʱcur2ָ��b����β�ڵ�
    if(cur1 != cur2)
        return NULL;//���һ���ڵ�ĵ�ַ����ͬ�����ཻ
    int step = fabs(num1 - num2);
    cur1 = headA;
    cur2 = headB;
    //����(�ڵ����������)ָ���߲�ಽ����ʱ���������ָ��ָ��Ľڵ����һ���ཻ�Ľڵ������ͬ
    if(num1 > num2)
    {
        while(step--)//a����ڵ�࣬���߲�ಽ
        {
            cur1 = cur1->next;
        }
    }
    else if(num1 < num2)
    {
        while(step--)//b����ڵ�࣬��cur2����step��
        {
            cur2 = cur2->next;
        }
    }
    //a,b����ڵ���ͬ����������
    while(cur1 != cur2)//��������������ָ��ͬʱ�ߣ�ֱ���ڵ���ͬ
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}*/
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //����2������ö�٣���a�����ÿ���ڵ��b����ȶ�һ��
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode* cur1, * cur2;
    cur1 = headA;
    cur2 = headB;
    while (cur1 != NULL)
    {
        cur2 = headB;//ÿ�αȶ�B��������ֵ����Ҫ��cur2��ʼ��Ϊb�����ͷ�ڵ�
        while (cur2 != NULL)
        {
            if (cur1 == cur2)
                return cur1;
            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }
    return NULL;

}