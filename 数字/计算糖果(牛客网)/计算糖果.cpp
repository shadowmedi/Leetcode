#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //B要同时满足4个表达式，要判断B1 == B2,若不成立则不存在这样的整数
    int A = (a + c) / 2;
    int C = (d - b) / 2;
    int B1 = (c - a) / 2;
    int B2 = (b + d) / 2;
    if (B1 != B2)
    {
        cout << "No";
    }
    else
    {
        cout << A << " " << B1 << " " << C;
    }
    return 0;
}