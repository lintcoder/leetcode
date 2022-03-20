int countHillValley(vector<int>& nums) {
        int len = nums.size();
        int i = 1;
        while (i < len-1 && nums[i] == nums[i-1])
            ++i;
        if (i == len-1)
            return 0;
        
        int prepos = i-1;
        int ct = 0;
        while (i < len)
        {
            int j = i;
            ++i;
            while (i < len && nums[i] == nums[i-1])
                ++i;
            if (i == len)
                break;
            if ((nums[j] < nums[prepos] && nums[j] < nums[i])
               || (nums[j] > nums[prepos] && nums[j] > nums[i]))
                ++ct;
            prepos = j;
        }
        
        return ct;
    }