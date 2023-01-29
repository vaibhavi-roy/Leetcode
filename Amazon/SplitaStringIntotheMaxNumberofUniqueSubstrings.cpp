class Solution
{
public:
    unordered_set<string> st;
    int ans = INT_MIN;
    int maxUniqueSplit(string s)
    {
        int count = 0;
        fun(s, count);
        return ans;
    }
    void fun(string s, int count)
    {
        if (s.length() == 0)
        {
            ans = max(ans, count);
            return;
        }
        string first = "";
        string second = "";

        for (int i = 0; i < s.length(); i++)
        {
            first.push_back(s[i]);

            if (st.find(first) == st.end())
            {
                st.insert(first);
                second = s.substr(i + 1, s.length());
                fun(second, count + 1);
                st.erase(first);
            }
            else
            {
                continue;
            }
        }
    }
};