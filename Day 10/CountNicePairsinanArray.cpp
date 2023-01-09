class Solution
{
public:
    int rev(int n)
    {
        int rev = 0;
        while (n)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i] - rev(nums[i]);
            mp[temp]++;
            res = (res + mp[temp] - 1) % 1000000007;
        }
        return res % 1000000007;
    }
};