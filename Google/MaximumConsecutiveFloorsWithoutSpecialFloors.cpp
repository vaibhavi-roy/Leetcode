class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        int n = special.size();
        sort(special.begin(), special.end());
        int a = 0;
        int b = 0;
        a = (special[0] - bottom);
        b = (top - special[n - 1]);
        int res = max(a, b);
        for (int i = 1; i < n; i++)
        {
            res = max(res, special[i] - special[i - 1] - 1);
        }
        return res;
    }
};
;