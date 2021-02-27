vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();
        if (len == 1)
            return {0};
        
        vector<int> res(len, 0);
        if (k == 0)
            return res;
        if (k > 0)
        {
            int i = 0, j = 1;
            int sum = 0;
            for (; j <= k; ++j)
                sum += code[(i+j)%len];
            res[0] = sum;
            ++i;
            int last = (k+1)%len;
            while (i < len)
            {
                sum += code[last] - code[i];
                res[i] = sum;
                last = (last+1)%len;
                ++i;
            }
            return res;
        }
        else
        {
            int i = 0, j = 1;
            int sum = 0;
            for (; j <= -k; ++j)
                sum += code[(i-j+len)%len];
            res[0] = sum;
            ++i;
            int last = len+k;
            while (i < len)
            {
                sum += code[i-1] - code[last];
                res[i] = sum;
                last = (last+1)%len;
                ++i;
            }
            return res;
        }
    }