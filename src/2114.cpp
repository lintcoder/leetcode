int mostWordsFound(vector<string>& sentences) {
        int len = sentences.size();
        int maxn = 0;
        for (int i = 0; i < len; ++i)
        {
            int n = count(sentences[i].begin(), sentences[i].end(), ' ');
            if (n > maxn)
                maxn = n;
        }
        
        return maxn+1;
    }