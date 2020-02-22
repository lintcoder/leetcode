int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = A.size();
        int maxPeri = 0;
        for (int i = len-1; i >= 2; --i)
        {
            if (A[i-2] + A[i-1] >A[i])
            {
                maxPeri = A[i-2] + A[i-1] + A[i];
                break;
            }
        }
        
        return maxPeri;
    }