int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        if (len <= 3)
            return arr[0];
        int n = int(len*0.25)+1;
        int i = len-1;
        int j = len*0.25;
        while(i >= j)
        {
            if (arr[i] != arr[i-n+1])
            {
                auto iter = lower_bound(arr.begin()+i-n+1, arr.begin()+i+1, arr[i]);
                i = iter-1-arr.begin();
            }
            else
                break;
        }
        
        return arr[i];
    }