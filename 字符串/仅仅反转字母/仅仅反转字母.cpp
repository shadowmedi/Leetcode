class Solution {
public:
    //�ж��ַ��Ƿ�Ϊ��ĸ
    bool isLetter(char x)
    {
        if ((x >= 'a' && x <= 'z')
            || (x >= 'A' && x <= 'Z'))
            return true;
        return false;
    }

    string reverseOnlyLetters(string s)
    {
        //��������ָ��ͬʱ���м��ߣ�����֮ǰ��������ĸ�ַ���++
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            //ע��ȫ�Ƿ���ĸ�����
            while (left < right && !isLetter(s[left]))
            {
                left++;
            }
            while (left < right && !isLetter(s[right]))
            {
                right--;
            }
            if (left < right)
                swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;

    }
};