int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len == 1)
            return 0;
        int maxnum = 0, submaxnum = 0, pos = 0;
        if (nums[0] > nums[1])
        {
            maxnum = nums[0];
            submaxnum = nums[1];
            pos = 0;
        }
        else
        {
            maxnum = nums[1];
            submaxnum = nums[0];
            pos = 1;
        }
        int i = 2;
        while (i < len)
        {
            if (nums[i] > maxnum)
            {
                submaxnum = maxnum;
                maxnum = nums[i];
                pos = i;
            }
            else if (nums[i] > submaxnum)
            {
                submaxnum = nums[i];
                if (submaxnum >= 50)
                    return -1;
            }
            ++i;
        }
        if (maxnum >= submaxnum*2)
            return pos;
        else
            return -1;
    }