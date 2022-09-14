#define _CRT_SECURE_NO_WARNINGS
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = NULL;
    int nextUp = 0;
    struct ListNode* cur1 = l1, * cur2 = l2, * cur3 = phead;
    while (cur1 || cur2)
    {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (cur1 && cur2)
        {
            if (cur1->val + cur2->val + nextUp >= 10)
            {
                newNode->val = (cur1->val + cur2->val + nextUp) % 10;
                nextUp = 1;
            }
            else
            {
                newNode->val = cur1->val + cur2->val + nextUp;
                nextUp = 0;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
            newNode->next = NULL;
            cur3->next = newNode;
            cur3 = cur3->next;
        }
        else
        {
            struct ListNode* notnull = cur1;
            if (cur1 == NULL)
                notnull = cur2;
            if (notnull->val + nextUp >= 10)
            {
                newNode->val = (notnull->val + nextUp) % 10;
                nextUp = 1;
            }
            else
            {
                newNode->val = notnull->val + nextUp;
                nextUp = 0;
            }
            if (cur1)
                cur1 = cur1->next;
            else
                cur2 = cur2->next;
            newNode->next = NULL;
            cur3->next = newNode;
            cur3 = cur3->next;
        }
    }
    if (nextUp == 1)
    {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = 1;
        newNode->next = NULL;
        cur3->next = newNode;
        cur3 = cur3->next;
    }

    struct ListNode* re = phead->next;
    free(phead);
    return re;

}