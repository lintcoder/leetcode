int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int len = points.size();
        if (len == 1)
            return 0;
        int a = points[0][0], b = points[0][1];
        int sum = 0;
        for (int i = 1; i < len; ++i)
        {
            int c = points[i][0], d = points[i][1];
            if (a == c && b != d)
                sum += abs(b-d);
            else if (a != c && b == d)
                sum += abs(a-c);
            else if (a != c && b != d)
            {
                int mindiff = abs(a-c) < abs(b-d) ? abs(a-c) : abs(b-d);
                int delta = abs(abs(a-c)-abs(b-d));
                sum += mindiff + delta;
            }
            a = c;
            b = d;
        }
        
        return sum;
    }