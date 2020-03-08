int thirdMax(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (len == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        int arr[3] = {0};
        arr[0] = nums[0];
        int ct = 1;
        int i = 1;
        while (i < len)
        {
            if (ct == 1)
            {
                if (nums[i] != arr[0])
                {
                    arr[1] = nums[i];
                    ++ct;
                }
            }
            else if (ct == 2)
            {
                if (nums[i] != arr[0] && nums[i] != arr[1])
                {
                    arr[2] = nums[i];
                    ++ct;
                    sort(arr, arr+3);
                }
            }
            else
            {
                if (nums[i] > arr[0] && nums[i] < arr[1])
                    arr[0] = nums[i];
                else if (nums[i] > arr[1] && nums[i] < arr[2])
                {
                    arr[0] = arr[1];
                    arr[1] = nums[i];
                }
                else if (nums[i] > arr[2])
                {
                    arr[0] = arr[1];
                    arr[1] = arr[2];
                    arr[2] = nums[i];
                }
            }
            ++i;
        }
        
        if (ct == 1)
            return arr[0];
        else if (ct == 2)
            return arr[0] > arr[1] ? arr[0] : arr[1];
        else
            return arr[0];
    }