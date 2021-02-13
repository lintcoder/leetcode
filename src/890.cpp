vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len = pattern.size();
        map<char, vector<int>> mp;
        for (int i = 0; i < len; ++i)
        {
            mp[pattern[i]].push_back(i);
        }
        
        int sz = words.size();
        vector<string> res;
        for (int i = 0; i < sz; ++i)
        {
            int flag[26] = {0};
            auto last = mp.end();
            auto iter = mp.begin();
            for (; iter != last; ++iter)
            {
                vector<int>& vec = iter->second;
                int n = vec.size();
                if (flag[words[i][vec[0]]-'a']== 1)
                    break;
                int j = 1;
                for (j = 1; j < n; ++j)
                {
                    if (words[i][vec[0]] != words[i][vec[j]])
                        break;
                }
                if (j != n)
                    break;
                flag[words[i][vec[0]]-'a'] = 1;
            }
            
            if (iter == last)
                res.push_back(words[i]);
        }
        
        return res;
    }