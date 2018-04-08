int findLengthOfLCIS(vector<int>& nums) {
         int len = nums.size();
         if (len <= 1)
            return len;
         int maxlen = 1;
         int count = 1;
         for (int i = 1; i < len; ++i)
         {
            if (nums[i] > nums[i - 1])
                ++count;
            else if (nums[i] <= nums[i - 1])
            {
                if (count > maxlen)
                    maxlen = count;
                count = 1;
            }
         }
         if (count > maxlen)
             maxlen = count;

         return maxlen;
    }