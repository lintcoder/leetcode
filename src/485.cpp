int findMaxConsecutiveOnes(vector<int>& nums) {
    int len = nums.size();
    int count = 0, subcount = 0;
    int i = 0;
    while (i < len)
    {
        while (i < len && nums[i] == 0)
            ++i;
        if (i == len)
        {
            if (subcount > count)
                count = subcount;
            break;
        }
        while (i < len && nums[i] == 1)
        {
            ++i;
            ++subcount;
        }
        if (subcount > count)
        {
            count = subcount;
        }
        subcount = 0;
    }
    return count;
}
