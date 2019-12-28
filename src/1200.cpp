vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());
        
        map<int, vector<int>> mp;
        int minval = 2e6;
        for (int i = 0; i < len-1; ++i)
        {
            int t = abs(arr[i+1]-arr[i]);
            if (t <= minval)
            {
                minval = t;
                mp[minval].push_back(i);
            }
        }
        
        int sz = mp[minval].size();
        vector<vector<int>> res(sz, vector<int>(2,0));
        for (int i = 0; i < sz; ++i)
        {
            res[i][0] = arr[mp[minval][i]];
            res[i][1] = arr[mp[minval][i]+1];
        }
        
        return res;
    }