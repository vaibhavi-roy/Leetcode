class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        unordered_map<int, int> sublast;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] == 0)
                continue;

            if (sublast[nums[i] - 1] > 0)
            {
                mp[nums[i]]--;
                sublast[nums[i] - 1]--;
                sublast[nums[i]]++;
            }
            else if (mp[nums[i] + 1] > 0 && mp[nums[i] + 2] > 0)
            {
                mp[nums[i]]--;
                mp[nums[i] + 1]--;
                mp[nums[i] + 2]--;
                sublast[nums[i] + 2]++;
            }
            else
                return false;
        }
        return true;
    }
};