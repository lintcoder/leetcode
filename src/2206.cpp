bool divideArray(vector<int>& nums) {
        int arr[501] = {0};
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            arr[nums[i]]++;
        }
        
        for (int i = 0; i < 501; ++i)
        {
            if (arr[i]%2 == 1)
                return false;
        }
        
        return true;
    }