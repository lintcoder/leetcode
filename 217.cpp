bool containsDuplicate(vector<int>& nums) {
    map<int, int> mp;
    int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] > 1)
            return true;
    }
    return false;
}
