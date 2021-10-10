vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int len = intervals.size();
        if (len == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        
        int pos[2] = {-1,-1};
        for (int i = 0; i < 2; ++i)
        {
            int j = 0;
            for (; j < len; ++j)
            {
                if (newInterval[i] <= intervals[j][1])
                {
                    pos[i] = j;
                    break;
                }
            }
            if (pos[i] == -1)
                pos[i] = len;
        }
        
        if (pos[0] == pos[1])
        {
            if (pos[0] == len || newInterval[1] < intervals[pos[0]][0])
            {
                res.reserve(len+1);
                for (int i = 0; i < pos[0]; ++i)
                    res.push_back(intervals[i]);
                res.push_back(newInterval);
                for (int i = pos[0]; i < len; ++i)
                    res.push_back(intervals[i]);
                return res;
            }
            else
            {
                intervals[pos[0]][0] = newInterval[0] < intervals[pos[0]][0] ? newInterval[0] : intervals[pos[0]][0];
                return intervals;
            }
        }
        else
        {
            for (int i = 0; i < pos[0]; ++i)
                res.push_back(intervals[i]);
            int lh = newInterval[0] < intervals[pos[0]][0] ? newInterval[0] : intervals[pos[0]][0];
            if (pos[1] == len || newInterval[1] < intervals[pos[1]][0])
            {
                res.push_back({lh, newInterval[1]});
                for (int i = pos[1]; i < len; ++i)
                    res.push_back(intervals[i]);
            }
            else
            {
                res.push_back({lh, intervals[pos[1]][1]});
                for (int i = pos[1]+1; i < len; ++i)
                    res.push_back(intervals[i]);
            }
            
            return res;
        }
    }