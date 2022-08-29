#define _CRT_SECURE_NO_WARNINGS
/*bool hasCycle(struct ListNode* head)
{
    //定义快慢指针，快指针一次走两步(可以一次走3步吗?)，慢指针一次走一步
    //若成环，快指针走到成环部分的第一个节点中，慢指针走到不成环部分的一半
    //待慢指针走到成环部分的第一个节点中，快指针会走到环里的某一个节点中
    //假设fast和slow的距离为N，fast一次走2步，slow一次走1步，每走一次N--，当N =0时，fast和slow相遇
    struct ListNode* fast = head, * slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        //若不成环，偶数个节点 slow找到中间节点时，fast会为NULL
        //奇数个节点 slow找到中间节点时，fast->next会为NULL
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}*/
bool hasCycle(struct ListNode* head)
{
    //一次走3步，假设非成环部分节点数为a，成环部分节点数为b,则当slow走到成环部分的起点时，fast在slow前面的距离为(2a-kb) [k为任意圈数]
    //fast即在slow后面的[(k+1)b-2a]
    //N = (k+1)b - 2a
    //由于N不断缩小2，若N为偶，N最后到0
    //若为奇数，b必为奇数
    //N最后到-1，即N重置为b-1(必为偶数)
    //所以可以1次走3步
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