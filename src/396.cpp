int maxRotateFunction(vector<int>& A) {
        int sz = A.size();
        int sum = 0, subsum = 0;
        int total = 0;
        for (int i = 0; i < sz; ++i)
            total += A[i];
        for (int i = 0; i < sz; ++i)
            subsum += i * A[i];
        sum = subsum;
        for (int i = 1; i < sz; ++i)
        {
            subsum = subsum + total - sz * A[sz - i];
            if (subsum > sum)
                sum = subsum;
        }
        
        return sum;
    }