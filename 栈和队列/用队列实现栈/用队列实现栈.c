#define _CRT_SECURE_NO_WARNINGS
//��дһ������(����ʵ��)
typedef int QDataType;//���д������Ĭ��Ϊint
typedef struct QueueNode//������еĽڵ�
{
    QDataType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue//ͷβָ�붨�����
{
    QNode* phead;
    QNode* tail;
}Queue;

void QueueInit(Queue* pq)//���г�ʼ��
{
    assert(pq);
    pq->phead = pq->tail = NULL;//��ͷβ�ÿ�
}

bool QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��
{
    assert(pq);
    return pq->phead == NULL;//��Ϊ�ն�ͷһ��ΪNULL
}

void QueuePush(Queue* pq, QDataType x)//�����
{
    assert(pq);
    //�����½ڵ㲢��ʼ��
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    assert(newNode);
    newNode->data = x;
    newNode->next = NULL;

    if (QueueEmpty(pq))
    {
        //��һ��Ԫ�ض�û�У�ͷβָ�붼Ҫ�ı�
        pq->phead = pq->tail = newNode;
    }
    else
    {
        //����Ԫ�أ�ֻ���ڶ�β�����½ڵ㣬Ȼ�����βָ��
        pq->tail->next = newNode;
        pq->tail = newNode;
    }
}

void QueuePop(Queue* pq)//������
{
    assert(pq);
    //����������
    assert(!QueueEmpty(pq));


    if (pq->phead == pq->tail)
    {
        //ֻ��һ��Ԫ�أ�ͷβָ�붼ָ��ͬһ���ڵ㣬Ҫ�����Ƕ��ÿ�
        free(pq->phead);
        pq->phead = pq->tail = NULL;
    }
    else
    {
        //���Ԫ�أ���ͷ�����ݣ�����ͷ�ڵ����һ���ڵ���Ϊ�µ�ͷ��㣬free��ͷ�ڵ�����ͷ�ڵ�
        QNode* newHead = pq->phead->next;
        free(pq->phead);
        pq->phead = newHead;
    }
}

int QueueFront(Queue* pq)//ȡ��ͷ������
{
    assert(pq);
    assert(!QueueEmpty(pq));//���в�Ϊ��
    return pq->phead->data;
}

int QueueBack(Queue* pq)//ȡ��β������
{
    assert(pq);
    assert(!QueueEmpty(pq));//���в�Ϊ��
    return pq->tail->data;
}

int QueueSize(Queue* pq)//��ȡ��ǰ���е�Ԫ�ظ���
{
    //��ͷ��ʼ����������������ʱֹͣ
    assert(pq);
    QNode* cur = pq->phead;
    int size = 0;
    while (cur != NULL)
    {
        size++;
        cur = cur->next;
    }
    return size;
}

typedef struct //����������ʵ��ջ
{
    Queue* queue1;
    Queue* queue2;
} MyStack;

//������n���ڵ�
//��Ҫ˼·��1 ��Ԫ���������ȳ�
//         2 A�����ÿգ�B���и���������
//         3 ��Ҫ��ջʱ����ɾȥ����Ϊ�յĶ��С�B�Ķ�βԪ��
//         4 �ѡ���Ϊ�յĶ��С�B��ǰ(n-1)�ڵ㰴˳������У�ͬʱ��˳�򿽱����ն���A
//         5 free��Bʣ�µĵ�n���ڵ㣬��ʱBΪ�ն��У�AΪ�ǿն��У�ʵ���˺���ȳ�
//         6 ��ջֻ���ڷǿն��ж�β���������ݼ���

MyStack* myStackCreate()//ջ�ĳ�ʼ�� 
{
    MyStack* re = (MyStack*)malloc(sizeof(MyStack));
    //�ڲ�������ָ��ͬ��Ҫ����ռ�
    Queue* q1 = (Queue*)malloc(sizeof(Queue));
    Queue* q2 = (Queue*)malloc(sizeof(Queue));
    assert(q1 && q2 && re);
    re->queue1 = q1;
    re->queue2 = q2;
    //��ʼ���ڲ�����������
    QueueInit(q1);
    QueueInit(q2);
    return re;
}

bool myStackEmpty(MyStack* obj)//�ж�ջ�Ƿ�Ϊ�� 
{
    assert(obj);
    //���ڲ����������ж�Ϊ����ջΪ��
    return QueueEmpty(obj->queue1) && QueueEmpty(obj->queue2);
}

void myStackPush(MyStack* obj, int x)//��ջ 
{
    assert(obj);
    //���1��ջΪ��   ��   �������ж�Ϊ��
    //���2��ջ��Ϊ�� ��   һ������Ϊ�գ���һ����Ϊ��
    if (myStackEmpty(obj))
    {
        //���ջΪ�գ����ĸ����ж�����
        QueuePush(obj->queue1, x);
    }
    else
    {
        //ջ��Ϊ��
        if (QueueEmpty(obj->queue1))
        {
            //�������1Ϊ�գ������������2
            QueuePush(obj->queue2, x);
        }
        else
        {
            //�������2Ϊ�գ����������1
            QueuePush(obj->queue1, x);
        }
    }
}

int myStackTop(MyStack* obj)//ȡջ����Ԫ��
{
    assert(obj);
    assert(!myStackEmpty(obj));//ջ��Ϊ��
    //ȡջ����Ԫ�ؼ� ��Ϊ�յĶ���ȡ��β��Ԫ��

    if (QueueEmpty(obj->queue1))//����1Ϊ�գ�ȡ����2�Ķ�β
        return QueueBack(obj->queue2);
    return QueueBack(obj->queue1);//����ȡ����1�Ķ�β
}

int myStackPop(MyStack* obj) //��ջ
{
    //����Ϊ�յĶ���ǰn-1�����ݿ�������һ�����У�ɾ����n������
    assert(obj);
    assert(!myStackEmpty(obj));//ջ��Ϊ��
    //����1Ϊ�գ��򿽱�����2�Ľڵ㵽����1
    if (QueueEmpty(obj->queue1))
    {
        QDataType re = obj->queue2->tail->data; //����ԭ����ջ��Ԫ��
        if (obj->queue2->phead == obj->queue2->tail)
        {
            //���ֻ��һ���ڵ㣬�ѽڵ��ͷŵ�����
            free(obj->queue2->phead);
            obj->queue2->phead = obj->queue2->tail = NULL;
        }
        else
        {
            //����ڵ�
            //�ҵ�β�ڵ��ǰһ��
            QNode* cur = obj->queue2->phead;
            while (cur->next != obj->queue2->tail)
            {
                cur = cur->next;
            }
            //��ͷ�ڵ㵽β�ڵ��ǰһ����������queue1
            obj->queue1->phead = obj->queue2->phead;
            obj->queue1->tail = cur;
            //cur->nextΪҪɾ����β�ڵ㣬���Ǻ���Ľڵ�
            free(cur->next);
            //ע��Ѷ���1��βָ���next�ÿգ�������Ұָ��
            obj->queue1->tail->next = NULL;
            //����queue2,�����������ÿ�
            obj->queue2->phead = NULL;
            obj->queue2->tail = NULL;

        }
        return re;
    }
    else//����2Ϊ��
    {
        //����ԭ����ջ��Ԫ��
        QDataType re = obj->queue1->tail->data;
        if (obj->queue1->phead == obj->queue1->tail)
        {
            //��ֻ��һ���ڵ㣬free����Ϊ�ն��еĽڵ㼴��
            free(obj->queue1->phead);
            obj->queue1->phead = obj->queue1->tail = NULL;
        }
        else
        {
            //����ڵ�
            QNode* cur = obj->queue1->phead;
            while (cur->next != obj->queue1->tail)
            {
                cur = cur->next;
            }
            obj->queue2->phead = obj->queue1->phead;
            obj->queue2->tail = cur;
            free(cur->next);
            obj->queue2->tail->next = NULL;
            //����queue1
            obj->queue1->phead = obj->queue1->tail = NULL;
        }
        return re;
    }
    return -1;
}

void myStackFree(MyStack* obj)//����ջ 
{
    assert(obj);
    //�ж��ĸ�����Ϊ��
    if (QueueEmpty(obj->queue1))
    {
        //����1Ϊ�գ��ڲ�û�нڵ㣩��������2��ȫ���ڵ�free��
        QNode* cur = obj->queue2->phead;
        while (cur != NULL)
        {
            QNode* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    else
    {
        //����2Ϊ�գ��ڲ�û�нڵ㣩��������2��ȫ���ڵ�free��
        QNode* cur = obj->queue1->phead;
        while (cur != NULL)
        {
            QNode* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    //ע�����1�Ͷ���2��ָ��Ҳָ����һ��ռ�
    free(obj->queue1);
    free(obj->queue2);
    free(obj);

}