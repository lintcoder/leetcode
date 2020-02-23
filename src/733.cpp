vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> flag(row, vector<int>(col, 0));
        vector<vector<int>> res(image);
        
        deque<pair<int, int>> dq;
        dq.push_back(make_pair(sr, sc));
        int color = image[sr][sc];
        
        int len = 1;
        while (len != 0)
        {
            for (int i = 0; i < len; ++i)
            {
                int m = dq[i].first, n = dq[i].second;
                res[m][n] = newColor;
                flag[m][n] = 1;
                if (m > 0 && flag[m-1][n] == 0 && image[m-1][n] == color)
                    dq.push_back(make_pair(m-1, n));
                if (m < row-1 && flag[m+1][n] == 0 && image[m+1][n] == color)
                    dq.push_back(make_pair(m+1, n));
                if (n > 0 && flag[m][n-1] == 0 && image[m][n-1] == color)
                    dq.push_back(make_pair(m, n-1));
                if (n < col-1 && flag[m][n+1] == 0 && image[m][n+1] == color)
                    dq.push_back(make_pair(m, n+1));
            }
            dq.erase(dq.begin(), dq.begin()+len);
            len = dq.size();
        }
        
        return res;
    }