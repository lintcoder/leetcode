int numSpecialEquivGroups(vector<string>& A) {
        int len = A.size();
        vector<vector<int>> vec(len, vector<int>(52, 0));
        for (int i = 0; i < len; ++i)
        {
            int sz = A[i].size();
            for (int j = 0; j < sz; ++j)
            {
                ++vec[i][j%2*26+A[i][j]-'a'];
            }
        }
        
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            for (int i = 0; i < 52; ++i)
            {
                if (a[i] == b[i])
                    continue;
                else if (a[i] < b[i])
                    return true;
                else
                    return false;
            }
            return false;
        };
        
        sort(vec.begin(), vec.end(), cmp);
        return unique(vec.begin(), vec.end()) - vec.begin();
    }