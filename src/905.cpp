vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        if (len <= 1)
            return A;
        int i = 0, j = len-1;
        while (i < j)
        {
            while (i < j && A[i]%2 == 0)
                ++i;
            while (i < j && A[j]%2 == 1)
                --j;
            if (i < j)
                swap(A[i], A[j]);
        }
        
        return A;
    }