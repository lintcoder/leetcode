int maximumNumberOfStringPairs(vector<string>& words) {
        int len = words.size();
        int ct = 0;
        vector<int> flag(len, 0);

        for (int i = 0; i < len-1; ++i)
        {
            if (flag[i] == 1)
                continue;
            for (int j = i+1; j < len; ++j)
            {
                if (flag[i] == 0)
                {
                    if (words[i][0] == words[j][1] && words[i][1] == words[j][0])
                    {
                        ++ct;
                        flag[i] = 1;
                        flag[j] = 1;
                    }
                }
            }
        }

        return ct;
    }