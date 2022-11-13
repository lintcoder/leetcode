string oddString(vector<string>& words) {
        int len = words.size();
        int n = words[0].size();
        int i = 0;
        
        vector<vector<int>> diffarr(2, vector<int>(n, 0));
        for (i = 0; i < 2; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                diffarr[i][j-1] = (int)words[i][j] - (int)words[i][j-1];
            }
        }
        
        bool flag = false;
        int pos = 0;
        for (i = 0; i < n-1; ++i)
        {
            if (diffarr[0][i] != diffarr[1][i])
            {
                flag = true;
                break;
            }
        }
        
        if (flag)
        {
            for (int j = 1; j < n; ++j)
            {
                int tmp = (int)words[2][j] - (int)words[2][j-1];
                if (tmp != diffarr[0][j-1])
                {
                    pos = 0;
                    break;
                }
                if (tmp != diffarr[1][j-1])
                {
                    pos = 1;
                    break;
                }
            }
            
            return words[pos];
        }
        else
        {
            for (i = 2; i < len; ++i)
            {
                for (int j = 1; j < n; ++j)
                {
                    int tmp = (int)words[i][j] - (int)words[i][j-1];
                    if (tmp != diffarr[0][j-1])
                    {
                        pos = i;
                        i = len;
                        break;
                    }
                }
            }
            
            return words[pos];
        }
    }