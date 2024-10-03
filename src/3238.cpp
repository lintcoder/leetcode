int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> nums(10, vector<int>(11,0));

        int len = pick.size();
        for (int i = 0; i < len; ++i)
        {
            nums[pick[i][0]][pick[i][1]]++;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 11; ++j)
            {
                if (nums[i][j] > i)
                {
                    ++sum;
                    break;
                }
            }
        }

        return sum;
    }