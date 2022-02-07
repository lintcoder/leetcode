int countElements(vector<int>& nums) {
        int minval = 1e6, maxval = -1e6;
        int minnum = 0, maxnum = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] < minval)
            {
                minval = nums[i];
                minnum = 1;
            }
            else if (nums[i] == minval)
            {
                ++minnum;
            }
            if (nums[i] > maxval)
            {
                maxval = nums[i];
                maxnum = 1;
            }
            else if (nums[i] == maxval)
            {
                ++maxnum;
            }
        }

        return (len-minnum-maxnum) > 0 ? (len-minnum-maxnum) : 0;
    }