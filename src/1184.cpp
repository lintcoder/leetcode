int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int len = distance.size();
        if (len == 1 || start == destination)
            return 0;
        if (start > destination)
        {
            int t = start;
            start = destination;
            destination = t;
        }
        
        int dist = 0, sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += distance[i];
            if (i >= start && i < destination)
                dist += distance[i];
        }
        
        sum -= dist;
        return dist < sum ? dist : sum;
    }