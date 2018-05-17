int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int i = 0, j = sz - 1;
        int sum = 0;
        while (i <= j)
        {
            while (i <= j && nums[i] != val)
                ++i;
            while (i <= j && nums[j] == val)
            {
                ++sum;
                --j;
            }
            if (i < j)
            {
                ++sum;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                ++i;
                --j;
            }
        }
        
        return sz - sum;
    }