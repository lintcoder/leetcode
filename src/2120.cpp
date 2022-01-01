vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len = s.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; ++i)
        {
            int r = startPos[0], c = startPos[1];
            int j = i;
            for (; j < len; ++j)
            {
                if (s[j] == 'L')
                {
                    if (c == 0)
                        break;
                    --c;
                }
                else if (s[j] == 'R')
                {
                    if (c == n-1)
                        break;
                    ++c;
                }
                else if (s[j] == 'U')
                {
                    if (r == 0)
                        break;
                    --r;
                }
                else
                {
                    if (r == n-1)
                        break;
                    ++r;
                }
            }
            
            res[i] = j-i;
        }
        
        return res;
    }