int scoreOfString(string s) {
        int len = s.size();
        int sum = 0;

        for (int i = 1; i < len; ++i)
        {
            sum += abs(s[i]-s[i-1]);
        }

        return sum;
    }