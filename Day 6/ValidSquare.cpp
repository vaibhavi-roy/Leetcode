class Solution
{
public:
    double distance(vector<int> v1, vector<int> v2)
    {
        return (((v2[0] - v1[0]) * (v2[0] - v1[0])) + ((v2[1] - v1[1]) * (v2[1] - v1[1])));
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> pts = {p1, p2, p3, p4};
        set<double> st;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                double val = distance(pts[i], pts[j]);
                if (val != 0)
                    st.insert(val);
                else
                    return false;
            }
        }
        return (st.size() == 2);
    }
};