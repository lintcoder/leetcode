int findClosestNumber(vector<int>& nums) {
        int mindist = 1e5;
        int val = -1e5;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            int tmp = abs(nums[i]);
            if (tmp < mindist)
            {
                mindist = tmp;
                val = nums[i];
            }
            else if (tmp == mindist)
            {
                if (nums[i] > val)
                    val = nums[i];
            }
        }
        
        return val;
    }