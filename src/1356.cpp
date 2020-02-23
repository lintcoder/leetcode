vector<int> sortByBits(vector<int>& arr) {
        int len = arr.size();
        if (len == 1)
            return arr;
        vector<bitset<32>> vec;
        for (int i = 0; i < len; ++i)
            vec.push_back(arr[i]);
        auto cmp = [](const bitset<32>& a, const bitset<32>& b) {
            int m = a.count(), n = b.count();
            return m < n || (m == n && a.to_ulong() < b.to_ulong());
        };
        
        sort(vec.begin(), vec.end(), cmp);
        vector<int> res(len);
        for (int i = 0; i < len; ++i)
            res[i] = vec[i].to_ulong();
        
        return res;
    }