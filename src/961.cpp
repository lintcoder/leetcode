int repeatedNTimes(vector<int>& A) {
        int ct[10000] = {0};
        int len = A.size();
        int i = 0;
        for (; i < len; ++i)
        {
            ct[A[i]]++;
            if (ct[A[i]] == (len/2))
                break;
        }
        
        return A[i];
    }