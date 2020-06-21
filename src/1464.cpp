int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int arr[2] = {0,0};
        arr[0] = nums[0];
        arr[1] = nums[1];
        if (arr[0] < arr[1])
            swap(arr[0], arr[1]);
        for (int i = 2; i < len; ++i)
        {
            if (nums[i] > arr[1])
            {
                if (nums[i] > arr[0])
                {
                    arr[1] = arr[0];
                    arr[0] = nums[i];
                }
                else
                    arr[1] = nums[i];
            }
        }
        
        return (arr[0]-1)*(arr[1]-1);
    }