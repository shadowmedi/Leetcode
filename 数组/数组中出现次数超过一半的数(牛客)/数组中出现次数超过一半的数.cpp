class Solution {
public:
    //˼·1 O(NlogN)������
    //ȡ�м�������ٱ�������ȷ��������ĳ��ִ���
    //��Ϊ�������ֳ��ִ����������鳤�ȵ�һ�룬��������м���������Ǹ�����.
    //��Ϊ���ܲ�������������������Ҫ�ٱ�������ȷ�����ĳ��ִ���
    /*

    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        //�������Ϊ�ջ�ֻ��һ������������
        if(numbers.empty())
            return 0;
        if(numbers.size() == 1)
            return numbers[0];

        //����
        sort(numbers.begin(),numbers.end());

        //ȡ�м����
        int midNum = numbers[numbers.size()/2];

        //�������飬ͳ��midNum�ĳ��ִ���
        int count = 0;
        for(int i = 0; i < numbers.size();i++)
        {
            if(numbers[i] == midNum)
                count++;
        }

        //������ִ����������ͷ��ض�Ӧ����
        if(count > numbers.size()/2)
            return midNum;
        return 0;
    }

    */

    //˼·��������O(N)
    //�ѳ��ִ�������һ���Ŀ��������Ϊ ��������������Ϊ�ǳ�����

    //�ȼ�����ڳ�����
    //���ĵ����ڣ���֤��������ǳ������������ǳ�����Ҳ���ܺͷǳ�����������

    //������ڳ����������ʣ�µ�һ���ǳ�����.

    //���Ҫ����һ�����飬ȷ��������Ƿ���������
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        //����Ϊ�պ�ֻ��һ��Ԫ�ص�������
        if (numbers.empty())
            return 0;
        if (numbers.size() == 1)
            return numbers[0];

        //������ڳ�������result��ſ��ܵĽ����times���result��ǰ��ĳ��ִ���(���е���֮��)
        int result = numbers[0];
        int times = 1;     //�Ȱѵ�һ��������

        for (int i = 1; i < numbers.size(); i++)
        {
            if (times > 0)               //��ǰresult��ǰ���г��ִ���
            {
                if (numbers[i] != result)//����ͬ���໥��ȥ,��ǰ����i++�Ͳ�����,result��ǰ����ִ���-1
                    times--;
                else                    //����result��ǰ��ĳ��ִ���+1
                    times++;
            }
            else if (times == 0)         //��ǰresult��ǰ��û�г��ִ��������ڲ�ͬ��������
            {
                result = numbers[i];    //����result��times
                times = 1;
            }
        }

        //�����ڲ�������û�����֣�һ�������ܴ��ڳ�����
        if (times == 0) // 1 1 1 2 2 2
            return 0;

        //�������飬ȷ�����ʣ�µ���result�Ƿ����㳬����������
        int count = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == result)
                count++;
        }
        if (count > numbers.size() / 2)
            return result;
        return 0;
    }
};