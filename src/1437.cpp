bool kLengthApart(vector<int>& nums, int k) {
        int len = nums.size();
        int i = 0;
        while (i < len && nums[i] == 0)
            ++i;
        if (i == len)
            return true;
        
        int j = i+1;
        int n = 0;
        while (j < len)
        {
            if (nums[j] == 0)
                ++n;
            else
            {
                if (n < k)
                    return false;
                else
                {
                    n = 0;
                    i = j;
                }
            }
            ++j;
        }
        
        return true;
    }