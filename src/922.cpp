vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        int i = 0, j = len-1;
        while (i < j)
        {
            if ((i%2 == 0 && A[i]%2 == 0) || (i%2 == 1 && A[i]%2 == 1))
                ++i;
            else
            {
                while ((j%2 == 0 && A[j]%2 == 0) || (j%2 == 1 && A[j]%2 == 1))
                    --j;
                int t = j;
                while (i < t)
                {
                    if ((i%2 == 0 && A[t]%2 == 0) || (i%2 == 1 && A[t]%2 == 1))
                    {
                        swap(A[i], A[t]);
                        break;
                    }
                    else
                        --t;
                }
                ++i;
            }
        }
        
        return move(A);
    }