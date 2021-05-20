string sortSentence(string s) {
        int len = s.size();
        vector<vector<int>> pos(9, vector<int>(2, -1));
        
        int i = 0;
        int lh = 0, rh = 0;
        int ct = 0;
        while (i < len)
        {
            while (i < len && s[i] != ' ')
                ++i;
            rh = i-2;
            pos[s[i-1]-'0'-1][0] = lh;
            pos[s[i-1]-'0'-1][1] = rh;
            ct += rh-lh+2;
            if (i == len)
            {
                --ct;
                break;
            }
            lh = i+1;
            ++i;
        }
        
        string res(ct, ' ');
        int k = 0;
        for (int i = 0; i < 9; ++i)
        {
            if (pos[i][0] == -1)
                break;
            for (int j = pos[i][0]; j <= pos[i][1]; ++j)
                res[k++] = s[j];
            if (k < ct)
                res[k++] = ' ';
        }
        
        return res;
    }