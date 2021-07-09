bool canBeIncreasing(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return true;
        
        int i = 0;
        for (; i < len-1; ++i)
        {
            if (nums[i+1] <= nums[i])
                break;
        }
        if (i >= len-2)
            return true;
        int j = i;
        if (i == 0 || (i > 0 && nums[i+1] > nums[i-1]))
        {
            i += 1;
            for (; i < len-1; ++i)
            {
                if (nums[i+1] <= nums[i])
                    break;
            }
            if (i == len-1)
                return true;
        }
        
        i = j;
        if (i > 0 && nums[i] < nums[i+2])
        {
            i += 2;
            for (; i < len-1; ++i)
            {
                if (nums[i+1] <= nums[i])
                    break;
            }
            if (i == len-1)
                return true;
        }
        
        return false;
    }