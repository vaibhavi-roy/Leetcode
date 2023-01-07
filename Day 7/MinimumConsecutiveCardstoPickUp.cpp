class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> mp;
        int res = INT_MAX, flag = 0;
        for (int i = 0; i < cards.size(); i++)
        {
            if (mp.count(cards[i]))
            {
                res = min(res, i - mp[cards[i]] + 1);
                flag = 1;
            }
            mp[cards[i]] = i;
        }
        return (flag == 0) ? -1 : res;
    }
};