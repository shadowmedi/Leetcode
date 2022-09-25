
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        //topk���⣬�ô��ѡ��

        //��nums���������β������ȼ�������
        priority_queue<int> pq;
        while (!nums.empty())
        {
            pq.push(nums.back());
            nums.pop_back();
        }
        //ȡ��k�����Ԫ�ؾ�ɾ(k-1)�ζѶ�Ԫ��
        while (--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};