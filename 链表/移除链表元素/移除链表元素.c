#define _CRT_SECURE_NO_WARNINGS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 /*struct ListNode* removeElements(struct ListNode* head, int val)
 {
     //思路1：定义prev和cur双指针
     struct ListNode* cur = head;
     struct ListNode* prev = NULL;
     while(cur != NULL)
     {
         if(cur->val == val)
         {
             if(cur == head)//头删
             {
                 head = head->next;
                 free(cur);
                 cur = head;
             }
             else
             {
                 prev->next = cur->next;
                 free(cur);
                 cur = prev->next;
             }
         }
         else
         {
             prev = cur;
             cur = cur->next;
         }
     }
     return head;
 }*/
 /*struct ListNode* removeElements(struct ListNode* head, int val)
 {
     //思路2：将不是val的值尾插到新链表，返回新链表的头节点
     //1 没有哨兵位头节点
     struct ListNode* cur = head;//用cur遍历原链表
     struct ListNode* tail = head = NULL;
     while(cur != NULL)
     {
         if(cur->val == val)
         {
             struct ListNode* next = cur->next;
             free(cur);
             cur = next;
         }
         else
         {
             if(head == NULL)
             {
                 tail = head = cur;
                 cur = cur->next;
             }
             else
             {
                 tail->next = cur;
                 tail = tail->next;
                 cur = cur->next;
             }
         }
     }
     if(tail != NULL)
         tail->next = NULL;
     return head;
 }*/
struct ListNode* removeElements(struct ListNode* head, int val)
{
    //有哨兵位头节点
    struct ListNode* cur = head;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    head->next = NULL;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            struct ListNode* next = cur->next;
            free(cur);
            cur = next;
        }
        else
        {
            tail->next = cur;
            tail = tail->next;
            cur = cur->next;
        }
    }
    tail->next = NULL;
    struct ListNode* re = head->next;
    free(head);
    head = NULL;
    return re;

}