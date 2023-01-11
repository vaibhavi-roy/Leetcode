class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int mini = INT_MAX, mid = mini;
        for (auto maxi : nums)
        {
            if (maxi < mini)
            {
                mini = maxi;
            }
            else if (maxi > mini && maxi < mid)
            {
                mid = maxi;
            }
            else if (maxi > mid)
            {
                return 1;
            }
        }
        return 0;
    }
};