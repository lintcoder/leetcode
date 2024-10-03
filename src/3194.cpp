double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = n/2;

        double minaverage = nums.back();
        for (int i = 0; i < k; ++i)
        {
            double tmp = (nums[i]+nums[n-1-i])/2.0;
            if (tmp < minaverage)
                minaverage = tmp;
        }

        return minaverage;
    }