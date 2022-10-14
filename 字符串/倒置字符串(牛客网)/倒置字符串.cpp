#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//思路：
//1 将整体逆置
//2 定义begin 和 end指针，使[begin, end)为一个单词，逆置每个单词
//begin到字符串尾部时停止

int main()
{
    string str;
    getline(cin, str);

    //先将整体倒置
    reverse(str.begin(), str.end());

    //定义start,end两个指针，从头开始将每个单词逆置
    //要使[start,end)这个区间是个单词
    auto start = str.begin();
    auto end = str.begin();
    while (start != str.end())
    {
        //找到当前单词的结尾位置
        while (*end != ' ' && end != str.end())
        {
            end++;
        }

        //逆置当前单词
        reverse(start, end);

        //更新start和end
        if (end == str.end())//end指向'\0'
            start = end;
        else                //end的指向空格位置
            start = end + 1;
        end = start;
    }
    cout << str;

}
