string digitSum(string s, int k) {
        int len = s.size();
        while (len > k)
        {
            int n = len/k;
            int j = 0, sum = 0, m = 0;
            for (int i = 0; i < n; ++i)
            {
                sum = 0;
                for (j = i*k; j < (i+1)*k; ++j)
                {
                    sum += s[j]-'0';
                }

                int lim = sum > 0 ? log10(sum) : 0;
                int idx = m+lim;
                int tmp = idx;
                while (lim >= 0)
                {
                    s[idx--] = sum%10+'0';
                    sum /= 10;
                    --lim;
                }
                m = tmp+1;
            }
            
            if (j < len)
            {
                sum = 0;
                for (int i = j; i < len; ++i)
                {
                    sum += s[i]-'0';
                }
                int lim = sum > 0 ? log10(sum) : 0;
                int idx = m+lim;
                int tmp = idx;
                while (lim >= 0)
                {
                    s[idx--] = sum%10+'0';
                    sum /= 10;
                    --lim;
                }
                m = tmp+1;
                len = m;
            }
            else
                len = m;
        }
        
        return s.substr(0,len);
    }