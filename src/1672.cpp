int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        if (row == 0)
            return 0;
        int col = accounts[0].size();
        int maxwealth = 0;
        for (int i = 0; i < row; ++i)
        {
            int wealth = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            if (wealth >maxwealth)
                maxwealth = wealth;
        }
        
        return maxwealth;
    }