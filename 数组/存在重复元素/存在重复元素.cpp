//˼·һ������+����;
//˼·������ϣ��;

class Solution {
public:
    /*bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int slow = 0;
        int fast = 1;
        while(fast < nums.size())
        {
            if(nums[slow] == nums[fast])
                return true;
            slow++;
            fast++;
        }
        return false;
    }*/
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> s;
        for (auto x : nums)
        {
            if (s.insert(x).second == false)
                return true;
        }
        return false;
    }

};