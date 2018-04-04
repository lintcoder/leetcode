int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int len = s.size();
        char c = s[0];
        int sum = 0;
        int val = mp[c];
        int i = 1;
        bool flag = true;
        while (i < len)
        {
            if (s[i] == c)
            {
                val += mp[c];
                if (!flag)
                {
                    sum += val;
                    val = 0;
                    flag = true;
                    ++i;
                    if (i == len)
                        break;
                    c = s[i];
                    val = mp[c];
                    ++i;
                }
                else
                    ++i;
            }
            else if (mp[s[i]] < mp[c])
            {
                sum += val;
                val = mp[s[i]];
                c = s[i];
                flag = false;
                ++i;
            }
            else
            {
                sum += -val + mp[s[i]];
                val = 0;
                flag = true;
                ++i;
                if (i == len)
                    break;
                c = s[i];
                val = mp[c];
                ++i;
            }
        }
        if (val != 0)
        	sum += val;

        return sum;
    }