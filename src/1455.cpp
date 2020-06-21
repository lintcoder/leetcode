int isPrefixOfWord(string sentence, string searchWord) {
        int len = sentence.size();
        int len2 = searchWord.size();
        int i = 0;
        int ct = 1;
        while (i < len)
        {
            int index = sentence.find(' ', i);
            if (index == string::npos)
            {
                if (len-i >= len2 && sentence.substr(i, len2) == searchWord)
                    return ct;
                else
                    break;
            }
            else
            {
                if (index-i >= len2 && sentence.substr(i, len2) == searchWord)
                    return ct;
                else
                {
                    i = index+1;
                    ++ct;
                }
            }
        }
        
        return -1;
    }