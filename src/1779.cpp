int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int len = points.size();
        int minv = numeric_limits<int>::max();
        int pos = -1;
        
        for (int i = 0; i < len; ++i)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int dist = abs(x-points[i][0]) + abs(y-points[i][1]);
                if (dist == 0)
                    return i;
                else if (dist < minv)
                {
                    minv = dist;
                    pos = i;
                }
            }
        }
        
        return pos;
    }