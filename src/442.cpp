vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        int len = nums.size();
        int i = 0;
        while (i < len)
        {
        	if (nums[i] == i+1)
        		++i;
        	else
        	{
        		int val = nums[i];
        		nums[i] = 0;
        		while (true)
        		{
        			if (nums[val - 1] == val)
        			{
        				res.push_back(val);
        				break;
        			}
        			else if (nums[val - 1] == 0)
        			{
        				nums[val - 1] = val;
        				break;
        			}
        			else
        			{
        				int tmp = nums[val - 1];
        				nums[val - 1] = val;
        				val = tmp;
        			}
        		}
        		++i;
        	}
        }

        return res;
    }