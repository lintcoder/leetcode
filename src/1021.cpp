string removeOuterParentheses(string S) {
        int len = S.size();
        if (len == 0 || len == 2)
            return "";
        
        int i = 0, last = 0;
        int left = 0, right = 0;
        string res("");
        while (i < len)
        {
            if (S[i] == '(')
                ++left;
            else
            {
                ++right;
                if (left == right)
                {
                    if (i - last + 1 > 2)
                        res.insert(res.end(), S.begin()+last+1, S.begin()+i);
                    last = i+1;
                }
            }
            ++i;
        }
        
        return res;
    }