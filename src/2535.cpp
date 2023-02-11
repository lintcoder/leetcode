int differenceOfSum(vector<int>& nums) {
        int elesum = 0, digitsum = 0;
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            elesum += nums[i];
            int tmp = nums[i];
            while (tmp != 0)
            {
                digitsum += tmp%10;
                tmp /= 10;
            }
        }

        return abs(elesum - digitsum);
    }