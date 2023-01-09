class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        set<int> s;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                for (int sz = 0; i + sz < grid.size() && i - sz >= 0 && j + 2 * sz < grid[0].size(); ++sz)
                {
                    int x = i, y = j, r_sum = 0;
                    do
                        r_sum += grid[x++][y++];
                    while (x < i + sz);
                    if (sz > 0)
                    {
                        do
                            r_sum += grid[x--][y++];
                        while (y < j + 2 * sz);
                        do
                            r_sum += grid[x--][y--];
                        while (x > i - sz);
                        do
                            r_sum += grid[x++][y--];
                        while (x < i);
                    }
                    s.insert(r_sum);
                    if (s.size() > 3)
                        s.erase(begin(s));
                }
        return vector<int>(rbegin(s), rend(s));
    }
};