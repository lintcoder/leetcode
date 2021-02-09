string reorderSpaces(string text) {
        int len = text.size();
        vector<pair<int,int>> wordpos;
        bool flag = false;
        int i = 0;
        int lh = 0, rh = 0;
        int word = 0, space = 0;
        while (i < len)
        {
            if (text[i] == ' ')
            {
                if (flag)
                {
                    rh = i-1;
                    flag = false;
                    wordpos.push_back(make_pair(lh, rh));
                }
                ++space;
            }
            else
            {
                if (!flag)
                {
                    lh = i;
                    ++word;
                    flag = true;
                }
                rh = i;
            }
            ++i;
        }
        if (text[len-1] != ' ')
            wordpos.push_back(make_pair(lh, rh));
        
        int n = word > 1 ? space/(word-1) : 0;
        int remain = space - n*(word-1);
        int k = 0;
        
        string res(len, ' ');
        for (int i = 0; i < word-1; ++i)
        {
            for (int j = wordpos[i].first; j <= wordpos[i].second; ++j)
                res[k++] = text[j];
            k += n;
        }
        
        for (int j = wordpos[word-1].first; j <= wordpos[word-1].second; ++j)
            res[k++] = text[j];
        
        return res;
    }