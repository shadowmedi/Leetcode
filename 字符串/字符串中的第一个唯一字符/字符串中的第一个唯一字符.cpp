#define _CRT_SECURE_NO_WARNINGS
class Solution {
    //�ü��������˼·������������±꽨��ӳ���ϵ
public:
    int firstUniqChar(string s)
    {
        //ֻ��Сд��ĸ
        int arr[26] = { 0 };

        string::iterator it = s.begin();
        while (it != s.end())
        {
            //�ַ�'a'��������Ӧarr[0]��ֵ
            //'b'��Ӧarr[1]��ֵ���Դ�����
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