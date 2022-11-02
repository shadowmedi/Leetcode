//思路：动态规划
//遍历数组，把以nums[i]结尾的最大子序列和存入数组arr中
//arr[i] = max(nums[i], nums[i]+arr[i-1])
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> arr;
        arr.resize(nums.size());
        int max = nums[0];//负责记录最大和
        arr[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            arr[i] = nums[i] > (nums[i] + arr[i - 1]) ? nums[i] : (nums[i] + arr[i - 1]);
            max = max > arr[i] ? max : arr[i];
        }
        return max;
    }
};