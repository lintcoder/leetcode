int findJudge(int N, vector<vector<int>>& trust) {
        vector<list<int>> vec(N);
        int len = trust.size();
        for (int i = 0; i < len; ++i)
        {
            vec[trust[i][1]-1].push_back(trust[i][0]);
        }
        
        int judge = -1;
        int ct = 0;
        for (int i = 0; i < N; ++i)
            if (vec[i].size() == N-1)
            {
                judge = i+1;
                ++ct;
            }
        if (ct != 1)
            return -1;
        for (int i = 0; i < N; ++i)
        {
            if (i != judge-1 && vec[i].size() != 0)
            {
                for (auto iter = vec[i].begin(); iter != vec[i].end(); ++iter)
                {
                    if (*iter == judge)
                        return -1;
                }
            }
        }
        
        return judge;
    }