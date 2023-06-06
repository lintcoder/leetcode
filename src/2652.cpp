int sumOfMultiples(int n) {
        const int arr[7] = {n/3, n/5, n/7, n/15, n/21, n/35, n/105};
        int sum1 = 3*arr[0] + arr[0]*(arr[0]-1)*3/2;
        int sum2 = 5*arr[1] + arr[1]*(arr[1]-1)*5/2;
        int sum3 = 7*arr[2] + arr[2]*(arr[2]-1)*7/2;
        int sum4 = 15*arr[3] + arr[3]*(arr[3]-1)*15/2;
        int sum5 = 21*arr[4] + arr[4]*(arr[4]-1)*21/2;
        int sum6 = 35*arr[5] + arr[5]*(arr[5]-1)*35/2;
        int sum7 = 105*arr[6] + arr[6]*(arr[6]-1)*105/2;

        return sum1+sum2+sum3-sum4-sum5-sum6+sum7;
    }