double averageWaitingTime(vector<vector<int>>& customers) {
        int len = customers.size();
        double avgWaitTime = 0;
        int prefinishtime = 0;
        int i = 0;
        
        while (i < len)
        {
            avgWaitTime += customers[i][0] >= prefinishtime ? customers[i][1] : prefinishtime-customers[i][0]+customers[i][1];
            prefinishtime = customers[i][0] >= prefinishtime ? customers[i][0]+customers[i][1] : prefinishtime+customers[i][1];
            ++i;
        }
        
        return avgWaitTime / len;
    }