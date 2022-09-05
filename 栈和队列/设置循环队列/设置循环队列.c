#define _CRT_SECURE_NO_WARNINGS
typedef int QDataType;
//����������ʵ��ѭ������
typedef struct
{
    QDataType* data;//�洢���ݵ�����
    int capacity;//ѭ�����е�����
    int head;//ͷ��Ԫ���±�
    int tail;//β��Ԫ���±� tailָ�����һ�����ݵ���һ��λ��
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) //ѭ�����еĳ�ʼ��
{
    MyCircularQueue* re = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //���ٶ�һ���ռ䣬�����ж϶������������һ��tail == headΪ�գ�tail+1 == headΪ��
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

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)//��β����� 
{
    //����������ˣ������ʧ��
    if (myCircularQueueIsFull(obj))
        return false;
    //1 ���������
    //obj->data[obj->tail] = value;
    //obj->tail++;
    //2 ��tail++��Ϊk+1����Ҫ��tail��0
    //if(obj->tail == obj->capacity)
        //obj->tail = 0;
    obj->data[obj->tail++] = value;
    obj->tail %= obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)//��ͷ������ 
{
    //�������Ϊ�գ�������ʧ��
    if (myCircularQueueIsEmpty(obj))
        return false;
    //��������£�ֻ��++head,���Ե�ԭ��������
    ++obj->head;
    //���head����>k,ҲҪ��0
    if (obj->head == obj->capacity)
        obj->head = 0;
    //����head % (k+1)
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
    //��Ϊ��βԪ����tail����һ���±�λ��
    //1 tail - 1 == -1
    //2 ��������
    if (obj->tail - 1 == -1)
        return obj->data[obj->capacity - 1];
    else
        return obj->data[obj->tail - 1];

}

