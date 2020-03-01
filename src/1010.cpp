int numPairsDivisibleBy60(vector<int>& time) {
        int len = time.size();
        if (len == 1)
            return 0;
        
        vector<int> vec(60);
        for (int i = 0; i < len; ++i)
        {
            vec[time[i]%60]++;
        }
        
        int sum = 0;
        sum += vec[0]*(vec[0]-1)/2 + vec[30]*(vec[30]-1)/2;
        for (int i = 1; i <= 29; ++i)
        {
            sum += vec[i]*vec[60-i];
        }
        
        return sum;
    }