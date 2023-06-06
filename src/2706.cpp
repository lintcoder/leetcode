int buyChoco(vector<int>& prices, int money) {
        int minprice1 = 101;
        int minprice2 = 101;
        int len = prices.size();

        for (int i = 0; i < len; ++i)
        {
            if (minprice1 == 101)
            {
                if (prices[i] < minprice1)
                    minprice1 = prices[i];
            }
            else if (prices[i] < minprice1)
            {
                minprice2 = minprice1;
                minprice1 = prices[i];
            }
            else if (prices[i] < minprice2)
            {
                minprice2 = prices[i];
            }
        }

        if (minprice1 + minprice2 <= money)
            return money - minprice1 - minprice2;
        else
            return money;
    }