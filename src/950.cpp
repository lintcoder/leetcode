vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int len = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(len, 0);
        vector<int> flag(len, 0);
        
        int ct = 0;
        int v = 0;
        int i = 0;
        while (ct < len)
        {
            int j;
            for (j = i; j < len; ++j)
            {
                if (flag[j] == 0)
                {
                    flag[j] = 1-v;
                    if (flag[j] == 1)
                        res[j] = deck[ct++];
                    v = 1-v;
                    i = (j+1)%len;
                    break;
                }
            }
            
            if (j == len)
            {
                for (j = 0; j < i; ++j)
                {
                    if (flag[j] == 0)
                    {
                        flag[j] = 1-v;
                        if (flag[j] == 1)
                            res[j] = deck[ct++];
                        v = 1-v;
                        i = (j+1)%len;
                        break;
                    }
                }
            } 
        }
        
        return res;
    }