int pivotInteger(int n) {
        int sum = (n*n+n)/2;
        int lim = sqrt(sum);
        if (lim*lim == sum)
            return lim;
        else
            return -1;
    }