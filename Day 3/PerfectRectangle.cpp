class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int x1 = INT_MAX;
        int x2 = INT_MIN;
        int y1 = INT_MAX;
        int y2 = INT_MIN;

        set<pair<int, int>> set;
        long long area = 0;

        for (vector<int> rect : rectangles)
        {
            x1 = min(rect[0], x1);
            y1 = min(rect[1], y1);
            x2 = max(rect[2], x2);
            y2 = max(rect[3], y2);
            area += (long long)(rect[2] - rect[0]) * (rect[3] - rect[1]);

            pair<int, int> s1, s2, s3, s4;
            s1 = {rect[0], rect[1]};
            s2 = {rect[0], rect[3]};
            s3 = {rect[2], rect[3]};
            s4 = {rect[2], rect[1]};

            if (set.count(s1))
                set.erase(s1);
            else
                set.insert(s1);
            if (set.count(s2))
                set.erase(s2);
            else
                set.insert(s2);
            if (set.count(s3))
                set.erase(s3);
            else
                set.insert(s3);
            if (set.count(s4))
                set.erase(s4);
            else
                set.insert(s4);
        }

        if (set.count({x1, y1}) == 0 || set.count({x1, y2}) == 0 || set.count({x2, y1}) == 0 || set.count({x2, y2}) == 0 || set.size() != 4)
            return false;

        return area == (long long)(x2 - x1) * (y2 - y1);
    }
};