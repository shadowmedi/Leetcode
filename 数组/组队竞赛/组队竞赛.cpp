#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        long long max = 0;

        vector<int> standardVal;
        standardVal.resize(3 * n);
        for (int i = 0; i < standardVal.size(); i++)
        {
            cin >> standardVal[i];
        }

        //先把数据排序
        sort(standardVal.begin(), standardVal.end());


        //每次取最小，最大，和次小值为一组,
        //每次的次小值之和就是队伍水平值最大总和
        for (int i = 0; i < n; i++)
        {
            //min = a[i]  max = a[3*n-2*i-1]  a[3*n-2*i-2]
            max += standardVal[3 * n - 2 * i - 2];
        }
        cout << max;
    }
    return 0;
}