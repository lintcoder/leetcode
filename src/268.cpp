int missingNumber(vector<int>& nums) {
    int len = nums.size();
    long long sum = 0;
    for (int i = 0; i < len; ++i)
        sum += i - nums[i];
    return sum + len;
}
