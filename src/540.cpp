int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        int single = 0;
        doFindSingle(nums, 0, len - 1, single);
        return single;
    }

    bool doFindSingle(vector<int>& nums, int p, int q, int& single)
    {
        if (p == q)
        {
            single = nums[p];
            return true;
        }
        else if (p == q - 1)
            return false;
        else
        {
            int mid = (p + q) / 2;
            bool flag = false;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                single = nums[mid];
                return true;
            }
            else if (nums[mid] == nums[mid - 1])
            {
                if (mid - 2 >= p)
                    flag = doFindSingle(nums, p, mid - 2, single);
                if (!flag)
                    return doFindSingle(nums, mid + 1, q, single);
                else
                    return flag;
            }
            else if (nums[mid] == nums[mid + 1])
            {
                if (mid + 2 <= q)
                    flag = doFindSingle(nums, mid + 2, q, single);
                if (!flag)
                    return doFindSingle(nums, p, mid - 1, single);
                else
                    return flag;
            }
        }
    }