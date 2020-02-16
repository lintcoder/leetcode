int maxNumberOfBalloons(string text) {
        int len = text.size();
        if (len <= 5)
            return 0;
        
        int arr[5] = {0};
        for (int i = 0; i < len; ++i)
        {
            switch(text[i])
            {
                case 'a':
                    arr[0]++;
                    break;
                case 'b':
                    arr[1]++;
                    break;
                case 'l':
                    arr[4]++;
                    break;
                case 'n':
                    arr[2]++;
                    break;
                case 'o':
                    arr[3]++;
                    break;
            }
        }
        
        arr[3] /= 2;
        arr[4] /= 2;
        int minnum = arr[0];
        for (int i = 1; i < 5; ++i)
            if (arr[i] < minnum)
                minnum = arr[i];
        return minnum;
    }