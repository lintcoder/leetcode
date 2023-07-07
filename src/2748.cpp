int countBeautifulPairs(vector<int>& nums) {
        int len = nums.size();
        int ct = 0;
        vector<vector<int>> digits(len, {0,0});

        for (int i = 0; i != len; ++i)
        {
            int x = nums[i]%10;
            int y = nums[i];
            while (y >= 10)
            {
                y /= 10;
            }
            digits[i][1] = x;
            digits[i][0] = y;
            if (x%2 == 0)
                digits[i][1] = 2;
            if (x%3 == 0)
                digits[i][1] = 3;
            if (x == 6)
                digits[i][1] = 6;
            if (y%2 == 0)
                digits[i][0] = 2;
            if (y%3 == 0)
                digits[i][0] = 3;
            if (y == 6)
                digits[i][0] = 6;
        }

        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if ((digits[i][0] == 2 && digits[j][1] == 2) || (digits[i][0] == 2 && digits[j][1] == 6))
                ;
                else if ((digits[i][0] == 3 && digits[j][1] == 3) || (digits[i][0] == 3 && digits[j][1] == 6))
                ;
                else if ((digits[i][0] == 6 && digits[j][1] == 2) || (digits[i][0] == 6 && digits[j][1] == 3) || (digits[i][0] == 6 && digits[j][1] == 6))
                ;
                else if ((digits[i][0] == digits[j][1]) && digits[i][0] != 1)
                ;
                else
                    ++ct;
            }
        }

        return ct;
    }