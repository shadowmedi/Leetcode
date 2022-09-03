#define _CRT_SECURE_NO_WARNINGS
//情况1：左括号多出
//情况2：右括号多出
//情况3：左括号与右括号不完全匹配

/*bool isValid(char * s)
{
    int length = strlen(s);
    char* stack = (char*)malloc(sizeof(char)* length);//开辟额外的空间用来入栈或出栈
    int num = 0;//记录额外空间的入栈数目
    for(int i = 0; i < length; i++)
    {
        if(*s == '(')//遇到左括号，将它对应的右括号入栈
            stack[num++] = ')';
        else if(*s == '{')
            stack[num++] = '}';
        else if(*s == '[')
            stack[num++] = ']';
        else if(num == 0 || stack[num-1] != *s)
        {//遇到右括号，1 栈里无数据 2 栈顶的括号!=该右括号 3 匹配成功，右括号出栈
            return false;
        }
        else
            num--;
        s++;
    }
    return num == 0;
}*/