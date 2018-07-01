int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        int p = 0, q = len-1;
        while (p < q)
        {
        	if (p == q-1)
        	{
        		if (A[p] > A[q])
        			return p;
        		else
        			return q;
        	}
        	int mid = (p+q)/2;
        	if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
        		return mid;
        	else if (A[mid] < A[mid-1])
        		q = mid-1;
        	else
        		p = mid+1;
        }
        return p;
    }