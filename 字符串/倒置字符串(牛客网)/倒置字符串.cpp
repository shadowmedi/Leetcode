#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//˼·��
//1 ����������
//2 ����begin �� endָ�룬ʹ[begin, end)Ϊһ�����ʣ�����ÿ������
//begin���ַ���β��ʱֹͣ

int main()
{
    string str;
    getline(cin, str);

    //�Ƚ����嵹��
    reverse(str.begin(), str.end());

    //����start,end����ָ�룬��ͷ��ʼ��ÿ����������
    //Ҫʹ[start,end)��������Ǹ�����
    auto start = str.begin();
    auto end = str.begin();
    while (start != str.end())
    {
        //�ҵ���ǰ���ʵĽ�βλ��
        while (*end != ' ' && end != str.end())
        {
            end++;
        }

        //���õ�ǰ����
        reverse(start, end);

        //����start��end
        if (end == str.end())//endָ��'\0'
            start = end;
        else                //end��ָ��ո�λ��
            start = end + 1;
        end = start;
    }
    cout << str;

}
