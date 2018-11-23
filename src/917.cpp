string reverseOnlyLetters(string S)
    {
        int len = S.size();
        int i = 0, j = len-1;
        while (i < j)
        {
            while (i < j && isalpha(S[i]) == false)
                ++i;
            while (i < j && isalpha(S[j]) == false)
                --j;
            if (i < j)
            {
                std::swap(S[i], S[j]);
                ++i;
                --j;
            }
        }

        return S;
    }