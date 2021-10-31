string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        int len = arr.size();
        for (int i = 0; i < len; ++i)
            mp[arr[i]]++;
        
        int ct = 1;
        for (int i = 0; i < len; ++i)
        {
            if (mp[arr[i]] == 1)
            {
                if (ct == k)
                    return arr[i];
                else
                    ++ct;
            }
        }
        
        return "";
    }