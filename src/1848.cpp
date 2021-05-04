int getMinDistance(vector<int>& nums, int target, int start) {
        int len = nums.size();
        if (nums[start] == target)
            return 0;
        int i = start-1, j = start+1;
        int ct = 1;
        while (i >= 0 && j < len)
        {
            if (nums[i] == target || nums[j] == target)
                break;
            --i;
            ++j;
            ++ct;
        }
        if (i >= 0 && j < len)
            return ct;
        
        while (i >= 0)
        {
            if (nums[i] == target)
                break;
            --i;
            ++ct;
        }
        if (i >= 0)
            return ct;
        
        while (j < len)
        {
            if (nums[j] == target)
                return ct;
            ++j;
            ++ct;
        }
        
        return ct;
    }