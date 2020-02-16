vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int len = queries.size();
        int sz = words.size();
        
        vector<int> res(len, 0);
        vector<int> freq(sz, 0);
        for (int i = 0; i < sz; ++i)
            freq[i] = calFreq(words[i]);
        sort(freq.begin(), freq.end());
        
        for (int i = 0; i < len; ++i)
        {
            int t = calFreq(queries[i]);
            auto iter = upper_bound(freq.begin(), freq.end(), t);
            res[i] = freq.end() - iter;
        }
        
        return res;
    }
    
    int calFreq(const string& str)
    {
        int len = str.size();
        int ct = 1;
        char minval = str[0];
        for (int i = 1; i < len; ++i)
        {
            if (str[i] < minval)
            {
                minval = str[i];
                ct = 1;
            }
            else if (str[i] == minval)
            {
                ++ct;
            }
        }
        
        return ct;
    }