string firstPalindrome(vector<string>& words) {
        int len = words.size();
        for (int i = 0; i < len; ++i)
        {
            bool flag = true;
            int sz = words[i].size();
            for (int j = 0; j < sz/2; ++j)
            {
                if (words[i][j] != words[i][sz-1-j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return words[i];
        }
        
        return "";
    }