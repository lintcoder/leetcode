vector<int> separateDigits(vector<int>& nums) {
        list<int> tmplist;
        int len = nums.size();
        for (int i = len-1; i >= 0; --i)
        {
            while (nums[i] != 0)
            {
                tmplist.push_front(nums[i]%10);
                nums[i] /= 10;
            }
        }

        return vector<int>(tmplist.begin(), tmplist.end());
    }