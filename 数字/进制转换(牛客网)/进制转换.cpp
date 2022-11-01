#include <iostream>
#include <stack>
using namespace std;
//基本思路：M%N M/N依次求转换成N进制数后每一位的数，依次入栈.
//注意 M <= 0 的情况
int main()
{
    int M = 0;
    int N = 0;
    cin >> M >> N;
    //注意负数
    int flag = 1;
    if (M < 0)
    {
        flag = -1;
        M = -M;
    }
    //用下标来访问进制数的每一位
    char arr[] = "0123456789ABCDEF";
    stack<char> st;
    if (M == 0)
        st.push('0');
    while (M)//M==0时说明转换后的数，他的每一位已经取完
    {
        //M%N M/N依次取每一位入栈
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
