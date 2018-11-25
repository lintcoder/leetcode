int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1)
            return sz;
        int val = nums[0];
        int i = 1, pos = 1, cnt = 1;
        while (i < sz)
        {
            if (nums[i] == val)
                ++i;
            else
            {
                nums[pos] = nums[i];
                val = nums[i];
                pos++;
                cnt++;
                ++i;
            }
        }
        return cnt;
    }