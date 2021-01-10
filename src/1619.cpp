double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        int k = len*0.05;
        double mean = 0;
        for (int i = k; i < len-k; ++i)
        {
            mean += arr[i];
        }
        
        return mean/(len-2*k);
    }