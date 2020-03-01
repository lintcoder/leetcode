vector<bool> prefixesDivBy5(vector<int>& A) {
        int len = A.size();
        int sum = 0;
        vector<bool> vec(len);
        for (int i = 0; i < len; ++i)
        {
            sum = sum*2 + A[i];
            sum %= 5;
            if (sum%5 == 0)
                vec[i] = true;
            else
                vec[i] = false;
        }
        
        return vec;
    }