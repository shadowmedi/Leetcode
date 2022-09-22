#define _CRT_SECURE_NO_WARNINGS
class Solution {
    //注意字符与数字的互转 
public:
    void reverse(string& num)
    {
        int begin = 0, end = num.size() - 1;
        while (begin < end)
        {
            swap(num[begin], num[end]);
            begin++;
            end--;
        }
    }
    string addStrings(string num1, string num2) {
        string num3;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        //标识进位,开始默认为0
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            //从低位到高位开始获取各自的数字
            size_t val1 = (end1 >= 0 ? num1[end1] - '0' : 0);
            size_t val2 = (end2 >= 0 ? num2[end2] - '0' : 0);
            //尾插相加的数(包括进位)
            num3.push_back((val1 + val2 + next) % 10 + '0');
            //判断接下来的数是否要进位
            next = ((val1 + val2 + next) > 9 ? 1 : 0);
            end1--;
            end2--;
        }
        //最后可能还会有进位，如'1'+'9'
        if (next == 1)
            num3.push_back('1');
        //最后逆置字符串(因为是从低位到高位开始尾插)
        reverse(num3);
        return num3;
    }
};