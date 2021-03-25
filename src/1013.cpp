bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += A[i];
        }
        if (sum%3 != 0)
            return false;
        
        int i = 0;
        int subsum = 0;
        while (i <len-2)
        {
            subsum += A[i];
            if (subsum == sum/3)
                break;
            ++i;
        }
        
        if (i == len-2)
            return false;
        ++i;
        
        subsum = 0;
        while (i < len-1)
        {
            subsum += A[i];
            if (subsum == sum/3)
                break;
            ++i;
        }
        
        return i < len-1;
    }