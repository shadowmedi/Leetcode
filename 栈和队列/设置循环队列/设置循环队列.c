#define _CRT_SECURE_NO_WARNINGS
typedef int QDataType;
//这里用数组实现循环队列
typedef struct
{
    QDataType* data;//存储数据的数组
    int capacity;//循环队列的容量
    int head;//头部元素下标
    int tail;//尾部元素下标 tail指向最后一个数据的下一个位置
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) //循环队列的初始化
{
    MyCircularQueue* re = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //开辟多一个空间，便于判断队列满的情况，一般tail == head为空，tail+1 == head为满
    re->data = (QDataType*)malloc(sizeof(QDataType) * (k + 1));
    re->head = re->tail = 0;
    re->capacity = k + 1;
    return re;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    if (obj->tail + 1 == obj->capacity)
        return obj->head == 0;
    else
        return obj->head == obj->tail + 1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->head == obj->tail;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->data);
    free(obj);
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)//队尾入队列 
{
    //如果队列满了，入队列失败
    if (myCircularQueueIsFull(obj))
        return false;
    //1 正常情况下
    //obj->data[obj->tail] = value;
    //obj->tail++;
    //2 若tail++变为k+1，则要把tail置0
    //if(obj->tail == obj->capacity)
        //obj->tail = 0;
    obj->data[obj->tail++] = value;
    obj->tail %= obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)//队头出队列 
{
    //如果队列为空，出队列失败
    if (myCircularQueueIsEmpty(obj))
        return false;
    //正常情况下，只需++head,忽略掉原来的数据
    ++obj->head;
    //如果head后来>k,也要置0
    if (obj->head == obj->capacity)
        obj->head = 0;
    //或者head % (k+1)
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    //因为队尾元素在tail的上一个下标位置
    //1 tail - 1 == -1
    //2 正常返回
    if (obj->tail - 1 == -1)
        return obj->data[obj->capacity - 1];
    else
        return obj->data[obj->tail - 1];

}

