bool detectCapitalUse(string word) {
    int len = word.size();
    if (len == 0)
        return true;
    else if (len == 1)
        return true;
    else
    {
        if (isupper(word[0]))
        {
            bool flag = isupper(word[1]);
            for (int i = 2; i < len; ++i)
                if (bool(isupper(word[i])) != flag)
                    return false;
            return true;
        }
        else
        {
            for (int i = 1; i < len; ++i)
                if (isupper(word[i]))
                    return false;
            return true;
        }
    }
}   
