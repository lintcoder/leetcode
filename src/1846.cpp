int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            if (arr[i] > arr[i-1]+1)
            {
                arr[i] = arr[i-1]+1;
            }
        }
        
        return arr[len-1];
    }