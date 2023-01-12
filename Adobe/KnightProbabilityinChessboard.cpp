class Solution
{
public:
    double dp[26][26][101];

    double func(int i, int j, int curr, int mx, int n)
    {
        if (i >= n || j >= n || i < 0 || j < 0)
        {
            return 0.0;
        }
        if (curr >= mx)
        {
            return 1.0;
        }
        if (dp[i][j][curr])
        {
            return dp[i][j][curr];
        }
        double ans = 0.0;

        ans = func(i + 1, j + 2, curr + 1, mx, n) +

              func(i + 1, j - 2, curr + 1, mx, n) +

              func(i - 1, j - 2, curr + 1, mx, n) +

              func(i - 1, j + 2, curr + 1, mx, n) +

              func(i + 2, j - 1, curr + 1, mx, n) +

              func(i + 2, j + 1, curr + 1, mx, n) +

              func(i - 2, j + 1, curr + 1, mx, n) +

              func(i - 2, j - 1, curr + 1, mx, n);

        ans = ans / 8.0;
        dp[i][j][curr] = ans;
        return ans;
    }
    double knightProbability(int n, int k, int i, int j)
    {

        for (int a = 0; a <= 25; a++)
        {
            for (int b = 0; b <= 25; b++)
            {
                for (int c = 0; c <= 100; c++)
                {
                    dp[a][b][c] = 0.0;
                }
            }
        }
        return func(i, j, 0, k, n);
    }
};