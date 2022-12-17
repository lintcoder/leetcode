int maximumValue(vector<string>& strs) {
        int len = strs.size();
        int maxval = 0;
        for (int i = 0; i < len; ++i)
        {
            int n = strs[i].size();
            bool flag = false;
            int j = 0;
            int val = 0;
            while (j < n)
            {
                if (isdigit(strs[i][j]))
                    val = val*10 + (strs[i][j]-'0');
                else
                {
                    flag = true;
                    break;
                }
                ++j;
            }

            if (flag)
            {
                if (n > maxval)
                    maxval = n;
            }
            else
            {
                if (val > maxval)
                    maxval = val;
            }
            cout << val << endl;
        }

        return maxval;
    }