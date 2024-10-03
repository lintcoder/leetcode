vector<int> getSneakyNumbers(vector<int>& nums) {
        int flag[100] = {0};
        int len = nums.size(), k = 0;

        vector<int> res(2, 0);
        for (int i = 0; i < len; ++i)
        {
            if (flag[nums[i]] == 0)
                flag[nums[i]] = 1;
            else
                res[k++] = nums[i];
        }

        return res;
    }