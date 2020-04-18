vector<string> stringMatching(vector<string>& words) {
        int len = words.size();
        auto cmp = [](const string& a, const string& b) {
            return a.size() < b.size();
        };
        
        sort(words.begin(), words.end(), cmp);
        vector<string> res;
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        
        return res;
    }