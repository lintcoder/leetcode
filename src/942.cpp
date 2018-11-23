vector<int> diStringMatch(string S) {
        int len = S.size()+1;
        if (len <= 1)
            return {};
        
        vector<int> res(len, 0);
        int k = len-2;
        int i = len-1, j = 0;
        while (k >= 0)
        {
            if (S[k] == 'I')
            {
                res[k+1] = i;
                --i;
            }
            else
            {
                res[k+1] = j;
                ++j;
            }
            --k;
        }
        res[0] = i;
        
        return res;
    }