int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3)
        	return 0;

        int i = 0;
        int sum = 0;
        while (i < len - 2)
        {
        	int dif = A[i + 1] - A[i];
        	int j = i + 1;
        	while (j+1 < len && A[j+1] - A[j] == dif)
        		++j;
        	if (j - i >= 2)
        	{
        		int n = j - i + 1 - 3 + 1;
        		sum += (1+n)*n/2;
        	}
        	i = j;
        }

        return sum;
    }