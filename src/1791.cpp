int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        
        if (c == a || c == b)
            return c;
        else
            return d;
    }