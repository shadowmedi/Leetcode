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

        //�Ȱ���������
        sort(standardVal.begin(), standardVal.end());


        //ÿ��ȡ��С����󣬺ʹ�СֵΪһ��,
        //ÿ�εĴ�Сֵ֮�;��Ƕ���ˮƽֵ����ܺ�
        for (int i = 0; i < n; i++)
        {
            //min = a[i]  max = a[3*n-2*i-1]  a[3*n-2*i-2]
            max += standardVal[3 * n - 2 * i - 2];
        }
        cout << max;
    }
    return 0;
}