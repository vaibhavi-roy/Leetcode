class Solution
{
public:
    vector<int> adj[200001];
    int vis[200001], dis[200001];
    int par[200001];
    int dp[200001];
    void dfs(int x, int p)
    {
        par[x] = p;
        for (int k : adj[x])
        {
            if (k != p)
            {
                dfs(k, x);
            }
        }
    }
    int solve(int x, int d, vector<int> &a, int p)
    {
        int ok = 0;
        int ans = -1e9;
        if (dis[x] != -1)
        {
            if (dis[x] < d)
            {
                ok = 0;
            }
            else if (dis[x] == d)
            {
                ok = a[x] / 2;
            }
            else
            {
                ok = a[x];
            }
        }
        else
        {
            ok = a[x];
        }

        int cur = -1e9;
        int check = 0;
        for (int j : adj[x])
        {
            if (j != p)
            {
                check = 1;
                solve(j, d + 1, a, x);
                cur = max(cur, dp[j]);
            }
        }
        if (!check)
        {
            cur = 0;
        }

        ok = ok + cur;
        cout << ok << " " << x << endl;
        ans = ok;
        return dp[x] = ans;
    }

    int mostProfitablePath(vector<vector<int>> &e, int bob, vector<int> &a)
    {
        for (vector<int> x : e)
        {
            int a1 = x[0];
            int b = x[1];
            adj[a1].push_back(b);
            adj[b].push_back(a1);
        }
        memset(dis, -1, sizeof(dis));
        memset(dp, -1, sizeof(dp));
        dfs(0, -1);
        vector<int> path;
        int ok = bob;
        while (ok != 0)
        {
            path.push_back(ok);
            ok = par[ok];
        }
        path.push_back(0);
        dis[bob] = 0;
        for (int i = 1; i < path.size(); i++)
        {
            dis[path[i]] = i;
        }
        int ans = solve(0, 0, a, -1);

        return ans;
    }
};