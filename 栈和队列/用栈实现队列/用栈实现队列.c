#define _CRT_SECURE_NO_WARNINGS
typedef int STDataType;
#define InitialCapacity 5
typedef struct Stack
{
    STDataType* data;//ջ���ٵĶ�̬�ռ�
    int capacity;//����
    int size;//���е�������
}Stack;

void StackInit(Stack* ps)//ջ�ĳ�ʼ��
{
    assert(ps);
    STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * InitialCapacity);
    assert(tmp);
    ps->data = tmp;
    ps->capacity = InitialCapacity;
    ps->size = 0;
}

bool StackEmpty(Stack* ps)//�ж�ջ�Ƿ�Ϊ��
{
    assert(ps);
    return ps->size == 0;
}

void StackPush(Stack* ps, STDataType x)//��ջ
{
    assert(ps);
    if (ps->capacity == ps->size)//������������Ҫ����
    {
        int newCapacity = ps->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * newCapacity);
        assert(tmp);
        ps->data = tmp;
        ps->capacity *= 2;
    }
    ps->data[ps->size] = x;
    ps->size++;
}

void StackPop(Stack* ps)//��ջ
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->size--;
}

STDataType StackTop(Stack* ps)//ȡջ��Ԫ��
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->data[ps->size - 1];
}

int StackSize(Stack* ps)//ջ��Ԫ�ظ���
{
    assert(ps);
    return ps->size;
}

//����˼·��
//1 ��2��ջʵ��Ԫ���Ƚ��ȳ�
//2 ��Ԫ����ջA���ٰ�Ԫ�������������ջB���ᷢ��Ԫ�ص�˳��ߵ���
//���� 1 2 3 4��ջA, 4��ջ��
//��ʱ���γ�ջ����ջB���ᰴ4 3 2 1��˳����ջB,1��ջ������ʱ��Bջ��˳����� 1 2 3 4
//ջB������һ����ջA���ݵ������ģ��������������Ƚ��ȳ���˳��
//��������������ջA����������ջB,����ʵ���Ƚ��ȳ�
typedef struct
{
    Stack pushst;//����������
    Stack popst;//���ڳ�����
} MyQueue;


MyQueue* myQueueCreate() //���еĳ�ʼ��
{
    MyQueue* re = (MyQueue*)malloc(sizeof(MyQueue));
    assert(re);
    //���ڲ�������ջ��ʼ��
    StackInit(&re->pushst);
    StackInit(&re->popst);
    return re;
}
bool myQueueEmpty(MyQueue* obj)//�����п� 
{
    assert(obj);
    //�ڲ�������ջͬʱΪ�գ������Ϊ��
    return StackEmpty(&obj->popst) && StackEmpty(&obj->pushst);
}

void myQueuePush(MyQueue* obj, int x)//����� 
{
    //��������pushstջ����
    assert(obj);
    StackPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj)//������ 
{
    assert(obj);
    assert(!myQueueEmpty(obj));
    if (StackEmpty(&obj->popst))
    {
        //obj->popst��ר�����������ݵģ��������ݣ��Ͱ�pushst�����ݳ�ջ������popst
        //������ջ���ݵ�������˳��ͱ䷴��
        //��ʱ��popst�����ݾ����Ƚ��ȳ���˳��
        while (!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst, StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }
    int re = StackTop(&obj->popst);
    StackPop(&obj->popst);
    return re;
}

int myQueuePeek(MyQueue* obj)//ȡ��ͷ���� 
{
    //��ȡpopst��ջ��
    assert(obj);
    assert(!myQueueEmpty(obj));
    if (StackEmpty(&obj->popst))//��popstΪ�գ��Ȱ����ݵ���ȥ
    {
        //��pushst��Ԫ�ص���
        while (!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst, StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }
    return StackTop(&obj->popst);
}



void myQueueFree(MyQueue* obj) //���ٶ���
{
    assert(obj);
    free(obj->pushst.data);
    free(obj->popst.data);
    obj->pushst.data = NULL;
    obj->popst.data = NULL;
    free(obj);
}