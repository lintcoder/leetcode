int minOperations(string s) {
        int len = s.size();
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i%2 == 0 && s[i] == '1')
                ++sum1;
            else if (i%2 == 1 && s[i] == '0')
                ++sum1;
        }
        
        for (int i = 0; i < len; ++i)
        {
            if (i%2 == 0 && s[i] == '0')
                ++sum2;
            else if (i%2 == 1 && s[i] == '1')
                ++sum2;
        }
        
        if (sum1 < sum2)
            return sum1;
        else
            return sum2;
    }