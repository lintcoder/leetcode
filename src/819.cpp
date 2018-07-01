string mostCommonWord(string paragraph, vector<string>& banned) {
        int len = paragraph.size();
        if (len == 0)
            return "";
        int num = banned.size();
        
        const char* exclude = " !?',;.";
        map<string, int> mp;
        
        int index = paragraph.find_first_not_of(exclude);
        if (index == string::npos)
            return "";
        
        bool flag = false;
        while (index != string::npos && index < len)
        {
            int pos = paragraph.find_first_of(exclude, index);
            if (pos == string::npos)
            {
                flag = true;
                break;
            }
                
            string s = paragraph.substr(index, pos - index);
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (find(banned.begin(), banned.end(), s) == banned.end())
                mp[s]++;
            if (pos == len - 1)
                break;
            index = paragraph.find_first_not_of(exclude, pos+1);
        }
        if (flag)
        {
            string s = paragraph.substr(index);
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (find(banned.begin(), banned.end(), s) == banned.end())
                mp[s]++;
        }
        
        string res;
        int maxnum = 0;
        for (auto m : mp)
        {
            if (m.second > maxnum)
            {
                maxnum = m.second;
                res = m.first;
            }
        }
        
        return res;
    }