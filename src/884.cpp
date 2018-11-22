vector<string> uncommonFromSentences(string A, string B) {
        int len1 = A.size();
        int len2 = B.size();
        if (len1 == 0 && len2 == 0)
            return {};
        
        map<string, int> mp;
        string::size_type i = A.find_first_not_of(" ");
        while (i != string::npos)
        {
            string::size_type pos = A.find(' ', i);
            if (pos != string::npos)
            {
                mp[A.substr(i, pos-i)]++;
                i = A.find_first_not_of(" ", pos+1);
            }
            else
            {
                mp[A.substr(i)]++;
                break;
            }
        }
        
        i = B.find_first_not_of(" ");
        while (i != string::npos)
        {
            string::size_type pos = B.find(' ', i);
            if (pos != string::npos)
            {
                mp[B.substr(i, pos-i)]++;
                i = B.find_first_not_of(" ", pos+1);
            }
            else
            {
                mp[B.substr(i)]++;
                break;
            }
        }
        
        vector<string> res;
        for (auto& m : mp)
        {
            if (m.second == 1)
                res.push_back(m.first);
        }
        
        return res;
    }