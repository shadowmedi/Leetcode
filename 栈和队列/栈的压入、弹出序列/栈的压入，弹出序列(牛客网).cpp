class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        //辅助栈 模拟出栈过程
        stack<int> st;
        //标识出栈数组下标
        int i = 0;
        for (int x : pushV)
        {
            //将pushV依次入栈
            st.push(x);

            //若此时栈顶元素和要出栈的数相同，则出栈,同时判断 新的栈顶 是否要出栈
            while (!st.empty() && st.top() == popV[i])
            {
                st.pop();
                i++;
            }
        }
        //入栈 1 2 3 4 5
        //出栈 5 4 3 2 1
        //最后若栈中还有数据，依次出栈与popV中的顺序比对
        while (!st.empty())
        {
            if (st.top() == popV[i])
            {
                st.pop();
                i++;
            }
            else
                return false;
        }
        return true;

    }
};