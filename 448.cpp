vector<int> findDisappearedNumbers(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    while (i < len)
    {
        if (nums[i] != i + 1)
        {
            int pos = nums[i] - 1;
            while (nums[pos] != pos + 1)
            {
                int tmp = nums[pos];
                nums[pos] = pos + 1;
                pos = tmp - 1;
            }
        }
        ++i;
    }
    int k = 0;
    for (int i = 0; i < len; ++i)
        if (nums[i] != i + 1)
            nums[k++] = i + 1;
    nums.resize(k);
    return nums;
}
