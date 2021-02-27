string getHappyString(int n, int k) {
        int maxn = 3*pow(2, n-1);
        if (k > maxn)
            return "";
        
        string res(n, ' ');
        int ct = 0;
        for (int i = 0; i < 3; ++i)
        {
            dfs('a'+i, 0, n, ct, k, res);
            if (ct == k)
                break;
        }
        
        return res;
    }
    
    void dfs(char c, int m, int n, int& ct, int k, string& res)
    {
        if (ct < k)
        {
            res[m++] = c;
            if (m == n)
            {
                ++ct;
                if (ct == k)
                    return;
            }
            else
            {
                for (int i = 0; i < 3; ++i)
                {
                    if ('a'+i != c)
                        dfs('a'+i, m, n, ct, k, res);
                }
            }
        }
    }