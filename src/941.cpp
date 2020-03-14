bool validMountainArray(vector<int>& A) {
        int len = A.size();
        if (len < 3)
            return false;
        
        int i = 1;
        for (i = 1; i < len; ++i)
        {
            if (A[i] == A[i-1])
                return false;
            if (A[i] < A[i-1])
                break;
        }
        if (i == 1 || i == len)
            return false;
        if (i == len-1)
            return true;
        for (; i < len-1; ++i)
        {
            if (A[i] <= A[i+1])
                return false;
        }
        
        return true;
    }