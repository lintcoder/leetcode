int heightChecker(vector<int>& heights) {
        int len = heights.size();
        vector<int> ori(heights);
        sort(heights.begin(), heights.end());
        
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (ori[i] != heights[i])
                ++ct;
        }
        
        return ct;
    }