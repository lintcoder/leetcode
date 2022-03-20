int numSplits(string s) {
        int charNum1[26] = {0};
        int charNum2[26] = {0};
        int len = s.size(), ct = 0;
        for (int i = 0; i < len; ++i)
        {
            int idx = s[i]-'a';
            if (charNum1[idx] == 0)
            {
                ++ct;
            }
            charNum1[idx]++;
        }
        
        int n = 0, sum = 0;
        for (int i = 0; i < len; ++i)
        {
            int idx = s[i]-'a';
            if (charNum2[idx] == 0)
            {
                charNum2[idx] = 1;
                ++n;
            }
            if (charNum1[idx] > 0)
            {
                --charNum1[idx];
                if (charNum1[idx] == 0)
                    --ct;
            }
            
            if (n == ct)
                ++sum;
        }
        
        return sum;
    }