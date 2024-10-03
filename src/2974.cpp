vector<int> numberGame(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res(len, 0);

        for (int i = 0; i < len/2; ++i)
        {
            res[i*2] = nums[i*2+1];
            res[i*2+1] = nums[i*2];
        }

        return res;
    }