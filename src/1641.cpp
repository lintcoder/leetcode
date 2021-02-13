int countVowelStrings(int n) {
        int ct = 0;
        for (int i = 0; i < 5; ++i)
            dfs(0, i, n, ct);
        
        return ct;
    }
    
    void dfs(int index, int v, int n, int& ct)
    {
        if (index == n-1)
            ++ct;
        else
        {
            for (int i = v; i < 5; ++i)
                dfs(index+1, i, n, ct);
        }
    }