vector<int> leftRigthDifference(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;

        vector<int> leftsum(len, 0);
        vector<int> res(len, 0);
        for (int i = 0; i < len; ++i)
        {
            leftsum[i] = sum;
            sum += nums[i];
        }
        for (int i = 0; i < len; ++i)
        {
            res[i] = abs(leftsum[i]-(sum-leftsum[i]-nums[i]));
        }

        return res;
    }