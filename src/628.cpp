int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 3)
            return nums[0]*nums[1]*nums[2];

        sort(nums.begin(), nums.end());
        if (nums[len-1] == 0)
            return 0;
        else if (nums[len-1] < 0)
            return nums[0]*nums[1]*nums[2];
        else
        {
            int p1 = nums[len-1]*nums[len-2]*nums[len-3];
            int p2 = 0;
            auto iter = lower_bound(nums.begin(), nums.end(), 0);
            if (iter - nums.begin() >= 2)
                p2 = nums[len-1]*nums[0]*nums[1];
            if (p1 > p2)
                return p1;
            else
                return p2;
        }
    }