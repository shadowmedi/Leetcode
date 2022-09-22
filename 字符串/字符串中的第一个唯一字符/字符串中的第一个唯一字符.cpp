#define _CRT_SECURE_NO_WARNINGS
class Solution {
    //用计数排序的思路，用新数组的下标建立映射关系
public:
    int firstUniqChar(string s)
    {
        //只有小写字母
        int arr[26] = { 0 };

        string::iterator it = s.begin();
        while (it != s.end())
        {
            //字符'a'的数量对应arr[0]的值
            //'b'对应arr[1]的值，以此类推
            ++arr[*it - 'a'];
            ++it;
        }
        it = s.begin();
        int re = 0;
        while (it != s.end())
        {
            if (arr[*it - 'a'] == 1)
                return re;
            ++re;
            ++it;
        }
        return -1;
    }
};