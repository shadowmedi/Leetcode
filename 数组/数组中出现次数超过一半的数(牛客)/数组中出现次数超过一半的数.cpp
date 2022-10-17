class Solution {
public:
    //思路1 O(NlogN)：排序：
    //取中间的数，再遍历数组确定这个数的出现次数
    //因为若有数字出现次数超过数组长度的一半，那排序后中间的数就是那个数字.
    //因为可能不存在这样的数，所以要再遍历数字确认它的出现次数
    /*

    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        //如果数组为空或只有一个数单独处理
        if(numbers.empty())
            return 0;
        if(numbers.size() == 1)
            return numbers[0];

        //排序
        sort(numbers.begin(),numbers.end());

        //取中间的数
        int midNum = numbers[numbers.size()/2];

        //遍历数组，统计midNum的出现次数
        int count = 0;
        for(int i = 0; i < numbers.size();i++)
        {
            if(numbers[i] == midNum)
                count++;
        }

        //满足出现次数的条件就返回对应数字
        if(count > numbers.size()/2)
            return midNum;
        return 0;
    }

    */

    //思路二：抵消O(N)
    //把出现次数超过一半的目标数定义为 超半数，其它数为非超半数

    //先假设存在超半数
    //核心点在于：保证超半数与非超半数相消，非超半数也可能和非超半数相消，

    //如果存在超半数，最后剩下的一定是超半数.

    //最后还要遍历一遍数组，确定这个数是否满足条件
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        //数组为空和只有一个元素单独处理
        if (numbers.empty())
            return 0;
        if (numbers.size() == 1)
            return numbers[0];

        //假设存在超半数，result存放可能的结果，times存放result在前面的出现次数(进行抵消之后)
        int result = numbers[0];
        int times = 1;     //先把第一个数填上

        for (int i = 1; i < numbers.size(); i++)
        {
            if (times > 0)               //当前result在前面有出现次数
            {
                if (numbers[i] != result)//不相同就相互消去,当前的数i++就不管了,result在前面出现次数-1
                    times--;
                else                    //否则result在前面的出现次数+1
                    times++;
            }
            else if (times == 0)         //当前result在前面没有出现次数（由于不同数相消）
            {
                result = numbers[i];    //更新result和times
                times = 1;
            }
        }

        //数组内部相消后没有数字，一定不可能存在超半数
        if (times == 0) // 1 1 1 2 2 2
            return 0;

        //遍历数组，确定最后剩下的数result是否满足超半数的条件
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