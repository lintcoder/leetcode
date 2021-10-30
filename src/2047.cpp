int countValidWords(string sentence) {
        auto first = sentence.begin();
        auto last = sentence.end();
        auto p = first, q = first;
        auto func = [](char c){
            return c == ' ';
        };
        
        int ct = 0;
        p = find_if_not(p, last, func);
        q = find_if(p, last, func);
        while (p != last && q != last)
        {
            if (isValid(sentence, p, q))
                ++ct;
            p = find_if_not(q, last, func);
            if (p != last)
                q = find_if(p, last, func);
        }
        
        if (p != last && isValid(sentence, p, q))
            ++ct;

        return ct;
    }
    
    bool isValid(const string& sentence, string::iterator& p, string::iterator& q)
    {
        int hyphennum = 0;
        for (auto iter = p; iter != q; ++iter)
        {
            if (isdigit(*iter))
                return false;
            if (*iter == '-')
            {
                ++hyphennum;
                if (hyphennum > 1)
                    return false;
                if (iter == p || iter == q-1)
                    return false;
                if (!isalpha(*(iter-1)) || !(isalpha(*(iter+1))))
                    return false;
            }
            if ((*iter == ',' || *iter == '.' || *iter == '!') && (iter != q-1))
                return false;
        }
        
        return true;
    }