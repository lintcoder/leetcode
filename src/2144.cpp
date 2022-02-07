int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int len = cost.size();
        int costSum = 0;
        int i = len-1;
        while (i >= 0)
        {
            costSum += cost[i];
            --i;
            if (i < 0)
                break;
            costSum += cost[i];
            --i;
            if (i < 0)
                break;
            --i;
        }
        
        return costSum;
    }