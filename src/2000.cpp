string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        if (index != string::npos)
        {
            int i = 0, j = index;
            while (i < j)
            {
                swap(word[i], word[j]);
                ++i;
                --j;
            }
        }
        
        return word;
    }