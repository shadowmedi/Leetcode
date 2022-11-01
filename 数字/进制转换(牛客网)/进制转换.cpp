#include <iostream>
#include <stack>
using namespace std;
//����˼·��M%N M/N������ת����N��������ÿһλ������������ջ.
//ע�� M <= 0 �����
int main()
{
    int M = 0;
    int N = 0;
    cin >> M >> N;
    //ע�⸺��
    int flag = 1;
    if (M < 0)
    {
        flag = -1;
        M = -M;
    }
    //���±������ʽ�������ÿһλ
    char arr[] = "0123456789ABCDEF";
    stack<char> st;
    if (M == 0)
        st.push('0');
    while (M)//M==0ʱ˵��ת�������������ÿһλ�Ѿ�ȡ��
    {
        //M%N M/N����ȡÿһλ��ջ
        st.push(arr[M % N]);
        M /= N;
    }
    if (flag == -1)
        st.push('-');
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}
