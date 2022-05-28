int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int len = s.size();
        
        int i, ct = 0;
        int sum = 0;
        for (i = 0; i < k; ++i)
            sum = sum*10 + s[i]-'0';
        
        if (sum > 0 && num%sum == 0)
            ++ct;
        i = 0;
        int coef = pow(10, k-1);
        for (int j = k; j < len; ++j)
        {
            sum = (sum - (s[i]-'0')*coef)*10 + s[j]-'0';
            if (sum > 0 && num%sum == 0)
                ++ct;
            ++i;
        }
        
        return ct;
    }