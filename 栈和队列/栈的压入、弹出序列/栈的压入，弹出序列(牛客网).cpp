class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        //����ջ ģ���ջ����
        stack<int> st;
        //��ʶ��ջ�����±�
        int i = 0;
        for (int x : pushV)
        {
            //��pushV������ջ
            st.push(x);

            //����ʱջ��Ԫ�غ�Ҫ��ջ������ͬ�����ջ,ͬʱ�ж� �µ�ջ�� �Ƿ�Ҫ��ջ
            while (!st.empty() && st.top() == popV[i])
            {
                st.pop();
                i++;
            }
        }
        //��ջ 1 2 3 4 5
        //��ջ 5 4 3 2 1
        //�����ջ�л������ݣ����γ�ջ��popV�е�˳��ȶ�
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