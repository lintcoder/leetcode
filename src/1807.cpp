string evaluate(string s, vector<vector<string>>& knowledge) {
        int len = knowledge.size();
        map<string, string> dict;
        for (int i = 0; i < len; ++i)
            dict.insert(make_pair(knowledge[i][0], knowledge[i][1]));
        
        stringstream ss;
        int sz = s.size();
        int i = 0;
        while (i < sz)
        {
            if (s[i] != '(')
            {
                ss << s[i];
                ++i;
            }
            else
            {
                string key;
                key.reserve(10);
                int j = i+1;
                while (j < sz && s[j] != ')')
                {
                    key.push_back(s[j]);
                    ++j;
                }
                if (dict.find(key) != dict.end())
                    ss << dict[key];
                else
                    ss << '?';
                i = j+1;
            }
        }
        
        return ss.str();
    }