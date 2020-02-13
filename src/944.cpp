int minDeletionSize(vector<string>& A) {
        int len = A.size();
        int sz = A[0].size();
        int ct = 0;
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < len-1; ++j)
                if (A[j][i] > A[j+1][i])
                {
                    ++ct;
                    break;
                }   
        }
        
        return ct;
    }