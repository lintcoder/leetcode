vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res(n*2);
        int len = target.size();
        int last = 0;
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            int tmp = target[i]-last-1;
            if (tmp == 0)
                res[ct++] = "Push";
            else
            {
                for (int j = 0; j < tmp; ++j)
                {
                    res[ct] = "Push";
                    res[ct+1] = "Pop";
                    ct += 2;
                }
                res[ct++] = "Push";
            }
            last = target[i];
        }
        
        res.resize(ct);
        return res;
    }