   string maximumOddBinaryNumber(string s) {
        int len = s.size();
        string res(len, '0');

        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if(s[i] == '1')
                ++ct;
        }
        res[len-1] = '1';
        for (int i = 1; i < ct; ++i)
        {
            res[i-1] = '1';
        }

        return res;
    }