void moveZeroes(vector<int>& nums) {
    int len = nums.size();
    int i = 0, j = 0;
    while (i < len && j < len)
    {
        while (i < len && nums[i] != 0 )
            i++;
        j = i + 1;
        while (j < len && nums[j] == 0)
            j++;
        if (j >= len)
            break;
        swap(nums[i], nums[j]);
        i++;
        j++;
    }
}
