int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len+1, 0);
        
        dp[0] = 0;
        dp[1] = 0;
        int i = 2;
        while (i <= len)
        {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
            ++i;
        }
        
        return dp[len];
    }