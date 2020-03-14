bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        if (len <= 1)
            return false;
        if (len == 2)
            return deck[0] == deck[1];
        
        map<int,int> mp;
        for (int i = 0; i < len; ++i)
            mp[deck[i]]++;
        
        int sz = mp.size();
        if (sz == 1)
            return true;
        auto iter = mp.begin();
        int a = iter->second;
        ++iter;
        int b = iter->second;
        ++iter;
        int div = gcd(a, b);
        if (div == 1)
            return false;
        for (; iter != mp.end(); ++iter)
        {
            div = gcd(iter->second, div);
            if (div == 1)
                return false;
        }
        
        return true;
    }
    
    int gcd(int a, int b)
    {
        if (a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        
        while (a != 1)
        {
            b %= a;
            if (b == 0)
                break;
            if (a > b)
            {
                int t = a;
                a = b;
                b = t;
            }
        }
        
        return a;
    }