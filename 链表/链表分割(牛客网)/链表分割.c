#define _CRT_SECURE_NO_WARNINGS
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        // write code here
        //定义两个新链表，遍历原链表，比x大的节点尾插到第一个链表，比x小的节点尾插到第二个链表.
        //1 不带哨兵位头节点
        //极端场景：全比x小  全比x大  有大有小——最后一个数比x小 最后一个数比x大
        /*struct ListNode* head1, * head2, * tail1, * tail2;
        head1 = head2 = tail1 = tail2 = NULL;
        struct ListNode* cur = pHead;
        while (cur != NULL)//遍历原链表
        {
            if (cur->val < x)//比x小放入第一个链表
            {
                if (head1 == NULL)//判空
                {
                    head1 = tail1 = cur;//tail1只需标记尾部
                }
                else
                {
                    tail1->next = cur;
                    tail1 = tail1->next;
                }
            }
            else//比x大放入第二个链表
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
        //链接第一个和第二个链表
        if (tail1 != NULL)
            tail1->next = head2;
        if (tail2 != NULL)
            tail2->next = NULL;//第二个链表尾部置NULL
        //全比x小，直接返回head1;全比x大，返回head2
        if (head1 == NULL && head2 != NULL)
            return head2;
        return head1;*/


        //带哨兵位头节点
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
        //链接两个链表
        tail1->next = head2->next;
        tail2->next = NULL;
        struct ListNode* re = head1->next;
        free(head1);
        free(head2);
        return re;


    }
};