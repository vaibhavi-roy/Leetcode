class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        for (auto elem : barcodes)
        {
            freq[elem]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : freq)
        {
            pq.push({it.second, it.first});
        }
        int prev = -1;
        while (!pq.empty())
        {
            if (prev == pq.top().second)
            {
                pair<int, int> pair1 = pq.top();
                pq.pop();
                pair<int, int> pair2 = pq.top();
                result.push_back(pair2.second);
                pq.pop();
                pair2.first--;
                if (pair2.first > 0)
                {
                    pq.push({pair2.first, pair2.second});
                }
                pq.push(pair1);
                prev = pair2.second;
            }
            else
            {
                pair<int, int> pair1 = pq.top();
                pq.pop();
                prev = pair1.second;
                result.push_back(pair1.second);
                pair1.first--;
                if (pair1.first > 0)
                {
                    pq.push({pair1.first, pair1.second});
                }
            }
        }
        return result;
    }
};