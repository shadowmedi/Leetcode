#define _CRT_SECURE_NO_WARNINGS
//���1�������Ŷ��
//���2�������Ŷ��
//���3���������������Ų���ȫƥ��

/*bool isValid(char * s)
{
    int length = strlen(s);
    char* stack = (char*)malloc(sizeof(char)* length);//���ٶ���Ŀռ�������ջ���ջ
    int num = 0;//��¼����ռ����ջ��Ŀ
    for(int i = 0; i < length; i++)
    {
        if(*s == '(')//���������ţ�������Ӧ����������ջ
            stack[num++] = ')';
        else if(*s == '{')
            stack[num++] = '}';
        else if(*s == '[')
            stack[num++] = ']';
        else if(num == 0 || stack[num-1] != *s)
        {//���������ţ�1 ջ�������� 2 ջ��������!=�������� 3 ƥ��ɹ��������ų�ջ
            return false;
        }
        else
            num--;
        s++;
    }
    return num == 0;
}*/