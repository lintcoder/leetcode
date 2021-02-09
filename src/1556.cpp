string thousandSeparator(int n) {
        string s = to_string(n);
        int len = s.size();
        int m = len +(len-1)/3;
        string res(m, ' ');
        int i = 0, j = m-1;
        while (i < len)
        {
            res[j] = s[len-1-i];
            --j;
            ++i;
            if (j >= 0 && i%3 == 0)
                res[j--] = '.';
        }
        
        return res;
    }