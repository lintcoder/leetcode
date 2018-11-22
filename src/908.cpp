int smallestRangeI(vector<int>& A, int K) {
        int len = A.size();
        if (len <= 1)
            return 0;
        
        sort(A.begin(), A.end());
        int diff = A[len-1] - A[0];
        return diff <= 2*K ? 0 : diff-2*K;
    }