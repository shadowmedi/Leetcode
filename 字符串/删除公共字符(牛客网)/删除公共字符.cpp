#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1, s2;
    //cin�����ո����ʱ�ͽ�����ȡ
    while (getline(cin, s1) && getline(cin, s2))
    {
        //����s2,��s2���ַ����ִ���ͨ���±��¼��hash��
        int hash[256] = { 0 };
        for (int i = 0; i < s2.size(); i++)
        {
            //s2[i]�ĳ��ִ�����1
            hash[s2[i]]++;
        }
        string ret;
        //����s1,��hash��δ���ֵ��ַ�,�ŵ���һ��string���͵ı�����
        for (int i = 0; i < s1.size(); i++)
        {
            //���s1[i]����ַ���hash�ĳ��ִ���Ϊ0
            if (hash[s1[i]] == 0)
            {
                ret += s1[i];
            }
        }
        cout << ret;
    }
    return 0;
}
