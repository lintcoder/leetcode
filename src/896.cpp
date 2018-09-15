bool isMonotonic(vector<int>& A) {
     int len = A.size();
     if (len == 1)
     return true;

 	 int pos = 1;
 	 while (A[pos] == A[0])
 	 	++pos;
 	 if (pos == len)
 	 	return true;

     bool flag = A[0] <= A[pos] ? true : false;
     for (int i = pos; i < len-1; ++i)
     {
     	if ((flag && A[i] > A[i+1]) || (!flag && A[i] < A[i+1]))
     		return false;
     }

     return true;
    }