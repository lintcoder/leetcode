int maxIceCream(vector<int>& costs, int coins) {
        int len = costs.size();
        sort(costs.begin(), costs.end());
        
        int n = 0;
        int i = 0;
        while (i < len && coins > 0)
        {
            if (coins >= costs[i])
            {
                coins -= costs[i];
                ++i;
                ++n;
            }
            else
                break;
        }
        
        return n;
    }