#define _CRT_SECURE_NO_WARNINGS
typedef int STDataType;
#define InitialCapacity 5
typedef struct Stack
{
    STDataType* data;//栈开辟的动态空间
    int capacity;//容量
    int size;//已有的数据量
}Stack;

void StackInit(Stack* ps)//栈的初始化
{
    assert(ps);
    STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * InitialCapacity);
    assert(tmp);
    ps->data = tmp;
    ps->capacity = InitialCapacity;
    ps->size = 0;
}

bool StackEmpty(Stack* ps)//判断栈是否为空
{
    assert(ps);
    return ps->size == 0;
}

void StackPush(Stack* ps, STDataType x)//入栈
{
    assert(ps);
    if (ps->capacity == ps->size)//容量已满，需要扩容
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

void StackPop(Stack* ps)//出栈
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->size--;
}

STDataType StackTop(Stack* ps)//取栈顶元素
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->data[ps->size - 1];
}

int StackSize(Stack* ps)//栈的元素个数
{
    assert(ps);
    return ps->size;
}

//基本思路：
//1 用2个栈实现元素先进先出
//2 将元素入栈A，再把元素依次提出拷进栈B，会发现元素的顺序颠倒了
//例如 1 2 3 4入栈A, 4在栈顶
//此时依次出栈并入栈B，会按4 3 2 1的顺序入栈B,1在栈顶，此时出B栈的顺序就是 1 2 3 4
//栈B的数据一定是栈A数据倒过来的，倒过来就满足先进先出的顺序
//若我们入数据在栈A，出数据在栈B,就能实现先进先出
typedef struct
{
    Stack pushst;//用于入数据
    Stack popst;//用于出数据
} MyQueue;


MyQueue* myQueueCreate() //队列的初始化
{
    MyQueue* re = (MyQueue*)malloc(sizeof(MyQueue));
    assert(re);
    //把内部的两个栈初始化
    StackInit(&re->pushst);
    StackInit(&re->popst);
    return re;
}
bool myQueueEmpty(MyQueue* obj)//队列判空 
{
    assert(obj);
    //内部的两个栈同时为空，则队列为空
    return StackEmpty(&obj->popst) && StackEmpty(&obj->pushst);
}

void myQueuePush(MyQueue* obj, int x)//入队列 
{
    //将数据入pushst栈即可
    assert(obj);
    StackPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj)//出队列 
{
    assert(obj);
    assert(!myQueueEmpty(obj));
    if (StackEmpty(&obj->popst))
    {
        //obj->popst是专门用来出数据的，若无数据，就把pushst的数据出栈拷贝到popst
        //但两个栈数据倒过来，顺序就变反了
        //此时出popst的数据就是先进先出的顺序
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

int myQueuePeek(MyQueue* obj)//取队头数据 
{
    //即取popst的栈顶
    assert(obj);
    assert(!myQueueEmpty(obj));
    if (StackEmpty(&obj->popst))//若popst为空，先把数据倒过去
    {
        //将pushst的元素倒入
        while (!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst, StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }
    return StackTop(&obj->popst);
}



void myQueueFree(MyQueue* obj) //销毁队列
{
    assert(obj);
    free(obj->pushst.data);
    free(obj->popst.data);
    obj->pushst.data = NULL;
    obj->popst.data = NULL;
    free(obj);
}