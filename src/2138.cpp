vector<string> divideString(string s, int k, char fill) {
        int len = s.size();
        int n = (len+k-1)/k;
        int total = n*k;
        vector<string> res(n, string(k, ' '));
        int i = 0, j = 0, m = -1;
        while (i < len)
        {
            if (i%k == 0)
            {
                ++m;
                j = 0;
                res[m][j] = s[i];
            }
            else
            {
                res[m][j] = s[i];
            }
            ++i;
            ++j;
        }
        
        while (i < total)
        {
            res[m][j++] = fill;
            ++i;
        }
        
        return res;
    }