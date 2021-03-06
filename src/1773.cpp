int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int len = items.size();
        int pos = -1;
        if (ruleKey == "type")
            pos = 0;
        else if (ruleKey == "color")
            pos = 1;
        else
            pos = 2;
        
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (items[i][pos] == ruleValue)
                ++ct;
        }
        
        return ct;
    }