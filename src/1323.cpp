int maximum69Number (int num) {
        string s = to_string(num);
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i)
            if (s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        
        for (int i = 0; i < len; ++i)
            res = res*10 + (s[i]-'0');
        
        return res;
    }
