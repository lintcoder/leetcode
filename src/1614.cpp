int maxDepth(string s) {
        int len = s.size();
        int maxdepth = 0;
        int depth = 0;
        int i = 0;
        
        while (i < len)
        {
            if (s[i] == '(')
                ++depth;
            else if (s[i] == ')')
            {
                if (depth > maxdepth)
                    maxdepth = depth;
                --depth;
            }
            ++i;
        }
        
        return maxdepth;
    }