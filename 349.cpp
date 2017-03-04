vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> mp;
    vector<int> res;
    int len1 = nums1.size();
    for (int i = 0; i < len1; ++i)
        mp[nums1[i]]++;
    sort(nums2.begin(), nums2.end());
    int len2 = nums2.size();
    int j = 0;
    while (j < len2)
    {
        int val = nums2[j];
        if (mp.find(val) != mp.end())
        {
            res.push_back(val);
        }
        while (j < len2 && nums2[j] == val)
            ++j;
    }
    return res;
}
