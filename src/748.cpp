string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int len = licensePlate.size();
        int num = 0;
        int dict[26] = {0};
        int dst[26] = {0};
        for (int i = 0; i != len; ++i)
        	if (isalpha(licensePlate[i]))
        	{
        		dict[tolower(licensePlate[i]) - 'a']++;
        		++num;
        	}

        int minlen = 1000;
        int sz = words.size();
        string res;

        for (int i = 0; i != sz; ++i)
        {
            len = words[i].size();
            if (len < num || len >= minlen)
                continue;
            int tmp = num;
            memcpy(dst, dict, sizeof(dict));
            for (int j = 0; j != len; ++j)
                if (dict[words[i][j] - 'a'] != 0)
                {
                    --dict[words[i][j] - 'a'];
                    --num;
                    if (num == 0)
                        break;
                }
            if (num == 0 && len < minlen)
            {
                minlen = len;
                res = words[i];
            }
            num = tmp;
            memcpy(dict, dst, sizeof(dst));
        }

        return res;
    }