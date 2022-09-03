#define _CRT_SECURE_NO_WARNINGS
typedef int QDataType;
typedef struct QNode//������еĽڵ�
{
    struct QNode* next;
    QDataType x;
}QNode;

typedef struct //����һ������
{
    QNode* phead;//��ͷ
    QNode* tail;//��β
    int capacity;//����
    int size;//���еĽڵ���
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    assert(obj);
    if (obj->phead == NULL)
        return true;
    return false;
}

MyCircularQueue* myCircularQueueCreate(int k)//���еĳ�ʼ�� 
{
    MyCircularQueue* re = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //����һ���ռ��Ŷ���
    assert(re);
    re->phead = re->tail = NULL;
    re->capacity = k;
    re->size = 0;
    return re;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    assert(obj);
    if (obj->size == obj->capacity)//��������
        return false;
    QNode* newNode = (QNode*)malloc(sizeof(QNode));//����ڵ㲢��ʼ��
    if (newNode == NULL)
        return false;
    newNode->x = value;
    newNode->next = NULL;
    if (obj->phead == NULL)//�����޽ڵ�
    {
        obj->phead = obj->tail = newNode;
        newNode->next = obj->phead;
        obj->size++;
        return true;
    }
    else
    {
        obj->tail->next = newNode;
        obj->tail = newNode;
        obj->tail->next = obj->phead;
        obj->size++;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    assert(obj);
    if (myCircularQueueIsEmpty(obj))//����Ϊ��
        return false;
    if (obj->phead == obj->tail)//ֻ��һ���ڵ�
    {
        free(obj->phead);
        obj->phead = obj->tail = NULL;
        obj->size--;
        return true;
    }
    else
    {
        QNode* newHead = obj->phead->next;
        free(obj->phead);
        obj->phead = newHead;
        obj->tail->next = obj->phead;
        obj->size--;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->phead->x;
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->tail->x;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    assert(obj);
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    assert(obj);
    if (obj->phead == NULL)
    {
        free(obj);
        obj = NULL;
        return;
    }
    QNode* cur = obj->phead->next;
    while (cur != obj->phead)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj->phead);
    free(obj);
    obj = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/