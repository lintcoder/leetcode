string getHint(string secret, string guess) {
        int digitnum1[10] = {0};
        int digitnum2[10] = {0};
    
        int sz = secret.size();
        int ctA = 0, ctB = 0;
        for (int i = 0; i != sz; ++i)
        {
            digitnum1[secret[i] - '0']++;
            digitnum2[guess[i] - '0']++;
            if (secret[i] == guess[i])
                ctA++;
        }
        for (int i = 0; i != 10; ++i)
        {
            ctB += digitnum1[i] < digitnum2[i] ? digitnum1[i] : digitnum2[i];
        }
    
        return num2str(ctA) + "A" + num2str(ctB - ctA) + "B";
    }

    string num2str(int n)
    {
        if (n == 0)
            return "0";
    
        string str;
        while (n != 0)
        {
            str.push_back(char(n % 10 + '0'));
            n /= 10;
        }
        reverse(str.begin(), str.end());
        return str;
    }