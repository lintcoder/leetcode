int findLHS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return 0;
        
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1];
        int maxlen = 0;
        int sublen = (b-a == 1) ? 2 : 0;
        int i = 2;
        int p = -1, q = -1;
        if (sublen == 2)
        {
            p = 0;
            q = 1;
        }
        while (i < len)
        {
            if (sublen != 0)
            {
                if (nums[i] == nums[i-1])
                {
                    ++sublen;
                    q = i;
                }
                else
                {
                    if (nums[i]-nums[i-1] == 1)
                    {
                        int j = i-1;
                        while (j >= 0 && nums[j] == nums[i-1])
                            --j;
                        p = j+1;
                        q = i;
                        if (sublen > maxlen)
                            maxlen = sublen;
                        sublen = i-j;
                    }
                    else
                    {
                        p = -1;
                        q = -1;
                        if (sublen > maxlen)
                            maxlen = sublen;
                        sublen = 0;
                    }
                }
            }
            else
            {
                if (nums[i]-nums[i-1] == 1)
                {
                    int j = i-1;
                    while (j >= 0 && nums[j] == nums[i-1])
                        --j;
                    p = j+1;
                    q = i;
                    if (sublen > maxlen)
                        maxlen = sublen;
                    sublen = i-j; 
                }
            }
            ++i;
        }
        
        if (sublen > maxlen)
            maxlen = sublen;
        return maxlen;
    }