class Solution
{
public:
    vector<vector<int>> dp;
    vector<int> res;
    int recur(int cap, vector<int> &aliceArrows, int ind)
    {
        if (ind == 0 || cap == 0)
            return 0;
        int put = 0;
        if (dp[ind][cap] != -1)
        {
            return dp[ind][cap];
        }

        if (cap > aliceArrows[ind - 1])
        {
            put =
                ind - 1 + recur(cap - aliceArrows[ind - 1] - 1, aliceArrows, ind - 1);
        }
        int nput = recur(cap, aliceArrows, ind - 1);
        return dp[ind][cap] = max(put, nput);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        int bobTotalArrow = numArrows;
        res.clear();
        res.resize(12, 0);

        dp.clear();
        dp.resize(13, vector<int>(bobTotalArrow + 1, -1));

        recur(bobTotalArrow, aliceArrows, 12);
        int result = dp[12][bobTotalArrow];
        int total = 0;
        for (int i = 12, j = bobTotalArrow; i > 0 && result > 0; i--)
        {
            if (result == dp[i - 1][j])
                continue;
            else
            {
                res[i - 1] = aliceArrows[i - 1] + 1;
                result -= (i - 1);
                j -= (aliceArrows[i - 1] + 1);
                total += aliceArrows[i - 1] + 1;
            }
        }
        if (total < bobTotalArrow)
        {
            res[0] = bobTotalArrow - total;
        }
        return res;
    }
};