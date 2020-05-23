int maxPower(string s) {
        int len = s.size();
        int maxmum = 1;
        
        char c = s[0];
        int i = 1, ct = 1;
        while (i < len)
        {
            if (s[i] == c)
                ++ct;
            else
            {
                if (ct > maxmum)
                    maxmum = ct;
                ct = 1;
                c = s[i];
            }
            
            ++i;
        }
        
        if (ct > maxmum)
            maxmum = ct;
        
        return maxmum;
    }