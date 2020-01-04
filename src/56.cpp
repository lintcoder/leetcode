vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len <= 1)
            return move(intervals);
        
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>> res;
        int b = intervals[0][0], e = intervals[0][1];
        int i = 1;
        while (i < len)
        {
            if (intervals[i][0] > e)
            {
                res.push_back({b, e});
                b = intervals[i][0];
                e = intervals[i][1];
                ++i;
            }
            else
            {
                e = intervals[i][1] > e ? intervals[i][1] : e;
                ++i;
            }
        }
        res.push_back({b, e});
        
        return move(res);
    }