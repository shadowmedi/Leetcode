
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        //topk问题，用大堆选数

        //将nums的数据依次插入优先级队列中
        priority_queue<int> pq;
        while (!nums.empty())
        {
            pq.push(nums.back());
            nums.pop_back();
        }
        //取第k个最大元素就删(k-1)次堆顶元素
        while (--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};