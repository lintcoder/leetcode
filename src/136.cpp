int singleNumber(vector<int>& nums) {
    int res = nums[0];
    int len = nums.size();
    for (int i = 1; i < len; ++i)
        res ^= nums[i];
    return res;
}
