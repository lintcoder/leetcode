int canBeTypedWords(string text, string brokenLetters) {
        int flag[26] = {0};
        int len = brokenLetters.size();
        for (int i = 0; i < len; ++i)
        {
            flag[brokenLetters[i]-'a'] = 1;
        }
        
        int textlen = text.size();
        int res = 0;
        int i = 0;
        bool isbroke = false;
        while (i < textlen)
        {
            if (text[i] == ' ')
            {
                if (isbroke == false)
                    ++res;
                isbroke = false;
            }
            else if (!isbroke && flag[text[i]-'a'] == 1)
            {
                isbroke = true;
            }
            ++i;
        }
        if (isbroke == false)
            ++res;
        
        return res;
    }