int totalMoney(int n) {
        int p = n/7;
        int r = n%7;
        int sum = 28*p + p*(p-1)*7/2;
        
        return sum + ((p+1)+(p+r))*r/2;
    }