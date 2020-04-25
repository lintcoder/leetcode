int minSetSize(vector<int>& arr) {
        int len = arr.size();
        if (len == 2)
            return 1;
        
        map<int, int> mp;
        for (int i = 0; i < len; ++i)
        {
            mp[arr[i]]++;
        }
        
        int sz = mp.size();
        vector<int> vec(sz);
        int i = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
            vec[i++] = iter->second;
        sort(vec.begin(), vec.end());
        int sum = 0;
        int ct = 0;
        for (i = sz-1; i >= 0; --i)
        {
            sum += vec[i];
            ++ct;
            if (sum >= len/2)
                break;
        }
        
        return ct;
    }