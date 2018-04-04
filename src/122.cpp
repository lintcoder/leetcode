int maxProfit(vector<int>& prices) {
     int len = prices.size();
     if (len <= 1)
     	return 0;
     int pr = prices[0];
     int profit = 0;
     int i = 1;
     while (i < len)
     {
     	if (prices[i] <= pr)
        {
            pr = prices[i];
            ++i;
        }
     	else
     	{
     		while (i + 1 < len && prices[i + 1] >= prices[i])
     			++i;
     		profit += prices[i]-pr;
     		if (i >= len - 2)
     			break;
     		else
     		{
     			pr = prices[i + 1];
     			i += 2;
     		}
     	}
     }

     return profit;  
    }