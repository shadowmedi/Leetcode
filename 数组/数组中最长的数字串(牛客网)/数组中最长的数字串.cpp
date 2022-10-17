#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;
//思路：定义cur和result两个字符串

//若遍历到连续的数字字符
//就把数字串放到cur

//若遍历到其它字符，
//比较cur和result的字符长度，把最长的字符串给result，同时把cur清空

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
    //记录当前的数字串
    string cur;

    //记录最长的数字串 
    string ret;

    //为了防止最后几个字符全是数字，由于'\0'不是数字字符，可以把遍历终止条件修改一下
    for (int i = 0; i <= str.size(); i++)
    {

        if (isNum(str[i]))
        {
            //如果当前字符是数字字符
            cur += str[i];
        }
        else
        {
            //如果当前字符不是数字字符

            //比较ret和cur，把最长的数字串放到ret

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
