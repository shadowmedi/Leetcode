#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;
//˼·������cur��result�����ַ���

//�������������������ַ�
//�Ͱ����ִ��ŵ�cur

//�������������ַ���
//�Ƚ�cur��result���ַ����ȣ�������ַ�����result��ͬʱ��cur���

bool isNum(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
int main()
{
    string str;
    cin >> str;
    //��¼��ǰ�����ִ�
    string cur;

    //��¼������ִ� 
    string ret;

    //Ϊ�˷�ֹ��󼸸��ַ�ȫ�����֣�����'\0'���������ַ������԰ѱ�����ֹ�����޸�һ��
    for (int i = 0; i <= str.size(); i++)
    {

        if (isNum(str[i]))
        {
            //�����ǰ�ַ��������ַ�
            cur += str[i];
        }
        else
        {
            //�����ǰ�ַ����������ַ�

            //�Ƚ�ret��cur����������ִ��ŵ�ret

            /*if(ret.size() > cur.size())
                cur.clear();
            else if(cur.size() >= ret.size())
            {
                ret = cur;
                cur.clear();
            }*/
            if (cur.size() > ret.size())
                ret = cur;
            cur.clear();
        }
    }
    cout << ret;
    return 0;
}
