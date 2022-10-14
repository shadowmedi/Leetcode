#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//思路：
//1 非递增：a[i] >= a[i+1]; 非递减a[i] <= a[i+1]

//2 遍历序列
//若a[i] > a[i+1]，说明进入非递增序列，
// 此时，内部while(i < a.size()&& a[i] >= a[i+1])i++确定该排序子序列的范围，循环结束后，说明确定了一个排序子序列;

//a[i] < a[i+1]，说明进入非递减序列，
// 同理，在内部确定该排序子序列的范围

//a[i] == a[i+1]，这两个数一定在同一个序列中，但不确定在非递增还是非递减，所以只需继续遍历

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v;
    //考虑多开一个空间，保证v[i]与v[i+1]比较时不越界
    v.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    v[n] = 0;
    int i = 0;
    //计算排序子序列的数量
    int count = 0;
    while (i < n)
    {
        if (v[i] < v[i + 1])
        {
            //进入非递减序列
            while (i < n && v[i] <= v[i + 1])//i < n保证数组不越界
                i++;
            //退出:1 i == n-1;  2 v[i] > v[i+1]
            i++;
            count++;//前面的数为一组排序子序列

        }
        else if (v[i] > v[i + 1])
        {
            //进入非递增序列
            while (i < n && v[i] >= v[i + 1])//i < n保证数组不越界
                i++;
            //退出:1 i == n-1;  2 v[i] < v[i+1]
            i++;
            count++;//前面的数为一组排序子序列

        }
        else
        {
            //v[i] == v[i+1]
            //此时v[i]和v[i+1]一定为同一组
            i++;
        }
    }
    cout << count;
    return 0;
}