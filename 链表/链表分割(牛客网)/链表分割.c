#define _CRT_SECURE_NO_WARNINGS
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        // write code here
        //������������������ԭ������x��Ľڵ�β�嵽��һ��������xС�Ľڵ�β�嵽�ڶ�������.
        //1 �����ڱ�λͷ�ڵ�
        //���˳�����ȫ��xС  ȫ��x��  �д���С�������һ������xС ���һ������x��
        /*struct ListNode* head1, * head2, * tail1, * tail2;
        head1 = head2 = tail1 = tail2 = NULL;
        struct ListNode* cur = pHead;
        while (cur != NULL)//����ԭ����
        {
            if (cur->val < x)//��xС�����һ������
            {
                if (head1 == NULL)//�п�
                {
                    head1 = tail1 = cur;//tail1ֻ����β��
                }
                else
                {
                    tail1->next = cur;
                    tail1 = tail1->next;
                }
            }
            else//��x�����ڶ�������
            {
                if (head2 == NULL)
                {
                    head2 = tail2 = cur;
                }
                else
                {
                    tail2->next = cur;
                    tail2 = tail2->next;
                }
            }
            cur = cur->next;
        }
        //���ӵ�һ���͵ڶ�������
        if (tail1 != NULL)
            tail1->next = head2;
        if (tail2 != NULL)
            tail2->next = NULL;//�ڶ�������β����NULL
        //ȫ��xС��ֱ�ӷ���head1;ȫ��x�󣬷���head2
        if (head1 == NULL && head2 != NULL)
            return head2;
        return head1;*/


        //���ڱ�λͷ�ڵ�
        struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* tail1, * tail2;
        tail1 = head1;
        tail2 = head2;
        tail1->next = tail2->next = NULL;
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                tail1->next = cur;
                tail1 = tail1->next;
            }
            else
            {
                tail2->next = cur;
                tail2 = tail2->next;
            }
            cur = cur->next;
        }
        //������������
        tail1->next = head2->next;
        tail2->next = NULL;
        struct ListNode* re = head1->next;
        free(head1);
        free(head2);
        return re;


    }
};