int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int sum = 0;
        int len = status.size();
        vector<int> flag(len, 0);
        
        deque<int> dq(initialBoxes.begin(), initialBoxes.end());
        int sz = dq.size();
        while (sz > 0)
        {
            int i = 0;
            for (i = 0; i < sz; ++i)
                if (status[dq[i]] == 1 && flag[dq[i]] == 0)
                    break;
            if (i == sz)
                break;
            
            int n = dq[i];
            dq.erase(dq.begin()+i);
            
            flag[n] = 1;
            sum += candies[n];
            
            int l = keys[n].size();
            for (int j = 0; j < l; ++j)
                status[keys[n][j]] = 1;
            l = containedBoxes[n].size();
            for (int j = 0; j < l; ++j)
                dq.push_back(containedBoxes[n][j]);
            sz = dq.size();
        }
        
        return sum;
    }