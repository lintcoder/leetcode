vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        int len = nums.size();
        if (len <= 1)
        	return res;
        vector<int> flag(len, 1);
        for (int i = 0; i < len; ++i)
        {
            if (flag[nums[i] - 1] == 1)
                flag[nums[i] - 1] = 0;
            else
                res[0] = nums[i];
        }
        for (int i = 0; i < len; ++i)
            if (flag[i] == 1)
            {
                res[1] = i+1;
                break;
            }
        return res;
    }