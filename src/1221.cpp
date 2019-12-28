int balancedStringSplit(string s) {
        int len = s.size();
        if (len == 0)
            return 0;
        if (len == 2)
            return 1;
        
        int lct = 0, rct = 0;
        int i = 0;
        int ct = 0;
        while (i < len)
        {
            if (s[i] == 'L')
                ++lct;
            else
                ++rct;
            if (lct == rct)
            {
                ++ct;
                lct = 0;
                rct = 0;
            }
            ++i;
        }
        
        return ct;
    }