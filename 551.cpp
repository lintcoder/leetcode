bool checkRecord(string s) {
        size_t len = s.size();
        if (len <= 1)
            return true;
        
        int num_A = 0, num_L = 0;
        char status = s[0];
        if (status == 'A')
            num_A++;
        else if (status == 'L')
            num_L++;
        size_t i = 1;
        while (i < len)
        {
            if (s[i] == 'P')
            {
                status = s[i];
                num_L = 0;
            }
            else if (s[i] == 'A')
            {
                if (num_A == 1)
                    return false;
                num_A = 1;
                num_L = 0;
                status = s[i];
            }
            else
            {
                if (num_L == 2)
                    return false;
                num_L++;
                status = s[i];
            }
            i++;
        }
        
        return true;
    }