int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int sz = points.size();
        int** distance = new int* [sz];
        for (int i = 0; i != sz; ++i)
            distance[i] = new int[sz];
        for (int i = 0; i != sz; ++i)
        {
            for (int j = i; j != sz; ++j)
            {
                if (i == j)
                    distance[i][j] = 0;
                else 
                {
                    int dx = points[i].first - points[j].first;
                    int dy = points[i].second - points[j].second;
                    distance[j][i] = distance[i][j] = dx * dx + dy * dy;
                }
            }
            sort(distance[i], distance[i] + sz);
        }
        
        int sum = 0;
        for (int i = 0; i != sz; ++i)
        {
            int tmpdist = distance[i][0];
            int j = 1;
            int cnt = 1;
            while (j < sz)
            {
                if (distance[i][j] == tmpdist)
                    ++cnt;
                else
                {
                    if (cnt > 1)
                        sum += cnt * (cnt - 1);
                    tmpdist = distance[i][j];
                    cnt = 1;
                }
                ++j;
            }
            if (cnt > 1)
                sum += cnt * (cnt - 1);
        }

        for (int i = 0; i != sz; ++i)
            delete[] distance[i];
        delete[] distance;
        
        return sum;
    }