int numOfStrings(vector<string>& patterns, string word) {
        int len = patterns.size();
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            if (word.find(patterns[i]) != string::npos)
                ++res;
        }
        
        return res;
    }