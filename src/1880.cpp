bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int len1 = firstWord.size();
        int len2 = secondWord.size();
        int len = targetWord.size();
        int val1 = 0, val2 = 0, val = 0;
        for (int i = 0; i < len1; ++i)
            val1 = 10*val1 + firstWord[i]-'a';
        for (int i = 0; i < len2; ++i)
            val2 = 10*val2 + secondWord[i]-'a';
        for (int i = 0; i < len; ++i)
            val = 10*val + targetWord[i]-'a';
        
        return val1 + val2 == val;
    }