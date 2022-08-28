#define _CRT_SECURE_NO_WARNINGS
/*bool hasCycle(struct ListNode* head)
{
    //定义快慢指针，快指针一次走两步(可以一次走3步吗?)，慢指针一次走一步
    //若成环，快指针走到成环部分的第一个节点中，慢指针走到不成环部分的一半
    //待慢指针走到成环部分的第一个节点中，快指针会走到环里的某一个节点中
    //最后由于成环，快慢指针只能在环内徘徊，最终两个指针会相遇
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
    //一次走3步
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