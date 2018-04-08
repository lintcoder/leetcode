int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int max = 0;
        if (len >= 2)
            max = domaxProfit(prices, 0, len - 1);
        return max;
    }
    
    int domaxProfit(vector<int>& prices, int p, int q)
    {
        if (p >= q - 1)
            return prices[q] > prices[p] ? prices[q] - prices[p] : 0;
        else
        {
            int mid = p / 2 + q / 2;
            int max1 = domaxProfit(prices, p, mid);
            int max2 = domaxProfit(prices, mid + 1, q);
            int submin = prices[p];
            int submax = 0;
            for (int i = p; i <= mid; ++i)
                if (prices[i] < submin)
                    submin = prices[i];
            for (int i = mid + 1; i <= q; ++i)
                if (prices[i] > submax)
                    submax = prices[i];
            int max3 = submax > submin ? submax - submin : 0;
            return max1 > max2 ? (max1 > max3 ? max1 : max3) : (max2 > max3 ? max2 : max3);
        }
    }