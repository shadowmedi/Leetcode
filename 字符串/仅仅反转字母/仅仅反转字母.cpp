class Solution {
public:
    //判断字符是否为字母
    bool isLetter(char x)
    {
        if ((x >= 'a' && x <= 'z')
            || (x >= 'A' && x <= 'Z'))
            return true;
        return false;
    }

    string reverseOnlyLetters(string s)
    {
        //定义左右指针同时向中间走，交换之前遇到非字母字符则++
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            //注意全是非字母的情况
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