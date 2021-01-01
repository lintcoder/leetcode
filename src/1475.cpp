vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();
        vector<int> res(prices.begin(), prices.end());
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (prices[j] <= prices[i])
                {
                    res[i] = prices[i]-prices[j];
                    break;
                }
            }
        }
        
        return res;
    }