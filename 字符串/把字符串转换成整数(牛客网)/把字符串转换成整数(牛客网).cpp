#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool isNum(char x)
    {
        if (x >= '0' && x <= '9')
            return true;
        return false;
    }
    int StrToInt(const string& str)
    {
        //判断是否为空字符串
        if (str.size() == 0)
            return 0;
        //标识正负
        int flag = 1;
        //处理第一个字符是否合法
        if (str[0] == '-')
            flag = -1;
        else if (str[0] == '+')
            flag = 1;
        else if (!isNum(str[0]))
            return 0;
        int end = str.size() - 1;
        int re = 0;
        int k = 1;
        while (end >= 1)
        {
            //从后往前遍历(方便把数加到re上)，遇到不合法直接返回
            if (!isNum(str[end]))
                return 0;
            //注意把字符转为数字，同时超过整形最大值后，re会变回负数
            re = re + (str[end] - '0') * k;
            if (re < 0)
                return flag * INT_MAX;
            k *= 10;
            end--;
        }
        if (str[0] == '-' || str[0] == '+')
            return re * flag;
        re = re + (str[0] - '0') * k;
        if (re < 0)
            return flag * INT_MAX;
        return re;
    }
};