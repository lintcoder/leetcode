int minCostToMoveChips(vector<int>& chips) {
        int len = chips.size();
        if (len == 1)
            return 0;
        
        int minval = 100;
        for (int i = 0; i <len; ++i)
        {
            int t = 0;
            for (int j = 0; j < len; ++j)
            {
                if (j != i)
                {
                    t += abs(chips[i]-chips[j])%2;
                }
            }
            if (t < minval)
                minval = t;
        }
        
        return minval;
    }