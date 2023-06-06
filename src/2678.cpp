int countSeniors(vector<string>& details) {
        int ct = 0;
        int len = details.size();
        for (int i = 0; i < len; ++i)
        {
            if ((details[i][11] > '6') || (details[i][11] == '6' && details[i][12] > '0'))
                ++ct;
        }

        return ct;
    }