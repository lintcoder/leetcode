int minimumSum(int num) {
        int arr[4] = {0};
        int i = 0;
        while (num > 0)
        {
            arr[i++] = num%10;
            num /= 10;
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = i+1; j < 4; ++j)
            {
                if (arr[i] > arr[j])
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }

        return arr[0]*10+arr[3] + arr[1]*10+arr[2];
    }