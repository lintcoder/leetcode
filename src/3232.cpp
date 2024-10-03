bool canAliceWin(vector<int>& nums) {
        int len = nums.size();
        int oddsum = 0, evensum = 0;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] < 10)
                oddsum += nums[i];
            else
                evensum += nums[i];
        }

        return oddsum != evensum;
    }