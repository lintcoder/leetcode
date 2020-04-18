int numTeams(vector<int>& rating) {
        int len = rating.size();
        if (len < 3)
            return 0;
        
        int ct = 0;
        for (int i = 0; i < len-2; ++i)
        {
            for (int j = i+1; j < len-1; ++j)
            {
                bool flag = rating[i] < rating[j] ? true : false;
                for (int k = j+1; k < len; ++k)
                {
                    if (flag && rating[j] < rating[k])
                        ++ct;
                    else if (!flag && rating[j] > rating[k])
                        ++ct;
                }
            }
        }
        
        return ct;
    }