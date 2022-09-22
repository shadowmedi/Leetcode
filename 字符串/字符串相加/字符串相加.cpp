#define _CRT_SECURE_NO_WARNINGS
class Solution {
    //ע���ַ������ֵĻ�ת 
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
        //��ʶ��λ,��ʼĬ��Ϊ0
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            //�ӵ�λ����λ��ʼ��ȡ���Ե�����
            size_t val1 = (end1 >= 0 ? num1[end1] - '0' : 0);
            size_t val2 = (end2 >= 0 ? num2[end2] - '0' : 0);
            //β����ӵ���(������λ)
            num3.push_back((val1 + val2 + next) % 10 + '0');
            //�жϽ����������Ƿ�Ҫ��λ
            next = ((val1 + val2 + next) > 9 ? 1 : 0);
            end1--;
            end2--;
        }
        //�����ܻ����н�λ����'1'+'9'
        if (next == 1)
            num3.push_back('1');
        //��������ַ���(��Ϊ�Ǵӵ�λ����λ��ʼβ��)
        reverse(num3);
        return num3;
    }
};