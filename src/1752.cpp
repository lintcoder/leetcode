bool check(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return true;
        int i = 0;
        while (i < len-1 && nums[i] == nums[i+1])
            ++i;
        if (i == len-1)
            return true;
        
        int val = 0;
        bool flag = false;
        if (nums[i] < nums[i+1])
            flag = true;
        if (flag)
        {
            val = nums[i];
            ++i;
            while (i < len && nums[i] >= nums[i-1])
                ++i;
            if (i == len)
                return true;
            if (nums[i] > val)
                return false;
            ++i;
            while (i < len && nums[i] >= nums[i-1] && nums[i] <= val)
                ++i;
            return i == len;
        }
        else
        {
            val = nums[i];
            ++i;
            while (i < len-1 && nums[i] <= nums[i+1] && nums[i+1] <= val)
                ++i;
            return i == len-1;
        }
    }