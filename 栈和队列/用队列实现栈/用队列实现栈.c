#define _CRT_SECURE_NO_WARNINGS
//先写一个队列(链表实现)
typedef int QDataType;//队列存的数据默认为int
typedef struct QueueNode//定义队列的节点
{
    QDataType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue//头尾指针定义队列
{
    QNode* phead;
    QNode* tail;
}Queue;

void QueueInit(Queue* pq)//队列初始化
{
    assert(pq);
    pq->phead = pq->tail = NULL;//将头尾置空
}

bool QueueEmpty(Queue* pq)//判断队列是否为空
{
    assert(pq);
    return pq->phead == NULL;//若为空队头一定为NULL
}

void QueuePush(Queue* pq, QDataType x)//入队列
{
    assert(pq);
    //申请新节点并初始化
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    assert(newNode);
    newNode->data = x;
    newNode->next = NULL;

    if (QueueEmpty(pq))
    {
        //若一个元素都没有，头尾指针都要改变
        pq->phead = pq->tail = newNode;
    }
    else
    {
        //若有元素，只需在队尾链接新节点，然后更新尾指针
        pq->tail->next = newNode;
        pq->tail = newNode;
    }
}

void QueuePop(Queue* pq)//出队列
{
    assert(pq);
    //队列无数据
    assert(!QueueEmpty(pq));


    if (pq->phead == pq->tail)
    {
        //只有一个元素，头尾指针都指向同一个节点，要把他们都置空
        free(pq->phead);
        pq->phead = pq->tail = NULL;
    }
    else
    {
        //多个元素，队头出数据，保留头节点的下一个节点作为新的头结点，free掉头节点后更新头节点
        QNode* newHead = pq->phead->next;
        free(pq->phead);
        pq->phead = newHead;
    }
}

int QueueFront(Queue* pq)//取队头的数据
{
    assert(pq);
    assert(!QueueEmpty(pq));//队列不为空
    return pq->phead->data;
}

int QueueBack(Queue* pq)//取队尾的数据
{
    assert(pq);
    assert(!QueueEmpty(pq));//队列不为空
    return pq->tail->data;
}

int QueueSize(Queue* pq)//获取当前队列的元素个数
{
    //从头开始遍历链表，遍历到空时停止
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

typedef struct //用两个队列实现栈
{
    Queue* queue1;
    Queue* queue2;
} MyStack;

//假设有n个节点
//主要思路：1 让元素满足后进先出
//         2 A队列置空，B队列负责存放数据
//         3 当要出栈时，即删去【不为空的队列】B的队尾元素
//         4 把【不为空的队列】B的前(n-1)节点按顺序出队列，同时按顺序拷贝到空队列A
//         5 free掉B剩下的第n个节点，此时B为空队列，A为非空队列，实现了后进先出
//         6 入栈只需在非空队列队尾处插入数据即可

MyStack* myStackCreate()//栈的初始化 
{
    MyStack* re = (MyStack*)malloc(sizeof(MyStack));
    //内部的两个指针同样要申请空间
    Queue* q1 = (Queue*)malloc(sizeof(Queue));
    Queue* q2 = (Queue*)malloc(sizeof(Queue));
    assert(q1 && q2 && re);
    re->queue1 = q1;
    re->queue2 = q2;
    //初始化内部的两个队列
    QueueInit(q1);
    QueueInit(q2);
    return re;
}

bool myStackEmpty(MyStack* obj)//判断栈是否为空 
{
    assert(obj);
    //若内部的两个队列都为空则栈为空
    return QueueEmpty(obj->queue1) && QueueEmpty(obj->queue2);
}

void myStackPush(MyStack* obj, int x)//入栈 
{
    assert(obj);
    //情况1：栈为空   即   两个队列都为空
    //情况2：栈不为空 即   一个队列为空，另一个不为空
    if (myStackEmpty(obj))
    {
        //如果栈为空，入哪个队列都可以
        QueuePush(obj->queue1, x);
    }
    else
    {
        //栈不为空
        if (QueueEmpty(obj->queue1))
        {
            //如果队列1为空，则数据入队列2
            QueuePush(obj->queue2, x);
        }
        else
        {
            //如果队列2为空，数据入队列1
            QueuePush(obj->queue1, x);
        }
    }
}

int myStackTop(MyStack* obj)//取栈顶的元素
{
    assert(obj);
    assert(!myStackEmpty(obj));//栈不为空
    //取栈顶的元素即 不为空的队列取队尾的元素

    if (QueueEmpty(obj->queue1))//队列1为空，取队列2的队尾
        return QueueBack(obj->queue2);
    return QueueBack(obj->queue1);//否则取队列1的队尾
}

int myStackPop(MyStack* obj) //出栈
{
    //将不为空的队列前n-1个数据拷贝到另一个队列，删除第n个数据
    assert(obj);
    assert(!myStackEmpty(obj));//栈不为空
    //队列1为空，则拷贝队列2的节点到队列1
    if (QueueEmpty(obj->queue1))
    {
        QDataType re = obj->queue2->tail->data; //保留原来的栈顶元素
        if (obj->queue2->phead == obj->queue2->tail)
        {
            //如果只有一个节点，把节点释放掉即可
            free(obj->queue2->phead);
            obj->queue2->phead = obj->queue2->tail = NULL;
        }
        else
        {
            //多个节点
            //找到尾节点的前一个
            QNode* cur = obj->queue2->phead;
            while (cur->next != obj->queue2->tail)
            {
                cur = cur->next;
            }
            //把头节点到尾节点的前一个都拷贝进queue1
            obj->queue1->phead = obj->queue2->phead;
            obj->queue1->tail = cur;
            //cur->next为要删除的尾节点，他是后进的节点
            free(cur->next);
            //注意把队列1的尾指针的next置空，否则是野指针
            obj->queue1->tail->next = NULL;
            //处理queue2,将它的数据置空
            obj->queue2->phead = NULL;
            obj->queue2->tail = NULL;

        }
        return re;
    }
    else//队列2为空
    {
        //保留原来的栈顶元素
        QDataType re = obj->queue1->tail->data;
        if (obj->queue1->phead == obj->queue1->tail)
        {
            //若只有一个节点，free掉不为空队列的节点即可
            free(obj->queue1->phead);
            obj->queue1->phead = obj->queue1->tail = NULL;
        }
        else
        {
            //多个节点
            QNode* cur = obj->queue1->phead;
            while (cur->next != obj->queue1->tail)
            {
                cur = cur->next;
            }
            obj->queue2->phead = obj->queue1->phead;
            obj->queue2->tail = cur;
            free(cur->next);
            obj->queue2->tail->next = NULL;
            //处理queue1
            obj->queue1->phead = obj->queue1->tail = NULL;
        }
        return re;
    }
    return -1;
}

void myStackFree(MyStack* obj)//销毁栈 
{
    assert(obj);
    //判断哪个队列为空
    if (QueueEmpty(obj->queue1))
    {
        //队列1为空（内部没有节点），将队列2的全部节点free掉
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
        //队列2为空（内部没有节点），将队列2的全部节点free掉
        QNode* cur = obj->queue1->phead;
        while (cur != NULL)
        {
            QNode* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    //注意队列1和队列2的指针也指向了一块空间
    free(obj->queue1);
    free(obj->queue2);
    free(obj);

}