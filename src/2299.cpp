bool strongPasswordCheckerII(string password) {
        string special = "!@#$%^&*()-+";
        int len = password.size();
        if (len < 8)
            return false;
        int lowernum = 0, uppernum = 0, digitnum = 0, specialnum = 0;
        char last = password[0];
        for (int i = 0; i < len; ++i)
        {
            if (password[i] >= 'a' && password[i] <='z')
                ++lowernum;
            else if (password[i] >= 'A' && password[i] <= 'Z')
                ++uppernum;
            else if (password[i] >= '0' && password[i] <= '9')
                ++digitnum;
            else if (special.find(password[i]) != string::npos)
                ++specialnum;
            if (i >= 1)
            {
                if (password[i] == last)
                    return false;
                last = password[i];
            }
        }
        
        return lowernum >= 1 && uppernum >= 1 && digitnum >= 1 && specialnum >= 1;
    }