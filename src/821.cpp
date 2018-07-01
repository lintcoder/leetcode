vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        vector<int> pos;
        int len = S.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (S[i] == C)
            {
                pos.push_back(i);
                ct++;
            }
        }
        
        int i = 0;
        int j = 0;
        while (i < len)
        {
            if (S[i] == C)
            {
                res.push_back(0);
                ++j;
            }
            else if (j == 0)
            {
                res.push_back(pos[j]-i);
            }
            else if (j < ct)
            {
                int p = pos[j]-i < i - pos[j-1] ? pos[j] - i : i - pos[j-1];
                res.push_back(p);
            }
            else
                res.push_back(i - pos[j-1]);
            ++i;
        }
        
        return res;
    }