int maxScore(string s) {
        int len = s.size();
        int arr[2] = {0, 0};
        for (int i = 0; i < len; ++i)
            arr[s[i]-'0']++;
        
        int num1 = 0, num2 = 0;
        int maxscore = 0;
        for (int i = 0; i < len-1; ++i)
        {
            if (s[i] == '0')
                ++num1;
            else
                ++num2;
            int tmp = num1 + arr[1]-num2;
            if (tmp > maxscore)
                maxscore = tmp;
        }
        
        return maxscore;
    }