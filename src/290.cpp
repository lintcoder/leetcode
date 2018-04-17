bool wordPattern(string pattern, string str) {
        vector<string> bijection(26, "");
        set<string> stjection;
        int sz = pattern.size();
        
        if (sz == 0)
            return false;
        char c;
        int index = 0, pos = 0;
        for (int i = 0; i != sz; ++i)
        {
            c = pattern[i];
            if (i < sz - 1)
                pos = str.find(' ', index);
            else
                pos = sz;
            if (pos == -1)
                return false;
            else
            {
                string s = str.substr(index, pos - index);
                string bi = bijection[c - 'a'];
                if (bi != "")
                {
                    if (bi != s)
                        return false;
                }
                else
                {
                    if (stjection.find(s) != stjection.end())
                        return false;
                    bijection[c - 'a'] = s;
                    stjection.insert(s);
                }
            }
            index = pos + 1;
        }
        
        return true;
    }