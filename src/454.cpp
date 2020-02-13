int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> sum;
        int len = A.size();
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
                sum.push_back(A[i]+B[j]);
        }
        sort(sum.begin(), sum.end());
        
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                int t = -(C[i]+D[j]);
                if (binary_search(sum.begin(), sum.end(), t))
                {
                    res += upper_bound(sum.begin(), sum.end(), t) - lower_bound(sum.begin(), sum.end(), t);
                }
            }
        }
        
        return res;
    }