bool checkDistances(string s, vector<int>& distance) {
        int len = s.size();
        vector<int> indexarr(26, -1);
        for (int i = 0; i < len; ++i)
        {
            if (indexarr[s[i]-'a'] == -1)
            {
                indexarr[s[i]-'a'] = i;
            }
            else
            {
                if ((abs(indexarr[s[i]-'a']-i)-1) != distance[s[i]-'a'])
                    return false;
            }
        }
        
        return true;
    }