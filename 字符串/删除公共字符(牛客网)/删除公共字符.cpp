#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1, s2;
    //cin遇到空格或换行时就结束读取
    while (getline(cin, s1) && getline(cin, s2))
    {
        //遍历s2,将s2的字符出现次数通过下标记录到hash中
        int hash[256] = { 0 };
        for (int i = 0; i < s2.size(); i++)
        {
            //s2[i]的出现次数加1
            hash[s2[i]]++;
        }
        string ret;
        //遍历s1,将hash中未出现的字符,放到另一个string类型的变量中
        for (int i = 0; i < s1.size(); i++)
        {
            //如果s1[i]这个字符在hash的出现次数为0
            if (hash[s1[i]] == 0)
            {
                ret += s1[i];
            }
        }
        cout << ret;
    }
    return 0;
}
