class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int res = 0, n = piles.size();
        sort(piles.begin(), piles.end());

        int j = n - 2;
        for (int i = 0; i < (n / 3); i++)
        {
            res += piles[j];
            j -= 2;
        }
        return res;
    }
};