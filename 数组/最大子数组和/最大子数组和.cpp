//˼·����̬�滮
//�������飬����nums[i]��β����������кʹ�������arr��
//arr[i] = max(nums[i], nums[i]+arr[i-1])
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> arr;
        arr.resize(nums.size());
        int max = nums[0];//�����¼����
        arr[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            arr[i] = nums[i] > (nums[i] + arr[i - 1]) ? nums[i] : (nums[i] + arr[i - 1]);
            max = max > arr[i] ? max : arr[i];
        }
        return max;
    }
};