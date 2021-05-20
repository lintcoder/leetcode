int secondHighest(string s) {
        int len = s.size();
        if (len <= 1)
            return -1;
        
        int maxdigit = -1, sndmaxdigit = -1;
        for (int i = 0; i < len; ++i)
        {
            if (isdigit(s[i]))
            {
                int t = s[i]-'0';
                if (t > maxdigit)
                {
                    sndmaxdigit = maxdigit;
                    maxdigit = t;
                }
                else if (t < maxdigit && t > sndmaxdigit)
                    sndmaxdigit = t;
            }
        }
        
        return sndmaxdigit;
    }