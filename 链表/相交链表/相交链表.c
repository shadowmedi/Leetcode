#define _CRT_SECURE_NO_WARNINGS
/*struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    //方法1：首先最后一个节点相同可以判断是否2链表相交
    //遍历两个链表，分别求出两个链表的节点数
    //节点数多的链表指针，从头开始先走差距步，使两个链表的两个指针离第一次相加的节点距离相同
    //然后同时走，直到两个指针指向的节点(地址)相同
    if(headA == NULL|| headB == NULL)
        return NULL;
    struct ListNode* cur1 = headA;  //cur1遍历a链表
    struct ListNode* cur2 = headB;  //cur2遍历b链表
    int num1,num2;
    num1 = num2 = 1;
    //num1记录a链表节点数，num2记录b链表节点数
    //若相交，首先最后一个节点的地址一定都相同
    while(cur1->next != NULL)
    {
        num1++;
        cur1 = cur1->next;
    }
    //此时cur1指向a链表尾节点
    while(cur2->next != NULL)
    {
        num2++;
        cur2 = cur2->next;
    }
    //此时cur2指向b链表尾节点
    if(cur1 != cur2)
        return NULL;//最后一个节点的地址不相同，不相交
    int step = fabs(num1 - num2);
    cur1 = headA;
    cur2 = headB;
    //先让(节点数多的链表)指针走差距步，此时两个链表的指针指向的节点与第一次相交的节点距离相同
    if(num1 > num2)
    {
        while(step--)//a链表节点多，先走差距步
        {
            cur1 = cur1->next;
        }
    }
    else if(num1 < num2)
    {
        while(step--)//b链表节点多，则cur2先走step步
        {
            cur2 = cur2->next;
        }
    }
    //a,b链表节点相同，则不做处理
    while(cur1 != cur2)//接下来两个链表指针同时走，直到节点相同
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}*/
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //方法2：暴力枚举，把a链表的每个节点和b链表比对一遍
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode* cur1, * cur2;
    cur1 = headA;
    cur2 = headB;
    while (cur1 != NULL)
    {
        cur2 = headB;//每次比对B链表所有值，都要把cur2初始化为b链表的头节点
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