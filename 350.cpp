vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> mp;
    vector<int> res;
    int len1 = nums1.size();
    int len2 = nums2.size();
    for (int i = 0; i < len1; ++i)
        mp[nums1[i]]++;
    for (int i = 0; i < len2; ++i)
    {
        if (mp.find(nums2[i]) != mp.end() && mp[nums2[i]] != 0)
        {
            res.push_back(nums2[i]);
            mp[nums2[i]]--;
        }
    }
    return res;
}
