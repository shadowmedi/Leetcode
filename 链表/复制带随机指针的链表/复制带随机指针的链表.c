#define _CRT_SECURE_NO_WARNINGS
struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    //遍历链表，进行拷贝，将拷贝的节点链接在原节点后面
    struct Node* cur = head;
    while (cur != NULL)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;//将拷贝的节点链接在原节点后面
        struct Node* next = cur->next;
        cur->next = copy;
        cur = next;
    }
    //遍历新链表
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
            copy->random = cur->random->next;//因为拷贝节点都是原节点的下一个
        }
        cur = cur->next->next;
        if (cur != NULL)
            copy = copy->next->next;
    }
    //把拷贝节点解下来尾插到另一个链表,还原原链表
    cur = head;
    copy = head->next;
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));//给哨兵位
    struct Node* tail = newHead;
    newHead->next = NULL;
    newHead->random = NULL;
    while (cur != NULL)
    {
        cur->next = copy->next;//还原原节点的链接关系
        cur = cur->next;
        tail->next = copy;//copy节点尾插到新链表
        tail = tail->next;
        if (cur)
            copy = cur->next;//向后更新copy的值
    }
    struct Node* re = newHead->next;
    free(newHead);
    return re;
}