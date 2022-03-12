int mostFrequent(vector<int>& nums, int key) {
        int len = nums.size();
        int target = 0, maxnum = 0;
        for (int i = 0; i < len; ++i)
        {
            int tmp = nums[i], ct = 0;
            for (int j = 0; j < len-1; ++j)
            {
                if (nums[j] == key && nums[j+1] == tmp)
                    ++ct;
            }

            if (ct > maxnum)
            {
                target = tmp;
                maxnum = ct;
            }
        }
        
        return target;
    }