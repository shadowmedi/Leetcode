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
        //�ж��Ƿ�Ϊ���ַ���
        if (str.size() == 0)
            return 0;
        //��ʶ����
        int flag = 1;
        //�����һ���ַ��Ƿ�Ϸ�
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
            //�Ӻ���ǰ����(��������ӵ�re��)���������Ϸ�ֱ�ӷ���
            if (!isNum(str[end]))
                return 0;
            //ע����ַ�תΪ���֣�ͬʱ�����������ֵ��re���ظ���
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