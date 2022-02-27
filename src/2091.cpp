int minimumDeletions(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return len;
        
        int maxval = -1e6, minval = 1e6;
        int maxpos = 0, minpos = 0;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] < minval)
            {
                minval = nums[i];
                minpos = i;
            }
            if (nums[i] > maxval)
            {
                maxval = nums[i];
                maxpos = i;
            }
        }
        
        int n1 = minpos > maxpos ? minpos+1 : maxpos+1;
        int n2 = minpos > maxpos ? len-maxpos : len-minpos;
        int n3 = (minpos < len-1-minpos ? minpos+1 : len-minpos) + (maxpos < len-1-maxpos ? maxpos+1 : len-maxpos);
        
        return min(min(n1, n2), n3);
    }