bool isAlienSorted(vector<string>& words, string order) {
        int len = words.size();
        if (len == 1)
            return true;
        
        map<char, int> dict;
        for (int i = 0; i < 26; ++i)
            dict[order[i]] = i;
        
        auto cmp = [&](const string& a, const string& b) {
            if (a == b)
                return true;
            int sz1 = a.size();
            int sz2 = b.size();
            int lim = sz1 < sz2 ? sz1 : sz2;
            int i = 0;
            while (i < lim)
            {
                if (dict[a[i]] < dict[b[i]])
                    return true;
                else if (dict[a[i]] > dict[b[i]])
                    return false;
                else
                    ++i;
            }
            
            return sz1 <= sz2;
        };
        
        for (int i = 0; i < len-1; ++i)
        {
            if (!cmp(words[i], words[i+1]))
                return false;
        }
        
        return true;
    }