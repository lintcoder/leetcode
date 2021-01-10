vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (auto v : nums)
            mp[v]++;

        auto cmp = [&mp](int a, int b) {
            return mp[a] < mp[b] || (mp[a] == mp[b] && a > b);
        };
        sort(nums.begin(), nums.end(), cmp);
        
        return nums;
    }