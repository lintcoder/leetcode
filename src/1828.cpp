vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int plen = points.size();
        int qlen = queries.size();
        
        vector<int> r2(qlen, 0);
        for (int i = 0; i < qlen; ++i)
            r2[i] = queries[i][2]*queries[i][2];
        
        vector<int> res(qlen, 0);
        for (int i = 0; i < qlen; ++i)
        {
            int ct = 0;
            for (int j = 0; j < plen; ++j)
            {
                if (((queries[i][0]-points[j][0])*(queries[i][0]-points[j][0]) +
                    (queries[i][1]-points[j][1])*(queries[i][1]-points[j][1])) <= r2[i])
                    ++ct;
            }
            
            res[i] = ct;
        }
        
        return res;
    }