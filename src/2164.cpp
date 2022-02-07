vector<int> sortEvenOdd(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return nums;
        for (int i = 0, j = 1; (i < len-1 || j < len-1); i += 2, j += 2)
        {
            for (int m = i+2; m < len; m += 2)
            {
                if (nums[i] > nums[m])
                    swap(nums[i], nums[m]);
            }
            for (int n = j+2; n < len; n += 2)
            {
                if (nums[j] < nums[n])
                    swap(nums[j], nums[n]);
            }
        }
        
        return nums;
    }