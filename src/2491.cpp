bool isCircularSentence(string sentence) {
        int len = sentence.size();
        char first = sentence[0], last = sentence[0];
        int i = 1;

        while (i < len)
        {
            if (sentence[i] == ' ')
            {
                last = sentence[i-1];
                if (sentence[i+1] != last)
                    return false;
                else
                    ++i;
            }
            else
                ++i;
        }

        return sentence[i-1] == first;
    }