vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        if (len1 == 1 && len2 == 1)
        return {A[0], B[0]};

        vector<int> res(2, 0);
        int arr1[100001] = {0};
        int arr2[100001] = {0};
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < len1; ++i)
        {
            sum1 += A[i];
            ++arr1[A[i]];
        }
        for (int i = 0; i < len2; ++i)
        {
            sum2 += B[i];
            ++arr2[B[i]];
        }

        int diff = (sum1 - sum2)/2;
        int i = 0;
        int k = 0;
        while (i < len1)
        {
            if (diff < 0 && A[i]-diff <= 100000 && B[A[i]-diff] != 0)
            break;
            else if (diff > 0 && A[i] > diff && B[A[i]-diff] != 0)
            break;
            ++i;
        }

        res[0] = A[i];
        res[1] = A[i]-diff;

        return res;
    }