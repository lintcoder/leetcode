bool checkIfPangram(string sentence) {
        int len = sentence.size();
        if (len < 26)
            return false;
        int arr[26] = {0};
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (arr[sentence[i]-'a'] == 0)
            {
                ++ct;
                arr[sentence[i]-'a'] = 1;
            }
        }
        
        return ct == 26;
    }