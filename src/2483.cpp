int bestClosingTime(string customers) {
        int len = customers.size();
        
        int minpenalty = 0;
        for (int i = 0; i < len; ++i)
        {
            if (customers[i] != 'N')
                ++minpenalty;
        }
        
        int penalty = minpenalty;
        int h = len;
        for (int i = len-1; i >= 0; --i)
        {
            if (customers[i] == 'Y')
                ++penalty;
            else
                --penalty;
            if (penalty <= minpenalty)
            {
                minpenalty = penalty;
                h = i;
            }
        }
        
        return h;
    }