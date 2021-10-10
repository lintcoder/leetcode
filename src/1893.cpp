bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int len = ranges.size();
        if (len == 0)
            return false;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0] || (a[0]==b[0] && a[1] < b[1]));
        };
        sort(ranges.begin(), ranges.end(), cmp);
        
        int lh = left, rh = right;
        for (int i = 0; i < len; ++i)
        {
            if (lh >= ranges[i][0] && lh <= ranges[i][1])
            {
                if (rh <= ranges[i][1])
                    return true;
                else
                    lh = ranges[i][1]+1;
            }
            if (rh >= ranges[i][0] && rh <= ranges[i][1])
            {
                if (lh >= ranges[i][0])
                    return true;
                else
                    rh = ranges[i][0]-1;
            }
        }
        
        return false;
    }