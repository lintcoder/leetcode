int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        int time = 0;
        int bg = timeSeries[0], ed = timeSeries[0]+duration-1;
        int i = 1;
        while (i < len)
        {
            if (timeSeries[i] > ed)
            {
                time += ed-bg+1;
                bg = timeSeries[i];
                ed = timeSeries[i]+duration-1;
            }
            else
            {
                ed = timeSeries[i]+duration-1;
            }
            ++i;
        }
        
        time += ed-bg+1;
        
        return time;
    }