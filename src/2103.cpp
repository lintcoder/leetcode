int countPoints(string rings) {
        vector<vector<int>> flag{10, {0,0,0}};
        int len = rings.size();
        
        int i = 0;
        while (i < len)
        {
            int pos = rings[i+1]-'0';
            if (rings[i] == 'R')
                flag[pos][0] = 1;
            else if (rings[i] == 'G')
                flag[pos][1] = 1;
            else
                flag[pos][2] = 1;
            i += 2;
        }
        
        int ct = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (flag[i][0] == 1 && flag[i][1] == 1 && flag[i][2] == 1)
                ++ct;
        }
        
        return ct;
    }