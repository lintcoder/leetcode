int countArrangement(int N) {
        if (N <= 2)
            return N;
        vector<int> arr(N, 0);
        int count = 0;
        int total = 0;

        docountArrange(arr, N, count, total);

        return total;
    }
    
    void docountArrange(vector<int>& arr, int n, int count, int& total)
    {
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == 0)
            {
                if ((count + 1) % (i + 1) == 0 || (i + 1) % (count + 1) == 0)
                {
                    arr[i] = 1;
                    if (count+1 < n)
                        docountArrange(arr, n, count+1, total);
                    else
                        total++;
                    arr[i] = 0;
                }
            }
        }
    }