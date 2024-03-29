int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        for (int i = len-2; i >= 0; --i)
        {
            for (int j = 0; j < i+1; ++j)
            {
                triangle[i][j] = triangle[i+1][j]<triangle[i+1][j+1] ? triangle[i][j]+triangle[i+1][j] : triangle[i][j]+triangle[i+1][j+1];
            }
        }
        
        return triangle[0][0];
    }