int countGoodRectangles(vector<vector<int>>& rectangles) {
        int len = rectangles.size();
        int n = 0;
        int maxlen = 0;
        for (int i = 0; i < len; ++i)
        {
            int k = rectangles[i][0] < rectangles[i][1] ? rectangles[i][0] : rectangles[i][1];
            if (k > maxlen)
            {
                maxlen = k;
                n = 1;
            }
            else if (k == maxlen)
                ++n;
        }
        
        return n;
    }