int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        int maxcount= 1;
        int i = 0;
        while (i < len)
        {
        		int j = i;
        		int ct = 1;
        		while (nums[j] != j && nums[j] != -1)
        		{
        			int tmp = nums[j];
        			nums[j] = -1;
        			j = tmp;
        			ct++;
        		}
        		if (ct - 1 > maxcount)
        			maxcount = ct - 1;
        		++i;
        }

        return maxcount;
    }