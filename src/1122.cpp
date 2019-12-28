vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        if (len1 == 0)
            return arr1;
        if (len2 == 0)
        {
            sort(arr1.begin(), arr1.end());
            return arr1;
        }
        
        map<int, int> mp;
        for (int i = 0; i < len2; ++i)
            mp[arr2[i]] = i;
        
        auto cmp = [&mp](int a, int b){
            auto iter1 = mp.find(a);
            auto iter2 = mp.find(b);
            if (iter1 != mp.end() && iter2 != mp.end())
                return mp[a] < mp[b];
            else if (iter1 != mp.end() && iter2 == mp.end())
                return true;
            else if (iter1 == mp.end() && iter2 != mp.end())
                return false;
            else
                return a < b;
        };
        
        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }