int sumOfUnique(vector<int>& nums) {
        int arr[101] = {0};
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            arr[nums[i]]++;
        
        int sum = 0;
        for (int i = 1; i <= 100; ++i)
            if (arr[i] == 1)
                sum += i;
        
        return sum;
    }